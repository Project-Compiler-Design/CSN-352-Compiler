.data
newline: .asciiz "\n"
str0: .asciiz ""
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -96
    sw   $ra, 92($sp)
    sw   $fp, 88($sp)
    li $t9, 3
    li $t8, 4
    li $t7, 5
    li $t6, 6
    li $t5, 7
    li $t4, 8
    li $t3, 9
    li $t2, 10
    li $t1, 11
    #Pushing b to stack
    sw $t9, 8($sp)
    #Pushing a to stack
    addi $t9, $sp, 0
    #Loading constant 5 into register
    li $t0, 5
    sw $t0, 0($t9)
    # Spilling t0 from $t9
    #Pushing a to stack
    addi $t9, $sp, 4
    #Loading constant 10 into register
    li $t0, 10
    sw $t0, 0($t9)
    # Spilling a from $t0
    lw $t0, 8($sp)
    # Spilling t1 from $t9
    add $t9, $t0, $t8
    # Spilling b from $t0
    add $t0, $t9, $t7
    # Spilling c from $t8
    add $t8, $t0, $t6
    # Spilling d from $t7
    add $t7, $t8, $t5
    # Spilling e from $t6
    add $t6, $t7, $t4
    # Spilling f from $t5
    add $t5, $t6, $t3
    # Spilling g from $t4
    add $t4, $t5, $t2
    # Spilling h from $t3
    add $t3, $t4, $t1
    # Spilling i from $t2
    move $t2, $t3
    la $a0, str0
    move $a1, $t2
    # Spilling j from $t1
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
    li $v0, 0
    lw   $fp, 88($sp)
    lw   $ra, 92($sp)
    addi $sp, $sp, 96
    li $v0, 10
    syscall
