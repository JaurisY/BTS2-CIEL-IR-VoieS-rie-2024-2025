int tableauPinLed[3] = {13, 12, 11};
int tableauPinBouton[3] = {4, 3, 2};
int tableauStock[3] = {0, 0, 0};
String tableauDico[3] = {"cafe", "chocolat chaud", "the"};
String s = "";

////////////////////////////////////////////////////////////////////////////////////////

void setup()
{
  Serial.begin(9600);
  
  for(int i = 2; i <= 4; i++)
  {
    pinMode(i, INPUT);
  	digitalWrite(i, HIGH);
    pinMode(i+9, OUTPUT);
  	digitalWrite(i+9, HIGH);
  }
  
}

////////////////////////////////////////////////////////////////////////////////////////

void remplir()
{
  if(digitalRead(4) == LOW)
    tableauStock[0] = 10;
  if(digitalRead(3) == LOW)
    tableauStock[1] = 10;
  if(digitalRead(2) == LOW)
    tableauStock[2] = 10;
}

void receptionCommande()
{
  char readChar;
  int buff = Serial.available(); // mise à jour du nombre de caratères restant
  if(buff > 0)
    {
    	while(buff > 0) // tant qu'il reste des caractères dans le buffer
    	{
       		readChar = Serial.read(); // lecture du caractère
          	delay(10);
          	s += readChar;
          	buff = Serial.available(); // mise à jour du nombre de caratères restant
    	}
  	}
}

void servirBoisson()
{
  if(s == tableauDico[0])
    tableauStock[0] -= 1;
  if(s == tableauDico[1])
    tableauStock[1] -= 1;
  if(s == tableauDico[2])
    tableauStock[2] -= 1;
}

void checkLumiere()
{ //cafe
  if (tableauStock[0] > 5)
  	digitalWrite(13, HIGH);
  if (tableauStock[0] <=5 && tableauStock[0] >2)
  {
   	digitalWrite(13, LOW);
    delay(1000);
    digitalWrite(13, HIGH);
    delay(1000);
  }
  if (tableauStock[0] < 3)
    digitalWrite(13, LOW);
  //chocolat chaud
  if (tableauStock[1] > 5)
  	digitalWrite(12, HIGH);
  if (tableauStock[1] <=5 && tableauStock[1] >2)
  {
   	digitalWrite(12, LOW);
    delay(1000);
    digitalWrite(12, HIGH);
    delay(1000);
  }
  if (tableauStock[1] < 3)
    digitalWrite(12, LOW);
  //the
  if (tableauStock[2] > 5)
  	digitalWrite(11, HIGH);
  if (tableauStock[2] <=5 && tableauStock[2] >2)
  {
   	digitalWrite(11, LOW);
    delay(1000);
    digitalWrite(11, HIGH);
    delay(1000);
  }
  if (tableauStock[2] < 3)
    digitalWrite(11, LOW);

}

////////////////////////////////////////////////////////////////////////////////////////

void loop()
{     
 remplir();
 receptionCommande();
 servirBoisson();
 checkLumiere(); 
 s = "";
}
