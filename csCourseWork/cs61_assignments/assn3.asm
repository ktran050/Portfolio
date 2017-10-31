;=================================================
; Name: <Tran, Kevin>
; Username: ktran050
;
; SID: 861172609
; Assignment Name: <assn 3>
; Lab Section: 23
; TA: Jose Rodriguez
;
; I hereby certify that I have not received 
; assistance on this assignment, or used code,
; from ANY outside source other than the
; instruction team. 
;
;=================================================
.ORIG x3000
        ;=============
        ;Instructions
        ;=============
LD R6, Convert_addr		; R6 <-- Address pointer for Convert
LDR R1, R6, #0			; R1 <-- VARIABLE Convert
LD R5, DEC_16			; R5 <-- 16 (# of times we are looping)
LD R4, MASK			; R4 <-- MASK
LD R3, DEC_4			; R3 <-- 4 (# of bits before a space)
LD R6, DEC_3			; R6 <-- 3 (# of times the space loop loops)

DO_WHILE_LOOP
	AND R2, R1, R4		; Determine the value of the first number (and the number and the mask)
	IF_STATEMENT
		BRn OUTPUT_ONE	; If this value is negative
	OUTPUT_ZERO		; If this value is zero
		LD R0, DEC_48		; Put the ASCII character zero in R0
		TRAP x21		; Output it
	BR END_IF
	OUTPUT_ONE
		LD R0, DEC_49		; Put the ASCII character one in R0
		TRAP x21		; Output it
		ADD R2, R2, #0		; Make sure the next branch checks the value of R2 not R0
	END_IF

	ADD R3, R3, #-1		; Decrement the space counter
	BRz HERE		; If its zero go to HERE
	END_HERE

	ADD R1, R1, R1		; Shift left by doubling R1
	ADD R5, R5, #-1		; Decrement counter
	BRp DO_WHILE_LOOP	; Do it again if its positive
END_DO_WHILE_LOOP

;LD R0, DEC_10			; Load the value of newline
;TRAP x21			; Output newline
HALT

HERE
	ADD R6, R6, #0	; Make sure the branch checks R6
	BRz END_HERE	; If R6 is zero we shouldn't be outputting another space
	ADD R6, R6, #-1	; Decrement the space counter's counter
	LD R0, DEC_32	; Load ASCII for space to R0
	TRAP x21	; Output a space
	LD R3, DEC_4	; Reset the counter
BR END_HERE

        ;=====
        ;Data
        ;=====

Convert_addr    .FILL 	x5000	            ; The address of where to find the data
MASK		.FILL	x8000	; Mask to test if the leading number is positive or negative
DEC_48		.FILL	#48	; ASCII zero
DEC_49		.FILL	#49	; ASCII one
DEC_32		.FILL	#32	; ASCII space
DEC_10		.FILL	#10	; ASCII newline
DEC_16		.FILL	#16	; Number of times we're looping
DEC_4		.FILL	#4	; Number of bits before a space
DEC_3		.FILL	#3	; Number of times the space loop loops

.ORIG x5000			    ; Remote data
Convert         .FILL xABCD	        ; <----!!!NUMBER TO BE CONVERTED TO BINARY!!!



.END