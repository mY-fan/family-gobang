#ifndef SERVICE_H
#define SERVICE_H

#include "house.h"
#include <map>

#include  <unistd.h>
#include  <sys/types.h>       /* basic system data types */
#include  <sys/socket.h>      /* basic socket definitions */
#include  <netinet/in.h>      /* sockaddr_in{} and other Internet defns */
#include  <arpa/inet.h>       /* inet(3) functions */
#include <sys/select.h>       /* select function*/

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 10240
class Service
{
public:
    Service();

private:
    vector<House> houses;
    map<QString,int> users;
};

#endif // SERVICE_H
