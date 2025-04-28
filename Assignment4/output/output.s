.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -28
    sw   $ra, 24($sp)
    sw   $fp, 20($sp)
    li $t8, 0
    li $t7, 4
    mul $t6, $t8, $t7
    li $t5, 1
    addi $t6, $t6, 0
    add $t6, $t6, $sp
    sw $t5, 0($t6)
    move $t4, $t5
    move $t3, $t7
    mul $t2, $t4, $t3
    li $t1, 2
    addi $t2, $t2, 0
    add $t2, $t2, $sp
    sw $t1, 0($t2)
    li $t0, 8
    move $t9, $t7
    move $t6, $t8
    mul $t2, $t9, $t6
    addi $t2, $t2, 0
    add $t2, $t2, $sp
    sw $t0, 0($t2)
    lw   $fp, 20($sp)
    lw   $ra, 24($sp)
    addi $sp, $sp, 28
    li $v0, 10
    syscall