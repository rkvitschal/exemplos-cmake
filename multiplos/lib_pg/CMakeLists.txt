# Criar a biblioteca util (pode ser estática ou dinâmica, ajuste conforme necessário)
add_library(lib_pg SHARED lib_pg.cpp)
#add_library(lib_pg STATIC lib_pg.cpp)

# Definir o diretório de includes para a biblioteca util
target_include_directories(lib_pg PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include> 
)

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
    target_link_libraries(lib_pg ${PostgreSQL_LIBRARIES})

    #Adiciona os includes de header do PostgreSQL ao projeto
    target_include_directories(lib_pg PUBLIC ${PostgreSQL_INCLUDE_DIRS})

# Se não achar o PostgreSQL joga a mensgem de  erro fatal
else()
    message(FATAL_ERROR "PostgreSQL não encontrado. Certifique-se de que esteja instalado e que o CMake possa encontrá-lo.")
endif()
# Por fim encerra o loop if