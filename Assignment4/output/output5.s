# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
static_counter: .word 0
str0: .asciiz "Static counter ="
str1: .asciiz "Program finished.\n"
.text
.globl main
count_with_static:
    move $fp, $sp
    addi $sp, $sp, -56
    sw   $ra, 52($sp)
    sw   $fp, 48($sp)
    sw   $t0, 44($sp)
    sw   $t1, 40($sp)
    sw   $t2, 36($sp)
    sw   $t3, 32($sp)
    sw   $t4, 28($sp)
    sw   $t5, 24($sp)
    sw   $t6, 20($sp)
    sw   $t7, 16($sp)
    sw   $t8, 12($sp)
    sw   $t9, 8($sp)
    lw $t9, static_counter
    li $t8, 1
    add $t9, $t9, $t8
    la $a0, str0
    move $a1, $t9
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
    move $t7, $v0
main:
    move $fp, $sp
    addi $sp, $sp, -16
    sw   $ra, 12($sp)
    sw   $fp, 8($sp)
    li $t6, 0
    la $a0, str1
#printf
 move $a0, $a0
    li $v0, 4
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t5, $v0
    li $v0, 0
    lw   $fp, 8($sp)
    lw   $ra, 12($sp)
    li $v0, 10
    syscall
