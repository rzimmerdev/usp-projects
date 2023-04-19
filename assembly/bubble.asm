.data
	num: .word 7, 5, 2, 1, 1, 3, 4	
	str: .asciiz " "
	
.text
.globl main
main:
	la $s0, num
	li $s1, 7	# s1 =  MAX = 7 
	li $t0, 0	# t0 =    i = 0
loop:
	# Branch out of loop if i is bigger than max
	bge $t0, $s1, end_loop
	
	# Store into j the value of max
	move $t1, $s1
	
	# Store into s2 the value of i + 1
	add $s2, $t0, 1
second_loop:

	# Branch out of loop if j is smaller than 0
	ble $t1, 0, end_second_loop
	
	# Load into registers values from static memory
	mul $t2, $t1, 4
	add $t2, $t2, $s0
	lw $t3, -4($t2)
	lw $t4, 0($t2)
	
	# End Second Loop if value at num[i-1] <= num[i]
	ble $t3, $t4, skip_second_loop
	sw $t3, 0($t2)
	sw $t4, -4($t2)
	add $t1, $t1, -1
	j second_loop

skip_second_loop:
	add $t1, $t1, -1
	j second_loop

end_second_loop:
	add $t0, $t0, 1
	j loop

end_loop:
	la $t0, num
	move $t1, $s1
print:

    beqz $t1, end_print
    li $v0, 1
    lw $a0, 0($t0)
    syscall

    addi $t0, $t0, 4
    addi $t1, $t1, -1

    j print
	
end_print:
	li $v0, 10
	syscall
