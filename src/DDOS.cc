#include "../include/DDOS.hh"

DDOS::DDOS(string target, unsigned long int frequency): target(target), frequency(frequency) {}

bool DDOS::ping() {
  // TODO:
  // Check if host exist, simule a ping command.
  return false;
}

bool DDOS::isIP() {
  // TODO:
  // Check if a syntax correspond to a IP format.
  return false;
}

void DDOS::attack() {
  // TODO:
  // Check if host is valid (::isIP && ::ping).
  // GO DDOS.
}

/*void DDOS::stop(vector<std::thread> threads) {

}*/

DDOS::~DDOS() {
  // TODO:
  // Destroy threads if frequency > 1.
}
