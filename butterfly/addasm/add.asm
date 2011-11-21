; Add 0x0F to 0x01
; Output to PORTD

.include "m169def.inc"
.def temp = r16
.def temp1 = r17
.def inout = r18

; Output to PortD

    ldi inout, 0b11111111 ; Enable PORTD ddr for output
    out DDRD, inout
    
    ldi temp, 0x0F
    ldi temp1, 0x01
    add temp1, temp
    out PORTD, temp1
