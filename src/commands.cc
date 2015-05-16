#include "../include/DDOS.hh"
#include "../include/commands.hh"

int main(int argc, char **argv) {

  int c;
  struct option options[] = {
      {"port",         required_argument, 0, 'p'},
      {"type",         required_argument, 0, 't'},
      {"frequency",    required_argument, 0, 'f'}
  };
  vector<string> commands;

  while(true) {
    c = getopt_long(argc, argv, "p:t:f:", options, NULL);

    if (c == -1)
      break;

    switch (c) {
      case 'p':
        PUSH_COMMAND
        break;

      case 't':
        PUSH_COMMAND
        break;

      case 'f':
        PUSH_COMMAND
        break;

      case '?':
        HELP
        break;

      default:
        DEFAULT
      }
    }
  return 0;
}
