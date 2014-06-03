#include <SPI.h>
#include <Ethernet.h>
#include "inIt.h"
#include "fonction.h"

void setup() {
  #include "setup.h"
}
  
  

void loop() { 
  // Allumage via la console serial
  byte val;
  if (Serial.available()) {
      // lit le premier byte dans la pile (valeur entre 0 to 255)
     val = Serial.read();  
     int num_instr = val - 49;
     int num_pin = val - 47;
     StatusLed[num_instr] = on_off_led(val, StatusLed[num_instr]);
  }

  EthernetClient client = server.available();
  if (client) {

    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        int Val_check;
        int Pin_check;
        byte c = client.read();

        
        if(incoming && c == ' '){ 
          incoming = 0;
        }
        if(c == '$'){ 
          incoming = 1; 
        }
        
        //Verifie l'URL pour la chaine $x (x = numero de la fonction)
        if(incoming == 1){
           
           if(c == '1') {
             Val_check = c - 49;
             Pin_check = c - 47;
             StatusLed[Val_check] = on_off_led(Pin_check, StatusLed[Val_check]);

             break;
           }  
           
           else if(c == '2') {
             Val_check = c - 49;
             Pin_check = c - 47;
             StatusLed[Val_check] = on_off_led(Pin_check, StatusLed[Val_check]);

             break;
           }  

        }

        if (c == '\n') {
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }

    delay(1);
    client.stop();
  }
}
