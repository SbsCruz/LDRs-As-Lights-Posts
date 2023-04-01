int sensor; //Variable para los sensores
int totalON = 0; // Variable para saber el número total de luces prendidas


void setup() {
    Serial.begin(9600);

    for( int i=13 ; i>=2 ; i--){
        pinMode(i,OUTPUT); //Configuramos los pines
    }
}


void loop() {
    // Hacemos uso de la función "Sensores"
    Sensores(sensor, 13,A0);
    Sensores(sensor, 12,A1);
    Sensores(sensor, 11,A2);
    Sensores(sensor, 10,A3);
    Sensores(sensor, 9,A4);
}

// Definimos la función "Sensores", que hace uso de la función "Numeros"
void Sensores(int vSensor, int led, int analog){
    vSensor=analogRead(analog);
    Serial.println(vSensor);
    delay(500);
    if(vSensor<900){
        digitalWrite(led, LOW);
        delay(100);
        totalON+=1;
        Numero(totalON);
    } else{
        digitalWrite(led, HIGH);
        delay(100);
}
}

// Definimos la función "Numeros" para encender el 7 segmentos según el número de luces encendidas
void Numero(int n){ //Función para encender los leds
    switch(n){
    case 1:
        digitalWrite(8, LOW);
        digitalWrite(7, LOW);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        delay(100);
        break;
    case 2:
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        delay(100);
        break;
    case 3:
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        delay(100);
        break;
    case 4:
        digitalWrite(8, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        delay(100);
        break;
    case 5:
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        delay(100);
        break;
    default:
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        delay(100);
        break;
}
}
