;=================================================
; Name: <Tran, Kevin>
; Username: ktran050
;
; SID: 861172609
; Assignment Name: <assn 3>
; Lab Section: 23
; TA: Jose Rodriguez
;
; I hereby certify that I have not received 
; assistance on this assignment, or used code,
; from ANY outside source other than the
; instruction team. 
;=================================================
.ORIG x3000
        ;=============
        ;Instructions
        ;=============
LD R6, Convert_addr		; R6 <-- Address pointer for Convert
LDR R1, R6, #0			; R1 <-- VARIABLE Convert

HALT
	;===================
	; "Function Calls"
	;===================

        ;=============
        ; Local Data
        ;=============
Convert_addr    .FILL	x5000	; The address of where to find the data
MASK		.FILL	x8000	; b1000 0000 0000 0000

                .ORIG x5000			    ; Remote data
Convert         .FILL xABCD		        ; <----!!!NUMBER TO BE CONVERTED TO BINARY!!!

.END