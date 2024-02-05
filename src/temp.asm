.data
    divider: .float 2.5

.text
    addi r1, r0, 10
    addi r2, r0, 7
    mul r3, r1, r2

    jie r2, r3, Execute
    // Not Equal Case
    div r3, divider
    sb r3, 0(r10)
    syscall

Execute:
    // Equal Case
    lui r4, 540000
    add r3, r3, r4
    syscall