/*
    LISTING NETWORK ADAPTERS ON LINUX AND MACOS -- Livro: Hands-On Network Programing with C p.75

*/

#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdlib.h>

int main()
{

    struct ifaddrs *addresses;

    if (getifaddrs(&addresses) == -1)
    {
        printf("getifaddrs call failed\n");
        return -1;
    }
    struct ifaddrs *address = addresses;
    while (address)
    {
        int family = address->ifa_addr->sa_family;
        if (family == AF_INET || family == AF_INET6 || family == AF_CAN)
        {
            printf("%s\t", address->ifa_name);
            printf("%s\t", family == AF_INET ? "IPV4" : "IPV6");

            char ap[100];
            const int family_size = family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
            getnameinfo(address->ifa_addr, family_size, ap, sizeof(ap), 0, 0, 1);
            printf("\t%s\n", ap);
        }
        address = address->ifa_next;
        // ipv4 ou ipv6
    }

    freeifaddrs(addresses);
    return 0;
}