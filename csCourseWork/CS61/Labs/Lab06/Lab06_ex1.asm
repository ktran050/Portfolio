;=================================================
; Name: Tran, Kevin
; Username: ktran050
;
; Lab: Lab 6
; Lab Section: 23
; TA: Jose Rodriguez
;=================================================
.ORIG x3000
;================
; Instructions
;================
LD R6, SUB_CONVERT_TO_BINARY  ; Load the pointer
JSRR R6				; Now the program has the user's input in R1
ADD R1, R1, #1			; R1 <-- R1 + 1

LD R6, SUB_CONVERT_BINARY_TO_DEC    ; Load the pointer
JSRR R6             ; Load the subroutine

HALT
;=============
; Local Data
;=============
SUB_CONVERT_TO_BINARY .FILL x3200
SUB_CONVERT_BINARY_TO_DEC   .FILL   x3400
.END
;========================================================================
; Subroutine: SUB_CONVERT_TO_BINARY_3200
; Parameter: None
; Postcondition: Take DEC or HEX from user and convert to binary and output it to R1
; Return Value: R1 will have the binary representation of the number given


.orig x3200
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_3200
ST R2, BACKUP_R2_3200
ST R3, BACKUP_R3_3200
ST R4, BACKUP_R4_3200
ST R5, BACKUP_R5_3200
ST R6, BACKUP_R6_3200
ST R7, BACKUP_R7_3200
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
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
BR FIN_SUB_1
TWO_COMP
	NOT R1, R1	; R1 <-- not[R1]
	ADD R1, R1, #1	; Add 1
END_TWO_COMP
BR FIN_SUB_1
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
FIN_SUB_1
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_3200
LD R2, BACKUP_R2_3200
LD R3, BACKUP_R3_3200
LD R4, BACKUP_R4_3200
LD R5, BACKUP_R5_3200
LD R6, BACKUP_R6_3200
LD R7, BACKUP_R7_3200
;(4) Return to where you came from
RET
;===============================
; Subroutine Data
;===============================
BACKUP_R0_3200  .BLKW   #1
BACKUP_R2_3200  .BLKW   #1
BACKUP_R3_3200  .BLKW   #1
BACKUP_R4_3200  .BLKW   #1
BACKUP_R5_3200  .BLKW   #1
BACKUP_R6_3200  .BLKW   #1
BACKUP_R7_3200  .BLKW   #1

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

;========================================================================
; Subroutine: SUB_CONVERT_BINARY_TO_DEC_3400
; Parameter: R1
; Postcondition: Take the DEC from R1 and convert to ASCII and output it to user
; Return Value: No return value


.orig x3400
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_3400
ST R1, BACKUP_R1_3400
ST R2, BACKUP_R2_3400
ST R3, BACKUP_R3_3400
ST R4, BACKUP_R4_3400
ST R5, BACKUP_R5_3400
ST R6, BACKUP_R6_3400
ST R7, BACKUP_R7_3400
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
LD R0, DEC_ZERO
LD R2, DEC_ZERO
LD R3, DEC_ZERO
LD R4, DEC_ZERO ; Clear unneeded registersexcept 7 (just in case)
LD R5, DEC_ZERO
LD R6, DEC_ZERO

ADD R1, R1, #0  ; Check R1
BRz R1_EMPTY

LD R6, NEG_10k  ; Test which loop we need to go to
ADD R6, R1, R6
BRp LOOP10k

LD R6, NEG_1k
ADD R6, R1, R6
BRp LOOP1k

LD R6, NEG_100
ADD R6, R1, R6
BRp LOOP100

LD R6, NEG_10
ADD R6, R1, R6
BRp LOOP10

; If it gets here then the number is single digit and thus can be converted and shipped out right away
ADD R0, R1, #0  ; Move the single digit to R0
LD R6, DEC_48   ; R6 <-- ASCII Modifier
ADD R0, R6, R0  ; Convert R0 to ASCII #
TRAP x21
BR END_SUB_2

; Looping starts here
;   R2 is only cleared in between loops and only if a loop has been called before it
; Loop for 10k
LD R2, DEC_ZERO ; Reset R2
LOOP10k
    LD R6, NEG_10k  ; Load -10 000
    ADD R1, R1, R6  ; Add that to R1 and store in R1
    BRnz END_LOOP10k   ; If the number isn't positive end the loop
    ADD R2, R2, #1  ; Increment R2
    BR LOOP10k
END_LOOP10k
LD R6, DEC_48   ; R6 <-- ASCII Modifier
ADD R0, R2, R6  ; Convert that number to ASCII
TRAP x21    ; Output it

; Loop for 1k
LD R2, DEC_ZERO ; Reset R2
LOOP1k
    LD R6, NEG_1k  ; Load -10 000
    ADD R6, R1, R6  ; Add that to R1 and store in R6
    BRnz END_LOOP1k   ; If the number isn't positive end the loop
    ADD R2, R2, #1  ; Increment R2
    BR LOOP1k
END_LOOP1k
LD R6, DEC_48   ; R6 <-- ASCII Modifier
ADD R0, R2, R6  ; Convert that number to ASCII
TRAP x21    ; Output it

; Loop for 100
LD R2, DEC_ZERO ; Reset R2
LOOP100
    LD R6, NEG_100  ; Load -10 000
    ADD R6, R1, R6  ; Add that to R1 and store in R6
    BRnz END_LOOP100   ; If the number isn't positive end the loop
    ADD R2, R2, #1  ; Increment R2
    BR LOOP100
END_LOOP100
LD R6, DEC_48   ; R6 <-- ASCII Modifier
ADD R0, R2, R6  ; Convert that number to ASCII
TRAP x21    ; Output it

; Loop for 10
LD R2, DEC_ZERO ; Reset R2
LOOP10
    LD R6, NEG_10  ; Load -10 000
    ADD R6, R1, R6  ; Add that to R1 and store in R6
    BRnz END_LOOP10   ; If the number isn't positive end the loop
    ADD R2, R2, #1  ; Increment R2
    BR LOOP10
END_LOOP10
LD R6, DEC_48   ; R6 <-- ASCII Modifier
ADD R0, R2, R6  ; Convert that number to ASCII
TRAP x21    ; Output it


BR END_SUB_2
R1_EMPTY
    LD R0, DEC_48
    TRAP x21
END_R1_EMPTY
END_SUB_2
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_3400
LD R1, BACKUP_R1_3400
LD R2, BACKUP_R2_3400
LD R3, BACKUP_R3_3400
LD R4, BACKUP_R4_3400
LD R5, BACKUP_R5_3400
LD R6, BACKUP_R6_3400
LD R7, BACKUP_R7_3400
;(4) Return to where you came from
RET
;===============================
; Subroutine Data
;===============================
; Backups
BACKUP_R0_3400  .BLKW   #1
BACKUP_R1_3400  .BLKW   #1
BACKUP_R2_3400  .BLKW   #1
BACKUP_R3_3400  .BLKW   #1
BACKUP_R4_3400  .BLKW   #1
BACKUP_R5_3400  .BLKW   #1
BACKUP_R6_3400  .BLKW   #1
BACKUP_R7_3400  .BLKW   #1

; Everything else
DEC_48  .FILL   #48
DEC_ZERO    .FILL #0

; Negative powers of 10
NEG_10k .FILL -0x2710
NEG_1k .FILL -0x03E8
NEG_100 .FILL -0x0064
NEG_10 .FILL -0xA
