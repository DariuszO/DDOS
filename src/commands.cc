#include "../include/commands.hh"

int main(int argc, char **argv) {

  int c;
  struct option options[] = {
      {"port",         required_argument, 0, 'p'},
      {"type",         required_argument, 0, 't'},
      {"frequency",    required_argument, 0, 'f'},
      {"target",       required_argument, 0, 'c'}
  };
  vector<string> commands = {"80", "UDP", "10", ""};

  while(true) {
    c = getopt_long(argc, argv, "p:t:f:c:", options, NULL);

    if (c == -1)
      break;

    switch (c) {
      case 'p':
        commands[0] = optarg;
        break;

      case 't':
        commands[1] = optarg;
        break;

      case 'f':
        commands[2] = optarg;
        break;

      case 'c':
        commands[3] = optarg;
        break;

      case '?':
        HELP
        break;

      default:
        DEFAULT
      }
    }

    MIN_SUPER_INT port = atoi(commands[0].c_str());
    MAX_SUPER_INT frequency = atoi(commands[2].c_str());
    bool type = (protocol(commands[1])) ? true : false;

    subChecking(&port, &frequency);

    DDOS go(commands[3], frequency, port, type);
    go.attack();
  return 0;
}

static bool protocol(string target) {
  regex protocol("UDP");
  return (regex_match(target.c_str(), protocol)) ? true : false;
}

template<typename P, typename F>
static void subChecking(P *port, F *frequency) {
  if(port == 0)
    port = (P *) 80;

  if(frequency == 0)
    frequency = (F *) 10;
}
