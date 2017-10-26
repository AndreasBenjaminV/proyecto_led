/*
Autor: Aitor Martin
Fecha: 26-12-2013
Titulo: Encendido y apagado aleatorio de reles
Placa: Arduino uno
Post: http://aitormartin-apuntes.blogspot.com.es/2013/12/arduino-encendido-aleatorio-de-reles-led.html

Código de dominio publico. Se puede distribuir y modificar  libremente, 
siempre y cuando se mencione al autor y se proporcione un enlace a su web.
*/

int pinArray[] = {0, 1, 2, 3, 4, 5, 6, 7};
int count = 0;
int timer = 1000;

void setup()
  {
  for (count=0;count<8;count++)    {
    pinMode(pinArray[count], OUTPUT);
    }
  }

void loop()
  {
  count = 0;  
  for(count;count<8;count++){        
    digitalWrite(pinArray[count], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer);  
  }
  }
