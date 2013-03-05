/* 
 * File:   main.cpp
 * Author: Michał Łapacz
 *
 * Created on February 26, 2013, 9:54 PM
 */

using namespace std;

#include "ServerManager.h"
#include "EventDispacher.h"
#include "MessageHandler.h"

int main(void)
{
    ServerManager::GetInstance().StartServer();

    return 0;
}