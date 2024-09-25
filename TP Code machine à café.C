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
  for(int i = 0; i <= 2; i++)
  {
    if(digitalRead(4-i) == LOW)
      tableauStock[i] = 10;
  }
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
  for(int i = 0; i <= 2; i++)
  {
  	if(s == tableauDico[i])
    	tableauStock[i] -= 1;
  }
}

void checkLumiere()
{ 
  for(int i = 0; i <= 2; i++)
  {
    if (tableauStock[i] > 5)
  		digitalWrite(13-i, HIGH);
  	if (tableauStock[i] <=5 && tableauStock[i] >2)
  	{
   		digitalWrite(13-i, LOW);
    	delay(1000);
    	digitalWrite(13-i, HIGH);
    	delay(1000);
  	}
  	if (tableauStock[i] < 3)
    	digitalWrite(13-i, LOW);
  }
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
