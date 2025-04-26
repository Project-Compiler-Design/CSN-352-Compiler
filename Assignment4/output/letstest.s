        .text
        .globl func
        .globl main

# -------------------------
# func(a,b,c,d,e,f):
#   sum = d + e
#   return sum
# -------------------------
func:
        addi    $sp, $sp, -40       # 40 bytes frame
        sw      $ra, 36($sp)        # save return addr
        sw      $fp, 32($sp)        # save old frame ptr
        move    $fp, $sp            # new frame ptr

        lw      $t0, 40($fp)        # load e
        addu    $v0, $a3, $t0       # sum = d + e

        move    $sp, $fp            # restore SP
        lw      $fp, 32($sp)        # restore FP
        lw      $ra, 36($sp)        # restore RA
        addi    $sp, $sp, 40        # pop frame
        jr      $ra                 # return

# -------------------------
# main():
#   x=10,y=20,z=30,p=40,q=50,r=60
#   result=func(x,y,z,p,q,r)
#   return 0
# -------------------------
main:
        addi    $sp, $sp, -32       # make room for 6 locals (if you want) + saved regs
        sw      $ra, 28($sp)
        sw      $fp, 24($sp)
        move    $fp, $sp

        # first four args
        li      $a0, 10
        li      $a1, 20
        li      $a2, 30
        li      $a3, 40

        # push 5th and 6th arguments
        li      $t0, 50
        li      $t1, 60
        sw      $t0, 4($sp)         # q at 4($sp)
        sw      $t1, 0($sp)         # r at 0($sp)

        jal     func                # call
        addi    $sp, $sp, 8         # pop q,r

        # ($v0 holds the return)

        #li      $v0, 0              # return 0
        move    $sp, $fp
        lw      $fp, 24($sp)
        lw      $ra, 28($sp)
        addi    $sp, $sp, 32
        jr      $ra
