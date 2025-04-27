.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -24
    sw   $ra, 20($sp)
    sw   $fp, 16($sp)
    li $t9, 5
    li.s $f31, 5.300000
mtc1 $t9, $f30
cvt.s.w $f30, $f30
    add.s $f29, $f31, $f30
    mov.s $f28, $f29
    lw   $fp, 16($sp)
    lw   $ra, 20($sp)
    addi $sp, $sp, 24
    li $v0, 10
    syscall
