#include <iostream>

#include "src/class1.hpp"
#include "src/class2.hpp"
#include "src/etc.hpp"

int main (){
    Class1 * c1 = new Class1();
    Class2 * c2 = new Class2();
    Etc * etc = new Etc();

    std::cout << "Olá, eu sou o main do programa." << std::endl;
    c1->hello();
    c2->hello();
    etc->hello();

    delete c1;
    delete c2;
    delete etc;

    return 0;

}