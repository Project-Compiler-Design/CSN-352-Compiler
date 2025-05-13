# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
static_repeat: .word 0
str0: .asciiz "Static counter ="
str1: .asciiz "i ="
str2: .asciiz "Repeating the loop using goto!\n\n"
str3: .asciiz "Program finished.\n"
.text
.globl main
count_with_static:
    move $fp, $sp
    addi $sp, $sp, -56
    sw   $ra, 52($sp)
    sw   $fp, 48($sp)
    sw   $t0, 44($sp)
    sw   $t1, 40($sp)
    sw   $t2, 36($sp)
    sw   $t3, 32($sp)
    sw   $t4, 28($sp)
    sw   $t5, 24($sp)
    sw   $t6, 20($sp)
    sw   $t7, 16($sp)
    sw   $t8, 12($sp)
    sw   $t9, 8($sp)
    li $t9, 0
    li $t8, 1
    add $t9, $t9, $t8
    la $a0, str0
    move $a1, $t9
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
    li $v0, 1
    lw   $fp, 48($sp)
    lw   $ra, 52($sp)
    lw   $t0, 44($sp)
    lw   $t1, 40($sp)
    lw   $t2, 36($sp)
    lw   $t3, 32($sp)
    lw   $t4, 28($sp)
    lw   $t5, 24($sp)
    lw   $t6, 20($sp)
    lw   $t7, 16($sp)
    lw   $t8, 12($sp)
    lw   $t9, 8($sp)
    addi $sp, $sp, 56
    jr   $ra
main:
    move $fp, $sp
    addi $sp, $sp, -56
    sw   $ra, 52($sp)
    sw   $fp, 48($sp)
    li $t6, 0
LABEL8:
    li $t6, 0
LABEL4:
    li $t5, 10
    slt $t4, $t6, $t5
    bnez $t4, LABEL6
    j LABEL5
LABEL6:
    li $t3, 2
    seq $t2, $t6, $t3
    bnez $t2, LABEL0
    j LABEL1
LABEL0:
    j LABEL7
LABEL1:
    li $t1, 5
    seq $t0, $t6, $t1
    bnez $t0, LABEL2
    j LABEL3
LABEL2:
    j LABEL5
LABEL3:
    la $a0, str1
    move $a1, $t6
    # Spilling counter from $t9
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
    # Spilling t0 from $t7
    jal count_with_static
    move $t7, $v0
    # Spilling t1 from $t4
    move $t4, $t7
LABEL7:
    # Spilling r from $t4
    li $t4, 1
    add $t6, $t6, $t4
    j LABEL4
LABEL5:
    # Spilling i from $t6
    lw $t6, static_repeat
    # Spilling t2 from $t2
    li $t2, 0
    # Spilling t3 from $t0
    seq $t0, $t6, $t2
    sw $t6, static_repeat
    bnez $t0, LABEL9
    j LABEL10
LABEL9:
    lw $t6, static_repeat
    # Spilling t6 from $t0
   li $t0, 1
   move $t6, $t0
   sw $t6, static_repeat
    la $a0, str2
    # Spilling repeat from $t6
#printf
 move $a0, $a0
    li $v0, 4
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t6, $v0
    j LABEL8
LABEL10:
    la $a0, str3
    # Spilling t4 from $t9
#printf
 move $a0, $a0
    li $v0, 4
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t9, $v0
    li $v0, 0
    lw   $fp, 48($sp)
    lw   $ra, 52($sp)
    li $v0, 10
    syscall
