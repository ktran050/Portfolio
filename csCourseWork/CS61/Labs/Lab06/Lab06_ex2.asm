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
; Prompt user and take one input
LEA R0, PROMPT  ; Prompt user
TRAP x22    ; Output prompt
TRAP x20    ; Take the character
TRAP x21    ; Echo
ADD R3, R0, #0  ; Move R0 to R3 to output newline

LD R0, DEC_10
TRAP x21    ; Output a newline

ADD R0, R3, #0  ; Move R0 back

; Load the subroutine
LD R6, SUB_ONES_COUNT  ; Load the pointer
JSRR R6     ; Load the subroutine

; Print the number of ones
LEA R0, OUTPUT_RESULTS_STRING   ; Load result string
TRAP x22    ; Output string
LD R6, DEC_48     ; R6 <-- ASCII modifier
ADD R0, R1, R6  ; Turn our counter into an ASCII and put it in R0
TRAP x21    ; Output it

LD R0, DEC_10
TRAP x21    ; Output a newline

HALT
;=============
; Local Data
;=============
SUB_ONES_COUNT  .FILL x3200
PROMPT   .STRINGZ    "Input a single character\n"
OUTPUT_RESULTS_STRING   .STRINGZ    "The number of one's in that character's binary is: "
DEC_48  .FILL   #48
DEC_10  .FILL   #10
.END
;========================================================================
; Subroutine: SUB_ONES_COUNT_3200
; Parameter: R0
; Postcondition: Take the character from R0 and find its ones and return to R1
; Return Value: R1 holds a DEC counter of the number of ones


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
; "Return the number of ones in the character"
; While the number isn't all zeroes
; AND MASK and R0
; If its one then increment the counter
LD R1, DEC_0    ; Clear the counter just in case

ADD R0, R0, #0  ; Check R0
BRz SKIP_TO_END ; If R0 already has zero then there's no ones to output

LD R5, MASK
WHILE_R0_!ZERO
    AND R6, R5, R0  ; Take the leading bit
    BRn LEAD_POS           ; If it's one add it
    BR CONTINUE     ; Else continue
    LEAD_POS
        ADD R1, R1, #1  ; Increment our counter
    END_LEAD_POS
    CONTINUE
    ADD R0, R0, R0  ; Double the R0 to get rid of the leading bit
    BRnp WHILE_R0_!ZERO
END_WHILE_R0_!ZERO

;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_3200
LD R2, BACKUP_R2_3200
LD R3, BACKUP_R3_3200
LD R4, BACKUP_R4_3200
LD R5, BACKUP_R5_3200
LD R6, BACKUP_R6_3200
LD R7, BACKUP_R7_3200
;(4) Return to where you came from
SKIP_TO_END
RET
;===============================
; Subroutine Data
;===============================
BACKUP_R0_3200  .BLKW   #1
BACKUP_R1_3200  .BLKW   #1
BACKUP_R2_3200  .BLKW   #1
BACKUP_R3_3200  .BLKW   #1
BACKUP_R4_3200  .BLKW   #1
BACKUP_R5_3200  .BLKW   #1
BACKUP_R6_3200  .BLKW   #1
BACKUP_R7_3200  .BLKW   #1
DEC_0   .FILL   #0
MASK .FILL x8000
