INCLUDE Irvine32.inc
includelib Irvine32.lib

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
buffer BYTE 501 DUP(?) ;上限輸入500字元
operand WORD 50 DUP(?)   ;上限輸入50數字
operator BYTE 50 DUP(?)   ;上限輸入50數字
operand_index WORD 0
operator_index WORD 0
now WORD 0
now_char BYTE ?
changed BYTE 0 
temp DWORD ?

.code
main proc

    mov esi,OFFSET operand
    mov edi,OFFSET operator
    mov edx, OFFSET buffer ;輸入輸出均放到edx
    mov ecx, LENGTHOF buffer  
    call ReadString

    ;將字串轉轉存到operand中
    .REPEAT 
        mov al,[edx] ;當前字元

        mov now_char,al 
        cmp now_char, 0 
        je done ;到結束字元跳出迴圈

        .IF now_char == '(' || now_char == ')' || now_char == '+' || now_char == '-' || now_char == '*' || now_char == '/'
              
              mov BL,now_char
              mov [edi],BL
              add edi, TYPE operator
              inc operator_index ;operator元素+1
              cmp changed,0

              je not_changed ;若沒變化不存入operand

              mov BX,now
              mov [esi],BX 
              add esi, TYPE operand
              mov now, 0 ; now為暫存值
              inc operand_index ;operand元素+1
              mov changed,0

              not_changed:

        .ELSE 
              mov ax,now ;now*=10
              mov bx,10
              push edx  ;防乘法破壞edx
              mul bx
              pop edx
              mov now,ax
              mov al,now_char
              sub al,'0'  ;將字元轉為數字
              movzx cx,al 
              add now, cx
              mov changed,1

        .ENDIF
        inc edx ;下一個字元


    .UNTIL now_char == 0

    done:
    cmp changed,0

    je not_changed2 ;若沒變化不存入operand
    mov BX,now      ;存最後一個數字
    mov [esi],BX
    inc operand_index

    not_changed2:

    mov esi,OFFSET operand
    movzx ecx,operand_index
    mov al, ' '

    ;遍歷輸出operand內容
    L3:
        movzx eax, WORD PTR [esi]
        call WriteDec
        mov al, ' '
        call WriteChar
        add esi,TYPE operand
        loop L3

    call Crlf

    mov esi,OFFSET operator
    movzx ecx,operator_index
    mov al, ' '

    ;遍歷輸出operator內容
    L4:
        mov al, BYTE PTR [esi]
        call WriteChar
        mov al, ' '
        call WriteChar
        add esi,TYPE operator
        loop L4

    invoke ExitProcess,0
main endp

END main