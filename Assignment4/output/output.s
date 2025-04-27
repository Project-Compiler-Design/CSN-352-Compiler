.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -20
    sw   $ra, 16($sp)
    sw   $fp, 12($sp)
    li $t9, 4
    #Pushing b to stack
    addi $t7, $sp, 0
    #Loading constant 5 into register
    li $t6, 5
    sw $t6, 0($t7)
    lw   $fp, 12($sp)
    lw   $ra, 16($sp)
    addi $sp, $sp, 20
    li $v0, 10
    syscall

