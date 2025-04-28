.data
newline: .asciiz "\n"
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -16
    sw   $ra, 12($sp)
    sw   $fp, 8($sp)
    li $t9, 5
LABEL0:
    li $t8, 0
    slt $t7, $t8, $t9
    bnez $t7, LABEL1
    j LABEL2
LABEL2:
    li $t6, 1
    sub $t9, $t9, $t6
    j LABEL0
LABEL1:
    lw   $fp, 8($sp)
    lw   $ra, 12($sp)
    addi $sp, $sp, 16
    li $v0, 10
    syscall
