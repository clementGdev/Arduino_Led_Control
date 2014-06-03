#include "arduino.h"

pinMode(2, OUTPUT);
pinMode(3, OUTPUT);


// Demarre la communication serie
Serial.begin(9600);
// Demarre la connexion ethernet
Ethernet.begin(mac, ip);
server.begin();

// Affiche l'adresse ip sur le moniteur serie
Serial.print("server is at ");
Serial.println(Ethernet.localIP());