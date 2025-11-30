; 作者: 111216019 蔡芳宇
; 輸入說明: 單行輸入多個以空格分隔的數字，最後一個數字後不得有多餘的空白字元
; 數值上限: 數字範圍:0~65535，最多連續輸入50個數字，總字串長度（包含空白）不得超過 500 字元
; 自評分數: 20%+80%

INCLUDE Irvine32.inc
includelib Irvine32.lib

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
buffer BYTE 501 DUP(?) ;上限輸入500字元
array WORD 50 DUP(?)   ;上限輸入50數字
array_index WORD 0
now WORD 0
now_char BYTE ?

.code
main proc

    mov esi,OFFSET array
    mov edx, OFFSET buffer ;輸入輸出均放到edx
    mov ecx, LENGTHOF buffer  
    call ReadString

    ;將字串轉轉存到array中
    .REPEAT 
        mov al,[edx] ;當前字元

        mov now_char,al 
        cmp now_char, 0 
        je done ;到結束字元跳出迴圈

        .IF now_char == ' '
              mov BX,now
              mov [esi],BX 
              add esi, TYPE array
              mov now, 0 ; now為暫存值
              inc array_index ;array元素+1

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

        .ENDIF
        inc edx ;下一個字元


    .UNTIL now_char == 0

    done:
    mov BX,now      ;存最後一個數字
    mov [esi],BX
    inc array_index

    ; bubble sort
    movzx ecx,array_index

    L1:
        mov esi,OFFSET array
        push ecx
        movzx ecx,array_index
        dec ecx

        L2:
            mov ax, [esi]
            cmp ax, [esi + TYPE array]

            ja same ;不交換

            mov ax, [esi + TYPE array] ;ax -> 後項
            XCHG [esi],ax
            mov [esi + TYPE array],ax

            same:
            add esi, TYPE array

            loop L2
        
        pop ecx

        loop L1


    mov esi,OFFSET array
    movzx ecx,array_index
    mov al, ' '

    ;遍歷輸出array內容
    L3:
        movzx eax, WORD PTR [esi]
        call WriteDec
        mov al, ' '
        call WriteChar
        add esi,TYPE array
        loop L3

    invoke ExitProcess,0
main endp

END main