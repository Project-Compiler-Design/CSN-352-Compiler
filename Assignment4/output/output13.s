# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
str0: .asciiz "1"
str1: .asciiz "2"
str2: .asciiz "3"
str3: .asciiz "default"
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -40
    sw   $ra, 36($sp)
    sw   $fp, 32($sp)
    li $t9, 5
    li $t8, 1
    seq $t7, $t9, $t8
    bnez $t7, LABEL0
    li $t6, 2
    seq $t5, $t9, $t6
    bnez $t5, LABEL1
    li $t4, 3
    seq $t3, $t9, $t4
    bnez $t3, LABEL2
    j LABEL3
LABEL0:
    la $a0, str0
#printf
 move $a0, $a0
    li $v0, 4
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t2, $v0
    j LABEL4
LABEL1:
    la $a0, str1
#printf
 move $a0, $a0
    li $v0, 4
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t1, $v0
    j LABEL4
LABEL2:
    la $a0, str2
#printf
 move $a0, $a0
    li $v0, 4
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t0, $v0
    j LABEL4
LABEL3:
    la $a0, str3
    # Spilling a from $t9
#printf
 move $a0, $a0
    li $v0, 4
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t9, $v0
LABEL4:
    li $v0, 0
    lw   $fp, 32($sp)
    lw   $ra, 36($sp)
    li $v0, 10
    syscall
