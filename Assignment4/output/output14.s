# =====================LIST OF ERRORS===================================
#Line 10 : Missing return statement
# ======================================================================
.data
newline: .asciiz "\n"
str0: .asciiz "Arithmetic test failed:"
str1: .asciiz "Recursion test failed:"
str2: .asciiz "Array sum test failed:"
str3: .asciiz "Branching test failed:"
str4: .asciiz "All tests passed successfully!\n"
.text
.globl main
addx:
    move $fp, $sp
    addi $sp, $sp, -60
    sw   $ra, 56($sp)
    sw   $fp, 52($sp)
    sw   $t0, 48($sp)
    sw   $t1, 44($sp)
    sw   $t2, 40($sp)
    sw   $t3, 36($sp)
    sw   $t4, 32($sp)
    sw   $t5, 28($sp)
    sw   $t6, 24($sp)
    sw   $t7, 20($sp)
    sw   $t8, 16($sp)
    sw   $t9, 12($sp)
    move $t9, $a0
    move $t8, $a1
    add $t7, $t9, $t8
    move $v0, $t7
    lw   $fp, 52($sp)
    lw   $ra, 56($sp)
    lw   $t0, 48($sp)
    lw   $t1, 44($sp)
    lw   $t2, 40($sp)
    lw   $t3, 36($sp)
    lw   $t4, 32($sp)
    lw   $t5, 28($sp)
    lw   $t6, 24($sp)
    lw   $t7, 20($sp)
    lw   $t8, 16($sp)
    lw   $t9, 12($sp)
    addi $sp, $sp, 60
    jr   $ra
factorial:
    move $fp, $sp
    addi $sp, $sp, -68
    sw   $ra, 64($sp)
    sw   $fp, 60($sp)
    sw   $t0, 56($sp)
    sw   $t1, 52($sp)
    sw   $t2, 48($sp)
    sw   $t3, 44($sp)
    sw   $t4, 40($sp)
    sw   $t5, 36($sp)
    sw   $t6, 32($sp)
    sw   $t7, 28($sp)
    sw   $t8, 24($sp)
    sw   $t9, 20($sp)
    move $t6, $a0
    li $t5, 1
    slt $t4, $t5, $t6
    xori $t4, $t4, 1
    bnez $t4, LABEL0
    j LABEL1
LABEL0:
    li $v0, 1
    lw   $fp, 60($sp)
    lw   $ra, 64($sp)
    lw   $t0, 56($sp)
    lw   $t1, 52($sp)
    lw   $t2, 48($sp)
    lw   $t3, 44($sp)
    lw   $t4, 40($sp)
    lw   $t5, 36($sp)
    lw   $t6, 32($sp)
    lw   $t7, 28($sp)
    lw   $t8, 24($sp)
    lw   $t9, 20($sp)
    addi $sp, $sp, 68
    jr   $ra
    j LABEL2
LABEL1:
    li $t3, 1
    sub $t2, $t6, $t3
    move $a0, $t2
    jal factorial
    move $t1, $v0
    mul $t0, $t6, $t1
    move $v0, $t0
    lw   $fp, 60($sp)
    lw   $ra, 64($sp)
    lw   $t0, 56($sp)
    lw   $t1, 52($sp)
    lw   $t2, 48($sp)
    lw   $t3, 44($sp)
    lw   $t4, 40($sp)
    lw   $t5, 36($sp)
    lw   $t6, 32($sp)
    lw   $t7, 28($sp)
    lw   $t8, 24($sp)
    lw   $t9, 20($sp)
    addi $sp, $sp, 68
    jr   $ra
LABEL2:
main:
    move $fp, $sp
    addi $sp, $sp, -124
    sw   $ra, 120($sp)
    sw   $fp, 116($sp)
    # Spilling a from $t9
    li $t9, 5
    # Spilling b from $t8
    li $t8, 10
    move $a0, $t9
    move $a1, $t8
    # Spilling t0 from $t7
    jal addx
    move $t7, $v0
    # Spilling n from $t6
    move $t6, $t7
    # Spilling t1 from $t4
    li $t4, 15
    # Spilling t2 from $t2
    sne $t2, $t6, $t4
    bnez $t2, LABEL3
    j LABEL4
LABEL3:
    la $a0, str0
    move $a1, $t6
    # Spilling t3 from $t1
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
    move $t1, $v0
    li $v0, 1
    lw   $fp, 116($sp)
    lw   $ra, 120($sp)
LABEL4:
    li $a0, 5
    # Spilling t4 from $t0
    jal factorial
    move $t0, $v0
    # Spilling result from $t6
    move $t6, $t0
    # Spilling t5 from $t7
    li $t7, 120
    # Spilling t6 from $t2
    sne $t2, $t6, $t7
    bnez $t2, LABEL5
    j LABEL6
LABEL5:
    la $a0, str1
    move $a1, $t6
    # Spilling t8 from $t0
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
    li $v0, 1
    lw   $fp, 116($sp)
    lw   $ra, 120($sp)
