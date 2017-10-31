;========================================================================
; Subroutine: SUB_OUTPUT_STR_R3_4400
; Parameter: R3
; Postcondition: The DEC value in R3 is output to the user
; Return Value: Nothing is returned
.orig x4400
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_4400
ST R1, BACKUP_R1_4400
ST R2, BACKUP_R2_4400
ST R3, BACKUP_R3_4400
ST R4, BACKUP_R4_4400
ST R5, BACKUP_R5_4400
ST R6, BACKUP_R6_4400
ST R7, BACKUP_R7_4400
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
LD R0, DEC_ZERO
LD R1, DEC_ZERO
LD R2, DEC_ZERO ; Clear unneeded registers except 7 (just in case)
LD R5, DEC_ZERO
LD R6, DEC_ZERO

ADD R3, R3, #0  ; Check R3
BRz R3_EMPTY
BRn R3_NEG
BRp R3_POS

; R3 was negative
R3_NEG
	; Move R0 to R1 temporarily
	ADD R1, R0, #0

	; Load a minus and output it
	LD R0, A_MINUS
	TRAP x21

	; Twos complement R3
	NOT R3, R3
	ADD R3, R3, #1

	; Move R0 back
	ADD R0, R1, #0

	; Go to loop check
	BR LOOP_CHECK
END_R3_NEG

R3_POS
	; Move R0 to R1 temporarily
	ADD R1, R0, #0

	; Load a plus and output it
	LD R0, A_PLUS
	TRAP x21

	; Move R0 back
	ADD R0, R1, #0

	; Go to loop check
END_R3_POS


LOOP_CHECK
ADD R4, R3, #0 
LD R6, NEG_10k  ; Test which loop we need to go to
ADD R6, R3, R6
BRzp LOOP10k

LD R6, NEG_1k
ADD R6, R3, R6
BRzp LOOP1k

LD R6, NEG_100
ADD R6, R3, R6
BRzp LOOP100

LD R6, NEG_10
ADD R6, R3, R6
BRzp LOOP10

; If it gets here then the number is single digit and thus can be converted and shipped out right away
ADD R0, R3, #0  ; Move the single digit to R0
LD R6, DEC_48   ; R6 <-- ASCII Modifier
ADD R0, R6, R0  ; Convert R0 to ASCII #
TRAP x21
BR END_SUB_6

; Looping starts here
;   R2 is only cleared in between loops and only if a loop has been called before it
; Loop for 10k
LD R2, DEC_ZERO ; Reset R2
LOOP10k
    LD R6, NEG_10k  ; Load -10 000
    ADD R6, R4, R6  ; Add that to R4 and store in R6
    BRn END_LOOP10k   ; If the number isn't positive end the loop
	ADD R4, R6, #0	; Only update R4 if R6 is positive
    ADD R2, R2, #1  ; Increment R2
    BR LOOP10k
END_LOOP10k
LD R6, DEC_48   ; R6 <-- ASCII Modifier
ADD R0, R2, R6  ; Convert that number to ASCII
TRAP x21    ; Output it

; Loop for 1k
LD R2, DEC_ZERO ; Reset R2
LOOP1k
    LD R6, NEG_1k  ; Load -10 00
    ADD R6, R4, R6  ; Add that to R4 and store in R6
    BRn END_LOOP1k   ; If the number isn't positive end the loop
	ADD R4, R6, #0	; Only update R4 if R6 is positive
    ADD R2, R2, #1  ; Increment R2
    BR LOOP1k
END_LOOP1k
LD R6, DEC_48   ; R6 <-- ASCII Modifier
ADD R0, R2, R6  ; Convert that number to ASCII
TRAP x21    ; Output it

; Loop for 100
LD R2, DEC_ZERO ; Reset R2
LOOP100
    LD R6, NEG_100  ; Load -100
    ADD R6, R4, R6  ; Add that to R4 and store in R6
    BRn END_LOOP100   ; If the number isn't positive end the loop
	ADD R4, R6, #0	; Only update R4 if R6 is positive
    ADD R2, R2, #1  ; Increment R2
    BR LOOP100
END_LOOP100
LD R6, DEC_48   ; R6 <-- ASCII Modifier
ADD R0, R2, R6  ; Convert that number to ASCII
TRAP x21    ; Output it

; Loop for 10
LD R2, DEC_ZERO ; Reset R2
LOOP10
    LD R6, NEG_10  ; Load -10
    ADD R6, R4, R6  ; Add that to R4 and store in R6
    BRn END_LOOP10   ; If the number isn't positive end the loop
	ADD R4, R6, #0	; Only update R4 if R6 is positive
    ADD R2, R2, #1  ; Increment R2
    BR LOOP10
END_LOOP10
LD R6, DEC_48   ; R6 <-- ASCII Modifier
ADD R0, R2, R6  ; Convert that number to ASCII
TRAP x21    ; Output it

; Whatever is left is a single digit
LD R0, DEC_48
ADD R0, R4, R0
TRAP x21


BR END_SUB_6
R3_EMPTY
    LD R0, DEC_48
    TRAP x21
END_R3_EMPTY
END_SUB_6
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_4400
LD R1, BACKUP_R1_4400
LD R2, BACKUP_R2_4400
LD R3, BACKUP_R3_4400
LD R4, BACKUP_R4_4400
LD R5, BACKUP_R5_4400
LD R6, BACKUP_R6_4400
LD R7, BACKUP_R7_4400
;(4) Return to where you came from
RET
;===============================
; Subroutine Data
;===============================
; Backups
BACKUP_R0_4400  .BLKW   #1
BACKUP_R1_4400  .BLKW   #1
BACKUP_R2_4400  .BLKW   #1
BACKUP_R3_4400  .BLKW   #1
BACKUP_R4_4400  .BLKW   #1
BACKUP_R5_4400  .BLKW   #1
BACKUP_R6_4400  .BLKW   #1
BACKUP_R7_4400  .BLKW   #1

; Everything else
DEC_48  .FILL   #48
DEC_ZERO    .FILL #0
A_MINUS	.FILL '-'
A_PLUS .FILL '+'

; Negative powers of 10
NEG_10k .FILL #-10000
NEG_1k .FILL #-1000
NEG_100 .FILL #-100
NEG_10 .FILL #-10