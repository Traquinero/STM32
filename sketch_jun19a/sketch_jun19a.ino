/*
  ARDUINO BLUETOOTH CONTROLLER
  CONFIGURACION DE GAMEPAD:
  PRESS FLECHA ADELANTE                 A
  RELEASE DE FLECHA ADELANTE            0   
  PRESS FLECHA ATRAS                    R
  RELEASE DE FLECHA ATRAS               0
  PRESS FLECHA IZQUIERDA                I
  RELEASE DE FLECHA IZQUIERDA           0
  PRESS FLECHA DERECHA                  D
  RELEASE DE FLECHA DERECHA             0
  PRESS DE CRUZ ANGULO MINIMO           J
  RELEASE DE CRUZ ANGULO MAXIMO         K
*/

//CONFIGURACIÓN DE PINES PARA EL 
const int pinMot1A = PA0;
const int pinMot1B = PA1;
//const int pinPWMA = PA2 ;
const int pinMot2A = PA3 ;
const int pinMot2B = PA4;
//const int pinPWMB = 10;

int retraso = 80;

void setup() {
  Serial1.begin(9600);
  // configuramos los pines como salida
  pinMode(pinMot1A, OUTPUT);
  pinMode(pinMot1B, OUTPUT);
  pinMode(pinMot2A, OUTPUT);
  pinMode(pinMot2B, OUTPUT);
  //pinMode(pinPWMA, OUTPUT);
  //pinMode(pinPWMB, OUTPUT);
}

void loop() {
  //Revisa si el puerto serie está libre para recibir datos por BT
  if (Serial1.available()) {
    char dato = Serial1.read();   //Lee el caracter recibido por BT
    //Reconoce y actua según el caracter enviado
    Serial1.println(dato);
    //Flechas de dirección
    switch (dato) {
      case 'A':
        Serial1.println("Avance");
        Avance();
        break;
      case 'R':
        Retroceso();
        Serial1.println("Retroceso");
        break;
      case 'D':
        GiroDerecha();
        Serial1.println("GiroDerecha");
        break;
      case 'I':
        GiroIzquierda();
        Serial1.println("GiroIzquierda");
        break;
      default:
        Alto();
        break;
    }
  }
  delay(retraso);
}

void Avance()
{
  digitalWrite(pinMot1A, HIGH);
  digitalWrite (pinMot1B, LOW);
  digitalWrite (pinMot2A, HIGH);
  digitalWrite (pinMot2B, LOW);
  //analogWrite (pinPWMA, 255);
  //analogWrite (pinPWMB, 255);
}

void Retroceso()
{
  digitalWrite(pinMot1A, LOW);
  digitalWrite (pinMot1B, HIGH);
  digitalWrite (pinMot2A, LOW );
  digitalWrite (pinMot2B, HIGH);
  //analogWrite (pinPWMA, 255);
  //analogWrite (pinPWMB, 255);
}
void GiroDerecha()
{
  digitalWrite (pinMot1A, LOW );
  digitalWrite (pinMot1B, HIGH);
  digitalWrite (pinMot2A, HIGH);
  digitalWrite (pinMot2B, LOW);
  //analogWrite (pinPWMA, 255);
  //analogWrite (pinPWMB, 255);
}
void GiroIzquierda()
{
  digitalWrite (pinMot1A, HIGH);
  digitalWrite (pinMot1B, LOW);
  digitalWrite (pinMot2A, LOW );
  digitalWrite (pinMot2B, HIGH);
  //analogWrite (pinPWMA, 255);
  //analogWrite (pinPWMB, 255);
}
void Alto()
{
  digitalWrite (pinMot1A, LOW);
  digitalWrite (pinMot1B, LOW);
  digitalWrite (pinMot2A, LOW);
  digitalWrite (pinMot2B, LOW);
  //analogWrite (pinPWMA, 0);
  //analogWrite (pinPWMB, 0);
}




