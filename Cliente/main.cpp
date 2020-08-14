#include <iostream>
#include "restclient-cpp/restclient.h"
using namespace std;

int main(int argc, char *argv[]) {

    for(int i = 0; i < argc; i++){
        printf("argumento %d, %s\n", i, argv[i]);
    }

    RestClient::Response r = RestClient::get("http://localhost:8080/user_manager");
    cout << r.body << endl;

    RestClient::Response r1 = RestClient::get("http://localhost:8080/hola");
    cout << r1.body;

    return 0;

}
