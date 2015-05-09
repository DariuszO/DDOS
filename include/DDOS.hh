#ifndef DDOS_H
#define DDOS_H

#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <vector>
#include <csignal>
#include <sys/socket.h>
#include <regex>

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
