#include "include/lib_pg.hpp"

void lib_pg::hello(){
    std::cout << PQlibVersion() << std::endl;
    return;
}