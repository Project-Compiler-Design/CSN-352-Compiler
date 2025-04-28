.data
newline: .asciiz "\n"
str0: .asciiz "Hi"
.text
.globl main
main:
    move $fp, $sp
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
    li $v0, 10
    syscall
