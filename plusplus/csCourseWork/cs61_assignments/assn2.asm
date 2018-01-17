;=================================================
; Name: Tran, Kevin
; Username: ktran050
; 
; Assignment name: <assn 2>
; Lab section: 23
; TA: Jose Rodriguez
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team.
;
;=================================================
.orig x3000
	;================
	; Instruction
	;================
		; Prompt the user for inputs
		LEA R0, PROMPT_INPUT
		TRAP x22


		; Take input 1, echo, save to register 2, and output a newline
		TRAP x20
		TRAP x21
		ADD R2, R0, #0
		LD R0, NEWLINE
		TRAP x21


		; Take input 2, echo, save to register 3, and output a newline
		TRAP x20
		TRAP x21
		ADD R3, R0, #0
		LD R0, NEWLINE
		TRAP x21


		; Change the ASCII chars into decimals and move them to 4 and 5 respectively
			; Set R1 to -48
		LD R1, ASCII_NEG_CONST
			; Convert ASCII to DEC
		ADD R4, R2, R1
		ADD R5, R3, R1


		; Do the subtraction of registers 4 and 5
		NOT R5, R5
		ADD R5, R5, #1
		ADD R6, R4, R5


		; Output the result
		BRn RES_IS_NEG
		BRp RES_PZ
		BRz RES_PZ


	RES_IS_NEG
		; If the answer is negative convert it to positive
		NOT R6, R6
		ADD R6, R6, #1


		; Change that result to ASCII
		LD R1, ASCII_CONST
		ADD R6, R6, R1


		; Output the result
			; First number (in ASCII)---------
		ADD R0, R2, #0
		TRAP x21
			; Space------------
		LD R0, SPACE
		TRAP x21
			; Minus------------
		LD R0, MINUS
		TRAP x21
			; Space------------
		LD R0, SPACE
		TRAP x21
			; Second Number (in ASCII)--------
		ADD R0, R3, #0
		TRAP x21
			; Space------------
		LD R0, SPACE
		TRAP x21
			; Equals------------
		LD R0, EQUALS
		TRAP x21
			; Space------------
		LD R0, SPACE
		TRAP x21
			; Output a negative----------
		LD R0, MINUS
		TRAP x21
			; Resulting number---------
		ADD R0, R6, #0
		TRAP x21
		LD R0, NEWLINE
		TRAP x21

		HALT

	RES_PZ
		; Change that result to ASCII
		LD R1, ASCII_CONST
		ADD R6, R6, R1


		; Output the result
			; First number (in ASCII)---------
		ADD R0, R2, #0
		TRAP x21
			; Space------------
		LD R0, SPACE
		TRAP x21
			; Minus------------
		LD R0, MINUS
		TRAP x21
			; Space------------
		LD R0, SPACE
		TRAP x21
			; Second Number (in ASCII)--------
		ADD R0, R3, #0
		TRAP x21
			; Space------------
		LD R0, SPACE
		TRAP x21
			; Equals------------
		LD R0, EQUALS
		TRAP x21
			; Space------------
		LD R0, SPACE
		TRAP x21
			; Resulting number---------
		ADD R0, R6, #0
		TRAP x21
		LD R0, NEWLINE
		TRAP x21

		HALT
	;================
	; Local Data
	;================
		HALT
		; Stores the string
		PROMPT_INPUT .STRINGZ "Enter two numbers (i.e '0' ... '9')\n"
		SPACE .FILL #32
		NEWLINE .FILL #10
		MINUS .FILL #45
		ASCII_CONST .FILL #48
		ASCII_NEG_CONST .FILL #-48
		EQUALS .FILL #61
		BLANK .FILL #0

.end
; cout Enter two numbers (i.e '0' ... '9')
; echo input 1
; echo input 2
; cout input 1 - input 2 = (answer)
