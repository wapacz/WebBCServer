/* 
 * File:   EventDispacher.cpp
 * Author: catchers
 * 
 * Created on February 27, 2013, 12:27 AM
 */

#include "EventDispacher.h"
#include <stdio.h>

EventDispacher::EventDispacher() {
}

EventDispacher::EventDispacher(const EventDispacher& orig) {
}

EventDispacher::~EventDispacher() {
}

void EventDispacher::Notify(int length, char* data) {
    
    printf("EventDispacher: packet contains \"%s\"\n", data);
}