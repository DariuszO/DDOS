#ifndef COMMANDS_H
#define COMMANDS_H

#include "DDOS.hh"

#define HELP puts("Usage :\n./DDOS -t [--target] 12.45.32.123 -s [--time] 3600 -p [--port] 80 -f [--frequency] 10\n\nNote :\n- Frequency is number of simultaneous requests (threads).\n- Time (or -s) is the time (in seconds) during the script is run.\n- -v or --version for display the version.");
#define DEFAULT puts("Use -h [--help] for more informations");
#define VERSION puts("1.0.0");

#define CHANGE_PORT puts("\033[33m[!]\033[m The value of port is invalid, we assign it 80.");
#define CHANGE_FREQUENCY puts("\033[33m[!]\033[m The value of frequency is invalid, we assign it 10.");
#define CHANGE_TIME puts("\033[33m[!]\033[m The value of time (in seconds) is invalid, we assign it 30.");

template<typename P, typename F, typename T>
static void subChecking(P *port, F *frequency, T *timeDDOS);

#endif
