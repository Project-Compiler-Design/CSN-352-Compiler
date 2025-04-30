# ======================================================================
# No Errors in the code
# Intermediate code generated successfully
# ======================================================================
.data
newline: .asciiz "\n"
str0: .asciiz "Sum of all variables ="
.text
.globl main
add_all:
    move $fp, $sp
    addi $sp, $sp, -844
    sw   $ra, 840($sp)
    sw   $fp, 836($sp)
    sw   $t0, 832($sp)
    sw   $t1, 828($sp)
    sw   $t2, 824($sp)
    sw   $t3, 820($sp)
    sw   $t4, 816($sp)
    sw   $t5, 812($sp)
    sw   $t6, 808($sp)
    sw   $t7, 804($sp)
    sw   $t8, 800($sp)
    sw   $t9, 796($sp)
    move $t9, $a0
    move $t8, $a1
    move $t7, $a2
    move $t6, $a3
    #popping from stack to $t5
    lw $t5, 0($fp)
    #pushing into function stack
    sw $t5, 0($sp)
    #popping from stack to $t4
    lw $t4, 4($fp)
    #pushing into function stack
    sw $t4, 4($sp)
    #popping from stack to $t3
    lw $t3, 8($fp)
    #pushing into function stack
    sw $t3, 8($sp)
    #popping from stack to $t2
    lw $t2, 12($fp)
    #pushing into function stack
    sw $t2, 12($sp)
    #popping from stack to $t1
    lw $t1, 16($fp)
    #pushing into function stack
    sw $t1, 16($sp)
    #popping from stack to $t0
    lw $t0, 20($fp)
    #pushing into function stack
    sw $t0, 20($sp)
    #Pushing a10 to stack
    sw $t0, 20($sp)
    #popping from stack to $t0
    lw $t0, 24($fp)
    #pushing into function stack
    sw $t0, 24($sp)
    #Pushing a11 to stack
    sw $t0, 24($sp)
    #popping from stack to $t0
    lw $t0, 28($fp)
    #pushing into function stack
    sw $t0, 28($sp)
    #Pushing a12 to stack
    sw $t0, 28($sp)
    #popping from stack to $t0
    lw $t0, 32($fp)
    #pushing into function stack
    sw $t0, 32($sp)
    #Pushing a13 to stack
    sw $t0, 32($sp)
    #popping from stack to $t0
    lw $t0, 36($fp)
    #pushing into function stack
    sw $t0, 36($sp)
    #Pushing a14 to stack
    sw $t0, 36($sp)
    #popping from stack to $t0
    lw $t0, 40($fp)
    #pushing into function stack
    sw $t0, 40($sp)
    #Pushing a15 to stack
    sw $t0, 40($sp)
    #popping from stack to $t0
    lw $t0, 44($fp)
    #pushing into function stack
    sw $t0, 44($sp)
    #Pushing a16 to stack
    sw $t0, 44($sp)
    #popping from stack to $t0
    lw $t0, 48($fp)
    #pushing into function stack
    sw $t0, 48($sp)
    #Pushing a17 to stack
    sw $t0, 48($sp)
    #popping from stack to $t0
    lw $t0, 52($fp)
    #pushing into function stack
    sw $t0, 52($sp)
    #Pushing a18 to stack
    sw $t0, 52($sp)
    #popping from stack to $t0
    lw $t0, 56($fp)
    #pushing into function stack
    sw $t0, 56($sp)
    #Pushing a19 to stack
    sw $t0, 56($sp)
    #popping from stack to $t0
    lw $t0, 60($fp)
    #pushing into function stack
    sw $t0, 60($sp)
    #Pushing a20 to stack
    sw $t0, 60($sp)
    #popping from stack to $t0
    lw $t0, 64($fp)
    #pushing into function stack
    sw $t0, 64($sp)
    #Pushing a21 to stack
    sw $t0, 64($sp)
    #popping from stack to $t0
    lw $t0, 68($fp)
    #pushing into function stack
    sw $t0, 68($sp)
    #Pushing a22 to stack
    sw $t0, 68($sp)
    #popping from stack to $t0
    lw $t0, 72($fp)
    #pushing into function stack
    sw $t0, 72($sp)
    #Pushing a23 to stack
    sw $t0, 72($sp)
    #popping from stack to $t0
    lw $t0, 76($fp)
    #pushing into function stack
    sw $t0, 76($sp)
    #Pushing a24 to stack
    sw $t0, 76($sp)
    #popping from stack to $t0
    lw $t0, 80($fp)
    #pushing into function stack
    sw $t0, 80($sp)
    #Pushing a25 to stack
    sw $t0, 80($sp)
    #popping from stack to $t0
    lw $t0, 84($fp)
    #pushing into function stack
    sw $t0, 84($sp)
    #Pushing a26 to stack
    sw $t0, 84($sp)
    #popping from stack to $t0
    lw $t0, 88($fp)
    #pushing into function stack
    sw $t0, 88($sp)
    #Pushing a27 to stack
    sw $t0, 88($sp)
    #popping from stack to $t0
    lw $t0, 92($fp)
    #pushing into function stack
    sw $t0, 92($sp)
    #Pushing a28 to stack
    sw $t0, 92($sp)
    #popping from stack to $t0
    lw $t0, 96($fp)
    #pushing into function stack
    sw $t0, 96($sp)
    #Pushing a29 to stack
    sw $t0, 96($sp)
    #popping from stack to $t0
    lw $t0, 100($fp)
    #pushing into function stack
    sw $t0, 100($sp)
    #Pushing a30 to stack
    sw $t0, 100($sp)
    #popping from stack to $t0
    lw $t0, 104($fp)
    #pushing into function stack
    sw $t0, 104($sp)
    #Pushing a31 to stack
    sw $t0, 104($sp)
    #popping from stack to $t0
    lw $t0, 108($fp)
    #pushing into function stack
    sw $t0, 108($sp)
    #Pushing a32 to stack
    sw $t0, 108($sp)
    #popping from stack to $t0
    lw $t0, 112($fp)
    #pushing into function stack
    sw $t0, 112($sp)
    #Pushing a33 to stack
    sw $t0, 112($sp)
    #popping from stack to $t0
    lw $t0, 116($fp)
    #pushing into function stack
    sw $t0, 116($sp)
    #Pushing a34 to stack
    sw $t0, 116($sp)
    #popping from stack to $t0
    lw $t0, 120($fp)
    #pushing into function stack
    sw $t0, 120($sp)
    #Pushing a35 to stack
    sw $t0, 120($sp)
    #popping from stack to $t0
    lw $t0, 124($fp)
    #pushing into function stack
    sw $t0, 124($sp)
    #Pushing a36 to stack
    sw $t0, 124($sp)
    #popping from stack to $t0
    lw $t0, 128($fp)
    #pushing into function stack
    sw $t0, 128($sp)
    #Pushing a37 to stack
    sw $t0, 128($sp)
    #popping from stack to $t0
    lw $t0, 132($fp)
    #pushing into function stack
    sw $t0, 132($sp)
    #Pushing a38 to stack
    sw $t0, 132($sp)
    #popping from stack to $t0
    lw $t0, 136($fp)
    #pushing into function stack
    sw $t0, 136($sp)
    #Pushing a39 to stack
    sw $t0, 136($sp)
    #popping from stack to $t0
    lw $t0, 140($fp)
    #pushing into function stack
    sw $t0, 140($sp)
    #Pushing a40 to stack
    sw $t0, 140($sp)
    #popping from stack to $t0
    lw $t0, 144($fp)
    #pushing into function stack
    sw $t0, 144($sp)
    #Pushing a41 to stack
    sw $t0, 144($sp)
    #popping from stack to $t0
    lw $t0, 148($fp)
    #pushing into function stack
    sw $t0, 148($sp)
    #Pushing a42 to stack
    sw $t0, 148($sp)
    #popping from stack to $t0
    lw $t0, 152($fp)
    #pushing into function stack
    sw $t0, 152($sp)
    #Pushing a43 to stack
    sw $t0, 152($sp)
    #popping from stack to $t0
    lw $t0, 156($fp)
    #pushing into function stack
    sw $t0, 156($sp)
    #Pushing a44 to stack
    sw $t0, 156($sp)
    #popping from stack to $t0
    lw $t0, 160($fp)
    #pushing into function stack
    sw $t0, 160($sp)
    #Pushing a45 to stack
    sw $t0, 160($sp)
    #popping from stack to $t0
    lw $t0, 164($fp)
    #pushing into function stack
    sw $t0, 164($sp)
    #Pushing a46 to stack
    sw $t0, 164($sp)
    #popping from stack to $t0
    lw $t0, 168($fp)
    #pushing into function stack
    sw $t0, 168($sp)
    #Pushing a47 to stack
    sw $t0, 168($sp)
    #popping from stack to $t0
    lw $t0, 172($fp)
    #pushing into function stack
    sw $t0, 172($sp)
    #Pushing a48 to stack
    sw $t0, 172($sp)
    #popping from stack to $t0
    lw $t0, 176($fp)
    #pushing into function stack
    sw $t0, 176($sp)
    #Pushing a49 to stack
    sw $t0, 176($sp)
    #popping from stack to $t0
    lw $t0, 180($fp)
    #pushing into function stack
    sw $t0, 180($sp)
    #Pushing a50 to stack
    sw $t0, 180($sp)
    #popping from stack to $t0
    lw $t0, 184($fp)
    #pushing into function stack
    sw $t0, 184($sp)
    #Pushing a51 to stack
    sw $t0, 184($sp)
    #popping from stack to $t0
    lw $t0, 188($fp)
    #pushing into function stack
    sw $t0, 188($sp)
    #Pushing a52 to stack
    sw $t0, 188($sp)
    #popping from stack to $t0
    lw $t0, 192($fp)
    #pushing into function stack
    sw $t0, 192($sp)
    #Pushing a53 to stack
    sw $t0, 192($sp)
    #popping from stack to $t0
    lw $t0, 196($fp)
    #pushing into function stack
    sw $t0, 196($sp)
    #Pushing a54 to stack
    sw $t0, 196($sp)
    #popping from stack to $t0
    lw $t0, 200($fp)
    #pushing into function stack
    sw $t0, 200($sp)
    #Pushing a55 to stack
    sw $t0, 200($sp)
    #popping from stack to $t0
    lw $t0, 204($fp)
    #pushing into function stack
    sw $t0, 204($sp)
    #Pushing a56 to stack
    sw $t0, 204($sp)
    #popping from stack to $t0
    lw $t0, 208($fp)
    #pushing into function stack
    sw $t0, 208($sp)
    #Pushing a57 to stack
    sw $t0, 208($sp)
    #popping from stack to $t0
    lw $t0, 212($fp)
    #pushing into function stack
    sw $t0, 212($sp)
    #Pushing a58 to stack
    sw $t0, 212($sp)
    #popping from stack to $t0
    lw $t0, 216($fp)
    #pushing into function stack
    sw $t0, 216($sp)
    #Pushing a59 to stack
    sw $t0, 216($sp)
    #popping from stack to $t0
    lw $t0, 220($fp)
    #pushing into function stack
    sw $t0, 220($sp)
    #Pushing a60 to stack
    sw $t0, 220($sp)
    #popping from stack to $t0
    lw $t0, 224($fp)
    #pushing into function stack
    sw $t0, 224($sp)
    #Pushing a61 to stack
    sw $t0, 224($sp)
    #popping from stack to $t0
    lw $t0, 228($fp)
    #pushing into function stack
    sw $t0, 228($sp)
    #Pushing a62 to stack
    sw $t0, 228($sp)
    #popping from stack to $t0
    lw $t0, 232($fp)
    #pushing into function stack
    sw $t0, 232($sp)
    #Pushing a63 to stack
    sw $t0, 232($sp)
    #popping from stack to $t0
    lw $t0, 236($fp)
    #pushing into function stack
    sw $t0, 236($sp)
    #Pushing a64 to stack
    sw $t0, 236($sp)
    #popping from stack to $t0
    lw $t0, 240($fp)
    #pushing into function stack
    sw $t0, 240($sp)
    #Pushing a65 to stack
    sw $t0, 240($sp)
    #popping from stack to $t0
    lw $t0, 244($fp)
    #pushing into function stack
    sw $t0, 244($sp)
    #Pushing a66 to stack
    sw $t0, 244($sp)
    #popping from stack to $t0
    lw $t0, 248($fp)
    #pushing into function stack
    sw $t0, 248($sp)
    #Pushing a67 to stack
    sw $t0, 248($sp)
    #popping from stack to $t0
    lw $t0, 252($fp)
    #pushing into function stack
    sw $t0, 252($sp)
    #Pushing a68 to stack
    sw $t0, 252($sp)
    #popping from stack to $t0
    lw $t0, 256($fp)
    #pushing into function stack
    sw $t0, 256($sp)
    #Pushing a69 to stack
    sw $t0, 256($sp)
    #popping from stack to $t0
    lw $t0, 260($fp)
    #pushing into function stack
    sw $t0, 260($sp)
    #Pushing a70 to stack
    sw $t0, 260($sp)
    #popping from stack to $t0
    lw $t0, 264($fp)
    #pushing into function stack
    sw $t0, 264($sp)
    #Pushing a71 to stack
    sw $t0, 264($sp)
    #popping from stack to $t0
    lw $t0, 268($fp)
    #pushing into function stack
    sw $t0, 268($sp)
    #Pushing a72 to stack
    sw $t0, 268($sp)
    #popping from stack to $t0
    lw $t0, 272($fp)
    #pushing into function stack
    sw $t0, 272($sp)
    #Pushing a73 to stack
    sw $t0, 272($sp)
    #popping from stack to $t0
    lw $t0, 276($fp)
    #pushing into function stack
    sw $t0, 276($sp)
    #Pushing a74 to stack
    sw $t0, 276($sp)
    #popping from stack to $t0
    lw $t0, 280($fp)
    #pushing into function stack
    sw $t0, 280($sp)
    #Pushing a75 to stack
    sw $t0, 280($sp)
    #popping from stack to $t0
    lw $t0, 284($fp)
    #pushing into function stack
    sw $t0, 284($sp)
    #Pushing a76 to stack
    sw $t0, 284($sp)
    #popping from stack to $t0
    lw $t0, 288($fp)
    #pushing into function stack
    sw $t0, 288($sp)
    #Pushing a77 to stack
    sw $t0, 288($sp)
    #popping from stack to $t0
    lw $t0, 292($fp)
    #pushing into function stack
    sw $t0, 292($sp)
    #Pushing a78 to stack
    sw $t0, 292($sp)
    #popping from stack to $t0
    lw $t0, 296($fp)
    #pushing into function stack
    sw $t0, 296($sp)
    #Pushing a79 to stack
    sw $t0, 296($sp)
    #popping from stack to $t0
    lw $t0, 300($fp)
    #pushing into function stack
    sw $t0, 300($sp)
    #Pushing a80 to stack
    sw $t0, 300($sp)
    #popping from stack to $t0
    lw $t0, 304($fp)
    #pushing into function stack
    sw $t0, 304($sp)
    #Pushing a81 to stack
    sw $t0, 304($sp)
    #popping from stack to $t0
    lw $t0, 308($fp)
    #pushing into function stack
    sw $t0, 308($sp)
    #Pushing a82 to stack
    sw $t0, 308($sp)
    #popping from stack to $t0
    lw $t0, 312($fp)
    #pushing into function stack
    sw $t0, 312($sp)
    #Pushing a83 to stack
    sw $t0, 312($sp)
    #popping from stack to $t0
    lw $t0, 316($fp)
    #pushing into function stack
    sw $t0, 316($sp)
    #Pushing a84 to stack
    sw $t0, 316($sp)
    #popping from stack to $t0
    lw $t0, 320($fp)
    #pushing into function stack
    sw $t0, 320($sp)
    #Pushing a85 to stack
    sw $t0, 320($sp)
    #popping from stack to $t0
    lw $t0, 324($fp)
    #pushing into function stack
    sw $t0, 324($sp)
    #Pushing a86 to stack
    sw $t0, 324($sp)
    #popping from stack to $t0
    lw $t0, 328($fp)
    #pushing into function stack
    sw $t0, 328($sp)
    #Pushing a87 to stack
    sw $t0, 328($sp)
    #popping from stack to $t0
    lw $t0, 332($fp)
    #pushing into function stack
    sw $t0, 332($sp)
    #Pushing a88 to stack
    sw $t0, 332($sp)
    #popping from stack to $t0
    lw $t0, 336($fp)
    #pushing into function stack
    sw $t0, 336($sp)
    #Pushing a89 to stack
    sw $t0, 336($sp)
    #popping from stack to $t0
    lw $t0, 340($fp)
    #pushing into function stack
    sw $t0, 340($sp)
    #Pushing a90 to stack
    sw $t0, 340($sp)
    #popping from stack to $t0
    lw $t0, 344($fp)
    #pushing into function stack
    sw $t0, 344($sp)
    #Pushing a91 to stack
    sw $t0, 344($sp)
    #popping from stack to $t0
    lw $t0, 348($fp)
    #pushing into function stack
    sw $t0, 348($sp)
    #Pushing a92 to stack
    sw $t0, 348($sp)
    #popping from stack to $t0
    lw $t0, 352($fp)
    #pushing into function stack
    sw $t0, 352($sp)
    #Pushing a93 to stack
    sw $t0, 352($sp)
    #popping from stack to $t0
    lw $t0, 356($fp)
    #pushing into function stack
    sw $t0, 356($sp)
    #Pushing a94 to stack
    sw $t0, 356($sp)
    #popping from stack to $t0
    lw $t0, 360($fp)
    #pushing into function stack
    sw $t0, 360($sp)
    #Pushing a95 to stack
    sw $t0, 360($sp)
    #popping from stack to $t0
    lw $t0, 364($fp)
    #pushing into function stack
    sw $t0, 364($sp)
    #Pushing a96 to stack
    sw $t0, 364($sp)
    #popping from stack to $t0
    lw $t0, 368($fp)
    #pushing into function stack
    sw $t0, 368($sp)
    #Pushing a97 to stack
    sw $t0, 368($sp)
    #popping from stack to $t0
    lw $t0, 372($fp)
    #pushing into function stack
    sw $t0, 372($sp)
    #Pushing a98 to stack
    sw $t0, 372($sp)
    #popping from stack to $t0
    lw $t0, 376($fp)
    #pushing into function stack
    sw $t0, 376($sp)
    #Pushing a99 to stack
    sw $t0, 376($sp)
    #popping from stack to $t0
    lw $t0, 380($fp)
    #pushing into function stack
    sw $t0, 380($sp)
    #Pushing a100 to stack
    sw $t0, 380($sp)
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
    lw $t2, 20($sp)
    # Spilling a9 from $t1
    add $t1, $t3, $t2
    # Spilling a10 from $t2
    lw $t2, 24($sp)
    # Spilling t0 from $t0
    add $t0, $t1, $t2
    # Spilling a11 from $t2
    lw $t2, 28($sp)
    # Spilling t1 from $t9
    add $t9, $t0, $t2
    # Spilling a12 from $t2
    lw $t2, 32($sp)
    # Spilling t2 from $t8
    add $t8, $t9, $t2
    # Spilling a13 from $t2
    lw $t2, 36($sp)
    # Spilling t10 from $t9
    add $t9, $t8, $t2
    # Spilling a14 from $t2
    lw $t2, 40($sp)
    # Spilling t11 from $t8
    add $t8, $t9, $t2
    # Spilling a15 from $t2
    lw $t2, 44($sp)
    # Spilling t12 from $t9
    add $t9, $t8, $t2
    # Spilling a16 from $t2
    lw $t2, 48($sp)
    # Spilling t13 from $t8
    add $t8, $t9, $t2
    # Spilling a17 from $t2
    lw $t2, 52($sp)
    # Spilling t14 from $t9
    add $t9, $t8, $t2
    # Spilling a18 from $t2
    lw $t2, 56($sp)
    # Spilling t15 from $t8
    add $t8, $t9, $t2
    # Spilling a19 from $t2
    lw $t2, 60($sp)
    # Spilling t16 from $t9
    add $t9, $t8, $t2
    # Spilling a20 from $t2
    lw $t2, 64($sp)
    # Spilling t17 from $t8
    add $t8, $t9, $t2
    # Spilling a21 from $t2
    lw $t2, 68($sp)
    # Spilling t18 from $t9
    add $t9, $t8, $t2
    # Spilling a22 from $t2
    lw $t2, 72($sp)
    # Spilling t19 from $t8
    add $t8, $t9, $t2
    # Spilling a23 from $t2
    lw $t2, 76($sp)
    # Spilling t20 from $t9
    add $t9, $t8, $t2
    # Spilling a24 from $t2
    lw $t2, 80($sp)
    # Spilling t21 from $t8
    add $t8, $t9, $t2
    # Spilling a25 from $t2
    lw $t2, 84($sp)
    # Spilling t22 from $t9
    add $t9, $t8, $t2
    # Spilling a26 from $t2
    lw $t2, 88($sp)
    # Spilling t23 from $t8
    add $t8, $t9, $t2
    # Spilling a27 from $t2
    lw $t2, 92($sp)
    # Spilling t24 from $t9
    add $t9, $t8, $t2
    # Spilling a28 from $t2
    lw $t2, 96($sp)
    # Spilling t25 from $t8
    add $t8, $t9, $t2
    # Spilling a29 from $t2
    lw $t2, 100($sp)
    # Spilling t26 from $t9
    add $t9, $t8, $t2
    # Spilling a30 from $t2
    lw $t2, 104($sp)
    # Spilling t27 from $t8
    add $t8, $t9, $t2
    # Spilling a31 from $t2
    lw $t2, 108($sp)
    # Spilling t28 from $t9
    add $t9, $t8, $t2
    # Spilling a32 from $t2
    lw $t2, 112($sp)
    # Spilling t29 from $t8
    add $t8, $t9, $t2
    # Spilling a33 from $t2
    lw $t2, 116($sp)
    # Spilling t3 from $t7
    add $t7, $t8, $t2
    # Spilling a34 from $t2
    lw $t2, 120($sp)
    # Spilling t30 from $t9
    add $t9, $t7, $t2
    # Spilling a35 from $t2
    lw $t2, 124($sp)
    # Spilling t31 from $t8
    add $t8, $t9, $t2
    # Spilling a36 from $t2
    lw $t2, 128($sp)
    # Spilling t32 from $t7
    add $t7, $t8, $t2
    # Spilling a37 from $t2
    lw $t2, 132($sp)
    # Spilling t33 from $t9
    add $t9, $t7, $t2
    # Spilling a38 from $t2
    lw $t2, 136($sp)
    # Spilling t34 from $t8
    add $t8, $t9, $t2
    # Spilling a39 from $t2
    lw $t2, 140($sp)
    # Spilling t35 from $t7
    add $t7, $t8, $t2
    # Spilling a40 from $t2
    lw $t2, 144($sp)
    # Spilling t36 from $t9
    add $t9, $t7, $t2
    # Spilling a41 from $t2
    lw $t2, 148($sp)
    # Spilling t37 from $t8
    add $t8, $t9, $t2
    # Spilling a42 from $t2
    lw $t2, 152($sp)
    # Spilling t38 from $t7
    add $t7, $t8, $t2
    # Spilling a43 from $t2
    lw $t2, 156($sp)
    # Spilling t39 from $t9
    add $t9, $t7, $t2
    # Spilling a44 from $t2
    lw $t2, 160($sp)
    # Spilling t4 from $t6
    add $t6, $t9, $t2
    # Spilling a45 from $t2
    lw $t2, 164($sp)
    # Spilling t40 from $t8
    add $t8, $t6, $t2
    # Spilling a46 from $t2
    lw $t2, 168($sp)
    # Spilling t41 from $t7
    add $t7, $t8, $t2
    # Spilling a47 from $t2
    lw $t2, 172($sp)
    # Spilling t42 from $t9
    add $t9, $t7, $t2
    # Spilling a48 from $t2
    lw $t2, 176($sp)
    # Spilling t43 from $t6
    add $t6, $t9, $t2
    # Spilling a49 from $t2
    lw $t2, 180($sp)
    # Spilling t44 from $t8
    add $t8, $t6, $t2
    # Spilling a50 from $t2
    lw $t2, 184($sp)
    # Spilling t45 from $t7
    add $t7, $t8, $t2
    # Spilling a51 from $t2
    lw $t2, 188($sp)
    # Spilling t46 from $t9
    add $t9, $t7, $t2
    # Spilling a52 from $t2
    lw $t2, 192($sp)
    # Spilling t47 from $t6
    add $t6, $t9, $t2
    # Spilling a53 from $t2
    lw $t2, 196($sp)
    # Spilling t48 from $t8
    add $t8, $t6, $t2
    # Spilling a54 from $t2
    lw $t2, 200($sp)
    # Spilling t49 from $t7
    add $t7, $t8, $t2
    # Spilling a55 from $t2
    lw $t2, 204($sp)
    # Spilling t5 from $t5
    add $t5, $t7, $t2
    # Spilling a56 from $t2
    lw $t2, 208($sp)
    # Spilling t50 from $t9
    add $t9, $t5, $t2
    # Spilling a57 from $t2
    lw $t2, 212($sp)
    # Spilling t51 from $t6
    add $t6, $t9, $t2
    # Spilling a58 from $t2
    lw $t2, 216($sp)
    # Spilling t52 from $t8
    add $t8, $t6, $t2
    # Spilling a59 from $t2
    lw $t2, 220($sp)
    # Spilling t53 from $t7
    add $t7, $t8, $t2
    # Spilling a60 from $t2
    lw $t2, 224($sp)
    # Spilling t54 from $t5
    add $t5, $t7, $t2
    # Spilling a61 from $t2
    lw $t2, 228($sp)
    # Spilling t55 from $t9
    add $t9, $t5, $t2
    # Spilling a62 from $t2
    lw $t2, 232($sp)
    # Spilling t56 from $t6
    add $t6, $t9, $t2
    # Spilling a63 from $t2
    lw $t2, 236($sp)
    # Spilling t57 from $t8
    add $t8, $t6, $t2
    # Spilling a64 from $t2
    lw $t2, 240($sp)
    # Spilling t58 from $t7
    add $t7, $t8, $t2
    # Spilling a65 from $t2
    lw $t2, 244($sp)
    # Spilling t59 from $t5
    add $t5, $t7, $t2
    # Spilling a66 from $t2
    lw $t2, 248($sp)
    # Spilling t6 from $t4
    add $t4, $t5, $t2
    # Spilling a67 from $t2
    lw $t2, 252($sp)
    # Spilling t60 from $t9
    add $t9, $t4, $t2
    # Spilling a68 from $t2
    lw $t2, 256($sp)
    # Spilling t61 from $t6
    add $t6, $t9, $t2
    # Spilling a69 from $t2
    lw $t2, 260($sp)
    # Spilling t62 from $t8
    add $t8, $t6, $t2
    # Spilling a70 from $t2
    lw $t2, 264($sp)
    # Spilling t63 from $t7
    add $t7, $t8, $t2
    # Spilling a71 from $t2
    lw $t2, 268($sp)
    # Spilling t64 from $t5
    add $t5, $t7, $t2
    # Spilling a72 from $t2
    lw $t2, 272($sp)
    # Spilling t65 from $t4
    add $t4, $t5, $t2
    # Spilling a73 from $t2
    lw $t2, 276($sp)
    # Spilling t66 from $t9
    add $t9, $t4, $t2
    # Spilling a74 from $t2
    lw $t2, 280($sp)
    # Spilling t67 from $t6
    add $t6, $t9, $t2
    # Spilling a75 from $t2
    lw $t2, 284($sp)
    # Spilling t68 from $t8
    add $t8, $t6, $t2
    # Spilling a76 from $t2
    lw $t2, 288($sp)
    # Spilling t69 from $t7
    add $t7, $t8, $t2
    # Spilling a77 from $t2
    lw $t2, 292($sp)
    # Spilling t7 from $t3
    add $t3, $t7, $t2
    # Spilling a78 from $t2
    lw $t2, 296($sp)
    # Spilling t70 from $t5
    add $t5, $t3, $t2
    # Spilling a79 from $t2
    lw $t2, 300($sp)
    # Spilling t71 from $t4
    add $t4, $t5, $t2
    # Spilling a80 from $t2
    lw $t2, 304($sp)
    # Spilling t72 from $t9
    add $t9, $t4, $t2
    # Spilling a81 from $t2
    lw $t2, 308($sp)
    # Spilling t73 from $t6
    add $t6, $t9, $t2
    # Spilling a82 from $t2
    lw $t2, 312($sp)
    # Spilling t74 from $t8
    add $t8, $t6, $t2
    # Spilling a83 from $t2
    lw $t2, 316($sp)
    # Spilling t75 from $t7
    add $t7, $t8, $t2
    # Spilling a84 from $t2
    lw $t2, 320($sp)
    # Spilling t76 from $t3
    add $t3, $t7, $t2
    # Spilling a85 from $t2
    lw $t2, 324($sp)
    # Spilling t77 from $t5
    add $t5, $t3, $t2
    # Spilling a86 from $t2
    lw $t2, 328($sp)
    # Spilling t78 from $t4
    add $t4, $t5, $t2
    # Spilling a87 from $t2
    lw $t2, 332($sp)
    # Spilling t79 from $t9
    add $t9, $t4, $t2
    # Spilling a88 from $t2
    lw $t2, 336($sp)
    # Spilling t8 from $t1
    add $t1, $t9, $t2
    # Spilling a89 from $t2
    lw $t2, 340($sp)
    # Spilling t80 from $t6
    add $t6, $t1, $t2
    # Spilling a90 from $t2
    lw $t2, 344($sp)
    # Spilling t81 from $t8
    add $t8, $t6, $t2
    # Spilling a91 from $t2
    lw $t2, 348($sp)
    # Spilling t82 from $t7
    add $t7, $t8, $t2
    # Spilling a92 from $t2
    lw $t2, 352($sp)
    # Spilling t83 from $t3
    add $t3, $t7, $t2
    # Spilling a93 from $t2
    lw $t2, 356($sp)
    # Spilling t84 from $t5
    add $t5, $t3, $t2
    # Spilling a94 from $t2
    lw $t2, 360($sp)
    # Spilling t85 from $t4
    add $t4, $t5, $t2
    # Spilling a95 from $t2
    lw $t2, 364($sp)
    # Spilling t86 from $t9
    add $t9, $t4, $t2
    # Spilling a96 from $t2
    lw $t2, 368($sp)
    # Spilling t87 from $t1
    add $t1, $t9, $t2
    # Spilling a97 from $t2
    lw $t2, 372($sp)
    # Spilling t88 from $t6
    add $t6, $t1, $t2
    # Spilling a98 from $t2
    lw $t2, 376($sp)
    # Spilling t89 from $t8
    add $t8, $t6, $t2
    # Spilling a99 from $t2
    lw $t2, 380($sp)
    # Spilling t9 from $t0
    add $t0, $t8, $t2
    move $v0, $t0
    lw   $fp, 836($sp)
    lw   $ra, 840($sp)
    lw   $t0, 832($sp)
    lw   $t1, 828($sp)
    lw   $t2, 824($sp)
    lw   $t3, 820($sp)
    lw   $t4, 816($sp)
    lw   $t5, 812($sp)
    lw   $t6, 808($sp)
    lw   $t7, 804($sp)
    lw   $t8, 800($sp)
    lw   $t9, 796($sp)
    addi $sp, $sp, 844
    jr   $ra
