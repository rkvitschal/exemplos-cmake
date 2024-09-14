cmake_minimum_required(VERSION 3.10)
project(RK_Multiplo)

# (Opcional) Configura para os arquivos executáveis ficarem em uma pasta /bin da pasta de trabalho no CMake
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Compila e salva as libis direto no diretório /bin junto com o executável do programa
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Adicionar os subprojetos
add_subdirectory(principal)
add_subdirectory(lib_pg)
add_subdirectory(lib_curl)

