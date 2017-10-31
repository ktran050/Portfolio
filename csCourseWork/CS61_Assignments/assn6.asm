;=================================================
; Name: <Tran, Kevin>
; Username: ktran050
;
; SID: 861172609
; Assignment Name: <assn 6>
; Lab Section: 23
; TA: Jose Rodriguez
;
; I hereby certify that I have not received 
; assistance on this assignment, or used code,
; from ANY outside source other than the
; instruction team. 
;
;=================================================
.ORIG x3000
;=============
;Instructions
;=============
MAIN

; Load the menu subroutine
LD R6, MENU
JSRR R6

; Do something based on the return value of MENU (R1)

; Convert R1 to DEC to simplify the checking
LD R6, ASC_N_0
ADD R1, R1, R6

OP1

; If R1 is equivalent to 1 then call ALL_MACHINES_BUSY
ADD R1, R1, #-1 ; Check R1
BRnp OP2        ; Proceed to the next Else If

LD R6, ALL_MACHINES_BUSY    ; Call the subroutine
JSRR R6

; Output depending on the return of this subroutine
ADD R2, R2, #0
BRz AMB_FALSE
BRnp AMB_TRUE

AMB_FALSE
    LEA R0, RESPONSE1_1
    TRAP x22
    BR END_OP1
AMB_TRUE
    LEA R0, RESPONSE1_2
    TRAP x22
    BR END_OP1

END_OP1
BR OP1_to_6     ; Short-Circuit
OP2             ; End if

; If R1 is equivalent to 2 then call ALL_MACHINES_FREE
ADD R1, R1, #-1 ; Check R1
BRnp OP3        ; Proceed to the next Else If

LD R6, ALL_MACHINES_FREE    ; Call the subroutine
JSRR R6

; Output depending on the return of this subroutine
ADD R2, R2, #0
BRz AMF_FALSE
BRnp AMF_TRUE

AMF_FALSE
    LEA R0, RESPONSE2_1
    TRAP x22
    BR END_OP2
AMF_TRUE
    LEA R0, RESPONSE2_2
    TRAP x22
    BR END_OP2

END_OP2
BR OP1_to_6     ; Short-Circuit
OP3             ; End If

; If R1 is equivalent to 3 then call NUM_BUSY_MACHINES
ADD R1, R1, #-1 ; Check R1
BRnp OP4        ; Proceed to the next Else If

LD R6, NUM_BUSY_MACHINES    ; Call the subroutine
JSRR R6

; Output depending on the return of this subroutine
    ; COUT: THEREARE
    LEA R0, THERE_ARE
    TRAP x22
    
    ; CHECK R2 FOR VALUES GREATER THAN 9
    AND R6, R6, #0
    ADD R6, R6, #-10
    ADD R6, R6, R2
    BRzp NBM_10
    
    ; COUT NUM_MACHINES(R2) *CONVERT FROM DEC TO ASCII*
    LD R6, ASC_0
    ADD R0, R2, R6
    TRAP x21
    BR SKIP_NBM_10
    
    ; NUMBER WAS GREATER THAN 10 SO OUTPUT IS A BIT DIFFERENT
    NBM_10
    
    LD R6, ASC_1
    TRAP x21
    
    ADD R0, R6, #0
    TRAP x21
    
    SKIP_NBM_10
    ; COUT: BUSY_MACH
    LEA R0, BUSY_MACH
    TRAP x22

END_OP3
BR OP1_to_6     ; Short-Circuit
OP4             ; End If

; If R1 is equivalent to 4 then call NUM_FREE_MACHINES
ADD R1, R1, #-1 ; Check R1
BRnp OP5        ; Proceed to the next Else If

LD R6, NUM_FREE_MACHINES    ; Call the subroutine
JSRR R6

