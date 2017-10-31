;=================================================
; Name: Tran, Kevin
; Username: ktran050
;
; Lab: Lab 3
; Lab Section: 23
; TA: Jose Rodriguez
;=================================================
; Use excersise 2 but now output each character to the console
; One per line

.ORIG x3000

	;==============
	; Instructions
	;==============

ADD R2, R2, #10		;Create the counter for the do while loop
LD R6, PTA		;Hold the address of the pointer
DO_WHILE_LOOP_LOAD
	TRAP x20		;Take input from the user
	STR R0, R6, #0		;Store the data at R0 to the address of R6
	ADD R6, R6, #1		;Increment the pointer
	ADD R2, R2, #-1		;Decrement the counter
	BRp DO_WHILE_LOOP_LOAD	;If positive continue looping
END_DO_WHILE_LOOP_LOAD

ADD R2, R2, #10		;Create the counter for the do while loop
LD R6, PTA		;Hold the address of the pointer
DO_WHILE_LOOP_OUTPUT
	LDR R0, R6, #0		;Load the data at the pointer
	ADD R6, R6, #1		;Increment the pointer
	ADD R2, R2, #-1		;Decrement the counter
	TRAP x21		;Output R0
	BRp DO_WHILE_LOOP_OUTPUT	;If positive continue looping
END_DO_WHILE_LOOP_OUTPUT

HALT
	;============
	; Local Data
	;============

PTA .FILL x4000		;Pointer to array

.ORIG x4000
ARRAY	.BLKW	#10	;Array of size 10

.END