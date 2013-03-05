/* 
 * File:   Message.h
 * Author: catchers
 *
 * Created on March 5, 2013, 12:31 AM
 */

#ifndef MESSAGE_H
#define	MESSAGE_H

class Message {
public:
    Message();
    Message(const Message& orig);
    virtual ~Message();
    virtual void analyze(char* data) = 0;
private:

};

#endif	/* MESSAGE_H */

