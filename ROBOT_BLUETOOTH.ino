  
#include <AFMotor.h>
#include <SoftwareSerial.h>

AF_DCMotor motorgauche(1), motordroit(2);
SoftwareSerial  Port(A1,A3);
int vit;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  Port.begin(9600);

  // turn on motor
  motorgauche.setSpeed(255);
  motordroit.setSpeed(255);
  motorgauche.run(BACKWARD);
  motordroit .run(RELEASE);
}

void loop()
{
char var;
if (Port.available()>0)
 {
var = Port.read();
if (var=='A') avancer(vit);
else if(var=='R')reculer(vit);
else if(var=='D')droit(vit);
else if(var=='G')gauche(vit);
else if(var=='S')arreter();
else if(var=='V'){
  vit = Port.parseInt();
  Serial.println(vit);
}
 }
}
void avancer(int vitesse)
{
  motorgauche.run(FORWARD);
  motordroit .run(BACKWARD);
  motordroit.setSpeed (vitesse);
  motorgauche.setSpeed (vitesse);
 
}
void droit(int vitesse)
{
  motorgauche.run(RELEASE);
  motordroit .run(BACKWARD);
  
}
void reculer(int vitesse)
{
  motorgauche.run(BACKWARD);
  motordroit .run(FORWARD);
  motordroit.setSpeed (vitesse);
  motorgauche.setSpeed (vitesse);
 
}
void gauche(int vitesse)
{
  motorgauche.run(FORWARD);
  motordroit .run(RELEASE);
  motordroit.setSpeed (vitesse);
  motorgauche.setSpeed (vitesse);
}
void arreter()
{
  motorgauche.run(RELEASE);
  motordroit .run(RELEASE);
 
}
