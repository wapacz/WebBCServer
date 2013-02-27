/* 
 * File:   ServerManager.cpp
 * Author: catchers
 * 
 * Created on February 26, 2013, 10:00 PM
 */

#include "ServerManager.h"
#include "EventDispacher.h"

ServerManager::ServerManager() {
    this->eventDispacher = NULL;
    
    
}

ServerManager::ServerManager(const ServerManager& orig) {
}

ServerManager::~ServerManager() {
    
}

void ServerManager::AddEventDispacher(EventDispacher* eventDispacher) {
    this->eventDispacher = eventDispacher;
}

void ServerManager::StartServer() {
    this->GetConnectionManager().StartListening();
}

ConnectionManager& ServerManager::GetConnectionManager() {
    return ConnectionManager::GetInstance();
}


        //if(this->eventDispacher != NULL)
          //  this->eventDispacher->Notify(numbytes, buf);