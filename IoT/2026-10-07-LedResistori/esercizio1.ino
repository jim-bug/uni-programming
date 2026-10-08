/*
*   Autore: Ignazio Leonardo Calogero Sperandeo
*   Data: 2026-10-07
*   Consegna: Rif. README.md
*   Soluzione con if
*   by jimbug // :)
*/


int pinLed_1 = 13;
int pinLed_2 = 12;
int pinButton = 11;

bool currentState = false;
bool lastState = false;
bool ledState = false;

void setup(){
    pinMode(pinLed_1, OUTPUT);
    pinMode(pinLed_2, OUTPUT);
    pinMode(pinButton, INPUT_PULLUP);

}

void loop(){
    currentState = digitalRead(pinButton);

    ledState ^= (lastState && !currentState);       // inverte lo stato dei LED alla pressione.

    digitalWrite(pinLed_1, ledState);
    digitalWrite(pinLed_2, ledState);

    lastState = currentState;

    delay(50);
}