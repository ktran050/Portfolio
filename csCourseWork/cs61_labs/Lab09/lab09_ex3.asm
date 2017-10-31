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
; Set capacity
ADD R3, R3, #5
; Set start
LD R1, STACK_ADDR
; Set top
LD R2, STACK_ADDR

; Take a single digit number from user
LEA R0, PROMPT_USER
TRAP x22
TRAP x20

; Echo
TRAP x21
ADD R5, R0, #0

; NEWLINE
AND R0, R0, #0
ADD R0, R0, #10
TRAP x21

; Move R0 back and convert it to DEC
LD R6, N_0
ADD R0, R6, R5

; Push it onto the stack
LD R6, SUB_STACK_PUSH
JSRR R6

; Take another single digit number from user
LEA R0, PROMPT_USER
TRAP x22
TRAP x20

; Echo
TRAP x21
ADD R5, R0, #0

; NEWLINE
AND R0, R0, #0
ADD R0, R0, #10
TRAP x21
; Move R0 back and convert it to DEC
LD R6, N_0
ADD R0, R6, R5
  
; Push it onto the stack
LD R6, SUB_STACK_PUSH
JSRR R6

; Call the SUB_RPN_MULTIPLY subroutine to pop the two values off the stack,
; multiply them, and push the result back onto the stack
LD R6, SUB_RPN_MULTIPLY
JSRR R6

; Output a newline
AND R0, R0, #0
ADD R0, R0, #10
TRAP x21

; POP the last value off the stack and print it out to the console in decimal format
LD R6, SUB_STACK_POP
JSRR R6

HALT
	;======
	; Data
	;======
SUB_RPN_MULTIPLY .FILL x3200
SUB_STACK_PUSH .FILL x3400
SUB_STACK_POP .FILL x3600
STACK_ADDR .FILL x5000

PROMPT_USER .STRINGZ "Input a single digit only\n"

N_0 .FILL -'0'

.END

;========================================================================
; Subroutine: SUB_RPN_MULTIPLY
; Parameter (R1): stack_addr: A pointer to the beginning of the stack
; Parameter (R2): top: A pointer to the next place to push the item
; Parameter (R3): capacity: The number of additional items the stack can hold
; Postcondition: The subroutine has popped off the top two values of the stack,
;               multiplied them together, and pushed the resulting value back
;               onto the stack.
; Return Value: R2 <- updated top value
;               R3 <- updated capacity value
.ORIG x3200
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R1, BACKUP_R0_3200
ST R1, BACKUP_R1_3200
ST R4, BACKUP_R4_3200
ST R5, BACKUP_R5_3200
ST R6, BACKUP_R6_3200
ST R7, BACKUP_R7_3200
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_1

; Take a value from the stack and put it in R5
ADD R5, R2, #-1
LDR R5, R5, #0
; Pop
LD R6, PPOP
JSRR R6

; Take a value from the stack and put it in R4
ADD R4, R2, #-1
LDR R4, R4, #0
; Pop
LD R6, PPOP
JSRR R6

; Swap R5 and R1 (R5 temporarily holding the pointer)
ADD R6, R1, #0
ADD R1, R5, #0
ADD R5, R6, #0

; Prepare R2 for the subroutine, hold its value in R6
ADD R6, R2, #0
ADD R2, R4, #0

; R0 holds R3 (capacity)
ADD R0, R3, #0

; Call multiplication subroutine
LD R4, MMULT
JSRR R4

; Move R1 and 2 back
ADD R1, R5, #0
ADD R2, R6, #0

; Output the value we are popping
LD R6, OOUT
JSRR R6

; Swap R3 and R0
ADD R6, R0, #0
ADD R0, R3, #0
ADD R3, R6, #0

; Push the result back onto the stack
LD R6, PPUSH
JSRR R6

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

PPOP .FILL x3600
PPUSH .FILL x3400
MMULT .FILL x4200
OOUT .FILL x4400

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
.ORIG x3400
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_3400
ST R1, BACKUP_R1_3400
ST R4, BACKUP_R4_3400
ST R5, BACKUP_R5_3400
ST R6, BACKUP_R6_3400
ST R7, BACKUP_R7_3400
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_2

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


BR END_SUB_2    ; Skip if not overflow
OVERFLOW
    LEA R0, OVERFLOW_MSG
    TRAP x22

END_SUB_2
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_3400
LD R1, BACKUP_R1_3400
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
BACKUP_R4_3400  .BLKW   #1
BACKUP_R5_3400  .BLKW   #1
BACKUP_R6_3400  .BLKW   #1
BACKUP_R7_3400  .BLKW   #1
OVERFLOW_MSG .STRINGZ "ERROR: OVERFLOW\n"

;========================================================================
; Subroutine: SUB_STACK_POP
; Parameter (R1): stack_addr: A pointer to the beginning of the stack
; Parameter (R2): top: A pointer to the next place to push the item
; Parameter (R3): capacity: The number of additional items the stack can hold
; Postcondition: The subroutine has pushed popped MEM[top] off of the stack.
;               If an underflow occured, the subroutine has printed an
;               underflow error messge and terminated
; Return Value: R0 <- value popped off of the stack
;               R2 <- updated top value
;               R3 <- updated capacity value
.ORIG x3600
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R1, BACKUP_R1_3600
ST R4, BACKUP_R4_3600
ST R5, BACKUP_R5_3600
ST R6, BACKUP_R6_3600
ST R7, BACKUP_R7_3600
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_3

; Check top
ADD R2, R2, #0
LD R6, COMPARE
ADD R6, R6, R2

; If top is equal to the start then go to underflow
BRz UNDERFLOW

; Else decrement top
ADD R2, R2, #-1

; Store the value of mem[R2] to 0
LDR R0, R2, #0

