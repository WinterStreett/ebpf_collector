// 函数接受指标名、标签、标签值和值作为参数
#include<string>
#include<sstream>
#include"tools.h"
std::string generate_prometheus_metric(const std::string& metric_name, 
                                       const std::string& label_name, 
                                       const std::string& label_value, 
                                       double value) {
    // 使用字符串流构建符合 Prometheus 格式的字符串
    std::stringstream ss;
    ss << metric_name << "{" << label_name << "=\"" << label_value << "\"} " << value;
    return ss.str();
}