LABEL6:
    # Spilling fact from $t6
    li $t6, 0
    # Spilling t9 from $t2
    li $t2, 4
    # Spilling t7 from $t1
    mul $t1, $t6, $t2
    # Spilling t10 from $t0
    li $t0, 1
    addi $t1, $t1, 0
    add $t1, $t1, $sp
    sw $t0, 0($t1)
    # Spilling t11 from $t1
    li $t1, 1
    #Pushing a to stack
    sw $t9, 20($sp)
    li $t9, 4
    #Pushing b to stack
    sw $t8, 24($sp)
    mul $t8, $t1, $t9
    li $t0, 2
    addi $t8, $t8, 0
    add $t8, $t8, $sp
    sw $t0, 0($t8)
    # Spilling t12 from $t8
    li $t8, 2
    li $t0, 4
    mul $t0, $t8, $t0
    #Pushing t13 to stack
    sw $t0, 28($sp)
    li $t0, 3
    lw $t0, 28($sp)
    addi $t0, $t0, 0
    add $t0, $t0, $sp
    sw $t0, 0($t0)
    # Spilling t13 from $t0
    li $t0, 3
    li $t0, 4
    mul $t0, $t0, $t0
    #Pushing t14 to stack
    sw $t0, 32($sp)
    li $t0, 4
    lw $t0, 32($sp)
    addi $t0, $t0, 0
    add $t0, $t0, $sp
    sw $t0, 0($t0)
    # Spilling t14 from $t0
    li $t0, 4
    li $t0, 4
    mul $t0, $t0, $t0
    #Pushing t15 to stack
    sw $t0, 36($sp)
    li $t0, 5
    lw $t0, 36($sp)
    addi $t0, $t0, 0
    add $t0, $t0, $sp
    sw $t0, 0($t0)
    # Spilling t15 from $t0
    li $t0, 0
    #Pushing array_sum to stack
    sw $t0, 40($sp)
    li $t0, 0
    li $t0, 0
LABEL7:
    #Pushing i to stack
    sw $t0, 44($sp)
    li $t0, 5
    slt $t0, $t0, $t0
    bnez $t0, LABEL9
    j LABEL8
LABEL9:
    # Spilling t16 from $t0
    li $t0, 4
    lw $t0, 44($sp)
    #Pushing i to stack
    sw $t0, 44($sp)
    mul $t0, $t0, $t0
    addi $t0, $t0, 0
    add $t0, $t0, $sp
    #Pushing t17 to stack
    sw $t0, 48($sp)
    lw $t0, 0($t0)
    #Pushing t18 to stack
    sw $t0, 52($sp)
    lw $t0, 40($sp)
    #Pushing array_sum to stack
    sw $t0, 40($sp)
    lw $t0, 52($sp)
    #Pushing t18 to stack
    sw $t0, 52($sp)
    add $t0, $t0, $t0
    #Pushing t19 to stack
    sw $t0, 56($sp)
    lw $t0, 40($sp)
    #Pushing array_sum to stack
    sw $t0, 40($sp)
    lw $t0, 56($sp)
    move $t0, $t0
    # Spilling t19 from $t0
    lw $t0, 44($sp)
    #Pushing i to stack
    sw $t0, 44($sp)
    li $t0, 1
    lw $t0, 44($sp)
    add $t0, $t0, $t0
    j LABEL7
LABEL8:
    # Spilling i from $t0
    lw $t0, 40($sp)
    #Pushing array_sum to stack
    sw $t0, 40($sp)
    li $t0, 15
    sne $t0, $t0, $t0
    bnez $t0, LABEL11
    j LABEL12
LABEL11:
    la $a0, str2
    # Spilling t20 from $t0
    lw $t0, 40($sp)
    move $a1, $t0
    #Pushing array_sum to stack
    sw $t0, 40($sp)
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
    li $v0, 1
    lw   $fp, 116($sp)
    lw   $ra, 120($sp)
LABEL12:
    # Spilling t21 from $t0
    li $t0, 0
    #Pushing value to stack
    sw $t0, 60($sp)
    lw $t0, 20($sp)
    #Pushing a to stack
    sw $t0, 20($sp)
    lw $t0, 24($sp)
    #Pushing b to stack
    sw $t0, 24($sp)
    slt $t0, $t0, $t0
    bnez $t0, LABEL13
    j LABEL14
LABEL13:
    # Spilling t22 from $t0
    lw $t0, 60($sp)
    li $t0, 1
    j LABEL15
LABEL14:
    li $t0, 2
LABEL15:
    #Pushing value to stack
    sw $t0, 60($sp)
    li $t0, 1
    sne $t0, $t0, $t0
    bnez $t0, LABEL16
    j LABEL17
LABEL16:
    la $a0, str3
    # Spilling t23 from $t0
    lw $t0, 60($sp)
    move $a1, $t0
    #Pushing value to stack
    sw $t0, 60($sp)
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
    li $v0, 1
    lw   $fp, 116($sp)
    lw   $ra, 120($sp)
LABEL17:
    la $a0, str4
    # Spilling t24 from $t0
#printf
 move $a0, $a0
    li $v0, 4
syscall
  li $v0, 4 
 la $a0, newline 
 syscall
    move $t0, $v0
    li $v0, 0
    lw   $fp, 116($sp)
    lw   $ra, 120($sp)
    li $v0, 10
    syscall
