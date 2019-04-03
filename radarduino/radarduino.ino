
// petit projet arduino radar 

// IMPORT LE MODULE SERVO.h
#include <Servo.h>. 
// Sensor associer les capteur ultra son emeteur et le recepteur 
const int trigPin = 9;
const int echoPin = 10;
// Variables pour la duree aet la distance  
long duration;
int distance;
Servo myServo; // cration de l'objet servo pour controler le servo moteur  
void setup() {
  pinMode(trigPin, OUTPUT); // mettre l'emeteur comme sortie 
  pinMode(echoPin, INPUT); // mettre le recepeteur comme sortie 
  Serial.begin(9600);
  myServo.attach(3); // on met le servo moteur sur la sortie 3 
}
void loop() {
  // tourner le servo moteur de 15 a 165 degres 
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();// appelle la fonction de calcul de distance mesuré par les capteurs ultrasons pour chaque degres 
  
  Serial.print(i); // envoyer le degres courant au port series 
  Serial.print(","); // 
  Serial.print(distance); // envoyer la valeur de la distance au port series degres 
  Serial.print("."); // 
  }
  // on repete l operation dans l'autre sens de 165 a 15 
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}

//fonction pour calculer la distance mesuree par les capteurs ultrason
 
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  
  //mettre le trigpin a un pour 10ms
   
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); //  lis  echoPin, retourne le temps du voyage de l onde sonore  en milliseconde
  distance= duration*0.034/2;        // il est bien evident quue la distance = 0.5*duree *0.034 ( vitesse du 340m la seconde 
  return distance;
}
