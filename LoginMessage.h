/* 
 * File:   LoginMessage.h
 * Author: catchers
 *
 * Created on March 5, 2013, 12:32 AM
 */

#ifndef LOGINMESSAGE_H
#define	LOGINMESSAGE_H

#include "Message.h"

class LoginMessage : public Message {
public:
    LoginMessage();
    LoginMessage(const LoginMessage& orig);
    virtual ~LoginMessage();
    void analyze(char* data);
private:

};

#endif	/* LOGINMESSAGE_H */

