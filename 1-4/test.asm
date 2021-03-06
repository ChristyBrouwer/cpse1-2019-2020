.cpu cortex-m0
.text
.global print_asciz
.global application
.align 1


print_asciz:
    PUSH {r5, lr}
    MOV  r5, r0

loop:
    LDRB r0, [r5]
    ADD r0,r0,#0
    BEQ done
    BL toggle_case
    BL uart_put_char
    ADD R5, #1
    B loop

done:
    POP {r5, pc}


.data
tekst:
    .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"

.text
application:
   PUSH {r0, lr}
    LDR  r0, =tekst
    BL print_asciz
    POP {r0, pc}

toggle_case:
    PUSH {r0, lr}
    LDR  r0, =tekst

    cmp r0, #65
    blt return

    cmp r0, #91
    blt lower

    cmp r0, #122
    bgt return

    cmp r0, #96
    bgt upper

lower:
    add r0, r0, #32
    b return

upper:
    sub r0, r0, #32

return:
    POP {r0, pc}