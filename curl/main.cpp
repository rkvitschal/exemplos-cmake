/*
    Exemplo simples de programa em C++ que apenas mostra a versão do Curl
    para validar que o Cmake está adicionando as dependendcias corretamente.
*/

#include <iostream>

#include <curl/curl.h>

int main (){
    std::cout << curl_version();

    return 0;
}

