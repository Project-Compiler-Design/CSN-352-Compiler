# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -24
    sw   $ra, 20($sp)
    sw   $fp, 16($sp)
    li $t9, 50
    #Pushing y to stack
    sw $t9, 0($sp)
    addi $t8, $sp, 0
    #Pushing p1 to stack
    sw $t8, 4($sp)
    addi $t9, $sp, 4
    #Pushing p2 to stack
    sw $t9, 8($sp)
    addi $t8, $sp, 8
    lw $t9, 0($sp)
    li $t7, 1
    sub $t9, $t9, $t7
    li $v0, 0
    lw   $fp, 16($sp)
    lw   $ra, 20($sp)
    li $v0, 10
    syscall
