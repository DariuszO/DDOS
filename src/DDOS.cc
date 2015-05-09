#include "../include/DDOS.hh"

DDOS::DDOS(string target, unsigned long int frequency, unsigned short int port, bool protocol): target(target), protocol(protocol), port(port), frequency(frequency) {}

bool DDOS::ping() {
  // TODO:
  // Check if host exist, simule a ping command.
  return false;
}

bool DDOS::isIPv4() {
  regex IPv4("([0-9]{1,3}.){3}\\.([0-9]{1,3})");
  return (regex_match(this->target, IPv4)) ? true : false;
}

void DDOS::goSocket() {
  // TODO:
  // Send a socket.
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
