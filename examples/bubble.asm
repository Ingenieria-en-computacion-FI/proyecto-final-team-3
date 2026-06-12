; Algoritmo de ordenamiento bubble
section .text
global bubble

bubble:
    push ebp
    mov ebp, esp
    push ebx
    push esi
    push edi
    mov esi, [ebp+12]
    mov ecx, [ebp+8]
    dec ecx
loop_i:
    mov edi, 0
loop_j:
    mov eax, [esi+edi*4]
    mov ebx, [esi+edi*4+4]
    cmp eax, ebx
    jle no_swap
swap:
    mov [esi+edi*4], ebx
    mov [esi+edi*4+4], eax
no_swap:
    inc edi
    cmp edi, ecx
    jl loop_j
    dec ecx
    cmp ecx, 0
    jg loop_i
    pop edi
    pop esi
    pop ebx
    mov esp, ebp
    pop ebp
    ret
