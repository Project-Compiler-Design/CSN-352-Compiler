# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
str0: .asciiz "This branch is always taken.\n"
str1: .asciiz "This branch is never taken.\n"
str2: .asciiz "Results: x="
str3: .asciiz "Counter:"
float_const_5.000000: .float 5.000000
float_const_30.000000: .float 30.000000
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -104
    sw   $ra, 100($sp)
    sw   $fp, 96($sp)
    li $t9, 5
    li $t8, 10
    li $t7, 15
    li $t6, 20
    li $t5, 2
    mul $t4, $t9, $t5
    move $t3, $t4
    add $t2, $t9, $t9
    move $t1, $t2
    li $t0, 4
    # Spilling a from $t9
    li $t9, 5
    # Spilling c from $t7
    mul $t7, $t0, $t9
    # Spilling t0 from $t4
    move $t4, $t7
    # Spilling t1 from $t2
    la $t2, float_const_30.000000
    l.s $f31, 0($t2)
    la $t2, float_const_5.000000
    l.s $f30, 0($t2)
    div.s $f29, $f31, $f30
    mov.s $f28, $f29
    li $t2, 8
    # Spilling t2 from $t7
    mul $t7, $t6, $t2
    # Spilling d from $t6
    move $t6, $t7
    # Spilling t4 from $t7
    li $t7, 100
    # Spilling unused from $t7
    li $t7, 0
    #Pushing u to stack
    sw $t6, 0($sp)
    li $t6, 1
    #Pushing x to stack
    sw $t3, 4($sp)
    add $t3, $t7, $t6
    move $t7, $t3
    # Spilling t5 from $t3
    li $t3, 1
    #Pushing y to stack
    sw $t1, 8($sp)
    add $t1, $t7, $t3
    move $t7, $t1
    # Spilling t6 from $t1
    li $t1, 1
    #Pushing z to stack
    sw $t4, 12($sp)
    add $t4, $t7, $t1
    move $t7, $t4
    # Spilling t7 from $t4
    move $t4, $t8
    move $t4, $t4
    # Spilling b from $t8
    li $t8, 1
    bnez $t8, LABEL0
    j LABEL1
LABEL0:
    la $a0, str0
    # Spilling temp from $t4
#printf
 move $a0, $a0
    li $v0, 4
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t4, $v0
    j LABEL2
LABEL1:
    la $a0, str1
    # Spilling t8 from $t4
#printf
 move $a0, $a0
    li $v0, 4
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t4, $v0
LABEL2:
    la $a0, str2
    # Spilling t9 from $t4
    lw $t4, 4($sp)
    move $a1, $t4
    #Pushing counter to stack
    sw $t7, 16($sp)
    lw $t7, 8($sp)
    move $a2, $t7
    #Pushing x to stack
    sw $t4, 4($sp)
    lw $t4, 12($sp)
    move $a3, $t4
    mov.s $f12, $f28
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
 move $a0, $a2
    li $v0, 1
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
 move $a0, $a3
    li $v0, 1
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
    move $t0, $v0
    la $a0, str3
    # Spilling t10 from $t0
    lw $t0, 0($sp)
    move $a1, $t0
    # Spilling y from $t7
    lw $t7, 16($sp)
    move $a2, $t7
    # Spilling z from $t4
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
 move $a0, $a2
    li $v0, 1
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t4, $v0
    li $v0, 0
    lw   $fp, 96($sp)
    lw   $ra, 100($sp)
    li $v0, 10
    syscall
