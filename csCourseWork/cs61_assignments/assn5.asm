;=================================================
; 
; Name: <Tran, Kevin>
; Username: ktran050
;
; SID: 861172609
; Assignment name: <assn 5>
; Lab section: 23
; TA: Jose Rodriguez
;
; I hereby certify that I have not received 
; assistance on this assignment, or used code
; from ANY outside source other than the
; instruction team. 
;
;=================================================

.ORIG x3000			; Program begins here
;==============
; Instructions
;==============

; Call Sub 1
LD R0, SUB_TAKE_INPUT
JSRR R0

; Move the value we got from Sub 1 to R2
ADD R2, R1, #0

; Call Sub 1
LD R0, SUB_TAKE_INPUT
JSRR R0

; Basic output ( cout << R1 << " * " << R2 << " = " << R3 )
	; Output R2
		; Move R2 to R3
		ADD R3, R2, #0

		; Call Sub 3
		LD R0, SUB_OUTPUT_STR_R3
		JSRR R0

	; Output times
		LEA R0, TIMES
		TRAP x22

	; Output R1
		; Move R1 to R3
		ADD R3, R1, #0

		; Call Sub 3
		LD R0, SUB_OUTPUT_STR_R3
		JSRR R0

	; Output equals
		LEA R0, EQUALS
		TRAP x22

; Call Sub 2
LD R0, SUB_MULT_R3_R2_R1
JSRR R0

LD R6, KEY
ADD R6, R4, R6
BRz ERR_OVER

; Call Sub 3
LD R0, SUB_OUTPUT_STR_R3
JSRR R0

; Output a space
LD R0, NEWLINE
TRAP x21


HALT

ERR_OVER
	; Output error
	LEA R0, OVERFLOW
	TRAP x22

	; Output a space
	LD R0, NEWLINE
	TRAP x21
HALT
;======
; Data
;======
TIMES .STRINGZ " * "
EQUALS .STRINGZ " = "
OVERFLOW .STRINGZ "Overflow!"
NEWLINE .FILL #10
KEY .FILL #30000

SUB_TAKE_INPUT .FILL x3200
SUB_MULT_R3_R2_R1 .FILL x3400
SUB_OUTPUT_STR_R3 .FILL x3600

;==============
; Remote Data
;==============


;========================================================================
; Subroutine: SUB_TAKE_INPUT_3200
; Parameter: None
; Postcondition: User will input a numeric string of no more than 5 characters that will be saved to R1
; Return Value: R1 will have the value of the number the user inputted

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

; Make sure everything is initialized to Zero
LD R0, DEC_0	; R0 <-- 0
LD R1, DEC_0	; R1 <-- 0
LD R2, DEC_0	; R2 <-- 0
LD R3, DEC_0	; R3 <-- 0
LD R4, DEC_0	; R4 <-- 0
LD R5, DEC_0	; R5 <-- 0
LD R6, DEC_0	; R6 <-- 0


;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_1

; Set up
LD R1, DEC_0	; R1 <-- 0
LD R5, DEC_5	; R4 <-- m[DEC_5] This is the counter

; Output the prompt
LD R0, introMessagePtr
TRAP x22

; First character
FIRST_CHAR
	; Take input and echo
TRAP x20
TRAP x21

	; Is it plus?
LD R6, N_plus	; (m[N_plus]) is -ASCII for '+'
ADD R6, R0, R6  ; Check if it's this
BRz I_WAS_SIGN	; If it was then continue

	; Is it minus?
LD R6, N_minus	; (m[N_minus]) is -ASCII for '-'
ADD R6, R0, R6  ; Check if it's this
BRz I_WAS_SIGN	; If it was then continue

	; Is it a number?
LD R6, N_0	; (m[N_plus]) is -ASCII for '0'
ADD R6, R0, R6  ; Check if it's this
BRn INVALID_INPUT ; If its less than ASCII 0 then its invalid
LD R6, N_9	; (m[N_plus]) is -ASCII for '9'
ADD R6, R0, R6  ; Check if it's this
BRp INVALID_INPUT ; If its more than ASCII 9 then its also invalid

	; If it got here it was a number. Load R1 with its value
	LD R6, N_48
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
BRp INVALID_INPUT
	; Else the enter is ok and end
BR CHECK_NEG

IT_WASNT_ENTER
	; If it got here it was a number. Load R1 with its value
LD R6, N_0	; (m[N_plus]) is -ASCII for '0'
ADD R6, R0, R6  ; Check if it's this
BRn INVALID_INPUT ; If its less than ASCII 0 then its invalid
LD R6, N_9	; (m[N_plus]) is -ASCII for '9'
ADD R6, R0, R6  ; Check if it's this
BRp INVALID_INPUT ; If its more than ASCII 9 then its also invalid

	; If it got here it was a number. Load R1 with its value
	LD R6, N_48
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
WHILE_LOOP
	; Take input and echo
TRAP x20
TRAP x21
	; Check for enter
	ADD R6, R0, #-10
	; End if enter is found
	BRz CHECK_NEG

	; Check if input is a number
	LD R6, N_0	; (m[N_plus]) is -ASCII for '0'
	ADD R6, R0, R6  ; Check if it's this
	BRn INVALID_INPUT ; If its less than ASCII 0 then its invalid
	LD R6, N_9	; (m[N_plus]) is -ASCII for '9'
	ADD R6, R0, R6  ; Check if it's this
	BRp INVALID_INPUT ; If its more than ASCII 9 then its also invalid

	; Else multiply R1 by 10
	ADD R4, R1, R1	; Multiply R1 by 10 (R4 = 2R1)
	ADD R1, R4, R4	; (R1 = 4R1)
	ADD R1, R1, R1	; (R1 = 8R1)
	ADD R1, R1, R4	; (R1 = 10R1)

	; Add R0 to R1 after converting to DEC
	LD R6, N_48
	ADD R6, R0, R6
	ADD R1, R6, R1

	; Continue while counter is positive
	ADD R5, R5, #-1
	BRp WHILE_LOOP
