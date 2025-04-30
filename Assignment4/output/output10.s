# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
str0: .asciiz " Answer"
.text
.globl main
fun:
    move $fp, $sp
    addi $sp, $sp, -64
    sw   $ra, 60($sp)
    sw   $fp, 56($sp)
    sw   $t0, 52($sp)
    sw   $t1, 48($sp)
    sw   $t2, 44($sp)
    sw   $t3, 40($sp)
    sw   $t4, 36($sp)
    sw   $t5, 32($sp)
    sw   $t6, 28($sp)
    sw   $t7, 24($sp)
    sw   $t8, 20($sp)
    sw   $t9, 16($sp)
    mov.s $f31, $f12
    move $t9, $a0
    mtc1 $t9, $f30
    cvt.s.w $f30, $f30
    add.s $f29, $f31, $f30
    mov.s $f28, $f29
    mov.s $f0, $f28
    lw   $fp, 56($sp)
    lw   $ra, 60($sp)
    lw   $t0, 52($sp)
    lw   $t1, 48($sp)
    lw   $t2, 44($sp)
    lw   $t3, 40($sp)
    lw   $t4, 36($sp)
    lw   $t5, 32($sp)
    lw   $t6, 28($sp)
    lw   $t7, 24($sp)
    lw   $t8, 20($sp)
    lw   $t9, 16($sp)
    addi $sp, $sp, 64
    jr   $ra
main:
    move $fp, $sp
    addi $sp, $sp, -24
    sw   $ra, 20($sp)
    sw   $fp, 16($sp)
    li $t8, 2
    li.s $f12, 2.000000
    li $a0, 3
    jal fun
    mov.s $f27, $f0
    mov.s $f26, $f27
    la $a0, str0
    mov.s $f12, $f26
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
    move $t6, $v0
    li $v0, 0
    lw   $fp, 16($sp)
    lw   $ra, 20($sp)
    li $v0, 10
    syscall
