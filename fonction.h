#include <arduino.h>

int on_off_led(int Valeur, int Stat ) {

  if(Stat == 0){
            Stat = 1;
            Serial.println("LED Number");
            Serial.println(Valeur);
            Serial.println("is ON");
            digitalWrite(Valeur, HIGH);
            Valeur = 0;
          }
          
         else if(Stat == 1){
            Stat = 0;
            Serial.println("LED Number");
            Serial.println(Valeur);
            Serial.println("is OFF");
            digitalWrite(Valeur, LOW);
            Valeur = 0;
          }
          return Stat;
}

