// $Id$

#include "StdAfx.h"
#include "Deployment_Plan_Generator.h"
#include "Deployment_Plan_Generator_Impl.h"
#include "DeploymentPlan_MainDialog.h"
#include "DeploymentPlanVisitor.h"

#include "game/be/Interpreter_T.h"

#include "UdmGme.h"
#include "UdmStatic.h"
#include "UdmConfig.h"

#include "game/utils/Project_Settings.h"
#include "Utils/Utils.h"

GAME_DECLARE_INTERPRETER (Deployment_Plan_Generator, Deployment_Plan_Generator_Impl);

/**
 * @struct insert_udm_t
 */
struct insert_udm_t
{
  insert_udm_t (UdmGme::GmeDataNetwork & network, std::set <Udm::Object> & coll)
    : network_ (network),
      coll_ (coll)
  {

  }

  void operator () (const GAME::FCO & fco) const
  {
    this->coll_.insert (this->network_.Gme2Udm (fco.impl ()));
  }

private:
  UdmGme::GmeDataNetwork & network_;

  std::set <Udm::Object> & coll_;
};

//
// Deployment_Plan_Generator_Impl
//
Deployment_Plan_Generator_Impl::Deployment_Plan_Generator_Impl (void)
: GAME::Interpreter_Impl_Base ("DAnCE Deployment Plan Generator",
                               "MGA.Interpreter.DeploymentPlan",
                               "PICML")
{

}

//
// ~Deployment_Plan_Generator_Impl
//
Deployment_Plan_Generator_Impl::~Deployment_Plan_Generator_Impl (void)
{

}

//
// invoke_ex
//
int Deployment_Plan_Generator_Impl::
invoke_ex (GAME::Project & project,
           GAME::FCO & focus,
           std::vector <GAME::FCO> & selected,
           long flags)
{
  UdmGme::GmeDataNetwork dngBackend (PICML::diagram);

  try
  {
    dngBackend.OpenExisting (project.impl ());

    // Get the last output directory.
    GAME::utils::Project_Settings settings (project);
    this->config_.output_path_ = settings.default_output_directory ("__PICML__/DeploymentPlan").c_str ();

    if (this->is_interactive_)
    {
      AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
      Deployment_Plan_Dialog dlg (this->config_, ::AfxGetMainWnd ());

      if (dlg.DoModal () == IDCANCEL)
        return 0;

      // Save the directory back to the model.
      settings.default_output_directory ("__PICML__/DeploymentPlan",
                                         this->config_.output_path_.GetBuffer ());
    }

    // Opening backend
    DeploymentPlanVisitor dpv (this->config_.output_path_.GetBuffer ());

    if (selected.empty ())
    {
      PICML::RootFolder folder = PICML::RootFolder::Cast (dngBackend.GetRootObject ());
      folder.Accept (dpv);
    }
    else
    {
      set <Udm::Object> objects;
      std::for_each (selected.begin (),
                     selected.end (),
                     insert_udm_t (dngBackend, objects));

      set <Udm::Object>::const_iterator
        iter = objects.begin (), iter_end = objects.end ();

      for (; iter != iter_end; ++ iter)
      {
        if (iter->type () != PICML::DeploymentPlan::meta)
          continue;

        PICML::DeploymentPlan plan = PICML::DeploymentPlan::Cast (*iter);
        plan.Accept (dpv);
      }
    }

    if (this->is_interactive_)
      ::AfxMessageBox ("Successfully generated deployment plan descriptors");

    // Closing backend
    dngBackend.CloseWithUpdate ();
    return 0;
  }
  catch (udm_exception & exc)
  {
    if (this->is_interactive_)
      ::AfxMessageBox (exc.what ());
  }

  dngBackend.CloseNoUpdate ();
  return -1;
}

//
// set_parameter
//
int Deployment_Plan_Generator_Impl::
set_parameter (const std::string & name, const std::string & value)
{
  if (name == "OutputPath")
    this->config_.output_path_ = value.c_str ();

  return 0;
}
