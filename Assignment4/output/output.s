.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -32
    sw   $ra, 28($sp)
    sw   $fp, 24($sp)
    li $t8, 0
    li $t7, 4
    mul $t6, $t8, $t7
    li $t5, 5
    addi $t6, $t6, 0
    add $t6, $t6, $sp
    sw $t5, 0($t6)
    move $t4, $t7
    move $t3, $t8
    mul $t2, $t4, $t3
    addi $t2, $t2, 0
    add $t2, $t2, $sp
    lw $t2, 0($t2)
    move $t1, $t2
    li $t0, 2
    # Spilling arr from $t9
    add $t9, $t1, $t0
    # Spilling t0 from $t6
    move $t6, $t9
    lw   $fp, 24($sp)
    lw   $ra, 28($sp)
    addi $sp, $sp, 32
    li $v0, 10
    syscall
