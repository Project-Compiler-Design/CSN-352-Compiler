.text
.globl main
add1:
    move $fp, $sp
    addi $sp, $sp, -32
    sw   $ra, 28($sp)
    sw   $fp, 24($sp)
    move $t9, $a0
    mov.s $f7, $f14
    mov.s $f6, $f14
    move $t8, $a1
    move $t7, $a2
    #popping from stack to $f5
    l.s $f5, 0($fp)
    #pushing into function stack
    s.s $f5, 0($sp)
    move $v0, $t9
    lw   $fp, 24($sp)
    lw   $ra, 28($sp)
    addi $sp, $sp, 32
    jr   $ra
main:
    move $fp, $sp
    addi $sp, $sp, -40
    sw   $ra, 36($sp)
    sw   $fp, 32($sp)
    li $t6, 10
    li.s $f4, 4.000000
    li.s $f3, 3.140000
    li $t5, 2
    li $t4, 609
    li.s $f2, 7.100000
    move $a0, $t6
    mov.s $f12, $f4
    mov.s $f14, $f3
    move $a1, $t5
    move $a2, $t4
    addi $sp, $sp, -4 
    s.s $f2, 0($sp)
    jal add1
    move $t3, $v0
    move $t2, $t3
	 move $a0, $v0 
 	 li   $v0, 1 
 	 syscall
    li $v0, 0
    lw   $fp, 32($sp)
    lw   $ra, 36($sp)
    addi $sp, $sp, 40
    li $v0, 10
    syscall
