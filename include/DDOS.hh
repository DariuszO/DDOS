#ifndef DDOS_H
#define DDOS_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <csignal>
#include <regex>
#include <thread>
#include <getopt.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

typedef unsigned short int MIN_SUPER_INT;
typedef unsigned long int MAX_SUPER_INT;

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

using namespace std;

class DDOS {
  private:
    char *target;
    bool protocol;
    MIN_SUPER_INT port;
    MAX_SUPER_INT frequency;
    vector<thread> threads;

    bool isIPv4();
    static void* goSocket(void *);

    bool getProtocol();
    MIN_SUPER_INT getPort();
    MAX_SUPER_INT getFrequency();


  public:
    DDOS(char *target, MAX_SUPER_INT frequency, MIN_SUPER_INT port, bool protocol);
    ~DDOS();

    void attack();
};

#endif
