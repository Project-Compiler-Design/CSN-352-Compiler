.text
.globl func
.globl main

func:
    move $fp, $sp
    addi $sp, $sp, -40
    sw   $ra, 36($sp)
    sw   $fp, 32($sp)
    

    move $t9, $a0
    move $t8, $a1
    move $t7, $a2
    move $t6, $a3
    #popping from stack to $t5
    lw $t5, -0($fp)
    #pushing into function stack
    sw $t5, 0($sp)
    #popping from stack to $t4
    lw $t4, -4($fp)
    #pushing into function stack
    sw $t4, 4($sp)
    add $t3, $t6, $t5
    move $t2, $t3
    move $v0, $t2

    move $sp, $fp
    lw   $fp, 32($sp)
    lw   $ra, 36($sp)
    addi $sp, $sp, 40
    jr   $ra
    
main:
    move $fp, $sp
    addi $sp, $sp, -40
    sw   $ra, 36($sp)
    sw   $fp, 32($sp)
    li $t1, 10
    li $t0, 20
    # Spilling a from $t9
    li $t9, 30
    # Spilling b from $t8
    li $t8, 40
    # Spilling c from $t7
    li $t7, 50
    # Spilling d from $t6
    li $t6, 60
    move $a0, $t1
    move $a1, $t0
    move $a2, $t9
    move $a3, $t8
    #pushing $t7 to stack
    addi $sp, $sp, -4
    sw $t7, 0($sp)
    #pushing $t6 to stack
    addi $sp, $sp, -4
    sw $t6, 0($sp)
    # Spilling e from $t5
    jal func
    move $t5, $v0
    # Spilling f from $t4
    move $t4, $t5
    li $v0, 0
    move $sp, $fp
    lw   $fp, 32($sp)
    lw   $ra, 36($sp)
    addi $sp, $sp, 40
    jr   $ra
.end main