// $Id: Execution_Times.aspx.cs,v 1.1.2.10.2.1 2006/05/15 18:45:12 hillj Exp $

using System;
using System.Collections;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Data.Odbc;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

namespace CUTS
{
  /// <summary>
  /// Summary description for Execution_Times.
  /// </summary>
  public partial class Execution_Times : System.Web.UI.Page
  {
    protected System.DateTime timestamp_;

    protected long test_;

    private OdbcConnection conn_  = new OdbcConnection(
        ConfigurationManager.AppSettings["ConnectionString"]);

    private void Page_Load(object sender, System.EventArgs e)
    {

    }

    /// <summary>
    ///
    /// </summary>
    private void init ()
    {
      try
      {
        // Get the test number from the query string.
        if (Request.QueryString["test"] != null)
        {
          this.test_ = System.Int32.Parse(Request.QueryString["test"]);

          // Open the connection.
          this.conn_.Open();

          // Get the critical paths.
          this.critical_paths_.DataSource = get_critical_paths();
          this.critical_paths_.DataBind();

          DateTime max_time = new DateTime();
          if (init_collection_time(ref max_time))
          {
            init_execution_times(max_time);

            this.timestamp_ = max_time;
            this.collection_times_.SelectedValue = max_time.ToString();
          }
        }
      }
      catch (OdbcException ex)
      {
        this.label_.Text =
          "ODBC exception has occured; " + ex.Message;
      }
      catch (ArgumentOutOfRangeException ex)
      {
        this.label_.Text = ex.Message;
      }
      catch (Exception ex)
      {
        this.label_.Text =
          "Unknown exception has occured; " + ex.Message;
      }
      finally
      {
        if (this.conn_.State == ConnectionState.Open)
        {
          this.conn_.Close();
        }
      }
    }

    protected void handle_view_clicked (Object sender, CommandEventArgs e)
    {
      if (e.CommandName == "path")
      {
        System.Text.StringBuilder sb = new System.Text.StringBuilder();
        sb.Append("Critical_Path_Timeline.aspx?t=");
        sb.Append(this.test_);
        sb.Append("&p=");
        sb.Append(this.critical_paths_.SelectedValue);

        Response.Redirect(sb.ToString());
      }
      else if (e.CommandName == "time")
      {
        this.conn_ = new OdbcConnection(
          ConfigurationManager.AppSettings["ConnectionString"]);

        try
        {
          this.conn_.Open();

          this.timestamp_ = DateTime.Parse(this.collection_times_.SelectedValue);
          this.placeholder_.Controls.Clear();
          init_execution_times(this.timestamp_);
        }
        catch (OdbcException)
        {

        }
        catch (Exception)
        {

        }
        finally
        {
          if (this.conn_.State == ConnectionState.Open)
          {
            this.conn_.Close();
          }
        }
      }
    }

    private void init_execution_times (DateTime time)
    {
      // Build the command to select the components in this test.
      System.Text.StringBuilder builder = new System.Text.StringBuilder();
      builder.Append("SELECT DISTINCT component, component_name ");
      builder.Append("FROM execution_time LEFT JOIN component_instances ");
      builder.Append("ON (component = component_id) ");
      builder.Append("WHERE (test_number = ? AND collection_time = ?) ");
      builder.Append("ORDER BY component_name");

      OdbcCommand command = new OdbcCommand(builder.ToString(),
                                            this.conn_);

      // Create the parameter for the command.
      OdbcParameter p1 = new OdbcParameter("test_number", OdbcType.Int);
      p1.Direction = ParameterDirection.Input;
      p1.Value = this.test_;
      command.Parameters.Add(p1);

      OdbcParameter p2 = new OdbcParameter("collection_time", OdbcType.DateTime);
      p2.Direction = ParameterDirection.Input;
      p2.Value = time;
      command.Parameters.Add(p2);

      // Execute the query as a data reader.
      OdbcDataReader c_reader = command.ExecuteReader();

      while (c_reader.Read())
      {
        long component_id = c_reader.GetInt32(0);

        // Create the control to display the component metrics.
        Control control = Page.LoadControl("Component_Metrics.ascx");
        CUTS.Component_Metrics m_ctrl = (CUTS.Component_Metrics)control;

        // Initialize the control with the appropriate data.
        m_ctrl.InstanceID = component_id;
        try
        {
          m_ctrl.InstanceName = c_reader.GetString(1);
        }
        catch (Exception)
        {
          m_ctrl.InstanceName =
            "Unknown instance [ID = " + component_id + "]";
        }

        // Get all the components that send to this component.
        OdbcDataReader s_reader = this.get_senders(component_id, time);

        while (s_reader.Read())
        {
          // Get the ID of the sender and get the metrics related
          // to this sender.
          long sender_id = s_reader.GetInt32(0);

          // Create a new sender metrics control.
          System.Web.UI.Control s_ctrl =
            Page.LoadControl("Sender_Metrics.ascx");
          CUTS.Sender_Metrics s_metric_ctrl = (CUTS.Sender_Metrics)s_ctrl;

          s_metric_ctrl.Test = this.test_;
          s_metric_ctrl.Owner = component_id;
          s_metric_ctrl.InstanceID = sender_id;

          try
          {
            s_metric_ctrl.InstanceName = s_reader.GetString(1);
          }
          catch (Exception)
          {
            s_metric_ctrl.InstanceName =
              "Unknown sender [ID = " + sender_id + "]";
          }

          s_metric_ctrl.BindDataSource(this.conn_, time);
          m_ctrl.SenderMetrics.Controls.Add (s_metric_ctrl);
        }

        // Close the reader w/ the sender components.
        s_reader.Close();

        // Add the control to the page.
        this.placeholder_.Controls.Add(m_ctrl);
      }

      c_reader.Close();
    }

