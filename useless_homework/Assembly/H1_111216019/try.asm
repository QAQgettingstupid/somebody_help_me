INCLUDE Irvine32.inc
includelib Irvine32.lib

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
buffer BYTE 501 DUP(?) ;¤W­­¿é¤J500¦r¤¸
array WORD 50 DUP(?)
array_end DWORD ?
now WORD 0
to_int BYTE ?
now_char BYTE ?

.code
main proc

    mov edx, OFFSET buffer
    mov ecx, 20
    call DumpMem

    invoke ExitProcess,0
main endp

END main