; Output depending on the return of this subroutine
    ; COUT: THEREARE
    LEA R0, THERE_ARE
    TRAP x22
    
    ; CHECK R2 FOR VALUES GREATER THAN 9
    AND R6, R6, #0
    ADD R6, R6, #-10
    ADD R6, R6, R2
    BRzp NFM_10
    
    ; COUT NUM_MACHINES(R2) *CONVERT FROM DEC TO ASCII*
    LD R6, ASC_0
    ADD R0, R2, R6
    TRAP x21
    BR SKIP_NFM_10
    
    ; NUMBER WAS GREATER THAN 10 SO OUTPUT IS A BIT DIFFERENT
    NFM_10
    
    LD R0, ASC_1
    TRAP x21
    LD R5, ASC_0
    ADD R0, R5, R6
    TRAP x21
    
    SKIP_NFM_10
    ; COUT: FREE_MACH
    LEA R0, FREE_MACH
    TRAP x22

END_OP4
BR OP1_to_6     ; Short-Circuit
OP5             ; End If

; If R1 is equivalent to 5 then call MACHINE_STATUS
ADD R1, R1, #-1 ; Check R1
BRnp OP6        ; Proceed to the next Else If

LD R6, MACHINE_STATUS    ; Call the subroutine
JSRR R6

; Output depending on the return of this subroutine
LEA R0, MACH_INE
TRAP x22

; CHECK R2 FOR VALUES GREATER THAN 9
AND R6, R6, #0
ADD R6, R6, #-10
ADD R6, R6, R3
BRn MS_0

LD R0, ASC_1
TRAP x21
ADD R3, R3, #-10

MS_0
LD R6, ASC_0
ADD R0, R6, R3
TRAP x21

ADD R2, R2, #0
BRz MS_FALSE

LEA R0, IS_FREE
TRAP x22
BR END_OP5

MS_FALSE
LEA R0, IS_BIZ
TRAP x22


END_OP5
BR OP1_to_6     ; Short-Circuit
OP6             ; End If

; If R1 is equivalent to 6 then call FIRST_FREE
ADD R1, R1, #-1 ; Check R1
BRnp OP7        ; Proceed to the next Else If

LD R6, FIRST_FREE    ; Call the subroutine
JSRR R6

; Output depending on the return of this subroutine
; Check if its -1
ADD R2, R2, #0
BRzp SKIP
; Output no machines are free
LEA R0, NO_FREE
TRAP x22
BR END_OP6

; Check if its 10 or more
SKIP

LEA R0, FIRST_AVAIL
TRAP x22

ADD R6, R2, #-10
BRn SKIP_TENS

LD R0, ASC_1
TRAP x21
ADD R2, R2, #-10

; Output
SKIP_TENS

LD R6, ASC_0
ADD R0, R2, R6
TRAP x21

AND R0, R0, #0
ADD R0, R0, #10
TRAP x21

END_OP6
BR OP1_to_6     ; Short-Circuit
OP7             ; End If

; The only thing that can be left is 7 (which will end the program)
LEA R0, RESPONSE7_1
TRAP x22
BR END_MAIN

OP1_to_6
BR MAIN

END_MAIN
HALT
;=====
;Data
;=====
MENU .FILL x3200
ALL_MACHINES_BUSY .FILL x3400
ALL_MACHINES_FREE .FILL x3600
NUM_BUSY_MACHINES .FILL x3800
NUM_FREE_MACHINES .FILL x4000
MACHINE_STATUS .FILL x4200
FIRST_FREE .FILL x4400

ASC_0 .FILL '0'
ASC_1 .FILL '1'
ASC_2 .FILL '2'
ASC_3 .FILL '3'
ASC_4 .FILL '4'
ASC_5 .FILL '5'
ASC_6 .FILL '6'
ASC_7 .FILL '7'
ASC_8 .FILL '8'
ASC_9 .FILL '9'

ASC_N_0 .FILL -'0'

RESPONSE1_1 .STRINGZ "Not all machines are busy\n"
RESPONSE1_2 .STRINGZ "All machines are busy\n"

