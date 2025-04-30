# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
str0: .asciiz "c is"
str1: .asciiz "c is"
str2: .asciiz "c is"
str3: .asciiz "c is"
str4: .asciiz "i is"
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -76
    sw   $ra, 72($sp)
    sw   $fp, 68($sp)
    li $t9, 3
    li $t8, 10
    li $t7, 1
    seq $t6, $t9, $t7
    bnez $t6, LABEL0
    li $t5, 2
    seq $t4, $t9, $t5
    bnez $t4, LABEL1
    li $t3, 3
    seq $t2, $t9, $t3
    bnez $t2, LABEL2
    j LABEL3
LABEL0:
    add $t1, $t9, $t8
    move $t0, $t1
    la $a0, str0
    move $a1, $t0
    # Spilling t10 from $t2
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
    move $t2, $v0
    j LABEL4
LABEL1:
    # Spilling t8 from $t6
    sub $t6, $t9, $t8
    move $t0, $t6
    la $a0, str1
    move $a1, $t0
    # Spilling t9 from $t4
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
    move $t4, $v0
    j LABEL4
LABEL2:
    # Spilling t0 from $t1
    mul $t1, $t9, $t8
    move $t0, $t1
    la $a0, str2
    move $a1, $t0
    # Spilling t1 from $t2
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
    move $t2, $v0
    j LABEL4
LABEL3:
    # Spilling t2 from $t6
    div $t9, $t8
    mflo $t6
    move $t0, $t6
    la $a0, str3
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
LABEL4:
    # Spilling b from $t8
    li $t8, 2
LABEL5:
    # Spilling c from $t0
    li $t0, 0
    # Spilling t3 from $t4
    slt $t4, $t8, $t0
    bnez $t4, LABEL6
    j LABEL7
LABEL7:
    la $a0, str4
    move $a1, $t8
    # Spilling t11 from $t4
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
    move $t4, $v0
    # Spilling t4 from $t1
    li $t1, 1
    sub $t8, $t8, $t1
    j LABEL5
LABEL6:
    li $v0, 0
    lw   $fp, 68($sp)
    lw   $ra, 72($sp)
    li $v0, 10
    syscall
