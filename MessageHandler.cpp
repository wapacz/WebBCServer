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
    this->MESSAGES = new Message*[NO_OF_MESSAGES];
    this->MESSAGES[LOGIN] = new LoginMessage();
    this->MESSAGES[LOGOUT] = new LoginMessage();
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
    if(data[0] < NO_OF_MESSAGES) {
        this->MESSAGES[data[0]]->analyze(data);
    }
}

void MessageHandler::SendData(char* data) {
    //ConnectionManager::GetInstance().Send()
}