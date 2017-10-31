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

LD R3, DEC_10	; R3 <-- DEC_10
LD R6, PTR_TO_ARR	; Reset pointer
BR OUTPUT_LOOP
END_OUTPUT_LOOP



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

OUTPUT_LOOP
	LD R4, MASK
	LD R5, DEC_16
	LDR R1, R6, #0
	BR OUTPUT_BINARY_LOOP
	END_OUTPUT_BINARY_LOOP
	LD R0, DEC_10
	TRAP x21
	ADD R6, R6, #1	; Increment pointer
	ADD R3, R3, #-1	; Decrement counter
	BRp OUTPUT_LOOP
BR END_OUTPUT_LOOP

OUTPUT_BINARY_LOOP
	IF_STATEMENT
		AND R2, R1, R4	; And Mask with R1 to receive the value of leading bit
		BRn OUTPUT_ONE	; If that value is one jump to OUTPUT_ONE
	OUTPUT_ZERO		; Else output zero
		LD R0, DEC_48	; Load value of ASCII zero
		TRAP x21	; Output ASCII zero
	BR END_IF		; Skip output one(since we went with output zero)
	OUTPUT_ONE
		LD R0, DEC_49	; Load value of ASCII one
		TRAP x21	; Output ASCII one
	END_IF

	ADD R2, R5, #-5
	BRz OUTPUT_SPACE
	
	ADD R2, R5, #-9
	BRz OUTPUT_SPACE
	ADD R2, R5, #-13
	BRz OUTPUT_SPACE

	END_OUTPUT_SPACE
;
	ADD R1, R1, R1		; Shift left by doubling R1
	ADD R5, R5, #-1		; Decrement counter
	BRp OUTPUT_BINARY_LOOP	; Do it again if its positive
BR END_OUTPUT_BINARY_LOOP

OUTPUT_SPACE
	LD R0, DEC_32
	TRAP x21
BR END_OUTPUT_SPACE
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