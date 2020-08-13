#include <iostream>
#include "restclient-cpp/restclient.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    RestClient::Response r = RestClient::get("http://www.google.com");
    cout << r.body;


    return 0;

}
