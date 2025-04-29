# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
str0: .asciiz "Sum of 5 numbers is:"
.text
.globl main
addx:
    move $fp, $sp
    addi $sp, $sp, -84
    sw   $ra, 80($sp)
    sw   $fp, 76($sp)
    sw   $t0, 72($sp)
    sw   $t1, 68($sp)
    sw   $t2, 64($sp)
    sw   $t3, 60($sp)
    sw   $t4, 56($sp)
    sw   $t5, 52($sp)
    sw   $t6, 48($sp)
    sw   $t7, 44($sp)
    sw   $t8, 40($sp)
    sw   $t9, 36($sp)
    move $t9, $a0
    move $t8, $a1
    move $t7, $a2
    move $t6, $a3
    #popping from stack to $t5
    lw $t5, 0($fp)
    #pushing into function stack
    sw $t5, 0($sp)
    add $t4, $t9, $t8
    add $t3, $t4, $t7
    add $t2, $t3, $t6
    add $t1, $t2, $t5
    move $v0, $t1
    lw   $fp, 76($sp)
    lw   $ra, 80($sp)
    lw   $t0, 72($sp)
    lw   $t1, 68($sp)
    lw   $t2, 64($sp)
    lw   $t3, 60($sp)
    lw   $t4, 56($sp)
    lw   $t5, 52($sp)
    lw   $t6, 48($sp)
    lw   $t7, 44($sp)
    lw   $t8, 40($sp)
    lw   $t9, 36($sp)
    addi $sp, $sp, 84
    jr   $ra
main:
    move $fp, $sp
    addi $sp, $sp, -20
    sw   $ra, 16($sp)
    sw   $fp, 12($sp)
    li $a0, 1
    li $a1, 1
    li $a2, 1
    li $a3, 1
    # Spilling a from $t9
    addi $sp, $sp, -4 
    li $t0, 1
    sw $t0, 0($sp)
    jal addx
    move $t9, $v0
    # Spilling b from $t8
    move $t8, $t9
    la $a0, str0
    move $a1, $t8
    # Spilling c from $t7
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
    move $t7, $v0
    li $v0, 0
    lw   $fp, 12($sp)
    lw   $ra, 16($sp)
    li $v0, 10
    syscall
