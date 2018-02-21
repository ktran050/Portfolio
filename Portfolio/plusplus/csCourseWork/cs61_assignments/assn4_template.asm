;=================================================
; 
; Name: <last name, first name>
; Username:
;
; SID:
; Assignment name: <assn ?>
; Lab section: 
; TA: 
;
; I hereby certify that I have not received 
; assistance on this assignment, or used code
; from ANY outside source other than the
; instruction team. 
;
;=================================================

.ORIG x3000			; Program begins here
;-------------
;Instructions
;-------------

;-------------------------------
;INSERT CODE STARTING FROM HERE 
;--------------------------------
;TO Output Intro Message
LD R0, introMessage  ; Output Intro Message
PUTS

;TO Output Error Message
LD R0, errorMessage  ; Output Error Message
PUTS

HALT
;---------------	
;Data
;---------------


introMessage .FILL x6000
errorMessage .FILL x6100

;------------
;Remote data
;------------
.ORIG x6000
;---------------
;messages
;---------------
intro .STRINGZ	"Input a positive or negative decimal number (max 5 digits), followed by ENTER\n"
;---------------
;error_messages
;---------------
.ORIG x6100	
error_mes .STRINGZ	"ERROR INVALID INPUT\n"

;---------------
;END of PROGRAM
;---------------
.END
;-------------------
;PURPOSE of PROGRAM
;-------------------

