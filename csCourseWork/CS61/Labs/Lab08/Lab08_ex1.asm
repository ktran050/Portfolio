;=================================================
; Name: <Tran, Kevin>
; Username: ktran050
;
; SID: 861172609
; Assignment name: <lab 8>
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
; Test harness
; 1) R0 <-- Some address to store the user-inputted string
LD R0, SOME_ADDR

; 2) Call SUB_TO_UPPER subroutine
LD R6, SUB_TO_UPPER
JSRR R6

; 3) Print out the string(which should now be upper case)
TRAP x22
LD R0, D_10
TRAP x21

HALT
	;======
	; Data
	;======
SUB_TO_UPPER .FILL x3200
SOME_ADDR .FILL x5000
D_10 .FILL #10
.END
;========================================================================
; Subroutine: SUB_TO_UPPER_3200
; Parameter: (R0) The address to store the string at
; Postcondition: The subroutine has allowed the user to input a string terminated by the [ENTER] key, has converted
;		 the string to uppercase, and has stored it in the null-terminated array that starts at (R0)
; Return Value: R0 <- The address of the now upper case string
.ORIG x3200
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_3200
ST R1, BACKUP_R1_3200
ST R2, BACKUP_R2_3200
ST R3, BACKUP_R3_3200
ST R4, BACKUP_R4_3200
ST R5, BACKUP_R5_3200
ST R6, BACKUP_R6_3200
ST R7, BACKUP_R7_3200

;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_1	; Start the algorithm
; Take in the string
	; Preparation
ADD R1, R0, #0			; Copy R0 to R1
LD R0, STRING_PTR		; Load prompt
TRAP x22 				; Output prompt
LD R0, D_0 				; Clear R0
LD R5, D_0 				; Clear R5

	; While R0 isn't [ENTER], check by comparing it to -10 (-10 is loaded into R6)
WHILE_INPUT ; Take in the string and convert it
	; Take in an input and echo
	TRAP x20				; Take input
	TRAP x21				; Echo

	; Check if it was enter
	LD R6, D_N_10			; Load D_N_6
	ADD R6, R0, R6			; R6 <-- (R0) + (R6)
	BRz END_SUB_1			; If it was enter end, else continue

	; Convert the string to uppercase (AND R0 with xFFDF or R6)
	LD R6, MASK				; Load xFFDF
	AND R0, R6, R0			; R0 <-- NOT(R0, R6) convert to uppercase and put in R0
	
	; Store the string and loop
	ADD R6, R5, R1			; R6 <-- R1 + R5 (counter)
	STR	R0, R6, #0			; Save data to R1 plus offset
	ADD R5, R5, #1			; Increment counter
	BR WHILE_INPUT			; Loop

END_WHILE_INPUT_LOOP

END_SUB_1	; End the algorithm
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_3200
LD R1, BACKUP_R1_3200
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
; Backups
BACKUP_R0_3200	.BLKW	#1
BACKUP_R1_3200  .BLKW   #1
BACKUP_R2_3200  .BLKW   #1
BACKUP_R3_3200  .BLKW   #1
BACKUP_R4_3200  .BLKW   #1
BACKUP_R5_3200  .BLKW   #1
BACKUP_R6_3200  .BLKW   #1
BACKUP_R7_3200  .BLKW   #1
STRING_PTR .FILL x6000
D_0 .FILL #0
D_N_10 .FILL #-10
MASK .FILL xFFDF

; Prompt for input
.ORIG x6000
PROMPT .STRINGZ "Enter input terminated by the [ENTER] key\n"
