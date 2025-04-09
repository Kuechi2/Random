#include <Arduino.h>
int Leds[] = {2,3,4,5,6,8,9}; //Liste mit den angeschlossenen LED
//Funktionsdeklarationen
void AllesAus();
void ZeigeZahl(int i);
void LedCheck();
void Wuerfeln();

//Funktionsimplementationen
void setup() 
{
  for(int i = 0; i < 7; i++)
  pinMode(Leds[i], OUTPUT);
  pinMode(13,INPUT);  //Button
  Serial.begin(9600);
  Serial.println("Zum Testen einer bestimmten Zahl gib sie hier ein:");
  LedCheck();
}

void loop() 
{
  if (Serial.available() > 0) //Wenn etwas vom angeschlossenen Computer gesendet wird (Tastendruck)...
  {
    char num = Serial.read(); //...lies den Wert der Tastatur als Ascii...
    ZeigeZahl(num-48);  //...und rechne es in einen Zahlenwert um, der dann angezeigt wird
  }
  if(digitalRead(13)==HIGH) Wuerfeln(); // wenn der Knopf gedrückt wird, starte die Funktion "Wuerfeln"
}

void AllesAus() //Schaltet alle LEDs aus
  {
    
  for(int i = 0; i < 7; i++)
    digitalWrite(Leds[i],LOW);
  }

  void ZeigeZahl(int n) //Schaltet die LEDs an, die die Zahl n darstellen
  {
    AllesAus();
    switch (n)  //was steht in "n"?
    {
    case 1: 
      digitalWrite(2,HIGH); //Mitte
      break;
    case 2:
      digitalWrite(3,HIGH); // Links Oben
      digitalWrite(9,HIGH); //Rechts Unten
      break;
    case 3:
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(9,HIGH);
      break;   
    case 4:
      digitalWrite(5,HIGH); //Rechts Oben
      digitalWrite(3,HIGH); //Links Oben
      digitalWrite(6,HIGH); //Rechts Unten
      digitalWrite(9,HIGH); //Links Unten
      break;   
    case 5:
      digitalWrite(5,HIGH); 
      digitalWrite(3,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(2,HIGH);
      break; 
    case 6:
      digitalWrite(5,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(4,HIGH); //Links Mitte
      digitalWrite(8,HIGH); //Rechts Mitte
      break; 
    default:
      digitalWrite(5,HIGH); //wenn die Zahl nicht zwischen 1-6 ist
      digitalWrite(3,HIGH); //gib ein "x" aus um den Fehler anzuzeigen
      digitalWrite(6,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(2,HIGH);
      break;
    }
  }
  void LedCheck() //Schaltet alle LEDs einmal kurz an um sie zu testen
  {
    for (int i = 0; i < 7; i++)
    {
      AllesAus();
      digitalWrite(Leds[i], HIGH);
      delay(200);
    }
    AllesAus();
  }
  void Wuerfeln() // Generiert 20 Zufallswerte von 1-6 und zeigt sie an.
  {               //Der letzte bleibt stehen und ist die gewürfelte Zahl
    for(int i = 1; i < 21; i++)
    {
      ZeigeZahl((int)random(7));
      delay(10*i);
    }
  }



