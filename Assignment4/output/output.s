.data
newline: .asciiz "\n"
str0: .asciiz ""
str1: .asciiz ""
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -32
    sw   $ra, 28($sp)
    sw   $fp, 24($sp)
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
    li $t6, 4
    la $a0, str0
    move $a1, $t6
#scanf
    li $v0, 4
syscall
    li $v0, 5
syscall
move $t6 ,$v0
    move $t5, $v0
    la $a0, str1
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
    move $t4, $v0
    li $v0, 0
    lw   $fp, 24($sp)
    lw   $ra, 28($sp)
    addi $sp, $sp, 32
    li $v0, 10
    syscall
