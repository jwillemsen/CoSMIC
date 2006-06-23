<%@ Reference control="Component_Metrics.ascx" %>
<%@ Page language="c#" codefile="Execution_Times.aspx.cs" autoeventwireup="true" 
         inherits="CUTS.Execution_Times" masterpagefile="~/BMW.master" %>

<asp:content runat="server"
             id="main_content_"
             contentplaceholderid="MainContent">
<p style="text-align:right">
  <asp:hyperlink runat="server"
                 navigateurl="~/"
                 text="Return" />
</p>

<h2 style="FONT-SIZE:2em">
  Performance Metrics for Test
  <%= this.test_ %>
  at
  <%= this.timestamp_ %>
</h2>

<table>
<tr>
  <td style="text-align:right;font-weight:bold">Collection Time:</td>
  <td>
    <asp:dropdownlist runat="server" id="collection_times_" 
      datatextfield="collection_time" datavaluefield="collection_time" />
    <asp:button runat="server" id="view_time_button_" text="View..."  
      oncommand="handle_view_clicked" commandname="time" />
  </td>
</tr>
<tr>
  <td style="text-align:right;font-weight:bold">Critical Path:</td>
  <td>
    <asp:dropdownlist runat="server" id="critical_paths_" datatextfield="path_name"
      datavaluefield="path_id" />
    <asp:button runat="server" text="View..." oncommand="handle_view_clicked"
      id="view_path_button_" commandname="path" />
  </td>
</tr>
</table>
<br />
<asp:placeholder runat="server" id="placeholder_" />
<asp:label runat="server" id="label_" />
</asp:content>