/* 
 * File:   ConnectionManager.h
 * Author: catchers
 *
 * Created on February 27, 2013, 8:46 PM
 */

#ifndef CONNECTIONMANAGER_H
#define	CONNECTIONMANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MYPORT "4950"    // the port users will be connecting to
#define MAXBUFLEN 100

class ConnectionManager {
    int sockfd;
    struct addrinfo hints;
    void* get_in_addr(struct sockaddr *sa);
    ConnectionManager();
    ConnectionManager(const ConnectionManager& orig);
    ConnectionManager& operator=(const ConnectionManager&);
public:
    virtual ~ConnectionManager();
    void StartListening();
    static ConnectionManager& GetInstance();
};

#endif	/* CONNECTIONMANAGER_H */

