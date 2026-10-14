/*
*   Autore: Ignazio Leonardo Calogero Sperandeo
*   Data: 2026-10-14
*   Consegna: Rif. README.md
*   by jimbug // :)
*/

const int led_pin = 9;
int brightness = 0;
int fade_amount = 5;

void setup() {
    pinMode(led_pin, OUTPUT);
}

void loop() {
    analogWrite(led_pin, brightness);

    brightness = brightness + fade_amount;

    if (brightness <= 0 || brightness >= 255) fade_amount = -fade_amount; 

    delay(30);
}