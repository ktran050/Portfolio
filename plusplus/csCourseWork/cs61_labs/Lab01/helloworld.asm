;
; Tran, Kevin
; Login: ktran050 (ktran050@ucr.edu)
; Section: 23
; TA: Jose Rodriguez
; Lab 01
;
.ORIG x3000
; Instructions
	LEA R0, MSG_TO_PRINT
	PUTS
	HALT
; Local Data
	MSG_TO_PRINT	.STRINGZ	"Hello world!!!\n"
.END