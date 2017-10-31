;=================================================
; Name: Tran, Kevin
; Username: ktran050
;
; Lab: Lab 5
; Lab Section: 23
; TA: Jose Rodriguez
;=================================================
.ORIG x3000
;================
; Instructions
;================

HALT
;=============
; Local Data
;=============
DEC_16  .FILL   #16
MASK    .FILL   x8000
.END
;========================================================================
; Subroutine: SUB_CONVERT_TO_BINARY_3200
; Parameter: R2
; Postcondition: Take DEC or HEX from R2 and convert to binary and output it to R1
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
; Print R2 into 16 bit binary
; Isolate leading bit
; Output that bit
; Double R2
; Keep going
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