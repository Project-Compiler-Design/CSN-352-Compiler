.data
newline: .asciiz "\n"
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -20
    sw   $ra, 16($sp)
    sw   $fp, 12($sp)
    #Pushing a to stack
    addi $t8, $sp, 0
    #Loading constant 5 into register
    li $t9, 5
    sw $t9, 0($t8)
    #Pushing a to stack
    addi $t7, $sp, 4
    #Loading constant 10 into register
    li $t9, 10
    sw $t9, 0($t7)
    lw   $fp, 12($sp)
    lw   $ra, 16($sp)
    addi $sp, $sp, 20
    li $v0, 10
    syscall
