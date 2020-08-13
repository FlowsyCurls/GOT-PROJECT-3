#include <iostream>
#include "restclient-cpp/restclient.h"
using namespace std;

int main(int argc, char *argv[]) {

    for(int i = 0; i < argc; i++){
        printf("argumento %d, %s\n", i, argv[i]);
    }

    //RestClient::Response r = RestClient::get("http://www.google.com");
    //cout << r.body;


    return 0;

}
