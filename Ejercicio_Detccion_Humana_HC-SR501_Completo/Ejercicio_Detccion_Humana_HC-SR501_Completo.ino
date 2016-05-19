//www.elbrujitocanaio.es
//Todo el c�digo esta bajo licencia de la Creative Commons.
//Deteccion humana HC-SR501
///////////////////////////////////////////////////////////
#define pinSensor 2 //Se�al del Sensor
#define pinLed 13 //Salida del Led
#define pinSonoro 11 //Salida altavoz
#define sonidoF 68 //Define frecuencia sonido(Tone())
#define pinRele 12 //Define salida para un rel�
void setup() {
pinMode(pinSensor,INPUT);//sensor
pinMode(pinLed,OUTPUT);//led
pinMode(pinSonoro,OUTPUT);//sonido
pinMode(pinRele,OUTPUT);//rele
Serial.begin(9600);//Activo la salida serie

}

void loop() {
  boolean Pres = digitalRead (pinSensor);//Tomo valor booleano:H � L
if (Pres == true){ //Si valor es H hay presencia
Serial.println("Detecta presencia");
digitalWrite(pinLed,HIGH);//Enciende el led
tone (pinSonoro,sonidoF);//Alarma sonora
digitalWrite(pinRele,HIGH);//Enciende el rele



delay(5000);//Tiempo de espera
}else{
Serial.println("No se Detecta presencia");//Si variable Pres = L
delay(100);
digitalWrite(pinLed,LOW);//Apaga el led
noTone(pinSonoro);
delay(100);
}
delay(500);//Paro de un segundo
}