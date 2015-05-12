#include "../include/DDOS.hh"

DDOS::DDOS(char *target, unsigned long int frequency, unsigned short int port, bool protocol): target(target), protocol(protocol), port(port), frequency(frequency) {}

bool DDOS::isIPv4() {
  regex IPv4("([0-9]{1,3}.){3}\\.([0-9]{1,3})");
  return (regex_match(this->target, IPv4)) ? true : false;
}

void DDOS::goSocket() {
  while (true) {
    SOCKADDR_IN sin;
    SOCKET sock = socket(AF_INET, this->protocol, 0);
    // TODO: Check socket.
    sin.sin_addr.s_addr = inet_addr(this->target);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(this->port);
    connect(sock, (SOCKADDR*)&sin, sizeof(sin));
    // TODO: Check connect.
    break;
  }
}

void DDOS::attack() {
  if(!this->isIPv4()) {
    // TODO: Return error.
  }
  while (true) {
    // TODO:
    // Create thread + pass a goSocket.
    break;
  }
}

/*void DDOS::stop(vector<std::thread> threads) {

}*/

DDOS::~DDOS() {
  // TODO:
  // Destroy threads if frequency > 1.
}
