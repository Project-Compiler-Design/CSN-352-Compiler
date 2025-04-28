.data
newline: .asciiz "\n"
str0: .asciiz "HI"
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
    addi $sp, $sp, -20
    sw   $ra, 16($sp)
    sw   $fp, 12($sp)
    li $a0, 5
    li $a1, 3
    jal addx
    move $t1, $v0
    move $t0, $t1
    la $a0, str0
    move $a1, $t0
    # Spilling a from $t9
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
    move $t9, $v0
    li $v0, 0
    lw   $fp, 12($sp)
    lw   $ra, 16($sp)
    jr   $ra
    li $v0, 10
    syscall
