;=================================================
; Name: Tran, Kevin
; Username: ktran050
;
; Lab: Lab 4
; Lab Section: 23
; TA: Jose Rodriguez
;=================================================
.ORIG x3000
	;==============
	; Instructions
	;==============
LD R3, DEC_0		; R3 <-- DEC_0
LD R4, DEC_10		; R4 <-- DEC_10
LD R6, PTR_TO_ARR	; R6 <-- PTR_TO_ARR

STORE_DATA_LOOP
	STR R3, R6, #0	; mem[R6] <-- R3
	ADD R6, R6, #1	; Increment the pointer
	ADD R3, R3, #1	; Increment the amount we add by
	ADD R4, R4, #-1	; Decrement the counter
	BRp STORE_DATA_LOOP	;While the counter is positive keep looping
END_STORE_DATA_LOOP

LD R6, PTR_TO_ARR	; Reset the pointer
LD R4, DEC_10		; Reset the counter
LD R1, DEC_48		; R1 <-- DEC_48
OUTPUT_LOOP
	LDR R0, R6, #0	; R0 <-- mem[R6]
	ADD R0, R0, R1	; R0 <-- R0 + R1(48) to turn the DEC to ASCII
	TRAP x21	; user <-- R0
	ADD R6, R6, #1	; Increment the pointer
	ADD R4, R4, #-1	; Decrement the counter
	BRp OUTPUT_LOOP		;While the counter is positive keep looping
END_OUTPUT_LOOP

LD R0, DEC_10	; R0 <-- ASCII(newline)
TRAP x21	; user <-- R0

HALT
	;============
	; Local Data
	;============
PTR_TO_ARR	.FILL	x4000
DEC_0		.FILL	#0
DEC_10		.FILL 	#10
DEC_48		.FILL	#48
.ORIG x4000
ARR	.BLKW	#10
.END