/*
*   Autore: Ignazio Leonardo Calogero Sperandeo
*   Data: 2026-10-14
*   Consegna: Rif. README.md
*   by jimbug // :)
*/

int sensor_value = 0;
float voltage_value = 0;

void setup(){
    pinMode(A0, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    sensor_value = analogRead(A0);
    voltage_value = (sensor_value * 5.0 / 1023.0);		// formula partitore di tensione, con cast implicito a float

    Serial.print("Sensor Value: ");
    Serial.print(sensor_value);
    Serial.print(" | Voltage Value: ");
    Serial.print(voltage_value);
    Serial.println(" V");


    digitalWrite(LED_BUILTIN, HIGH);
    delay(sensor_value);
    digitalWrite(LED_BUILTIN, LOW);
    delay(sensor_value);
}