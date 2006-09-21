﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:2.0.50727.42
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// 
// This source code was auto-generated by wsdl, Version=2.0.50727.42.
// 
namespace CUTS {
    using System.Xml.Serialization;
    using System.Web.Services;
    using System.ComponentModel;
    using System.Web.Services.Protocols;
    using System;
    using System.Diagnostics;
    
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("wsdl", "2.0.50727.42")]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Web.Services.WebServiceBindingAttribute(Name="CUTS.Benchmark_Data_Collector._SE_online_measurements", Namespace="urn:SLICE")]
    [System.Xml.Serialization.SoapIncludeAttribute(typeof(CUTSPath_Element))]
    public partial class CUTSBenchmark_Data_Collector_SE_online_measurements : System.Web.Services.Protocols.SoapHttpClientProtocol {
        
        private System.Threading.SendOrPostCallback execution_timeOperationCompleted;
        
        private System.Threading.SendOrPostCallback unbind_to_pathOperationCompleted;
        
        private System.Threading.SendOrPostCallback bind_to_pathOperationCompleted;
        
        /// <remarks/>
        public CUTSBenchmark_Data_Collector_SE_online_measurements() {
            this.Url = "http://localhost/SLICE/SLICE.asmx";
        }
        
        /// <remarks/>
        public event execution_timeCompletedEventHandler execution_timeCompleted;
        
        /// <remarks/>
        public event unbind_to_pathCompletedEventHandler unbind_to_pathCompleted;
        
        /// <remarks/>
        public event bind_to_pathCompletedEventHandler bind_to_pathCompleted;
        
        /// <remarks/>
        [System.Web.Services.Protocols.SoapRpcMethodAttribute("CUTS.Path_Measurement#execution_time", RequestNamespace="urn:SLICE", ResponseNamespace="urn:SLICE")]
        [return: System.Xml.Serialization.SoapElementAttribute("_return")]
        public CUTSEvent_Time_Info execution_time(int path_id) {
            object[] results = this.Invoke("execution_time", new object[] {
                        path_id});
            return ((CUTSEvent_Time_Info)(results[0]));
        }
        
        /// <remarks/>
        public System.IAsyncResult Beginexecution_time(int path_id, System.AsyncCallback callback, object asyncState) {
            return this.BeginInvoke("execution_time", new object[] {
                        path_id}, callback, asyncState);
        }
        
        /// <remarks/>
        public CUTSEvent_Time_Info Endexecution_time(System.IAsyncResult asyncResult) {
            object[] results = this.EndInvoke(asyncResult);
            return ((CUTSEvent_Time_Info)(results[0]));
        }
        
        /// <remarks/>
        public void execution_timeAsync(int path_id) {
            this.execution_timeAsync(path_id, null);
        }
        
        /// <remarks/>
        public void execution_timeAsync(int path_id, object userState) {
            if ((this.execution_timeOperationCompleted == null)) {
                this.execution_timeOperationCompleted = new System.Threading.SendOrPostCallback(this.Onexecution_timeOperationCompleted);
            }
            this.InvokeAsync("execution_time", new object[] {
                        path_id}, this.execution_timeOperationCompleted, userState);
        }
        
        private void Onexecution_timeOperationCompleted(object arg) {
            if ((this.execution_timeCompleted != null)) {
                System.Web.Services.Protocols.InvokeCompletedEventArgs invokeArgs = ((System.Web.Services.Protocols.InvokeCompletedEventArgs)(arg));
                this.execution_timeCompleted(this, new execution_timeCompletedEventArgs(invokeArgs.Results, invokeArgs.Error, invokeArgs.Cancelled, invokeArgs.UserState));
            }
        }
        
        /// <remarks/>
        [System.Web.Services.Protocols.SoapRpcMethodAttribute("CUTS.Path_Measurement#unbind_to_path", RequestNamespace="urn:SLICE", ResponseNamespace="urn:SLICE")]
        public void unbind_to_path(int path_id) {
            this.Invoke("unbind_to_path", new object[] {
                        path_id});
        }
        
        /// <remarks/>
        public System.IAsyncResult Beginunbind_to_path(int path_id, System.AsyncCallback callback, object asyncState) {
            return this.BeginInvoke("unbind_to_path", new object[] {
                        path_id}, callback, asyncState);
        }
        
        /// <remarks/>
        public void Endunbind_to_path(System.IAsyncResult asyncResult) {
            this.EndInvoke(asyncResult);
        }
        
        /// <remarks/>
        public void unbind_to_pathAsync(int path_id) {
            this.unbind_to_pathAsync(path_id, null);
        }
        
        /// <remarks/>
        public void unbind_to_pathAsync(int path_id, object userState) {
            if ((this.unbind_to_pathOperationCompleted == null)) {
                this.unbind_to_pathOperationCompleted = new System.Threading.SendOrPostCallback(this.Onunbind_to_pathOperationCompleted);
            }
            this.InvokeAsync("unbind_to_path", new object[] {
                        path_id}, this.unbind_to_pathOperationCompleted, userState);
        }
        
        private void Onunbind_to_pathOperationCompleted(object arg) {
            if ((this.unbind_to_pathCompleted != null)) {
                System.Web.Services.Protocols.InvokeCompletedEventArgs invokeArgs = ((System.Web.Services.Protocols.InvokeCompletedEventArgs)(arg));
                this.unbind_to_pathCompleted(this, new System.ComponentModel.AsyncCompletedEventArgs(invokeArgs.Error, invokeArgs.Cancelled, invokeArgs.UserState));
            }
        }
        
        /// <remarks/>
        [System.Web.Services.Protocols.SoapRpcMethodAttribute("CUTS.Path_Measurement#bind_to_path", RequestNamespace="urn:SLICE", ResponseNamespace="urn:SLICE")]
        [return: System.Xml.Serialization.SoapElementAttribute("_return")]
        public int bind_to_path(CUTSPath_Element[] path, ushort flags) {
            object[] results = this.Invoke("bind_to_path", new object[] {
                        path,
                        flags});
            return ((int)(results[0]));
        }
        
        /// <remarks/>
        public System.IAsyncResult Beginbind_to_path(CUTSPath_Element[] path, ushort flags, System.AsyncCallback callback, object asyncState) {
            return this.BeginInvoke("bind_to_path", new object[] {
                        path,
                        flags}, callback, asyncState);
        }
        
        /// <remarks/>
        public int Endbind_to_path(System.IAsyncResult asyncResult) {
            object[] results = this.EndInvoke(asyncResult);
            return ((int)(results[0]));
        }
        
        /// <remarks/>
        public void bind_to_pathAsync(CUTSPath_Element[] path, ushort flags) {
            this.bind_to_pathAsync(path, flags, null);
        }
        
        /// <remarks/>
        public void bind_to_pathAsync(CUTSPath_Element[] path, ushort flags, object userState) {
            if ((this.bind_to_pathOperationCompleted == null)) {
                this.bind_to_pathOperationCompleted = new System.Threading.SendOrPostCallback(this.Onbind_to_pathOperationCompleted);
            }
            this.InvokeAsync("bind_to_path", new object[] {
                        path,
                        flags}, this.bind_to_pathOperationCompleted, userState);
        }
        
        private void Onbind_to_pathOperationCompleted(object arg) {
            if ((this.bind_to_pathCompleted != null)) {
                System.Web.Services.Protocols.InvokeCompletedEventArgs invokeArgs = ((System.Web.Services.Protocols.InvokeCompletedEventArgs)(arg));
                this.bind_to_pathCompleted(this, new bind_to_pathCompletedEventArgs(invokeArgs.Results, invokeArgs.Error, invokeArgs.Cancelled, invokeArgs.UserState));
            }
        }
        
        /// <remarks/>
        public new void CancelAsync(object userState) {
            base.CancelAsync(userState);
        }
    }
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("wsdl", "2.0.50727.42")]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Web.Services.WebServiceBindingAttribute(Name="CUTS.Benchmark_Data_Collector._SE_controls", Namespace="urn:SLICE")]
    [System.Xml.Serialization.SoapIncludeAttribute(typeof(CUTSPath_Element))]
    public partial class CUTSBenchmark_Data_Collector_SE_controls : System.Web.Services.Protocols.SoapHttpClientProtocol {
        
        private System.Threading.SendOrPostCallback collect_performance_dataOperationCompleted;
        
        /// <remarks/>
        public CUTSBenchmark_Data_Collector_SE_controls() {
            this.Url = "http://localhost/SLICE/SLICE.asmx";
        }
        
        /// <remarks/>
        public event collect_performance_dataCompletedEventHandler collect_performance_dataCompleted;
        
        /// <remarks/>
        [System.Web.Services.Protocols.SoapRpcMethodAttribute("CUTS.BDC_Control_Handle#collect_performance_data", RequestNamespace="urn:SLICE", ResponseNamespace="urn:SLICE")]
        public void collect_performance_data() {
            this.Invoke("collect_performance_data", new object[0]);
        }
        
        /// <remarks/>
        public System.IAsyncResult Begincollect_performance_data(System.AsyncCallback callback, object asyncState) {
            return this.BeginInvoke("collect_performance_data", new object[0], callback, asyncState);
        }
        
        /// <remarks/>
        public void Endcollect_performance_data(System.IAsyncResult asyncResult) {
            this.EndInvoke(asyncResult);
        }
        
        /// <remarks/>
        public void collect_performance_dataAsync() {
            this.collect_performance_dataAsync(null);
        }
        
        /// <remarks/>
        public void collect_performance_dataAsync(object userState) {
            if ((this.collect_performance_dataOperationCompleted == null)) {
                this.collect_performance_dataOperationCompleted = new System.Threading.SendOrPostCallback(this.Oncollect_performance_dataOperationCompleted);
            }
            this.InvokeAsync("collect_performance_data", new object[0], this.collect_performance_dataOperationCompleted, userState);
        }
        
        private void Oncollect_performance_dataOperationCompleted(object arg) {
            if ((this.collect_performance_dataCompleted != null)) {
                System.Web.Services.Protocols.InvokeCompletedEventArgs invokeArgs = ((System.Web.Services.Protocols.InvokeCompletedEventArgs)(arg));
                this.collect_performance_dataCompleted(this, new System.ComponentModel.AsyncCompletedEventArgs(invokeArgs.Error, invokeArgs.Cancelled, invokeArgs.UserState));
            }
        }
        
        /// <remarks/>
        public new void CancelAsync(object userState) {
            base.CancelAsync(userState);
        }
    }
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("wsdl", "2.0.50727.42")]
    [System.SerializableAttribute()]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.SoapTypeAttribute(TypeName="CUTS.Event_Time_Info", Namespace="urn:SLICE")]
    public partial class CUTSEvent_Time_Info {
        
        private CUTSTime_Info timeField;
        
        private int max_eventsField;
        
        private int min_eventsField;
        
        /// <remarks/>
        public CUTSTime_Info time {
            get {
                return this.timeField;
            }
            set {
                this.timeField = value;
            }
        }
        
        /// <remarks/>
        public int max_events {
            get {
                return this.max_eventsField;
            }
            set {
                this.max_eventsField = value;
            }
        }
        
        /// <remarks/>
        public int min_events {
            get {
                return this.min_eventsField;
            }
            set {
                this.min_eventsField = value;
            }
        }
    }
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("wsdl", "2.0.50727.42")]
    [System.SerializableAttribute()]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.SoapTypeAttribute(TypeName="CUTS.Time_Info", Namespace="urn:SLICE")]
    public partial class CUTSTime_Info {
        
        private int totalField;
        
        private int maxField;
        
        private int minField;
        
        /// <remarks/>
        public int total {
            get {
                return this.totalField;
            }
            set {
                this.totalField = value;
            }
        }
        
        /// <remarks/>
        public int max {
            get {
                return this.maxField;
            }
            set {
                this.maxField = value;
            }
        }
        
        /// <remarks/>
        public int min {
            get {
                return this.minField;
            }
            set {
                this.minField = value;
            }
        }
    }
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("wsdl", "2.0.50727.42")]
    [System.SerializableAttribute()]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.SoapTypeAttribute(TypeName="CUTS.Path_Element", Namespace="urn:SLICE")]
    public partial class CUTSPath_Element {
        
        private string nodeField;
        
        private string srcField;
        
        private string dstField;
        
        /// <remarks/>
        [System.Xml.Serialization.SoapElementAttribute(IsNullable=true)]
        public string node {
            get {
                return this.nodeField;
            }
            set {
                this.nodeField = value;
            }
        }
        
        /// <remarks/>
        [System.Xml.Serialization.SoapElementAttribute(IsNullable=true)]
        public string src {
            get {
                return this.srcField;
            }
            set {
                this.srcField = value;
            }
        }
        
        /// <remarks/>
        [System.Xml.Serialization.SoapElementAttribute(IsNullable=true)]
        public string dst {
            get {
                return this.dstField;
            }
            set {
                this.dstField = value;
            }
        }
    }
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("wsdl", "2.0.50727.42")]
    public delegate void execution_timeCompletedEventHandler(object sender, execution_timeCompletedEventArgs e);
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("wsdl", "2.0.50727.42")]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    public partial class execution_timeCompletedEventArgs : System.ComponentModel.AsyncCompletedEventArgs {
        
        private object[] results;
        
        internal execution_timeCompletedEventArgs(object[] results, System.Exception exception, bool cancelled, object userState) : 
                base(exception, cancelled, userState) {
            this.results = results;
        }
        
        /// <remarks/>
        public CUTSEvent_Time_Info Result {
            get {
                this.RaiseExceptionIfNecessary();
                return ((CUTSEvent_Time_Info)(this.results[0]));
            }
        }
    }
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("wsdl", "2.0.50727.42")]
    public delegate void unbind_to_pathCompletedEventHandler(object sender, System.ComponentModel.AsyncCompletedEventArgs e);
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("wsdl", "2.0.50727.42")]
    public delegate void bind_to_pathCompletedEventHandler(object sender, bind_to_pathCompletedEventArgs e);
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("wsdl", "2.0.50727.42")]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    public partial class bind_to_pathCompletedEventArgs : System.ComponentModel.AsyncCompletedEventArgs {
        
        private object[] results;
        
        internal bind_to_pathCompletedEventArgs(object[] results, System.Exception exception, bool cancelled, object userState) : 
                base(exception, cancelled, userState) {
            this.results = results;
        }
        
        /// <remarks/>
        public int Result {
            get {
                this.RaiseExceptionIfNecessary();
                return ((int)(this.results[0]));
            }
        }
    }
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("wsdl", "2.0.50727.42")]
    public delegate void collect_performance_dataCompletedEventHandler(object sender, System.ComponentModel.AsyncCompletedEventArgs e);
}
