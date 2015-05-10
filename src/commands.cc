#include "../include/DDOS.hh"

int main(int argc, char **argv) {

  int test;

  test = system("ping 216.58.211.67 > nul");

    cout << test << endl;

  // Target (IP).
  // Frequency (Simultaneous requests).
  // Delete thread on CTRL+C.
  // signal(SIGINT, <<<func>>>);
  return 0;
}
