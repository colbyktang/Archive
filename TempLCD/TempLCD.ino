#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <LiquidCrystal.h>

#define TEMP_PIN         0
#define CLOCK_PRESCALE(n)   (CLKPR = 0x80, CLKPR = (n))

extern float readTemp;
float TEMP;

int main(void) {    
    CLOCK_PRESCALE(0);
    DDRC = B00000;
    Serial.begin(9600);
    float voltage, degreesC, degreesF;
    LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
    lcd.begin(16, 2);

    while(1){
        voltage = readTemp * 0.004882814;
        degreesC = (voltage - 0.5) * 100.0;
        degreesF = degreesC * (9.0/5.0) + 32.0;
        lcd.setCursor(0, 0);
        lcd.print("F: ");
        lcd.setCursor(3, 0);
        lcd.print(degreesF);
        lcd.setCursor(0, 1);
        lcd.print("C: ");
        lcd.setCursor(3, 1);
        lcd.print(degreesC);
        Serial.println(voltage);
        _delay_ms(50);
    }
}