    private OdbcDataReader get_senders (long component, DateTime time)
    {
      // Create the query to select the senders.
      System.Text.StringBuilder builder = new System.Text.StringBuilder ();
      builder.Append ("SELECT DISTINCT sender, component_name FROM execution_time ");
      builder.Append ("LEFT JOIN component_instances ON (sender = component_id) ");
      builder.Append ("WHERE (test_number = ? AND component = ? ");
      builder.Append ("AND collection_time = ?)");

      // Create and initialize the parameters.
      OdbcParameter p1 = new OdbcParameter ("test_number", OdbcType.Int);
      p1.Direction = ParameterDirection.Input;
      p1.Value = this.test_;

      OdbcParameter p2 = new OdbcParameter ("component", OdbcType.Int);
      p2.Direction = ParameterDirection.Input;
      p2.Value = component;

      OdbcParameter p3 = new OdbcParameter("collection_time", OdbcType.DateTime);
      p3.Direction = ParameterDirection.Input;
      p3.Value = time;

      // Insert the parameters into the command.
      OdbcCommand command = new OdbcCommand (builder.ToString (), this.conn_);
      command.Parameters.Add (p1);
      command.Parameters.Add (p2);
      command.Parameters.Add(p3);

      // Execute the command and return the reader.
      return command.ExecuteReader ();
    }

    private DataTable get_critical_paths ()
    {
      // Create a new command.
      OdbcCommand command = this.conn_.CreateCommand ();
      command.CommandText =
        "SELECT path_id, path_name FROM critical_path ORDER BY path_name";

      // Create an adapter w/ the following select command.
      OdbcDataAdapter adapter = new OdbcDataAdapter (command);

      // Create a new dataset and fill it using the adapter.
      DataSet ds = new DataSet ();
      adapter.Fill (ds, "critical_path");

      // Return the data table.
      return ds.Tables["critical_path"];
    }

    private bool init_collection_time (ref DateTime max_time)
    {
      OdbcParameter p1 = new OdbcParameter ("@test_number", OdbcType.Int);
      p1.Direction = ParameterDirection.Input;
      p1.Value = this.test_;

      System.Text.StringBuilder builder = new System.Text.StringBuilder ();
      builder.Append ("SELECT DISTINCT collection_time FROM execution_time ");
      builder.Append ("WHERE (test_number = ?)");

      OdbcCommand command = this.conn_.CreateCommand();
      command.CommandText = builder.ToString();
      command.Parameters.Add (p1);

      OdbcDataAdapter adapter = new OdbcDataAdapter(command);
      DataSet ds = new DataSet();

      adapter.Fill(ds, "collection_time");

      // Bind the dataset to the <collection_time_> control.
      this.collection_times_.DataSource = 
        ds.Tables["collection_time"].DefaultView;
      this.collection_times_.DataBind();

      Object result = 
        ds.Tables["collection_time"].Compute("MAX(collection_time)", "");

      if (result != DBNull.Value)
      {
        max_time = (DateTime)result;
        return true;
      }
      else
      {
        return false;
      }
    }

    #region Web Form Designer generated code
    override protected void OnInit(EventArgs e)
    {
      InitializeComponent();

      this.init ();

      base.OnInit(e);
    }

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
      this.Load += new System.EventHandler(this.Page_Load);
    }
    #endregion
  }
}