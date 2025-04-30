# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
str0: .asciiz ""
str1: .asciiz "Multi-level pointer value:"
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -68
    sw   $ra, 64($sp)
    sw   $fp, 60($sp)
    addi $t9, $sp, 0
    #Loading constant 7 into register
    li $t8, 7
    sw $t8, 0($t9)
    addi $t7, $sp, 4
    #Loading constant 8 into register
    li $t6, 8
    sw $t6, 0($t7)
    li $t5, 0
    li $t4, 4
    mul $t3, $t5, $t4
    li $t2, 5
    addi $t3, $t3, 8
    add $t3, $t3, $sp
    sw $t2, 0($t3)
    li $t1, 1
    li $t0, 4
    # Spilling t0 from $t9
    mul $t9, $t1, $t0
    # Spilling t1 from $t7
    li $t7, 4
    addi $t9, $t9, 8
    add $t9, $t9, $sp
    sw $t7, 0($t9)
    # Spilling t2 from $t3
    li $t3, 2
    # Spilling t3 from $t9
    li $t9, 4
    mul $t0, $t3, $t9
    #Pushing t4 to stack
    sw $t0, 20($sp)
    li $t0, 5
    lw $t0, 20($sp)
    addi $t0, $t0, 8
    add $t0, $t0, $sp
    sw $t0, 0($t0)
    # Spilling t4 from $t0
    li $t0, 4
    li $t0, 0
    mul $t0, $t0, $t0
    addi $t0, $t0, 8
    add $t0, $t0, $sp
    #Pushing t5 to stack
    sw $t0, 24($sp)
    lw $t0, 0($t0)
    #Pushing t6 to stack
    sw $t0, 28($sp)
    #Pushing c to stack
    sw $t0, 32($sp)
    lw $t0, 28($sp)
    move $t0, $t0
    la $a0, str0
    # Spilling t6 from $t0
    lw $t0, 32($sp)
    move $a1, $t0
    #Pushing c to stack
    sw $t0, 32($sp)
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
    move $t0, $v0
    # Spilling t7 from $t0
    li $t0, 50
    # Spilling y from $t0
    addi $t0, $sp, -1
    la $a0, str1
    # Spilling p1 from $t0
    lw $t0, 0()
    sw $t0, 36($sp)
    move $a1, $t0
    # Spilling p1 from 
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
    move , $v0
    li $v0, 0
    lw   $fp, 60($sp)
    lw   $ra, 64($sp)
    li $v0, 10
    syscall
