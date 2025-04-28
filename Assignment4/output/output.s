.data
newline: .asciiz "\n"
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -24
    sw   $ra, 20($sp)
    sw   $fp, 16($sp)
    li.s $f31, 2.530000
    li.s $f30, 4.300000
    add.s $f29, $f31, $f30
    mov.s $f28, $f29
    lw   $fp, 16($sp)
    lw   $ra, 20($sp)
    addi $sp, $sp, 24
    li $v0, 10
    syscall
