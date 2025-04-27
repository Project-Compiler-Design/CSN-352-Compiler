.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -20
    sw   $ra, 16($sp)
    sw   $fp, 12($sp)
    li.s $f31, 3.140000
    li.d $f28, 2.000000
    lw   $fp, 12($sp)
    lw   $ra, 16($sp)
    addi $sp, $sp, 20
    li $v0, 10
    syscall
