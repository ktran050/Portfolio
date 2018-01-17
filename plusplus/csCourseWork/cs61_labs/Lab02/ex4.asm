;=================================================
; Name: Tran, Kevin
; Username: ktran050
;
; Lab: Lab 2
; Lab Section: 23
; TA: David Rodriguez
;=================================================
.orig x3000
; Instructions
	LD R0, HEX_61
	LD R1, HEX_1A
	DO_WHILE_LOOP
		OUT
		ADD R0, R0, #1
		ADD R1, R1, #-1
		BRp DO_WHILE_LOOP
	END_DO_WHILE_LOOP
		
; Local Data
	HALT
	HEX_61	.FILL	x61
	HEX_1A	.FILL	x1A
.end