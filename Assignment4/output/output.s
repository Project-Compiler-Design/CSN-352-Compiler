.data
newline: .asciiz "\n"
str0: .asciiz "Hi"
.text
.globl main
main:
    move $fp, $sp
<<<<<<< HEAD
    addi $sp, $sp, -28
    sw   $ra, 24($sp)
    sw   $fp, 20($sp)
    li $t9, 0
    li $t9, 1
LABEL0:
    li $t8, 10
    slt $t7, $t9, $t8
    bnez $t7, LABEL2
    j LABEL1
LABEL2:
    li $t6, 3
    li $t5, 4
    add $t4, $t6, $t5
    move $t3, $t4
    move $t2, $t9
    add $t9, $t9, $t2
    j LABEL0
LABEL1:
    lw   $fp, 20($sp)
    lw   $ra, 24($sp)
    addi $sp, $sp, 28
=======
    addi $sp, $sp, -16
    sw   $ra, 12($sp)
    sw   $fp, 8($sp)
    li $t9, 5
    la $a0, str0
    move $a1, $t9
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
    move $t8, $v0
    li $v0, 0
    lw   $fp, 8($sp)
    lw   $ra, 12($sp)
    addi $sp, $sp, 16
>>>>>>> 6ff312695b6cdb9a4e3b8b18207282560174ae9d
    li $v0, 10
    syscall
