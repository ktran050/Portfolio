;=================================================
; Name: Tran, Kevin
; Username: ktran050
;
; Lab: Lab 2
; Lab Section: 23
; TA: David Rodriguez
;=================================================
.orig x3000
;
; Replace the data stored at DEC_65 and HEX_41 with two far away addresses such as x4000 and x4001
; (Don't change the labels) add the code segment from
;
; Instructions
	; Write a program that uses .FILL to load #65 and x41 into two memory locations with labels DEC_65 and HEX_41
	; Then use LD to load these values into register R3 and R4
	; Run the program and inspect the registers
	LD  R5, POINTER1
	LD  R6, POINTER2
	LDR R3, R5, #0
	LDR R4, R5, #1
	ADD R3, R3, #1
	ADD R4, R4, #1
	STR R3, R5, #0
	STR R4, R6, #0
; Local Data
	HALT
		;; Remote data
	POINTER1	.FILL	x4000
	POINTER2	.FILL	x4001
		.orig x4000
	DEC_65	.FILL	#65
	HEX_41	.FILL	x41
.end