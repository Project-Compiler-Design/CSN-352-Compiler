.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -32
    sw   $ra, 28($sp)
    sw   $fp, 24($sp)
    li $t9, 4
    li $t8, 10
    #Pushing a to stack
    sw $t9, 0($sp)
    addi $t7, $sp, 0
    sw $t8, 0($t7)
    lw $t9, 0($t7)
    sw $t9, 4($sp)
    lw $t6, 0($sp)
    add $t5, $t6, $t8
    move $t4, $t5
    lw   $fp, 24($sp)
    lw   $ra, 28($sp)
    addi $sp, $sp, 32
    li $v0, 10
    syscall