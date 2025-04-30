# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
str0: .asciiz ""
str1: .asciiz "Single level pointer value:"
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
    lw $t9, 0($sp)
    li $t7, 1
    add $t9, $t9, $t7
    la $a0, str0
    #Pushing i to stack
    sw $t9, 0($sp)
    lw $t6, 0($t8)
    sw $t6, 4($sp)
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
    move $t9, $v0
    li $t5, 50
    #Pushing y to stack
    sw $t5, 8($sp)
    addi $t4, $sp, 8
    lw $t5, 8($sp)
    li $t3, 1
    sub $t5, $t5, $t3
    la $a0, str1
    #Pushing y to stack
    sw $t5, 8($sp)
    lw $t2, 0($t4)
    sw $t2, 12($sp)
    move $a1, $t2
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
    lw   $fp, 32($sp)
    lw   $ra, 36($sp)
    li $v0, 10
    syscall
