#include <stdio.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <arpa/inet.h>


int main (int argc, char **argv) {
    int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
    printf("\nsocket fd: %d", udp_socket);

    char msg[] = "hello there";

    struct in_addr addr;
    inet_aton("192.168.1.1", &addr);
    //set dest address
    const struct sockaddr_in udpDestAddr = {
        .sin_family = AF_INET,
        .sin_port = 53,
        .sin_addr = addr
    };

    printf("\nsending udp message");
    ssize_t result = sendto(udp_socket, msg, sizeof(msg), 0, (struct sockaddr *)&udpDestAddr, sizeof(udpDestAddr));
    printf("\nresult: %ld", result);
    return 0;
}
