INCLUDE Irvine32.inc
includelib Irvine32.lib

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.code
main proc
    call ReadInt				
    add	eax,6				
    call WriteDec
    invoke ExitProcess,0
main endp

END main