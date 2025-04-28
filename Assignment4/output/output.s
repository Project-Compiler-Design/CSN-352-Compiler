.data
newline: .asciiz "\n"
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -12
    sw   $ra, 8($sp)
    sw   $fp, 4($sp)
    li $t9, 3
    li $v0, 0
    lw   $fp, 4($sp)
    lw   $ra, 8($sp)
    addi $sp, $sp, 12
    li $v0, 10
    syscall
