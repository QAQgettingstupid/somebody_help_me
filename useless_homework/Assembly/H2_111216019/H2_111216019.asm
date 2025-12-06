INCLUDE Irvine32.inc
includelib Irvine32.lib

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
buffer BYTE 501 DUP(?) ;上限輸入500字元
operand SWORD 50 DUP(?)   ;上限輸入50數字
operator BYTE 50 DUP(?)   ;上限輸入50數字
operand_index WORD 0
operator_index WORD 0
front_operator BYTE 0
now WORD 0
now_char BYTE ?
changed BYTE 0 ;數值是否被改變過flag
count BYTE 0 ;是否做運算flag

try BYTE "here!!! ",0

;運算元優先權表
CaseTable BYTE '+',1
          EntrySize = ($ - CaseTable)
          BYTE '-',1
          BYTE '*',2
          BYTE '/',2
          BYTE '(',0
          BYTE ')',3

NumberOfEntries = ($ - CaseTable)/EntrySize

find_priority PROTO,
    front:BYTE, 
    back:BYTE

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

              movzx eax, front_operator
              call WriteDec
              mov al, '$'
              call WriteChar
              movzx eax, now_char
              call WriteDec
              call Crlf
              
              
              mov BL,now_char
              mov [edi],BL
              add edi, TYPE operator
              inc operator_index ;operator元素+1

              ;是否多於2個運算元
              cmp front_operator,0

              jz less_than_two ;少於2個運算元
              INVOKE find_priority,front_operator,now_char
              mov count,0

              less_than_two:
              mov front_operator, BL

              cmp changed,0

              je not_changed ;若沒變化不存入operand

              ;存入數值
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
        movsx eax, WORD PTR [esi]
        call WriteInt
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

; 比較當前運算元與stack top運算元優先權
find_priority PROC,
    front:BYTE, 
    back:BYTE
    
    local f:BYTE,b:BYTE
    
    push ebx
    push ecx

    ;遍歷table找優先權
    mov ebx,OFFSET CaseTable
    mov ecx,NumberOfEntries

    L5:
        mov al,[ebx] ;取運算元
        cmp al,front
        jne notfound_front
        mov ah,[ebx+1]
        mov f,ah ;取前優先權

        notfound_front:
        cmp al,back
        jne notfound_back
        mov ah,[ebx+1]
        mov b,ah ;取後優先權
        
        notfound_back:
        add ebx,EntrySize
        loop L5
    pop ecx
    pop ebx

    ;比較優先權
    mov al,b
    cmp al,f
    ja back_higher ;後項優先權較高
    mov count,1
    ;還沒做QAQ

    back_higher:

    push edx
    mov edx, offset try
    call WriteString
    call Crlf
    pop edx

    ret
find_priority ENDP

END main