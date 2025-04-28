.data
newline: .asciiz "\n"
static_a: .float 5.300000
.data
float_const_4.000000: .float 4.000000
.text
.text
.globl main
main:
    move $fp, $sp
<<<<<<< HEAD
    addi $sp, $sp, -28
    sw   $ra, 24($sp)
    sw   $fp, 20($sp)
    la $t9, static_a
    l.s $f31, 0($t9)
    la $t8, float_const_4.000000
    l.s $f30, 0($t8)
    add.s $f29, $f31, $f30
    mov.s $f28, $f29
mtc1 $f28, $f28
cvt.s.w $f28, $f28
mtc1 $f31, $f31
cvt.s.w $f31, $f31
    add.s $f27, $f31, 
    mov.s $f26, $f27
    li $v0, 0
    lw   $fp, 20($sp)
    lw   $ra, 24($sp)
    addi $sp, $sp, 28
=======
    addi $sp, $sp, -16
    sw   $ra, 12($sp)
    sw   $fp, 8($sp)
    li $t9, 5
LABEL0:
    li $t8, 0
    slt $t7, $t8, $t9
    bnez $t7, LABEL1
    j LABEL2
LABEL2:
    li $t6, 1
    sub $t9, $t9, $t6
    j LABEL0
LABEL1:
    lw   $fp, 8($sp)
    lw   $ra, 12($sp)
    addi $sp, $sp, 16
>>>>>>> 6ccfb75a64099ecc5ff5952a333e07b31e7da547
    li $v0, 10
    syscall
