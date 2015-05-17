#ifndef COMMANDS_H
#define COMMANDS_H

#include "DDOS.hh"

#define HELP puts("<help>");
#define DEFAULT puts("<default>");

static bool protocol(string target);

template<typename T, typename O>
static void subChecking(T *port, O *frequency);

#endif
