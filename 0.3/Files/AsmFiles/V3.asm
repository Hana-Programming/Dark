includelib ..\0.3\Lib\Irvine\Kernel32.Lib
includelib ..\0.3\Lib\Irvine\User32.Lib

include ..\0.3\Lib\Dark\Lib.inc

.data
Xstring _COMP_VAR_1, "Debug: "
Xstring _COMP_VAR_2, "Baby a Triple!"
Xstring _COMP_VAR_3, "X Times 5 is: "
.code
Xtimes5 PROC x:_int
MOV eax, 5
MOV ebx, x
IMUL ebx, eax
MOV x, ebx
MOV ebx, x
ret
ret
Xtimes5 ENDP
XtimesY PROC x:_int, y:_int
MOV eax, y
MOV ebx, x
IMUL ebx, eax
MOV x, ebx
MOV ebx, x
ret
ret
XtimesY ENDP
IO?Debug PROC i:_int
INVOKE printS,OFFSET _COMP_VAR_1
INVOKE printILine,i
ret
IO?Debug ENDP
Main PROC 
MOV eax, 0
MOV _int PTR [ebp-4], eax
INVOKE XtimesY,1,3
MOV eax, ebx
MOV _int PTR[ebp - 4], eax
MOV eax, _int PTR[ebp - 4]
.if(eax==15)
JMP switch_0_0
.endif
.if(eax==3)
JMP switch_0_1
.endif
JMP R0_endif
switch_0_0:
INVOKE IO?Debug,_int PTR[ebp - 4]
JMP R0_endif
switch_0_1:
INVOKE printSLine,OFFSET _COMP_VAR_2
JMP R0_endif
R0_endif:
INVOKE printS,OFFSET _COMP_VAR_3
INVOKE Xtimes5, _int PTR[ebp - 4]
INVOKE printILine, ebx
exit
Main ENDP
END Main