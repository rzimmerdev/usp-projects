.data
	num: .word 7, 5, 2, 1, 1, 3, 4	
	str: .asciiz " "
	
.text
	la $s0, num
	li $s1, 6	# s1 =  MAX = 7 
	li $t0, 0	# t0 =    i = 0
loop:
	bge $t0, $s1, end_loop	# i >= max - 1 ?
	move $t1, $s1		# j = max - 1
	add $s2, $t0, 1		# s2 = i + 1
second_loop:
	ble $t1, 0, loop	# j <= i + 1 ?
	
	mul $t2, $t1, 4
	add $t2, $t2, $s0
	lw $t3, -4($t2)
	lw $t4, 0($t2)
	
	ble $t3, $t4, end_second_loop
	move $t5, $t4
	move $t4, $t3
	move $t3, $t5
	
	add $t0, $t0, 1
	j second_loop
	
end_second_loop:
	add $t1, $t1, -1
	j second_loop
	
end_loop:
	li $v0, 10
	syscall
