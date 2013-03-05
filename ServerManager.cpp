/* 
 * File:   ServerManager.cpp
 * Author: Michał Łapacz
 * 
 * Created on February 26, 2013, 10:00 PM
 */

#include "ServerManager.h"
#include "EventDispacher.h"

ServerManager::ServerManager() {
}

ServerManager::ServerManager(const ServerManager& orig) {
}

ServerManager::~ServerManager() {
}

void ServerManager::StartServer() {
    this->GetConnectionManager().StartListening("4950", ConnectionManager::UDP);
}

ConnectionManager& ServerManager::GetConnectionManager() {
    return ConnectionManager::GetInstance();
}

ServerManager& ServerManager::GetInstance() {
    static ServerManager instance;
    return instance;
}

        //if(this->eventDispacher != NULL)
          //  this->eventDispacher->Notify(numbytes, buf);