RESPONSE2_1 .STRINGZ "Not all machines are free\n"
RESPONSE2_2 .STRINGZ "All machines are free\n"

THERE_ARE .STRINGZ "There are "
BUSY_MACH .STRINGZ " busy machines\n"
FREE_MACH .STRINGZ " free machines\n"

MACH_INE .STRINGZ "Machine "
IS_BIZ .STRINGZ " is busy\n"
IS_FREE .STRINGZ " is free\n"

FIRST_AVAIL .STRINGZ "The first available machine is number "

NO_FREE .STRINGZ "No machines are free\n"

RESPONSE7_1 .STRINGZ "Goodbye!\n"

;========================================================================
; Subroutine: MENU
; Input: None
; Postcondition: The subroutine has printed menu with numerical
;               options, captured the user selection, and returned it.
; Return Value (R1): The option selected: #1, #2, #3, #4, #5, #6 or #7
;               no other return value is valid
.ORIG x3200
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
SUB_1

; Output the menu

LD R0, MENU_PTR
TRAP x22

; Take input
TRAP x20



; Only echo if input isn't enter
ADD R6, R0, #-10
BRz SKIP_ENTER_ECHO

TRAP x21

SKIP_ENTER_ECHO
; If not 1-7 end
LD R6, ASC_NEG_1          ; R6 <-- mem[ASC_NEG_1]
ADD R6, R0, R6          ; R6 <-- R0 + R6
BRn INVALID_INPUT

LD R6, ASC_NEG_7          ; R6 <-- mem[ASC_NEG_7]
ADD R6, R0, R6          ; R6 <-- R0 + R6
BRp INVALID_INPUT

; Pass that value and output an endl
ADD R1, R0, #0

AND R0, R0, #0
ADD R0, R0, #10
TRAP x21

BR END_SUB_1

    ; Output errors
INVALID_INPUT
        ; If R0 is enter then skip outputting enter
    ADD R0, R0, #-10
    BRz SKIP_OUTPUT_ENDL
    
        ; Output a newline
    LD R0, D_0
    ADD R0, R0, #10
    TRAP x21

    SKIP_OUTPUT_ENDL
        ; Output error
    LEA R0, ERR_MSG
    TRAP x22
    
        ; Start the subroutine over
    BR SUB_1
    
END_INVALID_INPUT

END_SUB_1
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
; Backups
BACKUP_R0_3200  .BLKW   #1
BACKUP_R2_3200  .BLKW   #1
BACKUP_R3_3200  .BLKW   #1
BACKUP_R4_3200  .BLKW   #1
BACKUP_R5_3200  .BLKW   #1
BACKUP_R6_3200  .BLKW   #1
BACKUP_R7_3200  .BLKW   #1

MENU_PTR .FILL x6000

D_0 .FILL #0

ASC_NEG_1 .FILL -'1'
ASC_NEG_7 .FILL -'7'

ERR_MSG .STRINGZ "INVALID INPUT\n"

;========================================================================
; Subroutine: ALL_MACHINES_BUSY
; Input: None
; Postcondition: The subroutine has returned a value
;				indicating  whether all machines are busy
; Return Value (R2): 1 if all machines are busy,	0 otherwise
.ORIG x3400
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_3400
ST R1, BACKUP_R1_3400
ST R3, BACKUP_R3_3400
ST R4, BACKUP_R4_3400
ST R5, BACKUP_R5_3400
ST R6, BACKUP_R6_3400
ST R7, BACKUP_R7_3400
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_2

; Clear our return value (R2)
AND R2, R2, #0

; Take in the value of BUSYNESS, located at x5000, to R6
LD R6, AMB
LDR R6, R6, #0

; If the value is zero then all machines are busy
BRnp END_SUB_2


ADD R2, R2, #1  ; Assert the switch

