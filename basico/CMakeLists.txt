# Define a versão mínima necessária do CMake
cmake_minimum_required(VERSION 3.20)

# Define o nome do projeto a ser compilado com CMake
project(rk_projeto_exemplo_basico)

# (Opcional) Configura para os arquivos executáveis ficarem em uma pasta /bin da pasta de trabalho no CMake
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Adiciona os arquivos CPP do projeto
add_executable(rk_projeto_exemplo_basico src/main.cpp  src/class1.cpp src/class2.cpp src/etc.cpp )
