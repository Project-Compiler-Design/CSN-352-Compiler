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
    addi $sp, $sp, -40
    sw   $ra, 36($sp)
    sw   $fp, 32($sp)
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
    lw $t6, 0($t9)
    sw $t6, 8($sp)
    lw $t5, 0($t6)
    sw $t5, 12($sp)
    move $a1, $t5
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
    lw   $fp, 32($sp)
    lw   $ra, 36($sp)
    li $v0, 10
    syscall
