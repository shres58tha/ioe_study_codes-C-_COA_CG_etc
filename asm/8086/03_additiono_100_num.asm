; 2074 bhadra add first 100 even number and display it
; working
      .model small
      .stack 100h
      .data
        ten dw 10
      .code


       main proc far
        mov ax,@data    ;initiliaze data and put it to data segment register
        mov ds,ax
        mov cx,64h      ; enter 100 int the counter register

        mov ax,00h      ; ax is to be used as accumulator
        mov dx,02h      ; dx is used as even counter and 2 is first even number
looping:
        add ax,dx
        add dx,02h      ; increment dx by 2
        loop looping    ; loops unitil the counter register decrements to 0

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

        mov ax,4C00h    ; setting interrupt vector for terminating program gracefully
        int 21h         ; calling interrupt vector
       main endp        ; ending main procedure
       end main         ; program terminated


