# Define a versão mínima necessária do CMake
cmake_minimum_required(VERSION 3.20)

# Define o nome do projeto a ser compilado com CMake
project(rk_lib)

# (Opcional) Configura para os arquivos das libs compartilhadas ficarem em uma pasta /libs da pasta de trabalho no CMake
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)

# (Opcional) Configura para os arquivos das libs estaticas ficarem em uma pasta /libs da pasta de trabalho no CMake
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)


# Criar a biblioteca estática
add_library(rk_lib_static STATIC lib.cpp)

# Criar a biblioteca dinâmica (compartilhada)
add_library(rk_lib_shared SHARED lib.cpp)


# (Opcional) Definir nomes diferentes para os arquivos de saída
set_target_properties(rk_lib_static PROPERTIES OUTPUT_NAME "rklib_s")
set_target_properties(rk_lib_shared PROPERTIES OUTPUT_NAME "rklib")