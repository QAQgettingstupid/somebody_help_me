;借我放一下, 還沒好

INCLUDE Irvine32.inc
includelib Irvine32.lib

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
my_DAS PROTO
my_DAA PROTO
test1 BYTE "DAS -> example : 48h - 35h",0
test2 BYTE "DAA -> example : 35h + 48h",0
say BYTE "here!!!",0
flags DWORD ?

.code
main proc

    ; ----- DAS ------

    mov al,48h 
    sub al,35h 

    ;取EFL到flags
    pushfd
    pop flags
    
    mov edx ,OFFSET test1
    call WriteString
    call Crlf
    call my_DAS
    call DumpRegs 

    ; ----- DAA ------

    mov al,35h 
    add al,48h

    ;取EFL到flags
    pushfd
    pop flags
    
    mov edx ,OFFSET test2
    call WriteString
    call Crlf
    call my_DAA
    call DumpRegs

    invoke ExitProcess,0
main endp

my_DAS PROC
    LOCAL AL_lo:BYTE,AL_hi:BYTE,AF_flag:BYTE,CF_flag:BYTE
    
    mov AF_flag,0
    mov CF_flag,0

    ;取後 4 bits
    mov AL_lo,AL
    AND AL_lo,0Fh

    ;取前 4 bits
    mov AL_hi,AL
    AND AL_hi,0F0h
    SHR AL_hi,4 ;讓AL_hi讀出來的值為0~15與AL_lo一致

    ; ------以下為低位檢查-------

    cmp AL_lo,9
    ja lo_changed ;低位須改變, 條件1 -> AL(lo) > 9
    
    bt flags,4 ;檢查AF
    jc lo_changed ;低位須改變, 條件2 -> AF=1

    jmp lo_not_changed ;低位不須改變

    lo_changed:

    sub AL,6
    mov AF_flag,1 ;AF = 1

    lo_not_changed:

    ; ------以下為高位檢查-------
    cmp AL_hi,9
    ja hi_changed ;高位須改變, 條件1 -> AL(hi) > 9

    bt flags,0 ;檢查CF
    jc hi_changed ;高位須改變, 條件2 -> CF=1

    jmp hi_not_changed ;高位不須改變

    hi_changed:

    sub AL,60h
    mov CF_flag,1 ;CF = 1

    hi_not_changed:

    .IF CF_flag == 1 && AF_flag == 1
        mov BL,15
        add BL,1
        stc
    .ELSEIF CF_flag == 1
        stc
    .ELSEIF AF_flag == 1
        mov BL,15
        add BL,1
    .ELSE
        mov BL,0
        add BL,0
    .ENDIF
    ret
my_DAS ENDP

my_DAA PROC
    LOCAL AL_lo:BYTE,AL_hi:BYTE,AF_flag:BYTE,CF_flag:BYTE
    
    mov AF_flag,0
    mov CF_flag,0

    ;取後 4 bits
    mov AL_lo,AL
    AND AL_lo,0Fh

    ; ------以下為低位檢查-------

    cmp AL_lo,9
    ja lo_changed ;低位須改變, 條件1 -> AL(lo) > 9
    
    bt flags,4 ;檢查AF
    jc lo_changed ;低位須改變, 條件2 -> AF=1

    jmp lo_not_changed ;低位不須改變

    lo_changed:

    add AL,6
    mov AF_flag,1 ;AF = 1

    lo_not_changed:

    ;取前 4 bits
    mov AL_hi,AL
    AND AL_hi,0F0h
    SHR AL_hi,4 ;讓AL_hi讀出來的值為0~15與AL_lo一致

    ; ------以下為高位檢查-------
    cmp AL_hi,9
    ja hi_changed ;高位須改變, 條件1 -> AL(hi) > 9

    bt flags,0 ;檢查CF
    jc hi_changed ;高位須改變, 條件2 -> CF=1

    jmp hi_not_changed ;高位不須改變

    hi_changed:

    add AL,60h
    mov CF_flag,1 ;CF = 1

    hi_not_changed:

    .IF CF_flag == 1 && AF_flag == 1
        mov BL,15
        add BL,1
        stc
    .ELSEIF CF_flag == 1
        stc
    .ELSEIF AF_flag == 1
        mov BL,15
        add BL,1
    .ELSE
        mov BL,0
        add BL,0
    .ENDIF
    ret
my_DAA ENDP

END main