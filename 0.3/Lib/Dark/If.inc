;---------------MACROS---------------
_IF_ MACRO
MOV ecx, 1
ENDM

_ENDIF_ MACRO Code, End
CMP ecx, 1
JE Code
JMP End
ENDM

_ELSE_ MACRO ElseEnd
CMP ecx, 0
MOV ecx, 1
JNE ElseEnd
ENDM

_ELSE_IF_ MACRO ElseIfEnd
CMP ecx, 0
JNE ElseIfEnd
ENDM

_AND_ MACRO
ENDM

_OR_ MACRO Code
CMP ecx, 1
JE Code
MOV ecx, 1
ENDM
;---------------MACROS---------------

.code
;---------------IF---------------
_IS_EQUAL_ PROC
	.if(eax == ebx)
	IMUL ecx, 1
	.else
	IMUL ecx, 0
	.endif
	ret
_IS_EQUAL_ ENDP

_IS_NOT_EQUAL_ PROC
	.if(eax != ebx)
	IMUL ecx, 1
	.else
	IMUL ecx, 0
	.endif
	ret
_IS_NOT_EQUAL_ ENDP

_IS_LESS_ PROC
	.if(eax < ebx)
	IMUL ecx, 1
	.else
	IMUL ecx, 0
	.endif
	ret
_IS_LESS_ ENDP

_IS_LESS_EQUAL_ PROC
	.if(eax <= ebx)
	IMUL ecx, 1
	.else
	IMUL ecx, 0
	.endif
	ret
_IS_LESS_EQUAL_ ENDP

_IS_GREATER_ PROC
	.if(eax > ebx)
	IMUL ecx, 1
	.else
	IMUL ecx, 0
	.endif
	ret
_IS_GREATER_ ENDP

_IS_GREATER_EQUAL_ PROC
	.if(eax >= ebx)
	IMUL ecx, 1
	.else
	IMUL ecx, 0
	.endif
	ret
_IS_GREATER_EQUAL_ ENDP
;---------------IF---------------