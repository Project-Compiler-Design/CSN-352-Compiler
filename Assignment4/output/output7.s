# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
str0: .asciiz ""
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -32
    sw   $ra, 28($sp)
    sw   $fp, 24($sp)
    li $t9, 0
    #Pushing i to stack
    sw $t9, 0($sp)
    addi $t8, $sp, 0
    #Pushing ptr to stack
    sw $t8, 4($sp)
    addi $t9, $sp, 4
    lw $t8, 0($t9)
    sw $t8, 8($sp)
    #Loading constant 10 into register
    li $t7, 10
    sw $t7, 0($t8)
    la $a0, str0
    lw $t6, 0($sp)
    move $a1, $t6
#printf
 move $a0, $a0
    li $v0, 4
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
 move $a0, $a1
    li $v0, 1
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t5, $v0
    li $v0, 0
    lw   $fp, 24($sp)
    lw   $ra, 28($sp)
    li $v0, 10
    syscall
