; WAP 8085 sort set of 3 data at 9040H in ascending order
; Store sorted table at 9054H
; move data
; set of 3 readings mean 6 byte data
; readings are 16 bit data

        LXI H,9040H	; copy data to dest
        LXI B,9054H
        MVI D,0AH	; 20 dec down counter

COPY:	MOV A,M
        STAX B
        INX H
        INX B
        DCR D
        JNZ COPY
; sorting
        MVI D,06H

AGAIN:	LXI H,9054H	; sort at destination
        MVI C,05H	; SUB counter main-1

        NEX: MOV A,M
        INX H 
        CMP M	     ; compare with 2nd data
        JC NOSWAP	 ; A < M sets carry
        MOV B,M
        MOV M,A
        DCX H
        MOV M,B
        INX H

NOSWAP: DCR C
        JNZ NEX
        DCR D
        JNZ AGAIN
        HLT
