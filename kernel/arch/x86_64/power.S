; .intel_syntax noprefix

; .section .text
; .global shutdown
; .type shutdown, @function

; shutdown:
; 	mov ax, 0x1000
; 	mov ax, ss
; 	mov sp, 0xf000
; 	mov ax, 0x5307
; 	mov bx, 0x0001
; 	mov cx, 0x0003
; 	int 0x15