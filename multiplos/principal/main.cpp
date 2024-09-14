#include <iostream>
#include "../lib_curl/include/lib_curl.hpp"
#include "../lib_pg/include/lib_pg.hpp"


int main(){
    std::cout << "Olá" << std::endl;
    lib_curl * curl = new lib_curl();

    curl->hello();

    delete curl;

    lib_pg * pg = new lib_pg();

    pg->hello();

    delete pg;

    return 0;
}