#pragma once

#using <mscorlib.dll>
#using <System.dll>
#using <System.Xml.dll>
#using <System.Web.Services.dll>
#using <System.EnterpriseServices.dll>

using namespace System::Security::Permissions;
[assembly:SecurityPermissionAttribute(SecurityAction::RequestMinimum, SkipVerification=false)];
//
// This source code was auto-generated by wsdl, Version=2.0.50727.42.
//
namespace SLICE {
    using namespace System::Xml::Serialization;
    using namespace System::Web::Services;
    using namespace System::ComponentModel;
    using namespace System::Web::Services::Protocols;
    using namespace System;
    using namespace System::Diagnostics;

    using namespace System;
    interface class ICUTSBenchmark_Data_Collector_SE_online_measurements;
    interface class ICUTSBenchmark_Data_Collector_SE_controls;
    ref class CUTSEvent_Time_Info;
    ref class CUTSTime_Info;
    ref class CUTSPath_Element;


    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.42"),
    System::Web::Services::WebServiceBindingAttribute(Name=L"CUTS.Benchmark_Data_Collector._SE_online_measurements", Namespace=L"urn:SLICE"),
    System::Xml::Serialization::SoapIncludeAttribute(SLICE::CUTSPath_Element::typeid)]
    public interface class ICUTSBenchmark_Data_Collector_SE_online_measurements {

        /// <remarks/>
        [System::Web::Services::WebMethodAttribute]
        [System::Web::Services::Protocols::SoapRpcMethodAttribute(L"CUTS.Path_Measurement#execution_time", RequestNamespace=L"urn:SLICE",
            ResponseNamespace=L"urn:SLICE")]
        [returnvalue: System::Xml::Serialization::SoapElementAttribute(L"_return")]
        SLICE::CUTSEvent_Time_Info^  execution_time(System::Int32 path_id) abstract;

        /// <remarks/>
        [System::Web::Services::WebMethodAttribute]
        [System::Web::Services::Protocols::SoapRpcMethodAttribute(L"CUTS.Path_Measurement#unbind_to_path", RequestNamespace=L"urn:SLICE",
            ResponseNamespace=L"urn:SLICE")]
        System::Void unbind_to_path(System::Int32 path_id) abstract;

        /// <remarks/>
        [System::Web::Services::WebMethodAttribute]
        [System::Web::Services::Protocols::SoapRpcMethodAttribute(L"CUTS.Path_Measurement#bind_to_path", RequestNamespace=L"urn:SLICE",
            ResponseNamespace=L"urn:SLICE")]
        [returnvalue: System::Xml::Serialization::SoapElementAttribute(L"_return")]
        System::Int32 bind_to_path(cli::array< SLICE::CUTSPath_Element^  >^  path, System::UInt16 flags) abstract;
    };

    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.42"),
    System::Web::Services::WebServiceBindingAttribute(Name=L"CUTS.Benchmark_Data_Collector._SE_controls", Namespace=L"urn:SLICE"),
    System::Xml::Serialization::SoapIncludeAttribute(SLICE::CUTSPath_Element::typeid)]
    public interface class ICUTSBenchmark_Data_Collector_SE_controls {

        /// <remarks/>
        [System::Web::Services::WebMethodAttribute]
        [System::Web::Services::Protocols::SoapRpcMethodAttribute(L"CUTS.BDC_Control_Handle#collect_performance_data", RequestNamespace=L"urn:SLICE",
            ResponseNamespace=L"urn:SLICE")]
        System::Void collect_performance_data() abstract;
    };

    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.42"),
    System::SerializableAttribute,
    System::Diagnostics::DebuggerStepThroughAttribute,
    System::ComponentModel::DesignerCategoryAttribute(L"code"),
    System::Xml::Serialization::SoapTypeAttribute(TypeName=L"CUTS.Event_Time_Info", Namespace=L"urn:SLICE")]
    public ref class CUTSEvent_Time_Info {

        private: SLICE::CUTSTime_Info^  timeField;

        private: System::Int32 max_eventsField;

        private: System::Int32 min_eventsField;

        /// <remarks/>
        public:  property SLICE::CUTSTime_Info^  time {
            SLICE::CUTSTime_Info^  get();
            System::Void set(SLICE::CUTSTime_Info^  value);
        }

        /// <remarks/>
        public:  property System::Int32 max_events {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }

        /// <remarks/>
        public:  property System::Int32 min_events {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
    };

    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.42"),
    System::SerializableAttribute,
    System::Diagnostics::DebuggerStepThroughAttribute,
    System::ComponentModel::DesignerCategoryAttribute(L"code"),
    System::Xml::Serialization::SoapTypeAttribute(TypeName=L"CUTS.Time_Info", Namespace=L"urn:SLICE")]
    public ref class CUTSTime_Info {

        private: System::Int32 totalField;

        private: System::Int32 maxField;

        private: System::Int32 minField;

        /// <remarks/>
        public:  property System::Int32 total {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }

        /// <remarks/>
        public:  property System::Int32 max {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }

        /// <remarks/>
        public:  property System::Int32 min {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
    };

    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.42"),
    System::SerializableAttribute,
    System::Diagnostics::DebuggerStepThroughAttribute,
    System::ComponentModel::DesignerCategoryAttribute(L"code"),
    System::Xml::Serialization::SoapTypeAttribute(TypeName=L"CUTS.Path_Element", Namespace=L"urn:SLICE")]
    public ref class CUTSPath_Element {

        private: System::String^  nodeField;

        private: System::String^  srcField;

        private: System::String^  dstField;

        /// <remarks/>
        public: [System::Xml::Serialization::SoapElementAttribute(IsNullable=true)]
         property System::String^  node {
            System::String^  get();
            System::Void set(System::String^  value);
        }

        /// <remarks/>
        public: [System::Xml::Serialization::SoapElementAttribute(IsNullable=true)]
         property System::String^  src {
            System::String^  get();
            System::Void set(System::String^  value);
        }

        /// <remarks/>
        public: [System::Xml::Serialization::SoapElementAttribute(IsNullable=true)]
         property System::String^  dst {
            System::String^  get();
            System::Void set(System::String^  value);
        }
    };
}
namespace SLICE {

