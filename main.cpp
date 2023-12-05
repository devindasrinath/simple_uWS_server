#include "uWebSockets/App.h"
#include <string>
#include <iostream>
int main() {
    std::string result;
    uWS::App().get("/candy/:val1", [&result](auto *res, auto *req) {

        // Retrieve the values of specific path parameters
        std::string_view val1 = req->getParameter(0);
        //std::string_view val2 = req->getParameter(1);

        //std::cout<<val1<<std::endl;
        //std::cout<<val2<<std::endl;
        // Retrieve the value of the query parameter "flavor"
        auto val = req->getQuery();

        std::cout<<val<<std::endl;
       // val='?'+ std::string(val) ;
       // std::basic_string_view<char> flavor = uWS::getDecodedQueryValue("flavor", val);

        //std::cout<<"You requested candy of kind: " << kind <<" with color: " << color << " and flavor: " << flavor<<std::endl;
        // Send a response with path and query parameters
        res->end(val);
    }).listen(3500, [](auto *token) {
        if (token) {
            std::cout << "Server listening on port 3500" << std::endl;
        } else {
            std::cerr << "Failed to listen on port 3500" << std::endl;
        }
    }).run();
}

