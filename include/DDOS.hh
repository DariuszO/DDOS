#ifndef DDOS_H
#define DDOS_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <csignal>
#include <regex>
#include <thread>
#include <getopt.h>
#include <map>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

typedef unsigned short int MIN_SUPER_INT;
typedef unsigned long int MAX_SUPER_INT;

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

#define BOOTSTRAP_SOCKET puts("\033[31m[!]\033[m Invalid socket.");
#define BOOTSTRAP_CONNECT puts("\033[31m[!]\033[m Unable connect to target.");
#define BOOTSTRAP_IPV4 puts("\033[31m[!]\033[m Please, specify a valid IP.");
#define BOOTSTRAP_THREADS puts("\033[32m[v]\033[m Operation finished, threads has been closed.");

#define DDOS_GO puts("\033[1;36mOngoing Attack...\e[0m");

using namespace std;

class DDOS {
  private:
    string target;
    MIN_SUPER_INT port;
    MAX_SUPER_INT frequency;
    vector<thread> threads;

    bool isIPv4();
    static void* goSocket(void *);

    MIN_SUPER_INT getPort();
    MAX_SUPER_INT getFrequency();


  public:
    DDOS(string target, MAX_SUPER_INT frequency, MIN_SUPER_INT port);
    ~DDOS();

    void attack();
};

#endif
