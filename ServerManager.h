/* 
 * File:   ServerManager.h
 * Author: Michał Łapacz
 *
 * Created on February 26, 2013, 10:00 PM
 */

#ifndef SERVERMANAGER_H
#define	SERVERMANAGER_H

#include <stdio.h>
#include "EventDispacher.h"
#include "ConnectionManager.h"

class ServerManager {
    ServerManager();
    ServerManager(const ServerManager& orig);
    ServerManager& operator=(const ServerManager&);
public:
    virtual ~ServerManager();
    void AddEventDispacher(EventDispacher* eventDispacher);
    void StartServer();
    ConnectionManager& GetConnectionManager();
    static ServerManager& GetInstance();
    

};

#endif	/* CONNECTIONMANAGER_H */

