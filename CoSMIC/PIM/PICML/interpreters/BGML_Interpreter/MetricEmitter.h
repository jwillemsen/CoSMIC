#ifndef METRIC_EMITTER_H
#define METRIC_EMITTER_H

#include "PICML.h"

#include <string>
#include <vector>

template <class T>
class MetricEmitter 
{
public:
	MetricEmitter (PICML::OperationBase &base, 
				   T& latency,
			       std::string& output_path,
			       std::vector<__int64>& task_priorities,
				   std::vector<__int64>& task_rates,
				   std::string& metric);
	~MetricEmitter ();
	
	void generate_benchmark ();

	std::string component_name (PICML::TwowayOperation& op);

	void return_type_signature (PICML::MemberType& mem_type,
								std::string& operation_name,
								int type);

	std::string operation_signature (PICML::TwowayOperation& op);

protected:
	void generate_header_file (std::string& class_name,
							   std::string& component_name,
							   std::string& operation_name,
							   std::vector<string>& arg_list);
	// Generate the header file information
	
private:
	PICML::OperationBase &operation_;
	T& latency_;
	std::string& output_path_;
	std::vector<__int64>& task_priorities_;
	std::vector<__int64>& task_rates_;
	std::string& metric_;
		
};

#include "MetricEmitter.cpp"

#endif /* LATENCY_EMITTER_H */