END_SUB_2
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_3400
LD R1, BACKUP_R1_3400
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
BACKUP_R3_3400  .BLKW   #1
BACKUP_R4_3400  .BLKW   #1
BACKUP_R5_3400  .BLKW   #1
BACKUP_R6_3400  .BLKW   #1
BACKUP_R7_3400  .BLKW   #1

AMB .FILL x5000

;========================================================================
; Subroutine: ALL_MACHINES_FREE
; Input: None
; Postcondition: The subroutine has returned a value
;				indicating whether all machines are busy
; Return Value (R2): 1 if all machines are free, 0 otherwise
.ORIG x3600
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_3600
ST R1, BACKUP_R1_3600
ST R3, BACKUP_R3_3600
ST R4, BACKUP_R4_3600
ST R5, BACKUP_R5_3600
ST R6, BACKUP_R6_3600
ST R7, BACKUP_R7_3600
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_3

; Clear our return value (R2)
AND R2, R2, #0

; Take in the value of BUSYNESS, located at x5000, to R6
LD R6, AMF
LDR R6, R6, #0

; If all of them are free the value would be 16 1s or xFFFF or DEC#-1
ADD R6, R6, #1
BRnp END_SUB_3

; If the value is zero then all the machines are free
ADD R2, R2, #1


END_SUB_3
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_3600
LD R1, BACKUP_R1_3600
LD R3, BACKUP_R3_3600
LD R4, BACKUP_R4_3600
LD R5, BACKUP_R5_3600
LD R6, BACKUP_R6_3600
LD R7, BACKUP_R7_3600
;(4) Return to where you came from
RET
;===============================
; Subroutine Data
;===============================
; Backups
BACKUP_R0_3600  .BLKW   #1
BACKUP_R1_3600  .BLKW   #1
BACKUP_R3_3600  .BLKW   #1
BACKUP_R4_3600  .BLKW   #1
BACKUP_R5_3600  .BLKW   #1
BACKUP_R6_3600  .BLKW   #1
BACKUP_R7_3600  .BLKW   #1

AMF .FILL x5000

;========================================================================
; Subroutine: NUM_BUSY_MACHINES
; Input: None
; Postcondition: The subroutine has returned the number of busy machines.
; Return Value (R2): The number of machines that are busy
.ORIG x3800
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_3800
ST R1, BACKUP_R1_3800
ST R3, BACKUP_R3_3800
ST R4, BACKUP_R4_3800
ST R5, BACKUP_R5_3800
ST R6, BACKUP_R6_3800
ST R7, BACKUP_R7_3800
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform

; Call NUM_FREE_MACHINES
LD R6, NFM_PTR
JSRR R6

; Load 16
AND R6, R6, #0
ADD R6, R6, #15
ADD R6, R6, #1

; Subtract R2 from 16 and return
NOT R2, R2
ADD R2, R2, #1

ADD R2, R6, R2


;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_3800
LD R1, BACKUP_R1_3800
LD R3, BACKUP_R3_3800
LD R4, BACKUP_R4_3800
LD R5, BACKUP_R5_3800
LD R6, BACKUP_R6_3800
LD R7, BACKUP_R7_3800
;(4) Return to where you came from
RET
;===============================
; Subroutine Data
;===============================
; Backups
BACKUP_R0_3800  .BLKW   #1
BACKUP_R1_3800  .BLKW   #1
BACKUP_R3_3800  .BLKW   #1
BACKUP_R4_3800  .BLKW   #1
BACKUP_R5_3800  .BLKW   #1
BACKUP_R6_3800  .BLKW   #1
BACKUP_R7_3800  .BLKW   #1

NFM_PTR .FILL x4000


;========================================================================
; Subroutine: NUM_FREE_MACHINES
; Input: None
; Postcondition: None The subroutine has returned the number of free machines
; Return Value (R2): The number of machines that are free
.ORIG x4000
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_4000
ST R1, BACKUP_R1_4000
ST R3, BACKUP_R3_4000
ST R4, BACKUP_R4_4000
ST R5, BACKUP_R5_4000
ST R6, BACKUP_R6_4000
ST R7, BACKUP_R7_4000
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_4

