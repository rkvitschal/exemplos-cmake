# Define a versão mínima necessária do CMake
cmake_minimum_required(VERSION 3.20)

# Define o nome do projeto a ser compilado com CMake
project(rk_projeto_exemplo_curl)

# Configura para os arquivos executáveis ficarem em uma pasta /bin da pasta de trabalho no CMake
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Adiciona os arquivos CPP do projeto
add_executable(rk_projeto_exemplo_curl src/main.cpp  src/class1.cpp src/class2.cpp src/etc.cpp )


# Caso queria definir por exemplo no Windows o caminho fico ao Curl
# Ajustar C:/caminhodo/curl/ conforme necessário
if (WIN32)

    # Informa caminho manual do diretório de include
    set(CURL_INCLUDE_DIR "C:/caminhodo/curl/include/")

    # Informa o caminho da lib do Curl
    set(CURL_LIBRARY "C:/caminhodo/curl/lib/libcurl_imp.lib")
endif (WIN32)

# Informa ao CMake para localizar o Curl
find_package(CURL)
# Verifica diretorios do cURL.
if(CURL_FOUND)
    # Se encontrar o Curl, informa o sucesso via mensagem.
    message("CURL Found")

    # Inclui o diretório do Include do Curl ao projeto
    include_directories(${CURL_INCLUDE_DIRS})

    # Vincula a LIB do Curl ao projeto
    target_link_libraries(rk_projeto_exemplo_curl ${CURL_LIBRARIES})

# Se não encontrar o Curl faz a ação abaixo
elseif(NOT CURL_FOUND)
    # Gera uma mensagem critica e aborta o processo
    message( FATAL_ERROR "CURL Not Found")

# Fim do IF de verificação do Curl
endif()
