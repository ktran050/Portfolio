;=================================================
; Name: Tran, Kevin
; Username: ktran050
;
; Lab: Lab 3
; Lab Section: 23
; TA: Jose Rodriguez
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
	LD  R5, DATA_PTR
	LDR R6, R5, #1
	LDR R3, R5, #0
	LDR R4, R5, #1
	ADD R3, R3, #1
	ADD R4, R4, #1
	STR R3, R5, #0
	STR R4, R5, #1
; Local Data
	HALT
		;; Remote data
	DATA_PTR	.FILL	x4000
		.orig x4000
	DEC_65	.FILL	#65
	HEX_41	.FILL	x41
.end