; Populate a counter of 16
AND R3, R3, #0
ADD R3, R3, #15
ADD R3, R3, #1

; Clear our return value
AND R2, R2, #0

; Load the value from x5000 and put it in R4
LD R6, NMF
LDR R4, R6, #0

; Start the while loop
WHILE_LOOP
    ; And R4 with mask and whatever is returned is put in R6
    LD R6, MASK
    AND R6, R4, R6
    
    ; If one then increment the counter
    BRz SKIP_INCREMENTING
    ADD R2, R2, #1
    
    ; Else skip incrementing
    SKIP_INCREMENTING
    
    ; Decrement 16-counter
    ADD R3, R3, #-1
    
    ; Double R4
    ADD R4, R4, R4
    
    ; Loop
    ADD R3, R3, #0
    BRp WHILE_LOOP
END_WHILE_LOOP

END_SUB_4
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_4000
LD R1, BACKUP_R1_4000
LD R3, BACKUP_R3_4000
LD R4, BACKUP_R4_4000
LD R5, BACKUP_R5_4000
LD R6, BACKUP_R6_4000
LD R7, BACKUP_R7_4000
;(4) Return to where you came from
RET
;===============================
; Subroutine Data
;===============================
; Backups
BACKUP_R0_4000  .BLKW   #1
BACKUP_R1_4000  .BLKW   #1
BACKUP_R3_4000  .BLKW   #1
BACKUP_R4_4000  .BLKW   #1
BACKUP_R5_4000  .BLKW   #1
BACKUP_R6_4000  .BLKW   #1
BACKUP_R7_4000  .BLKW   #1

MASK .FILL x8000
NMF .FILL x5000

;========================================================================
; Subroutine: MACHINE_STATUS
; Input (R1): Which machine to check
; Postcondition: The subroutine has returned a value
;				indicating whether or not machine (R1) is busy
; Return Value (R2): 0 if machine (R1) is busy, 1 if it is free
;               (R3): holds the value the user entered
.ORIG x4200
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_4200
ST R1, BACKUP_R1_4200
ST R4, BACKUP_R4_4200
ST R5, BACKUP_R5_4200
ST R6, BACKUP_R6_4200
ST R7, BACKUP_R7_4200
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_5

; Clear R2 and R3
AND R2, R2, #0
AND R3, R3, #0

; Call helper
LD R6, HELPER_PTR
JSRR R6

; If negative call error
ADD R6, R1, #0
BRn INVALID_INPUTTERS

ADD R6, R1, #-15
BRp INVALID_INPUTTERS

; If its valid contine below
START_CHECK

ADD R3, R1, #0

; Clear R2 and R4
AND R2, R2, #0
AND R4, R4, #0

; Load the value of busyness
LD R6, MS
LDR R5, R6, #0

; While loop that gets rid of the digits until we get to the one we want
AND R0, R0, #0
ADD R0, R0, #15

NOT R1, R1
ADD R1, R1, #1

ADD R1, R0, R1
ADD R1, R1, #0
BRnz END_WHILE_CHECK_LOOP
WHILE_CHECK_LOOP

    ; Double the value from busyness
    ADD R5, R5, R5

    ; Decrement the counter
    ADD R1, R1, #-1
    
    ; Loop while positive
    BRp WHILE_CHECK_LOOP
    
END_WHILE_CHECK_LOOP

; Check if the machine is available

    ; Load mask to R6
LD R6, MASKERS
    
    ; And the value with mask
AND R6, R5, R6

    ; If its zero then its not available and return 0
BRz END_SUB_5

    ; Else
ADD R2, R2, #1

BR END_SUB_5
; Ivalid input goes here
INVALID_INPUTTERS
    LEA R0, SUB5_ERR_MSG
    TRAP x22
    BR SUB_5