main:
    move $fp, $sp
    addi $sp, $sp, -420
    sw   $ra, 416($sp)
    sw   $fp, 412($sp)
    # Spilling a100 from $t2
    li $t2, 10
    # Spilling t90 from $t7
    li $t7, 10
    # Spilling t91 from $t3
    li $t3, 10
    # Spilling t92 from $t5
    li $t5, 10
    # Spilling t93 from $t4
    li $t4, 10
    # Spilling t94 from $t9
    li $t9, 10
    # Spilling t95 from $t1
    li $t1, 10
    # Spilling t96 from $t6
    li $t6, 10
    # Spilling t97 from $t8
    li $t8, 10
    # Spilling t98 from $t0
    li $t0, 10
    #Pushing a1 to stack
    sw $t2, 0($sp)
    li $t2, 10
    #Pushing a10 to stack
    sw $t0, 4($sp)
    li $t0, 10
    #Pushing a11 to stack
    sw $t2, 8($sp)
    li $t2, 10
    #Pushing a12 to stack
    sw $t0, 12($sp)
    li $t0, 10
    #Pushing a13 to stack
    sw $t2, 16($sp)
    li $t2, 10
    #Pushing a14 to stack
    sw $t0, 20($sp)
    li $t0, 10
    #Pushing a15 to stack
    sw $t2, 24($sp)
    li $t2, 10
    #Pushing a16 to stack
    sw $t0, 28($sp)
    li $t0, 10
    #Pushing a17 to stack
    sw $t2, 32($sp)
    li $t2, 10
    #Pushing a18 to stack
    sw $t0, 36($sp)
    li $t0, 10
    #Pushing a19 to stack
    sw $t2, 40($sp)
    li $t2, 10
    #Pushing a2 to stack
    sw $t7, 44($sp)
    li $t7, 10
    #Pushing a20 to stack
    sw $t0, 48($sp)
    li $t0, 10
    #Pushing a21 to stack
    sw $t2, 52($sp)
    li $t2, 10
    #Pushing a22 to stack
    sw $t7, 56($sp)
    li $t7, 10
    #Pushing a23 to stack
    sw $t0, 60($sp)
    li $t0, 10
    #Pushing a24 to stack
    sw $t2, 64($sp)
    li $t2, 10
    #Pushing a25 to stack
    sw $t7, 68($sp)
    li $t7, 10
    #Pushing a26 to stack
    sw $t0, 72($sp)
    li $t0, 10
    #Pushing a27 to stack
    sw $t2, 76($sp)
    li $t2, 10
    #Pushing a28 to stack
    sw $t7, 80($sp)
    li $t7, 10
    #Pushing a29 to stack
    sw $t0, 84($sp)
    li $t0, 10
    #Pushing a3 to stack
    sw $t3, 88($sp)
    li $t3, 10
    #Pushing a30 to stack
    sw $t2, 92($sp)
    li $t2, 10
    #Pushing a31 to stack
    sw $t7, 96($sp)
    li $t7, 10
    #Pushing a32 to stack
    sw $t0, 100($sp)
    li $t0, 10
    #Pushing a33 to stack
    sw $t3, 104($sp)
    li $t3, 10
    #Pushing a34 to stack
    sw $t2, 108($sp)
    li $t2, 10
    #Pushing a35 to stack
    sw $t7, 112($sp)
    li $t7, 10
    #Pushing a36 to stack
    sw $t0, 116($sp)
    li $t0, 10
    #Pushing a37 to stack
    sw $t3, 120($sp)
    li $t3, 10
    #Pushing a38 to stack
    sw $t2, 124($sp)
    li $t2, 10
    #Pushing a39 to stack
    sw $t7, 128($sp)
    li $t7, 10
    #Pushing a4 to stack
    sw $t5, 132($sp)
    li $t5, 10
    #Pushing a40 to stack
    sw $t0, 136($sp)
    li $t0, 10
    #Pushing a41 to stack
    sw $t3, 140($sp)
    li $t3, 10
    #Pushing a42 to stack
    sw $t2, 144($sp)
    li $t2, 10
    #Pushing a43 to stack
    sw $t7, 148($sp)
    li $t7, 10
    #Pushing a44 to stack
    sw $t5, 152($sp)
    li $t5, 10
    #Pushing a45 to stack
    sw $t0, 156($sp)
    li $t0, 10
    #Pushing a46 to stack
    sw $t3, 160($sp)
    li $t3, 10
    #Pushing a47 to stack
    sw $t2, 164($sp)
    li $t2, 10
    #Pushing a48 to stack
    sw $t7, 168($sp)
    li $t7, 10
    #Pushing a49 to stack
    sw $t5, 172($sp)
    li $t5, 10
    #Pushing a5 to stack
    sw $t4, 176($sp)
    li $t4, 10
    #Pushing a50 to stack
    sw $t0, 180($sp)
    li $t0, 10
    #Pushing a51 to stack
    sw $t3, 184($sp)
    li $t3, 10
    #Pushing a52 to stack
    sw $t2, 188($sp)
    li $t2, 10
    #Pushing a53 to stack
    sw $t7, 192($sp)
    li $t7, 10
    #Pushing a54 to stack
    sw $t5, 196($sp)
    li $t5, 10
    #Pushing a55 to stack
    sw $t4, 200($sp)
    li $t4, 10
    #Pushing a56 to stack
    sw $t0, 204($sp)
    li $t0, 10
    #Pushing a57 to stack
    sw $t3, 208($sp)
    li $t3, 10
    #Pushing a58 to stack
    sw $t2, 212($sp)
    li $t2, 10
    #Pushing a59 to stack
    sw $t7, 216($sp)
    li $t7, 10
    #Pushing a6 to stack
    sw $t9, 220($sp)
    li $t9, 10
    #Pushing a60 to stack
    sw $t5, 224($sp)
    li $t5, 10
    #Pushing a61 to stack
    sw $t4, 228($sp)
    li $t4, 10
    #Pushing a62 to stack
    sw $t0, 232($sp)
    li $t0, 10
    #Pushing a63 to stack
    sw $t3, 236($sp)
    li $t3, 10
    #Pushing a64 to stack
    sw $t2, 240($sp)
    li $t2, 10
    #Pushing a65 to stack
    sw $t7, 244($sp)
    li $t7, 10
    #Pushing a66 to stack
    sw $t9, 248($sp)
    li $t9, 10
    #Pushing a67 to stack
    sw $t5, 252($sp)
    li $t5, 10
    #Pushing a68 to stack
    sw $t4, 256($sp)
    li $t4, 10
    #Pushing a69 to stack
    sw $t0, 260($sp)
    li $t0, 10
    #Pushing a7 to stack
    sw $t1, 264($sp)
    li $t1, 10
    #Pushing a70 to stack
    sw $t3, 268($sp)
    li $t3, 10
    #Pushing a71 to stack
    sw $t2, 272($sp)
    li $t2, 10
    #Pushing a72 to stack
    sw $t7, 276($sp)
    li $t7, 10
    #Pushing a73 to stack
    sw $t9, 280($sp)
    li $t9, 10
    #Pushing a74 to stack
    sw $t5, 284($sp)
    li $t5, 10
    #Pushing a75 to stack
    sw $t4, 288($sp)
    li $t4, 10
    #Pushing a76 to stack
    sw $t0, 292($sp)
    li $t0, 10
    #Pushing a77 to stack
    sw $t1, 296($sp)
    li $t1, 10
    #Pushing a78 to stack
    sw $t3, 300($sp)
    li $t3, 10
    #Pushing a79 to stack
    sw $t2, 304($sp)
    li $t2, 10
    #Pushing a8 to stack
    sw $t6, 308($sp)
    li $t6, 10
    #Pushing a80 to stack
    sw $t7, 312($sp)
    li $t7, 10
    #Pushing a81 to stack
    sw $t9, 316($sp)
    li $t9, 10
    #Pushing a82 to stack
    sw $t5, 320($sp)
    li $t5, 10
    #Pushing a83 to stack
    sw $t4, 324($sp)
    li $t4, 10
    #Pushing a84 to stack
    sw $t0, 328($sp)
    li $t0, 10
    #Pushing a85 to stack
    sw $t1, 332($sp)
    li $t1, 10
    #Pushing a86 to stack
    sw $t3, 336($sp)
    li $t3, 10
    #Pushing a87 to stack
    sw $t2, 340($sp)
    li $t2, 10
    #Pushing a88 to stack
    sw $t6, 344($sp)
    li $t6, 10
    #Pushing a89 to stack
    sw $t7, 348($sp)
    li $t7, 10
    #Pushing a9 to stack
    sw $t8, 352($sp)
    li $t8, 10
    #Pushing a90 to stack
    sw $t9, 356($sp)
    li $t9, 10
    #Pushing a100 to stack
    sw $t9, 360($sp)
    lw $t9, 0($sp)
    move $a0, $t9
    #Pushing a1 to stack
    sw $t9, 0($sp)
    lw $t9, 44($sp)
    move $a1, $t9
    #Pushing a2 to stack
    sw $t9, 44($sp)
    lw $t9, 88($sp)
    move $a2, $t9
    #Pushing a3 to stack
    sw $t9, 88($sp)
    lw $t9, 132($sp)
    move $a3, $t9
    #Pushing a4 to stack
    sw $t9, 132($sp)
    lw $t9, 176($sp)
    #Pushing a5 to stack
    sw $t9, 176($sp)
    lw $t9, 220($sp)
    #Pushing a6 to stack
    sw $t9, 220($sp)
    lw $t9, 264($sp)
    #Pushing a7 to stack
    sw $t9, 264($sp)
    lw $t9, 308($sp)
    #Pushing a8 to stack
    sw $t9, 308($sp)
    lw $t9, 352($sp)
    #Pushing a9 to stack
    sw $t9, 352($sp)
    lw $t9, 4($sp)
    #Pushing a10 to stack
    sw $t9, 4($sp)
    lw $t9, 8($sp)
    #Pushing a11 to stack
    sw $t9, 8($sp)
    lw $t9, 12($sp)
    #Pushing a12 to stack
    sw $t9, 12($sp)
    lw $t9, 16($sp)
    #Pushing a13 to stack
    sw $t9, 16($sp)
    lw $t9, 20($sp)
    #Pushing a14 to stack
    sw $t9, 20($sp)
    lw $t9, 24($sp)
    #Pushing a15 to stack
    sw $t9, 24($sp)
    lw $t9, 28($sp)
    #Pushing a16 to stack
    sw $t9, 28($sp)
    lw $t9, 32($sp)
    #Pushing a17 to stack
    sw $t9, 32($sp)
    lw $t9, 36($sp)
    #Pushing a18 to stack
    sw $t9, 36($sp)
    lw $t9, 40($sp)
    #Pushing a19 to stack
    sw $t9, 40($sp)
    lw $t9, 48($sp)
    #Pushing a20 to stack
    sw $t9, 48($sp)
    lw $t9, 52($sp)
    #Pushing a21 to stack
    sw $t9, 52($sp)
    lw $t9, 56($sp)
    #Pushing a22 to stack
    sw $t9, 56($sp)
    lw $t9, 60($sp)
    #Pushing a23 to stack
    sw $t9, 60($sp)
    lw $t9, 64($sp)
    #Pushing a24 to stack
    sw $t9, 64($sp)
    lw $t9, 68($sp)
    #Pushing a25 to stack
    sw $t9, 68($sp)
    lw $t9, 72($sp)
    #Pushing a26 to stack
    sw $t9, 72($sp)
    lw $t9, 76($sp)
    #Pushing a27 to stack
    sw $t9, 76($sp)
    lw $t9, 80($sp)
    #Pushing a28 to stack
    sw $t9, 80($sp)
    lw $t9, 84($sp)
    #Pushing a29 to stack
    sw $t9, 84($sp)
    lw $t9, 92($sp)
    #Pushing a30 to stack
    sw $t9, 92($sp)
    lw $t9, 96($sp)
    #Pushing a31 to stack
    sw $t9, 96($sp)
    lw $t9, 100($sp)
    #Pushing a32 to stack
    sw $t9, 100($sp)
    lw $t9, 104($sp)
    #Pushing a33 to stack
    sw $t9, 104($sp)
    lw $t9, 108($sp)
    #Pushing a34 to stack
    sw $t9, 108($sp)
    lw $t9, 112($sp)
    #Pushing a35 to stack
    sw $t9, 112($sp)
    lw $t9, 116($sp)
    #Pushing a36 to stack
    sw $t9, 116($sp)
    lw $t9, 120($sp)
    #Pushing a37 to stack
    sw $t9, 120($sp)
    lw $t9, 124($sp)
    #Pushing a38 to stack
    sw $t9, 124($sp)
    lw $t9, 128($sp)
    #Pushing a39 to stack
    sw $t9, 128($sp)
    lw $t9, 136($sp)
    #Pushing a40 to stack
    sw $t9, 136($sp)
    lw $t9, 140($sp)
    #Pushing a41 to stack
    sw $t9, 140($sp)
    lw $t9, 144($sp)
    #Pushing a42 to stack
    sw $t9, 144($sp)
    lw $t9, 148($sp)
    #Pushing a43 to stack
    sw $t9, 148($sp)
    lw $t9, 152($sp)
    #Pushing a44 to stack
    sw $t9, 152($sp)
    lw $t9, 156($sp)
    #Pushing a45 to stack
    sw $t9, 156($sp)
    lw $t9, 160($sp)
    #Pushing a46 to stack
    sw $t9, 160($sp)
    lw $t9, 164($sp)
    #Pushing a47 to stack
    sw $t9, 164($sp)
    lw $t9, 168($sp)
    #Pushing a48 to stack
    sw $t9, 168($sp)
    lw $t9, 172($sp)
    #Pushing a49 to stack
    sw $t9, 172($sp)
    lw $t9, 180($sp)
    #Pushing a50 to stack
    sw $t9, 180($sp)
    lw $t9, 184($sp)
    #Pushing a51 to stack
    sw $t9, 184($sp)
    lw $t9, 188($sp)
    #Pushing a52 to stack
    sw $t9, 188($sp)
    lw $t9, 192($sp)
    #Pushing a53 to stack
    sw $t9, 192($sp)
    lw $t9, 196($sp)
    #Pushing a54 to stack
    sw $t9, 196($sp)
    lw $t9, 200($sp)
    #Pushing a55 to stack
    sw $t9, 200($sp)
    lw $t9, 204($sp)
    #Pushing a56 to stack
    sw $t9, 204($sp)
    lw $t9, 208($sp)
    #Pushing a57 to stack
    sw $t9, 208($sp)
    lw $t9, 212($sp)
    #Pushing a58 to stack
    sw $t9, 212($sp)
    lw $t9, 216($sp)
    #Pushing a59 to stack
    sw $t9, 216($sp)
    lw $t9, 224($sp)
    #Pushing a60 to stack
    sw $t9, 224($sp)
    lw $t9, 228($sp)
    #Pushing a61 to stack
    sw $t9, 228($sp)
    lw $t9, 232($sp)
    #Pushing a62 to stack
    sw $t9, 232($sp)
    lw $t9, 236($sp)
    #Pushing a63 to stack
    sw $t9, 236($sp)
    lw $t9, 240($sp)
    #Pushing a64 to stack
    sw $t9, 240($sp)
    lw $t9, 244($sp)
    #Pushing a65 to stack
    sw $t9, 244($sp)
    lw $t9, 248($sp)
    #Pushing a66 to stack
    sw $t9, 248($sp)
    lw $t9, 252($sp)
    #Pushing a67 to stack
    sw $t9, 252($sp)
    lw $t9, 256($sp)
    #Pushing a68 to stack
    sw $t9, 256($sp)
    lw $t9, 260($sp)
    #Pushing a69 to stack
    sw $t9, 260($sp)
    lw $t9, 268($sp)
    #Pushing a70 to stack
    sw $t9, 268($sp)
    lw $t9, 272($sp)
    #Pushing a71 to stack
    sw $t9, 272($sp)
    lw $t9, 276($sp)
    #Pushing a72 to stack
    sw $t9, 276($sp)
    lw $t9, 280($sp)
    #Pushing a73 to stack
    sw $t9, 280($sp)
    lw $t9, 284($sp)
    #Pushing a74 to stack
    sw $t9, 284($sp)
    lw $t9, 288($sp)
    #Pushing a75 to stack
    sw $t9, 288($sp)
    lw $t9, 292($sp)
    #Pushing a76 to stack
    sw $t9, 292($sp)
    lw $t9, 296($sp)
    #Pushing a77 to stack
    sw $t9, 296($sp)
    lw $t9, 300($sp)
    #Pushing a78 to stack
    sw $t9, 300($sp)
    lw $t9, 304($sp)
    #Pushing a79 to stack
    sw $t9, 304($sp)
    lw $t9, 312($sp)
    #Pushing a80 to stack
    sw $t9, 312($sp)
    lw $t9, 316($sp)
    #Pushing a81 to stack
    sw $t9, 316($sp)
    lw $t9, 320($sp)
    #Pushing a82 to stack
    sw $t9, 320($sp)
    lw $t9, 324($sp)
    #Pushing a83 to stack
    sw $t9, 324($sp)
    lw $t9, 328($sp)
    #Pushing a84 to stack
    sw $t9, 328($sp)
    lw $t9, 332($sp)
    #Pushing a85 to stack
    sw $t9, 332($sp)
    lw $t9, 336($sp)
    #Pushing a86 to stack
    sw $t9, 336($sp)
    lw $t9, 340($sp)
    #Pushing a87 to stack
    sw $t9, 340($sp)
    lw $t9, 344($sp)
    #Pushing a88 to stack
    sw $t9, 344($sp)
    lw $t9, 348($sp)
    #Pushing a89 to stack
    sw $t9, 348($sp)
    lw $t9, 356($sp)
    #Pushing a90 to stack
    sw $t9, 356($sp)
    lw $t9, 360($sp)
    #Pushing a100 to stack
    sw $t9, 360($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t8, 0($sp)
    addi $sp, $sp, -4 
    sw $t7, 0($sp)
    addi $sp, $sp, -4 
    sw $t6, 0($sp)
    addi $sp, $sp, -4 
    sw $t2, 0($sp)
    addi $sp, $sp, -4 
    sw $t3, 0($sp)
    addi $sp, $sp, -4 
    sw $t1, 0($sp)
    addi $sp, $sp, -4 
    sw $t0, 0($sp)
    addi $sp, $sp, -4 
    sw $t4, 0($sp)
    addi $sp, $sp, -4 
    sw $t5, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    addi $sp, $sp, -4 
    sw $t9, 0($sp)
    jal add_all
    move $t9, $v0
    #Pushing a91 to stack
    sw $t5, 364($sp)
    move $t5, $t9
    la $a0, str0
    move $a1, $t5
    # Spilling t99 from $t9
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
    li $v0, 0
    lw   $fp, 412($sp)
    lw   $ra, 416($sp)
    li $v0, 10
    syscall
