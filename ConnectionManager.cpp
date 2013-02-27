/* 
 * File:   ConnectionManager.cpp
 * Author: catchers
 * 
 * Created on February 27, 2013, 8:46 PM
 */

#include "ConnectionManager.h"

ConnectionManager::ConnectionManager() {
        
    struct addrinfo *servinfo, *p;
    int rv;
    
    memset(&(this->hints), 0, sizeof(this->hints));
    this->hints.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
    this->hints.ai_socktype = SOCK_DGRAM;
    this->hints.ai_flags = AI_PASSIVE; // use my IP
    
    if (rv = getaddrinfo(NULL, MYPORT, &(this->hints), &servinfo) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return;// 1;
    }
    
    // loop through all the results and bind to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((this->sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("listener: socket");
            continue;
        }

        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("listener: bind");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "listener: failed to bind socket\n");
        return;// 2;
    }

    freeaddrinfo(servinfo); 
}

ConnectionManager::ConnectionManager(const ConnectionManager& orig) {
}

ConnectionManager::~ConnectionManager() {
    close(this->sockfd);
}

ConnectionManager& ConnectionManager::GetInstance() {
    static ConnectionManager instance;
    return instance;
}

// get sockaddr, IPv4 or IPv6:
void* ConnectionManager::get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

void ConnectionManager::StartListening() {
        
    socklen_t addrLen;
    int numbytes;
    struct sockaddr_storage srcAddr;
    char s[INET6_ADDRSTRLEN];
    char buf[MAXBUFLEN];
    
    while(1)
    {
        printf("listener: waiting to recvfrom...\n");

        addrLen = sizeof(srcAddr);
        if ((numbytes = recvfrom(this->sockfd, buf, MAXBUFLEN-1 , 0,
            (struct sockaddr *)&srcAddr, &addrLen)) == -1) {
            perror("recvfrom");
            exit(1);
        }

        printf("listener: got packet from %s\n",
            inet_ntop(srcAddr.ss_family, this->get_in_addr((struct sockaddr *)&srcAddr), s, sizeof s));
        printf("listener: packet is %d bytes long\n", numbytes);
        buf[numbytes] = '\0';
        printf("listener: packet contains \"%s\"\n", buf);
    }    
}