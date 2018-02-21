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

DO_WHILE_LOOP
	STR R3, R6, #0	; mem[R6] <-- R3
	ADD R6, R6, #1	; Increment the pointer
	ADD R3, R3, #1	; Increment the amount we add by
	ADD R4, R4, #-1	; Decrement the counter
	BRp DO_WHILE_LOOP	;While the counter is positive keep looping
END_DO_WHILE_LOOP

LD R6, PTR_TO_ARR	; Reset the pointer
LDR R2, R6, #6		; R2 <-- mem[R6 + 6]
HALT
	;============
	; Local Data
	;============
PTR_TO_ARR	.FILL	x4000
DEC_0		.FILL	#0
DEC_10		.FILL 	#10
.ORIG x4000
ARR	.BLKW	#10
.END