    inline SLICE::CUTSTime_Info^  CUTSEvent_Time_Info::time::get() {
        return this->timeField;
    }
    inline System::Void CUTSEvent_Time_Info::time::set(SLICE::CUTSTime_Info^  value) {
        this->timeField = value;
    }

    inline System::Int32 CUTSEvent_Time_Info::max_events::get() {
        return this->max_eventsField;
    }
    inline System::Void CUTSEvent_Time_Info::max_events::set(System::Int32 value) {
        this->max_eventsField = value;
    }

    inline System::Int32 CUTSEvent_Time_Info::min_events::get() {
        return this->min_eventsField;
    }
    inline System::Void CUTSEvent_Time_Info::min_events::set(System::Int32 value) {
        this->min_eventsField = value;
    }


    inline System::Int32 CUTSTime_Info::total::get() {
        return this->totalField;
    }
    inline System::Void CUTSTime_Info::total::set(System::Int32 value) {
        this->totalField = value;
    }

    inline System::Int32 CUTSTime_Info::max::get() {
        return this->maxField;
    }
    inline System::Void CUTSTime_Info::max::set(System::Int32 value) {
        this->maxField = value;
    }

    inline System::Int32 CUTSTime_Info::min::get() {
        return this->minField;
    }
    inline System::Void CUTSTime_Info::min::set(System::Int32 value) {
        this->minField = value;
    }


    inline System::String^  CUTSPath_Element::node::get() {
        return this->nodeField;
    }
    inline System::Void CUTSPath_Element::node::set(System::String^  value) {
        this->nodeField = value;
    }

    inline System::String^  CUTSPath_Element::src::get() {
        return this->srcField;
    }
    inline System::Void CUTSPath_Element::src::set(System::String^  value) {
        this->srcField = value;
    }

    inline System::String^  CUTSPath_Element::dst::get() {
        return this->dstField;
    }
    inline System::Void CUTSPath_Element::dst::set(System::String^  value) {
        this->dstField = value;
    }
}