END_SUB_5
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_4200
LD R1, BACKUP_R1_4200
LD R4, BACKUP_R4_4200
LD R5, BACKUP_R5_4200
LD R6, BACKUP_R6_4200
LD R7, BACKUP_R7_4200
;(4) Return to where you came from
RET
;===============================
; Subroutine Data
;===============================
; Backups
BACKUP_R0_4200  .BLKW   #1
BACKUP_R1_4200  .BLKW   #1
BACKUP_R4_4200  .BLKW   #1
BACKUP_R5_4200  .BLKW   #1
BACKUP_R6_4200  .BLKW   #1
BACKUP_R7_4200  .BLKW   #1

ASCI_N_0 .FILL -'0'
N_plus .FILL -'+'
N_minus .FILL -'-'
MS .FILL x5000
MASKERS .FILL x8000
SUB5_ERR_MSG .STRINGZ "ERROR INVALID INPUT\n"
HELPER_PTR .FILL x4600

;========================================================================
; Subroutine: FIRST_FREE
; Input: None
; Postcondition: The subroutine has returned a value
;				indicating the lowest numbered free machine
; Return Value (R2): the number of the  free machine
.ORIG x4400
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_4400
ST R1, BACKUP_R1_4400
ST R3, BACKUP_R3_4400
ST R4, BACKUP_R4_4400
ST R5, BACKUP_R5_4400
ST R6, BACKUP_R6_4400
ST R7, BACKUP_R7_4400
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_6

    ; Clear R2
    AND R2, R2, #0
    
    ; Load a counter of 16
    AND R4, R4, #0
    ADD R4, R4, #8
    ADD R4, R4, #8
    
    ; Load the value of busyness
    LD R6, FF
    LDR R5, R6, #0
    
    ; Load a mask
    LD R3, MASKEETS
    
    ; While loop
    WHILE_AVAIL_LOOP
        ; Check the value against a mask
        AND R6, R3, R5
        
        ; If not zero return what index you're at and end
        BRnp END_SUB_6
        
        ; Else decrement the counter
        ADD R4, R4, #-1
        
        ; Increment curr
        ADD R2, R2, #1
        
        ; Left shift
        ADD R5, R5, R5
        
	ADD R4, R4, #0
        ; Loop while positive
        BRp WHILE_AVAIL_LOOP
    END_WHILE_AVAIL_LOOP

ADD R2, R2, #0
BRn END_SUB_6

ADD R2, R2, #1

NOT R2, R2
ADD R2, R2, #1

AND R6, R6, #0
ADD R6, R6, #15

ADD R2, R6, R2
    
END_SUB_6
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_4400
LD R1, BACKUP_R1_4400
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
BACKUP_R3_4400  .BLKW   #1
BACKUP_R4_4400  .BLKW   #1
BACKUP_R5_4400  .BLKW   #1
BACKUP_R6_4400  .BLKW   #1
BACKUP_R7_4400  .BLKW   #1

FF .FILL x5000
MASKEETS .FILL x8000

;========================================================================
; Subroutine: SUB_TAKE_INPUT_4600
; Parameter: None
; Postcondition: User will input a numeric string of no more than 5 characters that will be saved to R1
; Return Value: R1 will have the value of the number the user inputted

.orig x4600
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_4600
ST R2, BACKUP_R2_4600
ST R3, BACKUP_R3_4600
ST R4, BACKUP_R4_4600
ST R5, BACKUP_R5_4600
ST R6, BACKUP_R6_4600
ST R7, BACKUP_R7_4600

; Make sure everything is initialized to Zero
LD R0, H_DEC_0	; R0 <-- 0
LD R1, H_DEC_0	; R1 <-- 0
LD R2, H_DEC_0	; R2 <-- 0
LD R3, H_DEC_0	; R3 <-- 0
LD R4, H_DEC_0	; R4 <-- 0
LD R5, H_DEC_0	; R5 <-- 0
LD R6, H_DEC_0	; R6 <-- 0


