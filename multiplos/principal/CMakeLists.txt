# Criar o executável principal
add_executable(principal main.cpp)

# Definir o diretório de includes para o projeto principal
target_include_directories(principal PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Linkar com as bibliotecas locais criadas no projeto
target_link_libraries(principal lib_curl lib_pg) 