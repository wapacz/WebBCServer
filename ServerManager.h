/* 
 * File:   ServerManager.h
 * Author: catchers
 *
 * Created on February 26, 2013, 10:00 PM
 */

#ifndef SERVERMANAGER_H
#define	SERVERMANAGER_H

#include <stdio.h>
#include "EventDispacher.h"
#include "ConnectionManager.h"

class ServerManager {
    EventDispacher* eventDispacher;
public:
    ServerManager();
    ServerManager(const ServerManager& orig);
    virtual ~ServerManager();
    void AddEventDispacher(EventDispacher* eventDispacher);
    void StartServer();
    ConnectionManager& GetConnectionManager();
};

#endif	/* CONNECTIONMANAGER_H */

