# Criar a biblioteca util (pode ser estática ou dinâmica, ajuste conforme necessário)
add_library(lib_curl SHARED  lib_curl.cpp)
#add_library(lib_curl STATIC  lib_curl.cpp)

# Definir o diretório de includes para a biblioteca util
target_include_directories(lib_curl PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include> 
)


find_package(CURL)
# Verifica diretorios do cURL.
if(CURL_FOUND)
    # Se encontrar o Curl, informa o sucesso via mensagem.
    message(STATUS "CURL Found")

    # Inclui o diretório do Include do Curl ao projeto
    include_directories(${CURL_INCLUDE_DIRS})

    # Vincula a LIB do Curl ao projeto
    target_link_libraries(lib_curl ${CURL_LIBRARIES})

# Se não encontrar o Curl faz a ação abaixo
elseif(NOT CURL_FOUND)
    # Gera uma mensagem critica e aborta o processo
    message( FATAL_ERROR "CURL Not Found")

# Fim do IF de verificação do Curl
endif()
