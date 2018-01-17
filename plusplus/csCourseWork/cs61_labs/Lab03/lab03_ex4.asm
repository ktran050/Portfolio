;=================================================
; Name: Tran, Kevin
; Username: ktran050
;
; Lab: Lab 3
; Lab Section: 23
; TA: Jose Rodriguez
;=================================================
; Traverse the array without knowing beforehand how big it is
; Do this by rewriting ex3
; 1) Take input(until enter) with a do while loop and store this input

.ORIG x3000

	;==============
	; Instructions
	;==============

LD R6, PTA		;Save the adress the pointer is pointing to
INPUT_WHILE_LOOP
	TRAP x20	;Take user input
	ADD R5, R0, #0	;Copy input to R5
	STR R0, R6, #0	;Save the input
	ADD R6, R6, #1	;Increment the pointer
	ADD R5, R5, #-10	;Add -10(if the input is enter then it becomes zero)
	BRp INPUT_WHILE_LOOP	;If R5 is positive (not zero) continue
	BRn INPUT_WHILE_LOOP	;If R5 is negative (not zero) continue
END_INPUT_WHILE_LOOP

LD R6, PTA		;Save the adress the pointer is pointing to
OUTPUT_WHILE_LOOP
	LDR R0, R6, #0	;Take the input from the array
	ADD R5, R0, #0	;Copy the input to R5
	TRAP x21	;Output the input
	ADD R6, R6, #1	;Increment the pointer
	ADD R5, R5, #-10	;Add -10(if the input is enter then it becomes zero)
	BRp OUTPUT_WHILE_LOOP	;If R5 is positive (not zero) continue
	BRn OUTPUT_WHILE_LOOP	;If R5 is negative (not zero) continue
END_OUTPUT_WHILE_LOOP


HALT
	;============
	; Local Data
	;============

PTA .FILL x4000		;Pointer to array

.ORIG x4000


.END