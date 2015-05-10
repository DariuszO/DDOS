#ifndef DDOS_H
#define DDOS_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <csignal>
#include <regex>

#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

using namespace std;

class DDOS {
  private:
    char *target;
    bool protocol;
    unsigned short int port;
    unsigned long int frequency;

    bool isIPv4();
    void goSocket();

  public:
    DDOS(char *target, unsigned long int frequency, unsigned short int port, bool protocol);
    ~DDOS();

    void attack();
    // void stop(vector<thread> threads);
};

#endif
