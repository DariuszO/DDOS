#ifndef COMMANDS_H
#define COMMANDS_H

#include "DDOS.hh"

#define HELP puts("<help>");
#define DEFAULT puts("<default>");

#define CHANGE_PORT puts("\033[33m[!]\033[m The value of port is invalid, we assign it 80.");
#define CHANGE_FREQUENCY puts("\033[33m[!]\033[m The value of frequency is invalid, we assign it 10.");

static bool protocolChecking(string target);

template<typename T, typename O>
static void subChecking(T *port, O *frequency);

#endif
