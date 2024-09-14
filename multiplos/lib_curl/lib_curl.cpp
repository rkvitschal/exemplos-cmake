#include "include/lib_curl.hpp"


void lib_curl::hello(){
    std::cout << curl_version() << std::endl;
}