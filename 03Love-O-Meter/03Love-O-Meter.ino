const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup (){
    Serial.begin(9600);
    for(int pinNumber = 2; pinNumber < 5; pinNumber++){
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, LOW);
    }
}

void loop(){
    int sensorVal = analogRead(sensorPin);
    Serial.print("Sensor Value: " );
    Serial.print(sensorVal);

    float voltage = (sensorVal/1024.0) * 5.0;
    Serial.print(", Volts: ");
    Serial.print(voltage);

    float temp = (voltage - .5) * 100;
    Serial.print(", degrees C: ");
    Serial.println(temp);

    if(temp < baselineTemp){
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    } else if (temp >= baselineTemp+2 && temp < baselineTemp+4) {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    } else if (temp >= baselineTemp+4 && temp < baselineTemp+6) {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    } else if(temp >= baselineTemp+6){
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }
    delay(1000);
}
