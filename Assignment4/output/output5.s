# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
static_counter: .word 0
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
    lw $t9, static_counter
    li $t8, 1
    lw $t9, static_counter
    add $t9, $t9, $t8
    sw $t9, static_counter
    sw $t9, static_counter
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
main:
    move $fp, $sp
    addi $sp, $sp, -48
    sw   $ra, 44($sp)
    sw   $fp, 40($sp)
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
LABEL7:
    # Spilling t0 from $t7
    li $t7, 1
    add $t6, $t6, $t7
    j LABEL4
LABEL5:
    # Spilling i from $t6
    lw $t6, static_repeat
    # Spilling t1 from $t4
    li $t4, 0
    # Spilling t2 from $t2
    seq $t2, $t6, $t4
    sw $t6, static_repeat
    bnez $t2, LABEL9
    j LABEL10
LABEL9:
    lw $t6, static_repeat
    # Spilling t5 from $t2
   li $t2, 1
   move $t6, $t2
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
    # Spilling t3 from $t0
#printf
 move $a0, $a0
    li $v0, 4
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t0, $v0
    li $v0, 0
    lw   $fp, 40($sp)
    lw   $ra, 44($sp)
    li $v0, 10
    syscall
