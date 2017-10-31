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
; Test harness is just calling the subroutine
LD R6, SUB_PRINT_OPCODES
JSRR R6

HALT
	;======
	; Data
	;======
SUB_PRINT_OPCODES .FILL x3200
.END
;========================================================================
; Subroutine: SUB_PRINT_OPCODES_3200
; Parameter: None
; Postcondition: The subroutine has printed out a list of every LC3 instruction
;		and corresponding opcode in the following format:
;		ADD = 0001
;		AND = 0101
;		BR = 0000
; Return Value: None
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
ST R6, BACKUP_R6_3200
ST R7, BACKUP_R7_3200
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_1
; Make sure the data block contains an array of decimal values representing LC3 opcodes
; Also make sure the data block containts one representing LC3 instructions

; Preparation
LD R4, NAMES_PTR 	; Load a pointer to the first array (an array of names)
LD R5, CODES_PTR	; Load a pointer to the second array (an array of codes)

; Output loop
OUTPUT_LOOP
	NAME_LOOP 	; Loop to output names
		LDR R0, R4, #0	; R0 <-- mem[R4]

		; Checks
		BRz END_NAME_LOOP	; Check if the value brought in was 0
		ADD R6, R0, #1	; Check if the value brought in was -1
		BRz END_SUB_1 	; If it was end, else continue

		; It's safe to output now
		TRAP x21

		; Increment pointer
		ADD R4, R4, #1
		
		; Continue looping
		BR NAME_LOOP	; If it got here then its supposed to continue
	END_NAME_LOOP

	; Output "the middle part" (the bracketed part) ADD[ = ]0001
	LD R0, MID_PTR
	TRAP x22
	
	; Prep the subroutine
	LDR R3, R5, #0

	; Call other subroutine
	LD R6, SUB_OUTPUT_STR_R3
	JSRR R6
	
	; Increment pointers
	ADD R5, R5, #1
	ADD R4, R4, #1

	; Output a space
	LD R0, D_10
	TRAP x21
	
	; If it's here then continue
	BR OUTPUT_LOOP

END_OUTPUT_LOOP
; End output loop

END_SUB_1
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_3200
LD R1, BACKUP_R1_3200
LD R2, BACKUP_R2_3200
LD R3, BACKUP_R3_3200
LD R4, BACKUP_R4_3200
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
BACKUP_R4_3200  .BLKW   #1
BACKUP_R6_3200  .BLKW   #1
BACKUP_R7_3200  .BLKW   #1
NAMES_PTR .FILL x4000
CODES_PTR .FILL x5000
D_0 .FILL #0
MID_PTR .FILL x3900
SUB_OUTPUT_STR_R3 .FILL x3400
D_10 .FILL #10

;========================================================================
; Subroutine: SUB_PRINT_BINARY_3400
; Parameter: (R5) The address of a dec to turn into binary
; Postcondition: The subroutine has taken the va
; Return Value: None
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
SUB_2

; Take the decimal value
LDR R1, R5, #0

LD R6, DEC_10
ADD R6, R6, #2
; Get rid of the 12 leading digits (multiply by 2 12 times)
MULT_LOOP
	ADD R1, R1, R1
	ADD R6, R6, #-1
	BRp MULT_LOOP
END_MULT_LOOP

; Load counter with 4
LD R5, DEC_10
ADD R5, R5, #-6

; Begin loop
LEAST_SIG_LOOP
	; AND the mask with R1
	LD R6, MASK
	AND R6, R6, R1

	; If zero continue, else skip and output one
	BRnp OUTPUT_ONE
	LD R0, DEC_48
	TRAP x21
	BR STOP_OUTPUTTING

	OUTPUT_ONE
	LD R0, DEC_49
	TRAP x21
	
	STOP_OUTPUTTING
	; Multiply by two
	ADD R1, R1, R1

	; Decrement counter
	ADD R5, R5, #-1

	; Loop
	BRp LEAST_SIG_LOOP
; End loop
END_LEAST_SIG_LOOP

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

Convert_addr    .FILL 	x5000	            ; The address of where to find the data
MASK		.FILL	x8000	; Mask to test if the leading number is positive or negative
DEC_48		.FILL	#48	; ASCII zero
DEC_49		.FILL	#49	; ASCII one
DEC_32		.FILL	#32	; ASCII space
DEC_10		.FILL	#10	; ASCII newline


; "Middle part"
.ORIG x3900
MID .STRINGZ " = "

; Array of strings of names of opcodes
.ORIG x4000
ADD_NAME .STRINGZ "ADD"
AND_NAME .STRINGZ "AND"
BR_NAME .STRINGZ "BR"
JMP_NAME .STRINGZ "JMP"
JSR_NAME .STRINGZ "JSR"
JSRR_NAME .STRINGZ "JSRR"
LD_NAME .STRINGZ "LD"
LDI_NAME .STRINGZ "LDI"
LDR_NAME .STRINGZ "LDR"
LEA_NAME .STRINGZ "LEA"
NOT_NAME .STRINGZ "NOT"
RET_NAME .STRINGZ "RET"
RTI_NAME .STRINGZ "RTI"
ST_NAME .STRINGZ "ST"
STI_NAME .STRINGZ "STI"
STR_NAME .STRINGZ "STR"
TRAP_NAME .STRINGZ "TRAP"
;RESERVED_NAME .STRINGZ "reserved"
END .FILL #-1


; Array of opcodes
.ORIG x5000
ADD_OP .FILL #1
AND_OP .FILL #5
BR_OP .FILL #0
JMP_OP .FILL #12
JSR_OP .FILL #4
JSRR_OP .FILL #1
LD_OP .FILL #2
LDI_OP .FILL #10
LDR_OP .FILL #6
LEA_OP .FILL #14
NOT_OP .FILL #9
RET_OP .FILL #12
RTI_OP .FILL #8
ST_OP .FILL #3
STI_OP .FILL #11
STR_OP .FILL #7
TRAP_OP .FILL #15
;RESERVED_OP .FILL #13

; ***************** QUESTION: Do I use reserved? Are my arrays right? *****************