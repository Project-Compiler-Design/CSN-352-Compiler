.data
newline: .asciiz "\n"
str0: .asciiz "hello world"
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -12
    sw   $ra, 8($sp)
    sw   $fp, 4($sp)
    la $a0, str0
    li.s $f12, 3.100000
#printf
 move $a0, $a0
    li $v0, 4
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    mov.s $f12, $f12
    li $v0, 2
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t9, $v0
    li $v0, 10
    syscall
