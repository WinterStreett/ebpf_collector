#include<string>
std::string generate_prometheus_metric(const std::string& metric_name, 
                                       const std::string& label_name, 
                                       const std::string& label_value, 
                                       double value);