END_WHILE_LOOP

; If it gets here it wasn't terminated by an enter and thus should output a newline
LD R0, DEC_0
ADD R0, R0, #10
TRAP x21

CHECK_NEG
; if negative convert them
;check R2
ADD R2, R2, #0

; Load -'-'
LD R6, N_minus

; ADD them
ADD R6, R2, R6

; If it's zero then convert else you're done
BRnp END_SUB_1

NOT R1, R1
ADD R1, R1, #1

BR END_SUB_1
; Error message "function"
INVALID_INPUT
	; Output an error and start the subroutine over
	; If an enter caused the error then don't output a newline
	ADD R6, R0, #-10
	BRz END_OUTPUT_SPACE

	; Else output a newline
	OUTPUT_SPACE
		LD R0, DEC_10
		TRAP x21
	END_OUTPUT_SPACE
	LD R0, errorMessagePtr
	TRAP x22
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
BACKUP_R0_3200  .BLKW   #1
BACKUP_R2_3200  .BLKW   #1
BACKUP_R3_3200  .BLKW   #1
BACKUP_R4_3200  .BLKW   #1
BACKUP_R5_3200  .BLKW   #1
BACKUP_R6_3200  .BLKW   #1
BACKUP_R7_3200  .BLKW   #1
introMessagePtr .FILL x6000
errorMessagePtr .FILL x6100
DEC_0 .FILL #0
DEC_5 .FILL #5
DEC_10 .FILL #10
N_0 .FILL -'0'
N_9 .FILL -'9'
N_48 .FILL #-48
N_plus .FILL -'+'
N_minus .FILL -'-'
;========================================================================
; Subroutine: SUB_MULT_R3_R2_R1_3400
; Parameter: R1 and R2
; Postcondition: R1 and R2 will be multiplied with R3 holding the result, if overflowed switch in R4 will reflect that
; Return Value: DEC value in R3 holding result of multiplication, R4 will contain -30000 if it overflows
.orig x3400
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_3400
ST R1, BACKUP_R1_3400
ST R2, BACKUP_R2_3400
ST R5, BACKUP_R5_3400
ST R6, BACKUP_R6_3400
ST R7, BACKUP_R7_3400
;(2) Perform whatever algorithm(s) this subroutine is supposed to perform
SUB_2

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
		BR END_SUB_2

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
		BR END_SUB_2

		R2_IS_ONE
		; Return R1
		ADD R3, R1, #0

		; End sub
		BR END_SUB_2

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
		BR END_SUB_2

	R2_IS_N_ONE
		; Return 2s Comp R1
		NOT R1, R1
		ADD R3, R1, #1

		; End sub
		BR END_SUB_2

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
	BR END_SUB_2
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

END_SUB_2
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_3400
LD R1, BACKUP_R1_3400
LD R2, BACKUP_R2_3400
LD R5, BACKUP_R5_3400
LD R6, BACKUP_R6_3400
LD R7, BACKUP_R7_3400
;(4) Return to where you came from
RET
;===============================
; Subroutine Data
;===============================
BACKUP_R0_3400  .BLKW   #1
BACKUP_R1_3400  .BLKW   #1
BACKUP_R2_3400  .BLKW   #1
BACKUP_R5_3400  .BLKW   #1
BACKUP_R6_3400  .BLKW   #1
BACKUP_R7_3400  .BLKW   #1
D_0 .FILL #0
D_48 .FILL #48
LOCK .FILL #-30000
;========================================================================
; Subroutine: SUB_OUTPUT_STR_R3_3600
; Parameter: R3
; Postcondition: The DEC value in R3 is output to the user
; Return Value: Nothing is returned
.orig x3600
;========================================================================
;===============================
; Subroutine Instructions
;===============================
;(1) Backup R7 and all registers that this subroutine changes except return values
ST R0, BACKUP_R0_3600
ST R1, BACKUP_R1_3600
ST R2, BACKUP_R2_3600
ST R3, BACKUP_R3_3600
ST R4, BACKUP_R4_3600
ST R5, BACKUP_R5_3600
ST R6, BACKUP_R6_3600
ST R7, BACKUP_R7_3600
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
BR END_SUB_3

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


BR END_SUB_3
R3_EMPTY
    LD R0, DEC_48
    TRAP x21
END_R3_EMPTY
END_SUB_3
;(3) Restore the registers that you backed up
LD R0, BACKUP_R0_3600
LD R1, BACKUP_R1_3600
LD R2, BACKUP_R2_3600
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
BACKUP_R2_3600  .BLKW   #1
BACKUP_R3_3600  .BLKW   #1
BACKUP_R4_3600  .BLKW   #1
BACKUP_R5_3600  .BLKW   #1
BACKUP_R6_3600  .BLKW   #1
BACKUP_R7_3600  .BLKW   #1

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
;===============
;Initial prompt (IntroMessagePtr points here)
;===============
.ORIG x6000
intro .STRINGZ	"Input a positive or negative decimal number (max 5 digits), followed by ENTER\n"

;===============
;Error message (ErrorMessagePtr points here)
;===============
.ORIG x6100	
error_mes .STRINGZ	"ERROR INVALID INPUT\n"

;===============
;END of PROGRAM
;===============
.END