.data
newline: .asciiz "\n"
<<<<<<< HEAD
str0: .asciiz ""
=======
>>>>>>> 7ded009652e8681e96e875a2978bc5871bdc8344
.text
.globl main
addx:
    move $fp, $sp
    addi $sp, $sp, -72
    sw   $ra, 68($sp)
    sw   $fp, 64($sp)
    sw   $t0, 60($sp)
    sw   $t1, 56($sp)
    sw   $t2, 52($sp)
    sw   $t3, 48($sp)
    sw   $t4, 44($sp)
    sw   $t5, 40($sp)
    sw   $t6, 36($sp)
    sw   $t7, 32($sp)
    sw   $t8, 28($sp)
    sw   $t9, 24($sp)
    move $t9, $a0
    move $t8, $a1
    li $t7, 0
    seq $t6, $t8, $t7
    bnez $t6, LABEL0
    j LABEL1
LABEL0:
    move $v0, $t9
    lw   $fp, 64($sp)
    lw   $ra, 68($sp)
    lw   $t0, 60($sp)
    lw   $t1, 56($sp)
    lw   $t2, 52($sp)
    lw   $t3, 48($sp)
    lw   $t4, 44($sp)
    lw   $t5, 40($sp)
    lw   $t6, 36($sp)
    lw   $t7, 32($sp)
    lw   $t8, 28($sp)
    lw   $t9, 24($sp)
    addi $sp, $sp, 72
    jr   $ra
    j LABEL2
LABEL1:
    li $t5, 1
    sub $t4, $t8, $t5
    move $a0, $t9
    move $a1, $t4
    jal addx
    move $t3, $v0
    add $t2, $t9, $t3
    move $v0, $t2
    lw   $fp, 64($sp)
    lw   $ra, 68($sp)
    lw   $t0, 60($sp)
    lw   $t1, 56($sp)
    lw   $t2, 52($sp)
    lw   $t3, 48($sp)
    lw   $t4, 44($sp)
    lw   $t5, 40($sp)
    lw   $t6, 36($sp)
    lw   $t7, 32($sp)
    lw   $t8, 28($sp)
    lw   $t9, 24($sp)
    addi $sp, $sp, 72
    jr   $ra
LABEL2:
main:
    move $fp, $sp
<<<<<<< HEAD
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
=======
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
>>>>>>> 7ded009652e8681e96e875a2978bc5871bdc8344
    li $v0, 10
    syscall
