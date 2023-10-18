; program to clear screen
code segment
start:    assume cs:code
    mov ax,0600h    ;06 to scroll & 00 for full screen
    mov bh,0fh    	;attribute black for background and white for foreground
    mov cx,0000h    ;starting coordinates
    mov dx,184fh    ;ending coordinates
    int 10h         ;for video display
    mov ah,4ch      ;return to dos mode
    int 21h
code ends
end start


lea dx, string_2             ; load & display the string_2
mov ah, 9
int 21h

mov dx,small
add dx,30h
mov ah,02h
int 21h

; ax contains the number to be decoded and printed
		xri cx,cx
decode:                 ; result in ax now but in the hex
        mov dx,0000h    ; resetting the dx
        div ten         ; divide the dx:ax/ten dx contains the remiander
        inc cx          ; counter is needed to keep track of numer of digits pused to stack
        add dx,30h      ; to get to the ascii code of the digit in dx
        push dx         ; push ascii equivalent to the stack
        cmp ax,00h      ; see if the quotient is 0
        jne decode      ; decode more of digits as ax !=0

printing:
        pop dx          ; pop from stax to dx
        mov ah,02h      ; setting up interrupt vector for  printing
        int 21h         ; calling dos interrupt vector
        loop printing   ; keep printing till the counter is zero, ie all digits are popped

