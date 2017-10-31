;=================================================
; Name: <Tran, Kevin>
; Username: ktran050
;
; SID: 861172609
; Assignment name: <lab 7>
; Lab section: 23
; TA: Jose Rodriguez
;
; I hereby certify that I have not received 
; assistance on this assignment, or used code
; from ANY outside source other than the
; instruction team. 
;=================================================
.ORIG x3000
	;==============
	; Instructions
	;==============
; R0 <- Some address at which to store the array
LD R0, TEST_ADDR

; Call SUB_GET_STRING
LD R6, SUB_GET_STRING
JSRR R6 

; Call SUB_IS_A_PALINDROME
LD R6, SUB_IS_A_PALINDROMEs
JSRR R6

; Depending on the return of R4
ADD R4, R4, #0
BRp ITS_P
BRNZ ITS_NZ

ITS_P
	LD R0, PALIN_PTR
	TRAP x22
BR STOP
ITS_NZ
	LD R0, N_PALIN_PTR
	TRAP x22
STOP
HALT
	;======
	; Data
	;======
SUB_IS_A_PALINDROME .FILL x3200
SUB_GET_STRING .FILL x3400
PALIN_PTR .FILL x6200
N_PALIN_PTR .FILL x6300
TEST_ADDR .FILL x5000
.END
;========================================================================
; Subroutine: SUB_IS_A_PALINDROME_3200
; Parameter: R0(The address of the string)
; Postcondition: Determine whether the string at Ro is a palindrome or not and return a flag
; Return Value: R4 {1 if the string is a palindrome, 0 otherwise}
.orig x3200
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_3200
ST R1, BACKUP_R1_3200
ST R2, BACKUP_R2_3200
ST R3, BACKUP_R3_3200
ST R5, BACKUP_R5_3200
ST R6, BACKUP_R6_3200
ST R7, BACKUP_R7_3200
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
; Clear R4
LD R4, DEC_1
; Check how long the string is
	; Loop through the string
	; Have a counter if not 0

; LOOP
COMPARE_LOOP
; Compare current pointer and its foil
	
; If it matches then continue
	BRz CONTINUE_LOOP

; Else decrement R4
	ADD R4, R4, #-1

; Increment pointer
	CONTINUE_LOOP
	ADD R0, R0, #1

; Loop again
	BR COMPARE_LOOP

; END_LOOP
END_COMPARE_LOOP

;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_3200
LD R1, BACKUP_R1_3200
LD R2, BACKUP_R2_3200
LD R3, BACKUP_R3_3200
LD R5, BACKUP_R5_3200
LD R6, BACKUP_R6_3200
LD R7, BACKUP_R7_3200
;(4) Return to where you came from
RET
;===============================
; Subroutine Data
;===============================
; Backups
BACKUP_R0_3200  .BLKW   #1
BACKUP_R1_3200  .BLKW   #1
BACKUP_R2_3200  .BLKW   #1
BACKUP_R3_3200  .BLKW   #1
BACKUP_R5_3200  .BLKW   #1
BACKUP_R6_3200  .BLKW   #1
BACKUP_R7_3200  .BLKW   #1

DEC_1 .FILL #1

;========================================================================
; Subroutine: SUB_GET_STRING_3400
; Parameter: R0(The address of where to start storing the string
; Postcondition: The subroutine has had the user input a string terminated by the [ENTER] key and stores
;		the string in an array that starts at R0 and is NULL terminated
; Return Value: R5(The number of non-sentinel characters read from the user)
.ORIG x3400
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

; Copy R0 to R1
ADD R1, R0, #0

; Prompt user
LD R0, PROMPT_PTR
TRAP x22


LD R5, D_0
; While input != enter
WHILE_NOT_ENTER
; Take user input
	TRAP x20

; Echo user input
	TRAP x21

; If input is enter then end
	LD R6, D_0	; R6 <-- m[D_0]
	ADD R6, R6, #-10; R6 <-- R6 - 10 (Effectively R6 <-- #-10)
	ADD R6, R6, R0	; R6 <-- R6 + R0
	BRz END_WHILE_NOT_ENTER

; Save the value to address at R1
	STR R0, R1, #0

; Increment R1
	ADD R1, R1, #1

; Increment R5
	ADD R5, R5, #1

; Loop
	BR WHILE_NOT_ENTER

; End while
END_WHILE_NOT_ENTER

; Add #0 to the end of the string
	; Increment the pointer
ADD R1, R1, #1
	; Store #0
LD R6, D_0	; R6 <-- m[D_0]
STR R6, R1, #0

; R5 holds a counter for the number of non-sentinel characters entered in R5
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

PROMPT_PTR .FILL x6100
D_0 .FILL #0

.ORIG x6100
; Prompt for user input
PROMPT .STRINGZ "Enter a string terminated by the [ENTER] key\n"

.ORIG x6200
; Tell user it was a palindrome
PALIN .STRINGZ "It was a palindrome!\n"

.ORIG x6300
; Tell user it wasn't a palindrome
N_PALIN .STRINGZ "It wasn't palindrome\n"