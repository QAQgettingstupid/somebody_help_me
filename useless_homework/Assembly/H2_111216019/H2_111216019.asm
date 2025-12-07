; 作者: 111216019 蔡芳宇
; 輸入說明: 單行輸入四則運算式，數字與運算元不得有空白且只能輸入正整數
; 輸出說明: 含正負號之結果
; 數值上限: 結果(包含中途計算上限)可為: -32768~32767，最多連續輸入50個數字、50個運算元，總字串長度不得超過 500 字元
; 自評分數: 20%+60%+20%

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
now WORD 0
now_char BYTE ?
changed BYTE 0 ;數值是否被改變過flag
count BYTE 0 ;是否做運算flag
temp BYTE ? ;暫存用

error BYTE "divisor can't be 0 !!!",0

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

calculate PROTO

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

              ;右括號
              .IF now_char == ')'

                    ;pop到左括號為止
                    .REPEAT 
                        mov al,[edi - TYPE operator]
                        .IF al != '('
                            call calculate
                        .ENDIF
                        sub edi, TYPE operator 
                        dec operator_index ;operator元素-1

                    .UNTIL al == '(' 

              ;左括號
              .ELSEIF now_char == '('
                    mov BL,now_char
                    mov [edi],BL
                    add edi, TYPE operator
                    inc operator_index ;operator元素+1

              ; +-*/
              .ELSE
                    ;做到當前優先權大於stack top可push為止
                    .REPEAT 
                        cmp operator_index,0
                        jna only_one ;若包含當前只有一個運算元直接跳出
               
                        mov al,[edi - TYPE operator]
                        .IF al != '('
                            mov temp,al

                            ;比較優先權
                            INVOKE find_priority,temp,now_char

                            .IF count == 1
                                
                                ;四則運算
                                call calculate
                                sub edi, TYPE operator
                                dec operator_index ;operator元素-1

                            .ENDIF
                        .ENDIF
                    .UNTIL al == '(' || count == 0

                    only_one:

                    ;存入operator
                    mov BL,now_char
                    mov [edi],BL
                    add edi, TYPE operator
                    inc operator_index ;operator元素+1

              .ENDIF

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
    add esi, TYPE operand
    inc operand_index

    not_changed2:

    movzx ecx,operator_index

    ;遍歷剩餘operator做運算
    L2:
        call calculate
        sub edi, TYPE operator
        dec operator_index
        loop L2

    movsx eax,WORD PTR [operand]
    call WriteInt

    invoke ExitProcess,0
main endp


; -----------------------------
; find_priority
; 用途:比較當前運算元與 stack top 運算元優先權,及是否需要做四則運算
; 回傳值: count ,1 = 需做運算,0 = 不需做運算
; -----------------------------

find_priority PROC,
    front:BYTE, 
    back:BYTE
    
    local f:BYTE,b:BYTE
    
    push ebx
    push ecx

    
    mov ebx,OFFSET CaseTable
    mov ecx,NumberOfEntries

    ;遍歷table找優先權
    L5:
        mov al,[ebx] ;取運算元
        cmp al,front
        jne notfound_front ;沒找到對應前運算元優先權
        mov ah,[ebx+1]
        mov f,ah ;取前優先權

        notfound_front:
        cmp al,back
        jne notfound_back ;沒找到對應後運算元優先權
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

    mov count,0 ;初始化為不需做運算
    ja back_higher ;後項優先權較高
    mov count,1

    back_higher:

    ret
find_priority ENDP

; -----------------------------
; calculate
; 用途:實作四則運算
; -----------------------------

calculate PROC
    Local num_f:SWORD, num_b:SWORD, operator_now:BYTE
    
    ;取運算元
    push eax
    mov al, [edi - TYPE operator]
    mov operator_now, al
    pop eax

    ;取後數值
    push eax
    mov ax, [esi - TYPE operand]
    mov num_b, ax
    sub esi, TYPE operand
    dec operand_index 

    ;取前數值
    mov ax, [esi - TYPE operand]
    mov num_f, ax
    sub esi, TYPE operand
    dec operand_index 
    pop eax

    ;防值竄改
    push eax
    push ebx
    push ecx
    push edx

    .IF operator_now == '+'
        mov ax,num_f
        add ax, num_b

    .ELSEIF operator_now == '-'
        mov ax,num_f
        sub ax, num_b

    .ELSEIF operator_now == '*'
        mov ax,num_b
        imul num_f

    .ELSEIF operator_now == '/'

        cmp num_b,0
        je div_by_zero ;除以0錯誤處理

        mov ax,num_f
        CWD
        idiv num_b
    .ENDIF


    ;存結果回operand (以上結果剛好都在ax)
    mov [esi], ax
    add esi, TYPE operand
    inc operand_index

    ;還原值
    pop edx
    pop ecx
    pop ebx
    pop eax

    ret
calculate ENDP

div_by_zero:
    mov edx, OFFSET error
    call WriteString
    invoke ExitProcess,0

END main