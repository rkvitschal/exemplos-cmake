# Define a versão mínima necessária do CMake
cmake_minimum_required(VERSION 3.20)

# Define o nome do projeto a ser compilado com CMake
project(rk_recursivo)

# (Opcional) Configura para os arquivos executáveis ficarem em uma pasta /bin da pasta de trabalho no CMake
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Verifica recursivamente todos os arquivos .cpp a partir do diretório /src na pasta do projeto
# Caso precise, pode ser informado arquivos .c da mesma fora, só alterando de .cpp para .c
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Adiciona os arquivos recursivos informados acima, e também o arquivo main.cpp que está em uma pasta separada.
# O arquivo main.cpp poderia ser carregado de forma recursiva também, caso necessário.
add_executable(rk_recursivo ${SOURCES} main.cpp)

