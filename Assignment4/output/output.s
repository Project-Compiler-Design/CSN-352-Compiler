.data
newline: .asciiz "\n"
str0: .asciiz ""
.text
.globl main
foo:
    move $fp, $sp
    addi $sp, $sp, -12
    sw   $ra, 8($sp)
    sw   $fp, 4($sp)
    move $t9, $a0
    li $v0, 2
    lw   $fp, 4($sp)
    lw   $ra, 8($sp)
    addi $sp, $sp, 12
    jr   $ra
main:
    move $fp, $sp
    addi $sp, $sp, -24
    sw   $ra, 20($sp)
    sw   $fp, 16($sp)
    li $t8, 2
    li $a0, 3
    jal foo
    move $t7, $v0
    move $t6, $t7
    la $a0, str0
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
    move $t5, $v0
    li $v0, 0
    lw   $fp, 16($sp)
    lw   $ra, 20($sp)
    addi $sp, $sp, 24
    li $v0, 10
    syscall
