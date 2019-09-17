.cpu cortex-m0
.text
.global print_asciz
.align 1


print_asciz:
    PUSH {r5, lr}
    MOV  r5, r0

loop:
    LDRB r0, [r5]
    ADD r0,r0,#0
    BEQ done
    BL uart_put_char
    ADD R5, R5, #1
    B loop

done:
    POP {r5, pc}