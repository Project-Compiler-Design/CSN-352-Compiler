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
    addi $sp, $sp, -20
    sw   $ra, 16($sp)
    sw   $fp, 12($sp)
    addi $t9, $sp, 0
    #Loading constant 1 into register
    li $t8, 1
    sw $t8, 0($t9)
    addi $t7, $sp, 0
    #Loading constant 2 into register
    li $t6, 2
    sw $t6, 0($t7)
    li $v0, 0
    lw   $fp, 12($sp)
    lw   $ra, 16($sp)
    li $v0, 10
    syscall