;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_7

; Prompt user
LEA R0, PROMPT
TRAP x22

; Set up
LD R1, H_DEC_0	; R1 <-- 0
LD R5, H_DEC_5	; R4 <-- m[H_DEC_5] This is the counter

; First character
FIRST_CHAR
	; Take input and echo
TRAP x20

; If enter don't echo
;AND R6, R6, #0
;ADD R6, R6, #-10
;ADD R6, R6, R0
;BRz PLZ_NO

TRAP x21

PLZ_NO
	; Is it plus?
LD R6, H_N_plus	; (m[H_N_plus]) is -ASCII for '+'
ADD R6, R0, R6  ; Check if it's this
BRz I_WAS_SIGN	; If it was then continue

	; Is it minus?
LD R6, H_N_minus	; (m[H_N_minus]) is -ASCII for '-'
ADD R6, R0, R6  ; Check if it's this
BRz I_WAS_SIGN	; If it was then continue

	; Is it a number?
LD R6, H_N_0	; (m[H_N_plus]) is -ASCII for '0'
ADD R6, R0, R6  ; Check if it's this
BRn INVALID_INPUT_HELPER ; If its less than ASCII 0 then its invalid
LD R6, H_N_9	; (m[H_N_plus]) is -ASCII for '9'
ADD R6, R0, R6  ; Check if it's this
BRp INVALID_INPUT_HELPER ; If its more than ASCII 9 then its also invalid

	; If it got here it was a number. Load R1 with its value
	LD R6, H_N_48
	ADD R1, R0 , R6	; Make sure to conver it to ASCII
	ADD R5, R5, #-1	; Decrement the counter

BR END_FIRST_CHAR
I_WAS_SIGN
	ADD R2, R0, #0	; Copy the sign to R2
END_I_WAS_SIGN
END_FIRST_CHAR	; DONE CHECKING FIRST CHAR

; Second character
SECOND_CHAR
	; Take user input and echo
TRAP x20
TRAP x21
	; If the second char was an enter its a special circumstance
ADD R6, R0, #-10
BRnp IT_WASNT_ENTER
		; If it was enter check R2
ADD R2, R2, #0
	; If theres no value then the enter is invalid
BRp INVALID_INPUT_HELPER
	; Else the enter is ok and end
BR CHECK_NEG

IT_WASNT_ENTER
	; If it got here it was a number. Load R1 with its value
LD R6, H_N_0	; (m[H_N_plus]) is -ASCII for '0'
ADD R6, R0, R6  ; Check if it's this
BRn INVALID_INPUT_HELPER ; If its less than ASCII 0 then its invalid
LD R6, H_N_9	; (m[H_N_plus]) is -ASCII for '9'
ADD R6, R0, R6  ; Check if it's this
BRp INVALID_INPUT_HELPER ; If its more than ASCII 9 then its also invalid

	; If it got here it was a number. Load R1 with its value
	LD R6, H_N_48
	ADD R4, R1, R1	; Multiply R1 by 10 (R4 = 2R1)
	ADD R1, R4, R4	; (R1 = 4R1)
	ADD R1, R1, R1	; (R1 = 8R1)
	ADD R1, R1, R4	; (R1 = 10R1)

	ADD R6, R0, R6	; Convert R0 to ASCII
	ADD R1, R6, R1	; Add that value to R1
	ADD R5, R5, #-1	; Decrement the counter

END_SECOND_CHAR	; DONE CHECKING SECOND CHAR

; Last characters
	; While the counter isn't negative
WHILE_LOOP_HELPER
	; Take input and echo
