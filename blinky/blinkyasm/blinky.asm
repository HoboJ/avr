; Blinky C Program in Assembler
; Trevor Hennessy
.include "m169def.inc"
.def temp = r16
.def outerc = r17
.def innerc = r18
.def stackvar = r20

RESET:
    ; Set DDRD for output
    ; 0 = input, 1 = output
    ldi stackvar, low (ramend)
    out spl, stackvar
    ldi stackvar, high (ramend)
    out sph, stackvar
    ldi temp, 0xFF
    out DDRD, temp

SETL:
    ldi temp, 0x01 ; set temp to 1 so it can count up in LOOPL
    clc

LOOPL:
    ; loop to the left on leds
    out PORTD, temp
    rol temp
    brcs SETR ; branch if carry set and jump to SETR
    rcall DELAY
    rjmp LOOPL
    
LOOPR:
    ; loop to the right on leds
    out PORTD, temp
    ror temp
    brcs SETL ; branch if carry set and jump to SETL
    rcall DELAY
    rjmp LOOPR

SETR:
    ldi temp, 0x80 ; set temp to 128 so it can count down in LOOPR
    clc
    rjmp LOOPR

    ; Subroutine - function
DELAY: ; delay approx 1 second
    ldi outerc, 0xFF
OUTER:
    ldi innerc, 0xFF
INNER:
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    dec innerc
    brne INNER
    dec outerc
    brne OUTER
    ret
