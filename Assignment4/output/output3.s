# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
str0: .asciiz "Sum of all variables ="
.text
.globl main
main:
    move $fp, $sp
    addi $sp, $sp, -812
    sw   $ra, 808($sp)
    sw   $fp, 804($sp)
    li $t9, 10
    li $t8, 10
    li $t7, 10
    li $t6, 10
    li $t5, 10
    li $t4, 10
    li $t3, 10
    li $t2, 10
    li $t1, 10
    li $t0, 10
    #Pushing a10 to stack
    sw $t0, 0($sp)
    li $t0, 10
    #Pushing a11 to stack
    sw $t0, 4($sp)
    li $t0, 10
    #Pushing a12 to stack
    sw $t0, 8($sp)
    li $t0, 10
    #Pushing a13 to stack
    sw $t0, 12($sp)
    li $t0, 10
    #Pushing a14 to stack
    sw $t0, 16($sp)
    li $t0, 10
    #Pushing a15 to stack
    sw $t0, 20($sp)
    li $t0, 10
    #Pushing a16 to stack
    sw $t0, 24($sp)
    li $t0, 10
    #Pushing a17 to stack
    sw $t0, 28($sp)
    li $t0, 10
    #Pushing a18 to stack
    sw $t0, 32($sp)
    li $t0, 10
    #Pushing a19 to stack
    sw $t0, 36($sp)
    li $t0, 10
    #Pushing a20 to stack
    sw $t0, 40($sp)
    li $t0, 10
    #Pushing a21 to stack
    sw $t0, 44($sp)
    li $t0, 10
    #Pushing a22 to stack
    sw $t0, 48($sp)
    li $t0, 10
    #Pushing a23 to stack
    sw $t0, 52($sp)
    li $t0, 10
    #Pushing a24 to stack
    sw $t0, 56($sp)
    li $t0, 10
    #Pushing a25 to stack
    sw $t0, 60($sp)
    li $t0, 10
    #Pushing a26 to stack
    sw $t0, 64($sp)
    li $t0, 10
    #Pushing a27 to stack
    sw $t0, 68($sp)
    li $t0, 10
    #Pushing a28 to stack
    sw $t0, 72($sp)
    li $t0, 10
    #Pushing a29 to stack
    sw $t0, 76($sp)
    li $t0, 10
    #Pushing a30 to stack
    sw $t0, 80($sp)
    li $t0, 10
    #Pushing a31 to stack
    sw $t0, 84($sp)
    li $t0, 10
    #Pushing a32 to stack
    sw $t0, 88($sp)
    li $t0, 10
    #Pushing a33 to stack
    sw $t0, 92($sp)
    li $t0, 10
    #Pushing a34 to stack
    sw $t0, 96($sp)
    li $t0, 10
    #Pushing a35 to stack
    sw $t0, 100($sp)
    li $t0, 10
    #Pushing a36 to stack
    sw $t0, 104($sp)
    li $t0, 10
    #Pushing a37 to stack
    sw $t0, 108($sp)
    li $t0, 10
    #Pushing a38 to stack
    sw $t0, 112($sp)
    li $t0, 10
    #Pushing a39 to stack
    sw $t0, 116($sp)
    li $t0, 10
    #Pushing a40 to stack
    sw $t0, 120($sp)
    li $t0, 10
    #Pushing a41 to stack
    sw $t0, 124($sp)
    li $t0, 10
    #Pushing a42 to stack
    sw $t0, 128($sp)
    li $t0, 10
    #Pushing a43 to stack
    sw $t0, 132($sp)
    li $t0, 10
    #Pushing a44 to stack
    sw $t0, 136($sp)
    li $t0, 10
    #Pushing a45 to stack
    sw $t0, 140($sp)
    li $t0, 10
    #Pushing a46 to stack
    sw $t0, 144($sp)
    li $t0, 10
    #Pushing a47 to stack
    sw $t0, 148($sp)
    li $t0, 10
    #Pushing a48 to stack
    sw $t0, 152($sp)
    li $t0, 10
    #Pushing a49 to stack
    sw $t0, 156($sp)
    li $t0, 10
    #Pushing a50 to stack
    sw $t0, 160($sp)
    li $t0, 10
    #Pushing a51 to stack
    sw $t0, 164($sp)
    li $t0, 10
    #Pushing a52 to stack
    sw $t0, 168($sp)
    li $t0, 10
    #Pushing a53 to stack
    sw $t0, 172($sp)
    li $t0, 10
    #Pushing a54 to stack
    sw $t0, 176($sp)
    li $t0, 10
    #Pushing a55 to stack
    sw $t0, 180($sp)
    li $t0, 10
    #Pushing a56 to stack
    sw $t0, 184($sp)
    li $t0, 10
    #Pushing a57 to stack
    sw $t0, 188($sp)
    li $t0, 10
    #Pushing a58 to stack
    sw $t0, 192($sp)
    li $t0, 10
    #Pushing a59 to stack
    sw $t0, 196($sp)
    li $t0, 10
    #Pushing a60 to stack
    sw $t0, 200($sp)
    li $t0, 10
    #Pushing a61 to stack
    sw $t0, 204($sp)
    li $t0, 10
    #Pushing a62 to stack
    sw $t0, 208($sp)
    li $t0, 10
    #Pushing a63 to stack
    sw $t0, 212($sp)
    li $t0, 10
    #Pushing a64 to stack
    sw $t0, 216($sp)
    li $t0, 10
    #Pushing a65 to stack
    sw $t0, 220($sp)
    li $t0, 10
    #Pushing a66 to stack
    sw $t0, 224($sp)
    li $t0, 10
    #Pushing a67 to stack
    sw $t0, 228($sp)
    li $t0, 10
    #Pushing a68 to stack
    sw $t0, 232($sp)
    li $t0, 10
    #Pushing a69 to stack
    sw $t0, 236($sp)
    li $t0, 10
    #Pushing a70 to stack
    sw $t0, 240($sp)
    li $t0, 10
    #Pushing a71 to stack
    sw $t0, 244($sp)
    li $t0, 10
    #Pushing a72 to stack
    sw $t0, 248($sp)
    li $t0, 10
    #Pushing a73 to stack
    sw $t0, 252($sp)
    li $t0, 10
    #Pushing a74 to stack
    sw $t0, 256($sp)
    li $t0, 10
    #Pushing a75 to stack
    sw $t0, 260($sp)
    li $t0, 10
    #Pushing a76 to stack
    sw $t0, 264($sp)
    li $t0, 10
    #Pushing a77 to stack
    sw $t0, 268($sp)
    li $t0, 10
    #Pushing a78 to stack
    sw $t0, 272($sp)
    li $t0, 10
    #Pushing a79 to stack
    sw $t0, 276($sp)
    li $t0, 10
    #Pushing a80 to stack
    sw $t0, 280($sp)
    li $t0, 10
    #Pushing a81 to stack
    sw $t0, 284($sp)
    li $t0, 10
    #Pushing a82 to stack
    sw $t0, 288($sp)
    li $t0, 10
    #Pushing a83 to stack
    sw $t0, 292($sp)
    li $t0, 10
    #Pushing a84 to stack
    sw $t0, 296($sp)
    li $t0, 10
    #Pushing a85 to stack
    sw $t0, 300($sp)
    li $t0, 10
    #Pushing a86 to stack
    sw $t0, 304($sp)
    li $t0, 10
    #Pushing a87 to stack
    sw $t0, 308($sp)
    li $t0, 10
    #Pushing a88 to stack
    sw $t0, 312($sp)
    li $t0, 10
    #Pushing a89 to stack
    sw $t0, 316($sp)
    li $t0, 10
    #Pushing a90 to stack
    sw $t0, 320($sp)
    li $t0, 10
    #Pushing a91 to stack
    sw $t0, 324($sp)
    li $t0, 10
    #Pushing a92 to stack
    sw $t0, 328($sp)
    li $t0, 10
    #Pushing a93 to stack
    sw $t0, 332($sp)
    li $t0, 10
    #Pushing a94 to stack
    sw $t0, 336($sp)
    li $t0, 10
    #Pushing a95 to stack
    sw $t0, 340($sp)
    li $t0, 10
    #Pushing a96 to stack
    sw $t0, 344($sp)
    li $t0, 10
    #Pushing a97 to stack
    sw $t0, 348($sp)
    li $t0, 10
    #Pushing a98 to stack
    sw $t0, 352($sp)
    li $t0, 10
    #Pushing a99 to stack
    sw $t0, 356($sp)
    li $t0, 10
    #Pushing a100 to stack
    sw $t0, 360($sp)
    add $t0, $t9, $t8
    # Spilling a1 from $t9
    add $t9, $t0, $t7
    # Spilling a2 from $t8
    add $t8, $t9, $t6
    # Spilling a3 from $t7
    add $t7, $t8, $t5
    # Spilling a4 from $t6
    add $t6, $t7, $t4
    # Spilling a5 from $t5
    add $t5, $t6, $t3
    # Spilling a6 from $t4
    add $t4, $t5, $t2
    # Spilling a7 from $t3
    add $t3, $t4, $t1
    # Spilling a8 from $t2
    lw $t2, 0($sp)
    # Spilling a9 from $t1
    add $t1, $t3, $t2
    # Spilling a10 from $t2
    lw $t2, 4($sp)
    # Spilling t0 from $t0
    add $t0, $t1, $t2
    # Spilling a11 from $t2
    lw $t2, 8($sp)
    # Spilling t1 from $t9
    add $t9, $t0, $t2
    # Spilling a12 from $t2
    lw $t2, 12($sp)
    # Spilling t2 from $t8
    add $t8, $t9, $t2
    # Spilling a13 from $t2
    lw $t2, 16($sp)
    # Spilling t10 from $t9
    add $t9, $t8, $t2
    # Spilling a14 from $t2
    lw $t2, 20($sp)
    # Spilling t11 from $t8
    add $t8, $t9, $t2
    # Spilling a15 from $t2
    lw $t2, 24($sp)
    # Spilling t12 from $t9
    add $t9, $t8, $t2
    # Spilling a16 from $t2
    lw $t2, 28($sp)
    # Spilling t13 from $t8
    add $t8, $t9, $t2
    # Spilling a17 from $t2
    lw $t2, 32($sp)
    # Spilling t14 from $t9
    add $t9, $t8, $t2
    # Spilling a18 from $t2
    lw $t2, 36($sp)
    # Spilling t15 from $t8
    add $t8, $t9, $t2
    # Spilling a19 from $t2
    lw $t2, 40($sp)
    # Spilling t16 from $t9
    add $t9, $t8, $t2
    # Spilling a20 from $t2
    lw $t2, 44($sp)
    # Spilling t17 from $t8
    add $t8, $t9, $t2
    # Spilling a21 from $t2
    lw $t2, 48($sp)
    # Spilling t18 from $t9
    add $t9, $t8, $t2
    # Spilling a22 from $t2
    lw $t2, 52($sp)
    # Spilling t19 from $t8
    add $t8, $t9, $t2
    # Spilling a23 from $t2
    lw $t2, 56($sp)
    # Spilling t20 from $t9
    add $t9, $t8, $t2
    # Spilling a24 from $t2
    lw $t2, 60($sp)
    # Spilling t21 from $t8
    add $t8, $t9, $t2
    # Spilling a25 from $t2
    lw $t2, 64($sp)
    # Spilling t22 from $t9
    add $t9, $t8, $t2
    # Spilling a26 from $t2
    lw $t2, 68($sp)
    # Spilling t23 from $t8
    add $t8, $t9, $t2
    # Spilling a27 from $t2
    lw $t2, 72($sp)
    # Spilling t24 from $t9
    add $t9, $t8, $t2
    # Spilling a28 from $t2
    lw $t2, 76($sp)
    # Spilling t25 from $t8
    add $t8, $t9, $t2
    # Spilling a29 from $t2
    lw $t2, 80($sp)
    # Spilling t26 from $t9
    add $t9, $t8, $t2
    # Spilling a30 from $t2
    lw $t2, 84($sp)
    # Spilling t27 from $t8
    add $t8, $t9, $t2
    # Spilling a31 from $t2
    lw $t2, 88($sp)
    # Spilling t28 from $t9
    add $t9, $t8, $t2
    # Spilling a32 from $t2
    lw $t2, 92($sp)
    # Spilling t29 from $t8
    add $t8, $t9, $t2
    # Spilling a33 from $t2
    lw $t2, 96($sp)
    # Spilling t3 from $t7
    add $t7, $t8, $t2
    # Spilling a34 from $t2
    lw $t2, 100($sp)
    # Spilling t30 from $t9
    add $t9, $t7, $t2
    # Spilling a35 from $t2
    lw $t2, 104($sp)
    # Spilling t31 from $t8
    add $t8, $t9, $t2
    # Spilling a36 from $t2
    lw $t2, 108($sp)
    # Spilling t32 from $t7
    add $t7, $t8, $t2
    # Spilling a37 from $t2
    lw $t2, 112($sp)
    # Spilling t33 from $t9
    add $t9, $t7, $t2
    # Spilling a38 from $t2
    lw $t2, 116($sp)
    # Spilling t34 from $t8
    add $t8, $t9, $t2
    # Spilling a39 from $t2
    lw $t2, 120($sp)
    # Spilling t35 from $t7
    add $t7, $t8, $t2
    # Spilling a40 from $t2
    lw $t2, 124($sp)
    # Spilling t36 from $t9
    add $t9, $t7, $t2
    # Spilling a41 from $t2
    lw $t2, 128($sp)
    # Spilling t37 from $t8
    add $t8, $t9, $t2
    # Spilling a42 from $t2
    lw $t2, 132($sp)
    # Spilling t38 from $t7
    add $t7, $t8, $t2
    # Spilling a43 from $t2
    lw $t2, 136($sp)
    # Spilling t39 from $t9
    add $t9, $t7, $t2
    # Spilling a44 from $t2
    lw $t2, 140($sp)
    # Spilling t4 from $t6
    add $t6, $t9, $t2
    # Spilling a45 from $t2
    lw $t2, 144($sp)
    # Spilling t40 from $t8
    add $t8, $t6, $t2
    # Spilling a46 from $t2
    lw $t2, 148($sp)
    # Spilling t41 from $t7
    add $t7, $t8, $t2
    # Spilling a47 from $t2
    lw $t2, 152($sp)
    # Spilling t42 from $t9
    add $t9, $t7, $t2
    # Spilling a48 from $t2
    lw $t2, 156($sp)
    # Spilling t43 from $t6
    add $t6, $t9, $t2
    # Spilling a49 from $t2
    lw $t2, 160($sp)
    # Spilling t44 from $t8
    add $t8, $t6, $t2
    # Spilling a50 from $t2
    lw $t2, 164($sp)
    # Spilling t45 from $t7
    add $t7, $t8, $t2
    # Spilling a51 from $t2
    lw $t2, 168($sp)
    # Spilling t46 from $t9
    add $t9, $t7, $t2
    # Spilling a52 from $t2
    lw $t2, 172($sp)
    # Spilling t47 from $t6
    add $t6, $t9, $t2
    # Spilling a53 from $t2
    lw $t2, 176($sp)
    # Spilling t48 from $t8
    add $t8, $t6, $t2
    # Spilling a54 from $t2
    lw $t2, 180($sp)
    # Spilling t49 from $t7
    add $t7, $t8, $t2
    # Spilling a55 from $t2
    lw $t2, 184($sp)
    # Spilling t5 from $t5
    add $t5, $t7, $t2
    # Spilling a56 from $t2
    lw $t2, 188($sp)
    # Spilling t50 from $t9
    add $t9, $t5, $t2
    # Spilling a57 from $t2
    lw $t2, 192($sp)
    # Spilling t51 from $t6
    add $t6, $t9, $t2
    # Spilling a58 from $t2
    lw $t2, 196($sp)
    # Spilling t52 from $t8
    add $t8, $t6, $t2
    # Spilling a59 from $t2
    lw $t2, 200($sp)
    # Spilling t53 from $t7
    add $t7, $t8, $t2
    # Spilling a60 from $t2
    lw $t2, 204($sp)
    # Spilling t54 from $t5
    add $t5, $t7, $t2
    # Spilling a61 from $t2
    lw $t2, 208($sp)
    # Spilling t55 from $t9
    add $t9, $t5, $t2
    # Spilling a62 from $t2
    lw $t2, 212($sp)
    # Spilling t56 from $t6
    add $t6, $t9, $t2
    # Spilling a63 from $t2
    lw $t2, 216($sp)
    # Spilling t57 from $t8
    add $t8, $t6, $t2
    # Spilling a64 from $t2
    lw $t2, 220($sp)
    # Spilling t58 from $t7
    add $t7, $t8, $t2
    # Spilling a65 from $t2
    lw $t2, 224($sp)
    # Spilling t59 from $t5
    add $t5, $t7, $t2
    # Spilling a66 from $t2
    lw $t2, 228($sp)
    # Spilling t6 from $t4
    add $t4, $t5, $t2
    # Spilling a67 from $t2
    lw $t2, 232($sp)
    # Spilling t60 from $t9
    add $t9, $t4, $t2
    # Spilling a68 from $t2
    lw $t2, 236($sp)
    # Spilling t61 from $t6
    add $t6, $t9, $t2
    # Spilling a69 from $t2
    lw $t2, 240($sp)
    # Spilling t62 from $t8
    add $t8, $t6, $t2
    # Spilling a70 from $t2
    lw $t2, 244($sp)
    # Spilling t63 from $t7
    add $t7, $t8, $t2
    # Spilling a71 from $t2
    lw $t2, 248($sp)
    # Spilling t64 from $t5
    add $t5, $t7, $t2
    # Spilling a72 from $t2
    lw $t2, 252($sp)
    # Spilling t65 from $t4
    add $t4, $t5, $t2
    # Spilling a73 from $t2
    lw $t2, 256($sp)
    # Spilling t66 from $t9
    add $t9, $t4, $t2
    # Spilling a74 from $t2
    lw $t2, 260($sp)
    # Spilling t67 from $t6
    add $t6, $t9, $t2
    # Spilling a75 from $t2
    lw $t2, 264($sp)
    # Spilling t68 from $t8
    add $t8, $t6, $t2
    # Spilling a76 from $t2
    lw $t2, 268($sp)
    # Spilling t69 from $t7
    add $t7, $t8, $t2
    # Spilling a77 from $t2
    lw $t2, 272($sp)
    # Spilling t7 from $t3
    add $t3, $t7, $t2
    # Spilling a78 from $t2
    lw $t2, 276($sp)
    # Spilling t70 from $t5
    add $t5, $t3, $t2
    # Spilling a79 from $t2
    lw $t2, 280($sp)
    # Spilling t71 from $t4
    add $t4, $t5, $t2
    # Spilling a80 from $t2
    lw $t2, 284($sp)
    # Spilling t72 from $t9
    add $t9, $t4, $t2
    # Spilling a81 from $t2
    lw $t2, 288($sp)
    # Spilling t73 from $t6
    add $t6, $t9, $t2
    # Spilling a82 from $t2
    lw $t2, 292($sp)
    # Spilling t74 from $t8
    add $t8, $t6, $t2
    # Spilling a83 from $t2
    lw $t2, 296($sp)
    # Spilling t75 from $t7
    add $t7, $t8, $t2
    # Spilling a84 from $t2
    lw $t2, 300($sp)
    # Spilling t76 from $t3
    add $t3, $t7, $t2
    # Spilling a85 from $t2
    lw $t2, 304($sp)
    # Spilling t77 from $t5
    add $t5, $t3, $t2
    # Spilling a86 from $t2
    lw $t2, 308($sp)
    # Spilling t78 from $t4
    add $t4, $t5, $t2
    # Spilling a87 from $t2
    lw $t2, 312($sp)
    # Spilling t79 from $t9
    add $t9, $t4, $t2
    # Spilling a88 from $t2
    lw $t2, 316($sp)
    # Spilling t8 from $t1
    add $t1, $t9, $t2
    # Spilling a89 from $t2
    lw $t2, 320($sp)
    # Spilling t80 from $t6
    add $t6, $t1, $t2
    # Spilling a90 from $t2
    lw $t2, 324($sp)
    # Spilling t81 from $t8
    add $t8, $t6, $t2
    # Spilling a91 from $t2
    lw $t2, 328($sp)
    # Spilling t82 from $t7
    add $t7, $t8, $t2
    # Spilling a92 from $t2
    lw $t2, 332($sp)
    # Spilling t83 from $t3
    add $t3, $t7, $t2
    # Spilling a93 from $t2
    lw $t2, 336($sp)
    # Spilling t84 from $t5
    sub $t5, $t3, $t2
    # Spilling a94 from $t2
    lw $t2, 340($sp)
    # Spilling t85 from $t4
    add $t4, $t5, $t2
    # Spilling a95 from $t2
    lw $t2, 344($sp)
    # Spilling t86 from $t9
    add $t9, $t4, $t2
    # Spilling a96 from $t2
    lw $t2, 348($sp)
    # Spilling t87 from $t1
    add $t1, $t9, $t2
    # Spilling a97 from $t2
    lw $t2, 352($sp)
    # Spilling t88 from $t6
    add $t6, $t1, $t2
    # Spilling a98 from $t2
    lw $t2, 356($sp)
    # Spilling t89 from $t8
    add $t8, $t6, $t2
    # Spilling a99 from $t2
    lw $t2, 360($sp)
    # Spilling t9 from $t0
    add $t0, $t8, $t2
    # Spilling a100 from $t2
    move $t2, $t0
    la $a0, str0
    move $a1, $t2
    # Spilling t90 from $t7
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
    li $v0, 0
    lw   $fp, 804($sp)
    lw   $ra, 808($sp)
    li $v0, 10
    syscall
