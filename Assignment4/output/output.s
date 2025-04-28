.data
str0: .asciiz "Hi"
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -16
    sw   $ra, 12($sp)
    sw   $fp, 8($sp)
    li.s $f31, 5.500000
    la $a0, str0
    mov.s $f12, $f31
 move $a0, $a0
    li $v0, 4
syscall
    mov.s $f12, $f12
    li $v0, 2
syscall
    move $t9, $v0
    li $v0, 0
    lw   $fp, 8($sp)
    lw   $ra, 12($sp)
    addi $sp, $sp, 16
    li $v0, 10
    syscall
