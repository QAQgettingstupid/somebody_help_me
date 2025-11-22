INCLUDE Irvine32.inc
includelib Irvine32.lib

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
buffer BYTE 501 DUP(?) ;上限輸入500字元
array WORD 50 DUP(?)
array_end DWORD ?
now WORD 0
to_int BYTE ?

.code
main proc

    mov esi,OFFSET array
    mov edx, OFFSET buffer ;輸入輸出均放到edx
    mov ecx, LENGTHOF buffer  
    call ReadString

    ;將字串轉轉存到array中
    .REPEAT 
        mov al,[edx] ;當前字元
        .IF al == ' '
              mov BX,now
              mov [esi],BX  
              add esi, TYPE array
              mov now, 0 ; now為暫存值

         .ELSE
              push eax
              movzx eax,now ;now*=10
              mov ebx,10
              mul ebx
              mov now,ax
              pop eax
              sub al,'0'  ;將字元轉為數字
              movzx cx,al 
              add now, cx 
         .ENDIF
         inc edx

    .UNTIL al == 0Dh 
    mov BX,now      ;存最後一個數字
    mov [esi],BX

    mov array_end,esi ;紀錄array結束位置
    mov esi,OFFSET array
    mov al, ' '

    ;遍歷輸出array內容
    .WHILE esi < array_end 
         movzx eax, WORD PTR [esi]
         call WriteDec
         mov al, ' '
         call WriteChar
         add esi,TYPE array
    .ENDW
    movzx eax, word ptr [esi]
    call WriteDec
    invoke ExitProcess,0
main endp

END main