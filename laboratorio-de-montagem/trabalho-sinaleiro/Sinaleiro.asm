.device atmega328p
.org 0x00

.equ DDRB = 0x04
.equ PortB = 0x05
.equ vermelho1 = 0x02
.equ amareloA = 0x01
.equ verde1 = 0x00
.equ vermelho2 = 0x05
.equ amareloB = 0x04
.equ verde2 = 0x03
rjmp configura
 
Configura:
	ldi r16, 0xFF
	out DDRB, r16
        sbi PortB, vermelho1
        sbi PortB, vermelho2
        sbi PortB, verde1
        sbi Portb, verde2
        sbi portb, amareloa
        sbi portb, amarelob
inicio:
    ldi r26,0x50 ; 18 segundos
    ldi r27,0x46 ;O R27 e o R26 quando subtraidos funcionam como apenas um registrador, o r27 é o mais significativo
    cbi PortB, Vermelho2 ;Acende o vermelho2
    cbi PortB, verde1 ;acende o verde1
    rcall delay

    sbi PortB, verde1
    cbi Portb, amareloA
    ldi r26,0xD0 ; 2 segundos
    ldi r27,0x7 ;2 segundos
    rcall delay

    sbi Portb, amareloA
    sbi portb, vermelho2
    cbi Portb, vermelho1
    cbi Portb, verde2
    ldi r26, 0x40 ; 8 segundos
    ldi r27, 0x1F ; 8 segundos
    rcall delay

    sbi PortB, vermelho2
    ldi r26, 0x11 ; 10 s
    ldi r27, 0x27 ; 10 s
    rcall delay

    sbi Portb, verde2
    cbi portb, amarelob
    ldi r26,0x40 ;2s
    ldi r27,0x1F ;2s
    rcall delay

    sbi portb, amarelob
    cbi portb, vermelho2
    ldi r26, 0xE8 ;1s
    ldi r27, 0x03 ;1s
    sbi portb, vermelho1
    rjmp inicio

    
    



delay:
	sbiw r26, 0x01
	ldi r25, 0xf
	nop
	jmp loop
delay_real:
	sbiw r26, 0x01
	brcc milisegundo
	nop
	ret
milisegundo:
	ldi r24, 0x90
	ldi r25, 0xf
	nop
	nop
loop:
	sbiw r24, 0x01
	brne loop
	nop
	nop
	nop
	rjmp delay_real
