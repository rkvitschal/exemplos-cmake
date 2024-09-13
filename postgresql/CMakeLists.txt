# Define a versão mínima necessária do CMake
cmake_minimum_required(VERSION 3.20)

# Define o nome do projeto a ser compilado com CMake
project(rk_pg)

# (Opicional) Configura para os arquivos executáveis ficarem em uma pasta /bin da pasta de trabalho no CMake
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Adiciona os arquivos CPP do projeto
add_executable(rk_pg main.cpp  )

#Informa que o PostgreSQL é requirido
find_package(PostgreSQL REQUIRED)

#Regrade de validação do PostgreSQL
if(PostgreSQL_FOUND)
    # Imprime mensagens opcionais de que encontrou o PostgreSQL e os caminhos
    message(STATUS "PostgreSQL encontrado:")
    message(STATUS "  include dirs: ${PostgreSQL_INCLUDE_DIRS}")
    message(STATUS "  libraries: ${PostgreSQL_LIBRARIES}")
    message(STATUS "  library dirs: ${PostgreSQL_LIBRARY_DIRS}")

    #Adiciona as libs do PostgreSQL ao projeto
    target_link_libraries(rk_pg ${PostgreSQL_LIBRARIES})

    #Adiciona os includes de header do PostgreSQL ao projeto
    target_include_directories(rk_pg PUBLIC ${PostgreSQL_INCLUDE_DIRS})

# Se não achar o PostgreSQL joga a mensgem de  erro fatal
else()
    message(FATAL_ERROR "PostgreSQL não encontrado. Certifique-se de que esteja instalado e que o CMake possa encontrá-lo.")
endif()
# Por fim encerra o loop if
