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
; Store the address at the beginning of the stack
LD R1, STACK_ADDR
; Store the top pointer
ADD R2, R1, #0
; Store capacity
AND R3, R3, #0
ADD R3, R3, #5

; Test harness calls subroutine

ADD R0, R0, #1
LD R6, SUB_ADDR
JSRR R6

ADD R0,R0, #1
LD R6, SUB_ADDR
JSRR R6

ADD R0,R0, #1
LD R6, SUB_ADDR
JSRR R6

ADD R0,R0, #1
LD R6, SUB_ADDR
JSRR R6

ADD R0,R0, #1
LD R6, SUB_ADDR
JSRR R6

ADD R0,R0, #1
LD R6, SUB_ADDR
JSRR R6

HALT
	;======
	; Data
	;======
SUB_ADDR .FILL x3200
STACK_ADDR .FILL x5000

.END

;========================================================================
; Subroutine: SUB_STACK_PUSH
; Parameter (R0): The value to push onto the stack
; Parameter (R1): stack_addr: A pointer to the beginning of the stack
; Parameter (R2): top: A pointer to the next place to push the item
; Parameter (R3): capacity: The number of additional items the stack can hold
; Postcondition: The subroutine has pushed (R0) onto the stack. If an overflow
;               occurred, the subroutine has printed an overflow error message and terminated
; Return Value: R2 <- updated top value
;               R3 <- updated capacity value
.ORIG x3200
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_3200
ST R1, BACKUP_R1_3200
ST R4, BACKUP_R4_3200
ST R5, BACKUP_R5_3200
ST R6, BACKUP_R6_3200
ST R7, BACKUP_R7_3200
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_1

; Check capacity
ADD R3, R3, #0

; If zero then go to overflow
BRz OVERFLOW

; Else add the number to wherever top is
STR R0, R2, #0

; Increment top
ADD R2, R2, #1

; Decrement capacity
ADD R3, R3, #-1


BR END_SUB_1    ; Skip if not overflow
OVERFLOW
    LEA R0, OVERFLOW_MSG
    TRAP x22

END_SUB_1
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_3200
LD R1, BACKUP_R1_3200
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
BACKUP_R0_3200  .BLKW   #1
BACKUP_R1_3200  .BLKW   #1
BACKUP_R4_3200  .BLKW   #1
BACKUP_R5_3200  .BLKW   #1
BACKUP_R6_3200  .BLKW   #1
BACKUP_R7_3200  .BLKW   #1
OVERFLOW_MSG .STRINGZ "ERROR: OVERFLOW\n"
