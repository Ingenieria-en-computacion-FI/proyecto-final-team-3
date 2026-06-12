; ============================================================
; ejemplos/test2.asm
; Programa de demostracion general del ensamblador (IA-32).
; Ejercita: Algoritmo de ordenamiento Bubble sort usando extern
; ============================================================
extern bubble

section .data
arr: dd 7, 2, 9, 1, 5
n: dd 5

section .text
global _start
_start:
    push arr
    push n
    call bubble
    add esp, 8

    mov eax, 1       ; Número de syscall para sys_exit
    mov ebx, 0       
    int 0x80
