.data
newline: .asciiz "\n"
str0: .asciiz ""
float_const_2.000000: .float 2.000000
float_const_1.000000: .float 1.000000
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -36
    sw   $ra, 32($sp)
    sw   $fp, 28($sp)
    li $t8, 0
    li $t7, 4
    mul $t6, $t8, $t7
    la $t5, float_const_1.000000
    l.s $f31, 0($t5)
    li $t5, 0
   add $t6, $t6, $t5
    add $t6, $t6, $sp
    s.s $f31, 0($t6)
    li $t4, 1
    li $t3, 4
    mul $t2, $t4, $t3
    la $t1, float_const_2.000000
    l.s $f30, 0($t1)
    li $t1, 0
   add $t2, $t2, $t1
    add $t2, $t2, $sp
    s.s $f30, 0($t2)
    li $t0, 4
    # Spilling t0 from $t6
    li $t6, 0
    # Spilling t1 from $t2
    mul $t2, $t0, $t6
    li $t0, 0
   add $t2, $t2, $t0
    add $t2, $t2, $sp
    l.s $f29, 0($t2)
    mov.s $f28, $f29
    la $a0, str0
    mov.s $f12, $f28
    # Spilling a from $t9
#printf
 move $a0, $a0
    li $v0, 4
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
    move $t9, $v0
    li $v0, 0
    lw   $fp, 28($sp)
    lw   $ra, 32($sp)
    addi $sp, $sp, 36
    li $v0, 10
    syscall
