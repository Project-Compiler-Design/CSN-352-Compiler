# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
str0: .asciiz "Sum of 10 numbers is:"
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -24
    sw   $ra, 20($sp)
    sw   $fp, 16($sp)
    li $t9, 0
    li $t8, 0
    li $t9, 0
LABEL0:
    li $t7, 10
    slt $t6, $t9, $t7
    bnez $t6, LABEL2
    j LABEL1
LABEL2:
    add $t8, $t8, $t9
    li $t5, 1
    add $t9, $t9, $t5
    j LABEL0
LABEL1:
    la $a0, str0
    move $a1, $t8
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
    move $t4, $v0
    li $v0, 0
    lw   $fp, 16($sp)
    lw   $ra, 20($sp)
    li $v0, 10
    syscall