TRAP x20
TRAP x21
	; Check for enter
	ADD R6, R0, #-10
	; End if enter is found
	BRz CHECK_NEG

	; Check if input is a number
	LD R6, H_N_0	; (m[H_N_plus]) is -ASCII for '0'
	ADD R6, R0, R6  ; Check if it's this
	BRn INVALID_INPUT_HELPER ; If its less than ASCII 0 then its invalid
	LD R6, H_N_9	; (m[H_N_plus]) is -ASCII for '9'
	ADD R6, R0, R6  ; Check if it's this
	BRp INVALID_INPUT_HELPER ; If its more than ASCII 9 then its also invalid

	; Else multiply R1 by 10
	ADD R4, R1, R1	; Multiply R1 by 10 (R4 = 2R1)
	ADD R1, R4, R4	; (R1 = 4R1)
	ADD R1, R1, R1	; (R1 = 8R1)
	ADD R1, R1, R4	; (R1 = 10R1)

	; Add R0 to R1 after converting to DEC
	LD R6, H_N_48
	ADD R6, R0, R6
	ADD R1, R6, R1

	; Continue while counter is positive
	ADD R5, R5, #-1
	BRp WHILE_LOOP_HELPER
END_WHILE_LOOP_HELPER

; If it gets here it wasn't terminated by an enter and thus should output a newline
LD R0, H_DEC_0
ADD R0, R0, #10
TRAP x21

CHECK_NEG
; if negative convert them
;check R2
ADD R2, R2, #0

; Load -'-'
LD R6, H_N_minus

; ADD them
ADD R6, R2, R6

; If it's zero then convert else you're done
BRnp END_SUB_7

NOT R1, R1
ADD R1, R1, #1

BR END_SUB_7
; Error message "function"
INVALID_INPUT_HELPER
	; Output an error and start the subroutine over
	; If an enter caused the error then don't output a newline
	ADD R6, R0, #-10
	BRz END_OUTPUT_SPACE

	; Else output a newline
	OUTPUT_SPACE
		LD R0, H_DEC_10
		TRAP x21
	END_OUTPUT_SPACE
	LD R0, SUB_ERR_MSG_PTR
	TRAP x22
	BR SUB_7
END_INVALID_INPUT_HELPER

END_SUB_7
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_4600
LD R2, BACKUP_R2_4600
LD R3, BACKUP_R3_4600
LD R4, BACKUP_R4_4600
LD R5, BACKUP_R5_4600
LD R6, BACKUP_R6_4600
LD R7, BACKUP_R7_4600
;(4) Return to where you came from
RET
;===============================
; Subroutine Data
;===============================
BACKUP_R0_4600  .BLKW   #1
BACKUP_R2_4600  .BLKW   #1
BACKUP_R3_4600  .BLKW   #1
BACKUP_R4_4600  .BLKW   #1
BACKUP_R5_4600  .BLKW   #1
BACKUP_R6_4600  .BLKW   #1
BACKUP_R7_4600  .BLKW   #1
SUB_ERR_MSG_PTR .FILL x5500
H_DEC_0 .FILL #0
H_DEC_5 .FILL #5
H_DEC_10 .FILL #10
H_N_0 .FILL -'0'
H_N_9 .FILL -'9'
H_N_48 .FILL #-48
H_N_plus .FILL -'+'
H_N_minus .FILL -'-'
PROMPT .STRINGZ "Enter which machine you want the status of (0-15), followed by ENTER: "

;======================
; Location of Busyness
.ORIG x5000
BUSYNESS .FILL x8000
;======================

.ORIG x5500
SUB_ERR_MSG .STRINGZ "ERROR INVALID INPUT\n"

;==================
; String Locations
;==================
.ORIG x6000
MENUSTRING .STRINGZ "**********************\n* The Busyness Server *\n**********************\n1. Check to see whether all machines are busy\n2. Check to see whether all machines are free\n3. Report the number of busy machines\n4. Report the number of free machines\n5. Report the status of machine n\n6. Report the number of the first available machine\n7. Quit\n"


;==============
; Program end
;==============
.END