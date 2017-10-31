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
LD R5, DEC_16       ; R5 <-- #16
Trap x20            ; Take one input and do nothing with it
LD R6, SUB_CONVERT_FROM_BINARY  ; Load the pointer
JSSR R6             ; Call the Subroutine
HALT
;=============
; Local Data
;=============
DEC_16  .FILL   #16
SUB_CONVERT_FROM_BINARY .FILL   x3400
.END
;========================================================================
; Subroutine: SUB_CONVERT_FROM_BINARY_3400
; Parameter: R2
; Postcondition: Take DEC or HEX from R2 and convert to binary and output it to R1
; Return Value: R1 will have the binary representation of the number given


.orig x3400
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_3200
ST R2, BACKUP_R2_3200
ST R3, BACKUP_R3_3200
ST R4, BACKUP_R4_3200
ST R5, BACKUP_R5_3200   ; This holds the counter of DEC_16
ST R6, BACKUP_R6_3200
ST R7, BACKUP_R7_3200
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform

DO_WHILE_LOOP       ; Continue as long as R5 is positive
    TRAP x20            ; Take input from user
    ADD R2, R0, R2      ; Add whatever value this is (1 or 0) to R2
    ADD R2, R2, R2      ; Double R2
    ADD R5, R5, #-1     ; Decrement the counter
    BRp DO_WHILE_LOOP   ; Continue as long as R5 is positive
END_DO_WHILE_LOOP
; Save that to R2
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