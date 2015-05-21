#ifndef COMMANDS_H
#define COMMANDS_H

#include "DDOS.hh"

#define HELP puts("<help>");
#define DEFAULT puts("<default>");

#define CHANGE_PORT puts("\033[33m[!]\033[m The value of port is invalid, we assign it 80.");
#define CHANGE_FREQUENCY puts("\033[33m[!]\033[m The value of frequency is invalid, we assign it 10.");
#define CHANGE_TIME puts("\033[33m[!]\033[m The value of time (in seconds) is invalid, we assign it 30.");

template<typename P, typename F, typename T>
static void subChecking(P *port, F *frequency, T *timeDDOS);

#endif
