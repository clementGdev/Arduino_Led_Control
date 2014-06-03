boolean incoming = 0;
int StatusR = 0;
int StatusG = 0;
int StatusLed[2] = {0, 0};


byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0xBD, 0x25 };
IPAddress ip(192,168,1,25);

EthernetServer server(80);

