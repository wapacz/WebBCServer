/* 
 * File:   main.cpp
 * Author: Michał Łapacz
 *
 * Created on February 26, 2013, 9:54 PM
 */

using namespace std;

#include "ServerManager.h"
#include "EventDispacher.h"

int main(void)
{
    ServerManager server;
    EventDispacher eventDisp;
    server.AddEventDispacher(&eventDisp);
    
    server.StartServer();

    return 0;
}