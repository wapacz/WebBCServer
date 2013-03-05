/* 
 * File:   MessageHandler.cpp
 * Author: catchers
 * 
 * Created on March 5, 2013, 12:31 AM
 */

#include "MessageHandler.h"
#include "ConnectionManager.h"
#include "Message.h"

MessageHandler::MessageHandler() {
}

MessageHandler::MessageHandler(const MessageHandler& orig) {
}

MessageHandler::~MessageHandler() {
}

MessageHandler& MessageHandler::GetInstance() {
    static MessageHandler instance;
    return instance;
}

void MessageHandler::DataReceived(char* data) {
    
}

void MessageHandler::SendData(char* data) {
    //ConnectionManager::GetInstance().Send()
}