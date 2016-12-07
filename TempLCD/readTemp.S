#include <avr/io.h>

        .section        .text
        .global         readTemp
		    .extern			    TEMP

readTemp:
		in          r24, PORTC           ; get current bits
    ret
