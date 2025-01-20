#include "../include/httplib.h"
#include<string>
#include"../include/tools.h"

int main() {
    httplib::Server svr;

    svr.Get("/metrics", [](const httplib::Request&, httplib::Response& res) {
        res.set_content(generate_prometheus_metric("test_metrics","label","1",100), "text/plain");
    });

    svr.listen("0.0.0.0", 9500);
    return 0;
}