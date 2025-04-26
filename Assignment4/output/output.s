.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -20
    sw   $ra, 16($sp)
    sw   $fp, 12($sp)
    li $t9, 1
    li $t8, 2
    seq $t7, $t9, $t8
    bnez $t7, LABEL0
    j LABEL1
LABEL0:
    li $t9, 3
    j LABEL2
LABEL1:
    li $t9, 4
LABEL2:
    move $v0, $t9
    lw   $fp, 12($sp)
    lw   $ra, 16($sp)
    addi $sp, $sp, 20
    li $v0, 10
    syscall
