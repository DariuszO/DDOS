#ifndef DDOS_H
#define DDOS_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <regex>
#include <csignal>

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

using namespace std;

class DDOS {
  private:
    string target;
    bool protocol;
    unsigned short int port;
    unsigned long int frequency;

    bool isIPv4();
    bool ping();

    void goSocket();

  public:
    DDOS(string target, unsigned long int frequency, unsigned short int port, bool protocol);
    ~DDOS();

    void attack();
    // void stop(vector<thread> threads);
};

#endif
