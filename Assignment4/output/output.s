.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -28
    sw   $ra, 24($sp)
    sw   $fp, 20($sp)
    li $t9, 0
    li $t9, 1
LABEL0:
    li $t8, 10
    slt $t7, $t9, $t8
    bnez $t7, LABEL2
    j LABEL1
LABEL2:
    li $t6, 3
    li $t5, 4
    add $t4, $t6, $t5
    move $t3, $t4
    move $t2, $t9
    add $t9, $t9, $t2
    j LABEL0
LABEL1:
    lw   $fp, 20($sp)
    lw   $ra, 24($sp)
    addi $sp, $sp, 28
    li $v0, 10
    syscall