; Increment capacity
ADD R3, R3, #1


BR END_SUB_3    ; Skip if not overflow
UNDERFLOW
    LEA R0, UNDERFLOW_MSG
    TRAP x22

END_SUB_3
;(3) Restore the registers that you backed up
LD R1, BACKUP_R1_3600
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
BACKUP_R1_3600  .BLKW   #1
BACKUP_R4_3600  .BLKW   #1
BACKUP_R5_3600  .BLKW   #1
BACKUP_R6_3600  .BLKW   #1
BACKUP_R7_3600  .BLKW   #1
UNDERFLOW_MSG .STRINGZ "ERROR: UNDERFLOW\n"
COMPARE .FILL -x5000

;========================================================================
; Subroutine: SUB_MULT_R3_R2_R1_4200
; Parameter: R1 and R2
; Postcondition: R1 and R2 will be multiplied with R3 holding the result, if overflowed switch in R4 will reflect that
; Return Value: DEC value in R3 holding result of multiplication, R4 will contain -30000 if it overflows
.orig x4200
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_4200
ST R1, BACKUP_R1_4200
ST R2, BACKUP_R2_4200
ST R5, BACKUP_R5_4200
ST R6, BACKUP_R6_4200
ST R7, BACKUP_R7_4200
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_5

LD R4, D_0

; Check if either value is zero
	ADD R6, R1, #0
	BRz IS_ZERO
	ADD R6, R2, #0
	BRz IS_ZERO

	BR NOT_ZERO
	; If it gets here then a value was zero and we should return zero
		IS_ZERO
		; Return 0
		LD R3, D_0

		; End Sub
		BR END_SUB_5

NOT_ZERO
; Check if either value is one
	ADD R6, R1, #-1
	BRz R1_IS_ONE
	ADD R6, R2, #-1
	BRz R2_IS_ONE

	BR NOT_ONE
	; If it gets here one of them is a one
		R1_IS_ONE
		; Return R2
		ADD R3, R2, #0

		; End sub
		BR END_SUB_5

		R2_IS_ONE
		; Return R1
		ADD R3, R1, #0

		; End sub
		BR END_SUB_5

NOT_ONE
; Check if either value is negative one
	ADD R6, R1, #1
	BRz R1_IS_N_ONE
	ADD R6, R2, #1
	BRz R2_IS_N_ONE

	BR NOT_N_ONE
	; If it gets here one of them is a negative one
	R1_IS_N_ONE
		; Return 2s Comp R2
		NOT R2, R2
		ADD R3, R2, #1

		; End sub
		BR END_SUB_5

	R2_IS_N_ONE
		; Return 2s Comp R1
		NOT R1, R1
		ADD R3, R1, #1

		; End sub
		BR END_SUB_5

NOT_N_ONE
; Absolute values and activate switches if theyre negative
	; Check R1
	ADD R6, R1, #0

	; If R1 isn't negative continue
	BRzp CHECK_R2

	; Else activate switch and take twos complement
	ADD R4, R4, #1
	NOT R1, R1
	ADD R1, R1, #1

	; Check R2
	CHECK_R2
	ADD R6, R2, #0

	; If not negative then continue to ABS_CHECK
	BRzp ABS_CHECK
	
	; Else activate switch and take twos complement
	ADD R4, R4, #-1
	NOT R2, R2
	ADD R2, R2, #1
	
ABS_CHECK
; Find which absolute value is greater
	; Subtract R2 from R1
	NOT R6, R2
	ADD R6, R6, #1
	ADD R6, R6, R1

	; If positive R1 is greater
	BRp R1_GREATER

	; Else R2 is greater
	BR R2_GREATER

END_ABS_CHECK
; Multiply
LD R3, D_0
	; Which ever one is greater will loop the other number amount of times
	R1_GREATER
	LD R3, D_0
	LD R4, D_0
		LOOP_R2_NUM_TIMES
			ADD R3, R3, R1 ; ADD the value of R1 to R3
			BRn OVERFLOWED
			ADD R2, R2, #-1	; Decrement the counter
			BRp LOOP_R2_NUM_TIMES
		END_LOOP_R2_NUM_TIMES
		BR CONTINUE
	END_R1_GREATER
	R2_GREATER
	LD R3, D_0
	LD R4, D_0
		LOOP_R1_NUM_TIMES
			ADD R3, R3, R2 ; ADD the value of R2 to R3
			BRn OVERFLOWED
			ADD R1, R1, #-1	; Decrement the counter
			BRp LOOP_R1_NUM_TIMES
		END_LOOP_R1_NUM_TIMES
		BR CONTINUE
	END_R2_GREATER

OVERFLOWED
	LD R4, LOCK
	BR END_SUB_5
END_OVERFLOWED

CONTINUE
; Check for negative

	; Check R4
	ADD R4, R4, #0
	
	; If zero continue
	BRz ALMOST_DONE

	; Else Twos comp
	NOT R3, R3
	ADD R3, R3, #1

ALMOST_DONE
; Return R3 (done automatically)

END_SUB_5
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_4200
LD R1, BACKUP_R1_4200
LD R2, BACKUP_R2_4200
LD R5, BACKUP_R5_4200
LD R6, BACKUP_R6_4200
LD R7, BACKUP_R7_4200
;(4) Return to where you came from
RET
;===============================
; Subroutine Data
;===============================
BACKUP_R0_4200  .BLKW   #1
BACKUP_R1_4200  .BLKW   #1
BACKUP_R2_4200  .BLKW   #1
BACKUP_R5_4200  .BLKW   #1
BACKUP_R6_4200  .BLKW   #1
BACKUP_R7_4200  .BLKW   #1
D_0 .FILL #0
D_48 .FILL #48
LOCK .FILL #-30000

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
