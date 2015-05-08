#ifndef DDOS_H
#define DDOS_H

#include <iostream>
#include <thread>
#include <vector>
#include <csignal>

using namespace std;

class DDOS {
  private:
    string target;
    unsigned long int frequency;
    bool isHost(string target);

  public:
    DDOS();
    void attack();
    void stop(vector<thread> threads);
    ~DDOS();
};

#endif
