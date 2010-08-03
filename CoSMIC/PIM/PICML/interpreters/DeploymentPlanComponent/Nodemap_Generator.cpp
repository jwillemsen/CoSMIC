#include "Nodemap_Generator.h"

#include "Utils/UDM/Position_Sort_T.h"

#include "boost/bind.hpp"

#include <algorithm>

//
// Nodemap_Generator
//
Nodemap_Generator::
Nodemap_Generator (const std::string & outputPath)
: outputPath_ (outputPath)
{
}


//
// ~Nodemap_Generator
//
Nodemap_Generator::
~Nodemap_Generator (void)
{
}


//
// Visit_DeploymentPlan
//
void Nodemap_Generator::
Visit_DeploymentPlan (const PICML::DeploymentPlan & plan)
{
  // Create the document
  this->outputPath_.append ("/");
  this->outputPath_.append (plan.name ().operator std::string ().c_str ());
  this->outputPath_.append (".nodemap");

  // Visit all the nodes in the deployment plan.  
  std::vector <PICML::NodeReference> nodes = plan.NodeReference_children ();
  
  std::for_each (nodes.begin (),
                 nodes.end (),
                 boost::bind (&PICML::NodeReference::Accept, 
                              _1, 
                              boost::ref (*this)));
  if(out.is_open ())
    out.close ();
}


//
// Visit_NodeReference
//
void Nodemap_Generator::
Visit_NodeReference (const PICML::NodeReference & noderef)
{
  this->curr_node_ref_name_ = noderef.name ();
  
  std::set <PICML::PropertyMapping> mapping = noderef.dstPropertyMapping () ;
  std::for_each (mapping.begin (),
                 mapping.end (),
                 boost::bind (&PICML::PropertyMapping::Accept,
                              _1,
                              boost::ref (*this)));
}


//
// Visit_PropertyMapping
//
void Nodemap_Generator::
Visit_PropertyMapping (const PICML::PropertyMapping & pmapping)
{
	PICML::Property prop = pmapping.dstPropertyMapping_end ();
	PICML::Property (prop).Accept (*this);
}


//
// Visit_Property
//
void Nodemap_Generator::
Visit_Property (const PICML::Property & prop)
{
  this->curr_prop_name_ = prop.name ();

  typedef UDM_Position_Sort_T <PICML::DataValue, PS_Top_To_Bottom> sorter_t;
  sorter_t sorter ("DataValueAspect", PS_Top_To_Bottom ());
  std::set <PICML::DataValue, sorter_t> sorted_values (sorter);
  sorted_values = prop.DataValue_kind_children_sorted (sorter);

  std::for_each (sorted_values.begin (),
                 sorted_values.end (),
                 boost::bind (&PICML::DataValue::Accept,
                              _1,
                              boost::ref (*this)));
}


//
// Visit_DataValue
//
void Nodemap_Generator::
Visit_DataValue (const PICML::DataValue & dv)
{
  if (this->curr_prop_name_ == "StringIOR")
  {
    if(!out.is_open ())
    {
      out.open (this->outputPath_.c_str (), std::ios::trunc);
      out<<this->curr_node_ref_name_<<" "<<dv.Value ();
    }
    else
    {
      out<<std::endl<<std::endl<<this->curr_node_ref_name_<<" "<<dv.Value ();
    }
  }
}