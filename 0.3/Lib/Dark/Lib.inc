include ..\0.3\Lib\Irvine\Irvine32.inc
includelib ..\0.3\Lib\Irvine\Irvine32.lib

Include If.inc
Include Type.inc

;--------CoreFunctions--------;
.code
printS PROC s:_string
MOV edx, s
call WriteString
ret
printS ENDP

printI PROC i:_int
MOV eax, i
call WriteInt
ret
printI ENDP

printSLine PROC s:_string
MOV edx, s
call WriteString
call Crlf
ret
printSLine ENDP

printILine PROC i:_int
MOV eax, i
call WriteInt
call Crlf
ret
printILine ENDP

;--------CoreFunctions--------;