//
// Created by thisisyj on 19/10/20.
//
#include "Socket_Servidor.h"
#include "Socket.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main() {
    int Server;
    int Client;
    int Aux;
    int Size;
    char Sentence[7];
    Server = Socket_Inet("cpp_java");
    if (Server == -1) {
        printf("No se puede abrir socket servidor\n");
        exit(-1);
    }
    Client = Client_Connection(Server);
    if (Client == -1) {
        printf("No se puede abrir socket de cliente\n");
        exit(-1);
    }
    Size = 5;
    strcpy(Sentence, "Hola");
    Aux = htonl(Size);
    Socket_Writer(Client, (char *) &Aux, sizeof(Size));
    printf("Enviado: %d\n", Size);
    Socket_Writer(Client, Sentence, Size);
    printf("Enviado: %s\n", Sentence);
    Socket_Reader(Client, (char *) &Aux, sizeof(Size));
    Size = ntohl(Aux);
    printf("Recibido: %d\n", Size);
    Socket_Reader(Client, Sentence, Size);
    printf("Recibido: %s\n", Sentence);
    close(Client);
    close(Server);
}