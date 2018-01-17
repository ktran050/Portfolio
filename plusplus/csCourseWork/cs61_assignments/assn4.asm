;=================================================
; 
; Name: <Tran, Kevin>
; Username: ktran050
;
; SID: 861172609
; Assignment name: <assn 4>
; Lab section: 23
; TA: Jose Rodriguez
;
; I hereby certify that I have not received 
; assistance on this assignment, or used code
; from ANY outside source other than the
; instruction team. 
;
;=================================================
.ORIG x3000
	;==============
	; Instructions
	;==============
END
LD R0, DEC_0	;
LD R1, DEC_0	;
LD R2, DEC_0	;
LD R3, DEC_0	;
LD R4, DEC_5	; Counter for max number of digits inputted
LD R5, DEC_0	;
LD R6, DEC_0	;

; ======================= Step 1 =========================
; Prompt user
LD R0, PROMPT_PTR		; R0 <-- Prompt
TRAP x22			; user <-- R0

; ======================= Step 2 =========================
; Take input for the first char
TRAP x20	; Take character of input

; ======================= Step 3 =========================
; Echo the input
TRAP x21	; Echo

; ======================= Step 4 =========================
; Check if the char is valid and if valid do something depending on if its a sign or a number
LD R6, DEC_NEG_45	; R6 <-- #-45
ADD R6, R0, R6		; R6 <-- R0 + R6
ADD R6, R6, #0
BRz SAVE_SIGN		; If R0 was 45 this would be zero, meaning user inputted a negative number

LD R6, DEC_NEG_43	; R6 <-- #-43
ADD R6, R0, R6		; R6 <-- R0 - 43
BRz SAVE_SIGN	; If the result is zero then input was plus

LD R6, DEC_NEG_48
ADD R6, R0, R6		; R6 <-- R0 - 48
BRn INVALID_INPUT_ERROR	; R6 < 0 (less than ASCII 0)

LD R6, DEC_NEG_57	; R6 <-- R0 - 57
ADD R6, R0, R6
BRp INVALID_INPUT_ERROR	; R6 > 0 (more than ASCII 9)

LD R6, DEC_NEG_48	; R6 <-- #-48
ADD R1, R0, R6		; Turn the ASCII into DEC and add it to R1
ADD R4, R4, #-1		; Decrement digit counter

END_CHAR_CHECK_1

; ======================= Step 5 =========================
; Check the second character
TRAP x20		; Take input
TRAP x21		; Echo
ADD R6, R0, #-10	; R6 <-- R0 - 10
BRz SECOND_CHAR_CHECK	; If R0 is 10

LD R6, DEC_NEG_48	; R6 <-- #-48
ADD R6, R0, R6		; R6 <-- R0 + R6
BRn INVALID_INPUT_ERROR	; If the value is less than 0 then input was invalid

LD R6, DEC_NEG_57	; R6 <-- #-57
ADD R6, R0, R6		; R6 <-- R0 + R6
BRp INVALID_INPUT_ERROR	; If the value was more than 0 then input was invalid

ADD R6, R1, R1		; R6 <-- 2xR1 (R1 has 1R1; R6 has 2R1)
ADD R6, R6, R6		; R6 <-- 2xR6 (R6 has 4R1)
ADD R6, R6, R1		; R6 <-- R6 + R1 (R6 has 5R1)
ADD R1, R6, R6		; R1 <-- 2xR6 (R1 has 10x R1)

LD R6, DEC_NEG_48	; R6 <-- #-48
ADD R0, R0, R6		; Turn the ASCII into DEC
ADD R1, R0, R1		; R1 <-- R0 + R1
ADD R4, R4, #-1		; Decrement digit counter

BR CONTINUE		; Skip second char check

SECOND_CHAR_CHECK	
	ADD R5, R5, #0	; Check R5
	BRp INVALID_INPUT_ERROR ; If there's a sign then it means the enter was invalid
	HALT		; End if its a valid enter
END_SECOND_CHAR_CHECK

CONTINUE
WHILE_INPUT
	TRAP x20	; Take input
	TRAP x21	; Echo
	BR ENTER_CHECK	; Check if enter was entered
	END_ENTER_CHECK
	ADD R4, R4, #0	; Check counter
	BRz INVALID_INPUT_ERROR
	BR NUM_CHECK	; Check if a number was entered
	END_NUM_CHECK
	BR ADD_NEW_NUM	; If the program made it this far then we know we can add the new value
	END_ADD_NEW_NUM

	ADD R4, R4, #-1	; Decrement counter
	BRp WHILE_INPUT
	BRz WHILE_INPUT
END_WHILE_INPUT


ENTERED
; Check if the number is supposed to be negative
LD R6, DEC_NEG_43	; R6 <-- #-43
ADD R5, R6, R5		; R5 <-- R5 + R6
BRp TWO_COMP		; Positive if R5 contained the value of minus
TRAP x25
TWO_COMP
	NOT R1, R1	; R1 <-- not[R1]
	ADD R1, R1, #1	; Add 1
END_TWO_COMP
TRAP x25
	;=============
	; "Functions"
	;=============
SAVE_SIGN
	ADD R5, R0, #0		; Copy the sign from R0
BR END_CHAR_CHECK_1

INVALID_INPUT_ERROR
	LD R0, INVALID_PTR	; Load the invalid input error message
	TRAP x22		; Output it
BR END

ENTER_CHECK
	ADD R6, R0, #-10	; R6 <-- R0 - 10
	BRz ENTERED		; If R0 was a space then stop
BR END_ENTER_CHECK

NUM_CHECK
	LD R6, DEC_NEG_48	; R6 <-- #-48
	ADD R6, R0, R6		; R6 <-- R0 + R6
	BRn INVALID_INPUT_ERROR	; If the value is less than 0 then input was invalid

	LD R6, DEC_NEG_57	; R6 <-- #-57
	ADD R6, R0, R6		; R6 <-- R0 + R6
	BRp INVALID_INPUT_ERROR	; If the value was more than 0 then input was invalid
BR END_NUM_CHECK

ADD_NEW_NUM
	LD R6, DEC_NEG_48	; R6 <-- #-48
	ADD R0, R0, R6		; R0 <-- R0 + R6 (convert R0 to DEC)

	ADD R6, R1, R1		; R6 <-- 2xR1 (R1 has 1R1; R6 has 2R1)
	ADD R6, R6, R6		; R6 <-- 2xR6 (R6 has 4R1)
	ADD R6, R6, R1		; R6 <-- R6 + R1 (R6 has 5R1)
	ADD R1, R6, R6		; R1 <-- 2xR6 (R1 has 10x R1)
	ADD R1, R0, R1		; R1 <-- R1 + R0
BR END_ADD_NEW_NUM

	;======
	; Data
	;======
PROMPT_PTR	.FILL x6000
INVALID_PTR	.FILL x6100

DEC_0		.FILL	#0
DEC_5		.FILL	#5
DEC_43		.FILL	#43
DEC_45		.FILL	#45
DEC_NEG_43	.FILL	#-43
DEC_NEG_45	.FILL	#-45
DEC_NEG_48	.FILL	#-48
DEC_NEG_57	.FILL	#-57

.ORIG x6000
PROMPT		.STRINGZ	"Input a positive or negative decimal number (max 5 digits), followed by ENTER\n"

.ORIG x6100
INVALID_INPUT	.STRINGZ	"\nERROR INVALID INPUT\n"

.END