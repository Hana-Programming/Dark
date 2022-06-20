_char typedef byte
_int typedef sdword
_bool typedef byte
_float typedef real4
_string typedef dword

_MOV MACRO type, value
	MOV type PTR [eax], value
ENDM

_GET MACRO type, output
	MOV output, type PTR [eax]
ENDM

ARRAY MACRO name, type, size
	name type size DUP(0)
ENDM

Xstring MACRO name, value
	name _char value, 0
ENDM

?MOV MACRO type, distance, value
	MOV eax, ebp
	SUB eax, distance
	_MOV type, value
ENDM

?GET MACRO type, distance, output
	MOV eax, ebp
	SUB eax, distance
	_GET type, output
ENDM

?MOV_STRING MACRO start, value
	MOV esi, ebp
	ADD esi, start

	MOV ebx, esi
	ADD ebx, LENGTHOF value

	L1:

	MOV eax, esi
	SUB eax, ebx

	CMP eax, 0
	JE L2

	MOV ecx, esi
	SUB ecx, ebp
	DEC ecx

	MOV dl, value[ecx]
	MOV _char PTR [esi], dl
	INC esi
	JMP L1
	L2:
ENDM

?GET_STRING MACRO start, value

	MOV ebx, start
	MOV ecx, ebx
	ADD ecx, LENGTHOF value
	MOV edx, 0

	L3:
    ?GET _char, ebx, al

	MOV value[edx], al
	INC ebx
	INC edx
	CMP ebx, ecx
	JNE L3
ENDM