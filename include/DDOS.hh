#ifndef DDOS_H
#define DDOS_H

#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <vector>
#include <csignal>

using namespace std;

class DDOS {
  private:
    string target;
    unsigned long int frequency;

    bool isIP();
    bool ping();

  public:
    DDOS(string target, unsigned long int frequency);
    ~DDOS();

    void attack();
    // void stop(vector<thread> threads);
};

#endif
