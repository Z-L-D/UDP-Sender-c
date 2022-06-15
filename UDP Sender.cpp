#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib,"Ws2_32.lib")

int main(void)
{
    // Initialize Winsock 
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    const char* command = "Hello from C";
    PCWSTR address = L"127.0.0.1";
    short port = 5500;    

    SOCKET socket_object = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    struct sockaddr_in server_object;
    server_object.sin_family = AF_INET;
    server_object.sin_port = htons(port);
    //server_object.sin_addr.s_addr = inet_addr(address);
    InetPton(AF_INET, address, &server_object.sin_addr.s_addr);

    sendto(socket_object, command, (int)strlen(command), 0, (SOCKADDR*)&server_object, sizeof(server_object));

    closesocket(socket_object);
}