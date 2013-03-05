/* 
 * File:   MessageHandler.h
 * Author: catchers
 *
 * Created on March 5, 2013, 12:31 AM
 */

#ifndef MESSAGEHANDLER_H
#define	MESSAGEHANDLER_H

#include "LoginMessage.h"


class MessageHandler {
public:
    virtual ~MessageHandler();
    static MessageHandler& GetInstance();
    void DataReceived(char* data);
    void SendData(char* data);
private:
    enum MESSAGE {
        LOGIN,
        LOGOUT,
        
        NO_OF_MESSAGES
    };
    MessageHandler();
    MessageHandler(const MessageHandler& orig);
    
//    Message** MESSAGES = new Message*[NO_OF_MESSAGES];
};

#endif	/* MESSAGEHANDLER_H */

