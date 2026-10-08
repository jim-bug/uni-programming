/*
*   Autore: Ignazio Leonardo Calogero Sperandeo
*   Data: 2026-10-07
*   Consegna: Rif. README.md
*   by jimbug // :)
*/


// pin collegati ai due LED e al pulsante.
int pinLed_1 = 13;
int pinLed_2 = 12;
int pinButton = 11;

// stati usati per rilevare la pressione del pulsante.
bool currentState = false;
bool lastState = false;
bool ledState = false;

void setup(){
    pinMode(pinLed_1, OUTPUT);
    pinMode(pinLed_2, OUTPUT);
    pinMode(pinButton, INPUT_PULLUP);
}

void loop(){
    // con INPUT_PULLUP il pulsante vale LOW quando viene premuto.
    currentState = digitalRead(pinButton);

    // controlla che si tratti di una nuova pressione del pulsante.
    if (currentState == LOW && lastState == HIGH) {
        // se i LED sono spenti li accende; altrimenti li spegne.
        if (ledState == false) {
            ledState = true;
        } else {
            ledState = false;
        }
    }

    // i due LED mantengono sempre lo stesso stato.
    digitalWrite(pinLed_1, ledState);
    digitalWrite(pinLed_2, ledState);

    // salva lo stato per riconoscere la prossima nuova pressione.
    lastState = currentState;

    delay(50);
}