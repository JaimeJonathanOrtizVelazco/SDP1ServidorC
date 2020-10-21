//
// Created by thisisyj on 19/10/20.
//
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
int Client_Connection(int Descriptor) {
    socklen_t Longitud_Cliente;
    struct sockaddr Cliente;
    int Hijo;
    Longitud_Cliente = sizeof(Cliente);
    Hijo = accept(Descriptor, &Cliente, &Longitud_Cliente);
    if (Hijo == -1)
        return -1;
    return Hijo;
}
int Socket_Inet(char *Service) {
    struct sockaddr_in address;
    struct servent *port;
    int Descriptor;
    Descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (Descriptor == -1)
        return -1;
    port = getservbyname(Service, "tcp");
    if (port == NULL)
        return -1;
    address.sin_family = AF_INET;
    address.sin_port = port->s_port;
    address.sin_addr.s_addr = INADDR_ANY;
    if (bind(
            Descriptor,
            (struct sockaddr *) &address,
            sizeof(address)) == -1) {
        close(Descriptor);
        return -1;
    }
    if (listen(Descriptor, 1) == -1) {
        close(Descriptor);
        return -1;
    }
    return Descriptor;
}