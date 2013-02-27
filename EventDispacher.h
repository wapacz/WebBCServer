/* 
 * File:   EventDispacher.h
 * Author: catchers
 *
 * Created on February 27, 2013, 12:27 AM
 */

#ifndef EVENTDISPACHER_H
#define	EVENTDISPACHER_H

#include "PacketObserver.h"

class EventDispacher {
    enum EVENTS {
        EVENT_1,
        EVENT_2,
        EVENT_3,
        EVENT_4,
        EVENT_5,
        
        NUM_OF_EVENTS
    };
    PacketObserver PacketEvents[NUM_OF_EVENTS];
public:
    EventDispacher();
    EventDispacher(const EventDispacher& orig);
    virtual ~EventDispacher();
    void Notify(int length, char* data);
private:

};

#endif	/* EVENTDISPACHER_H */

