.data
newline: .asciiz "\n"
str0: .asciiz ""
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -32
    sw   $ra, 28($sp)
    sw   $fp, 24($sp)
    li.s $f31, 1.000000
    #Pushing a to stack
    s.s $f31, 0($sp)
    li.s $f31, 0
   add.s $f30, $sp, $f31
    #Pushing b to stack
    s.s $f30, 4($sp)
    li.s $f30, 4
   add.s $f29, $sp, $f30
    l.s $f28, 0($f29)
    s.s $f28, 8($sp)
    #Loading constant 2.000000 into register
    li.s $f27, 2.000000
    s.s $f27, 0($f28)
    la $a0, str0
#printf
 move $a0, $a0
    li $v0, 4
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t9, $v0
    li $v0, 0
    lw   $fp, 24($sp)
    lw   $ra, 28($sp)
    addi $sp, $sp, 32
    li $v0, 10
    syscall
