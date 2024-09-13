#include <iostream>

#include <postgresql/libpq-fe.h>

int main(){

        PGconn *conn = PQconnectdb("dbname=meu_banco user=meu_usuario password=minha_senha hostaddr=127.0.0.1 port=5432");

    if (PQstatus(conn) == CONNECTION_BAD) {
        std::cerr << "Erro de conexão: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return 1;
    }

    std::cout << "Conectado ao PostgreSQL!" << std::endl;

    PQfinish(conn);
    return 0;

}