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
LD R4, DEC_9		; R4 <-- DEC_9
LD R6, PTR_TO_ARR	; R6 <-- PTR_TO_ARR

STR R3, R6, #0	; mem[R6] <-- R3
ADD R6, R6, #1	; Increment the pointer
ADD R3, R3, #2	; R3 <-- R3 + 2(give R3 its base value of 2^1)

BR STORE_DATA_LOOP
END_STORE_DATA_LOOP

LD R6, PTR_TO_ARR	; Reset pointer
LDR R2, R6, #6		; R2 <-- mem[R6 +6]
HALT
	;===================
	; "Function Calls"
	;===================

STORE_DATA_LOOP
	STR R3, R6, #0	; mem[R6] <-- R3
	ADD R6, R6, #1	; Increment the pointer
	ADD R3, R3, R3	; Double R3
	ADD R4, R4, #-1	; Decrement the counter
	BRp STORE_DATA_LOOP	;While the counter is positive keep looping
BR END_STORE_DATA_LOOP

	;============
	; Local Data
	;============
PTR_TO_ARR	.FILL	x4000

DEC_0		.FILL	#0
DEC_3		.FILL	#3
DEC_4		.FILL	#4
DEC_9		.FILL	#9
DEC_10		.FILL 	#10
DEC_16		.FILL	#16
DEC_32		.FILL	#32
DEC_48		.FILL	#48
DEC_49		.FILL	#49
MASK		.FILL	x8000

.ORIG x4000
ARR	.BLKW	#10
.END