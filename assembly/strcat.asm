.data
	.align 0
	first: .space 20
	second: .space 20
	leitura_1: .asciiz "Insira a primeira string:\n"
	leitura_2: .asciiz "Insira a segunda string:\n"
	saida: .asciiz "Concatenado: "
.text
.globl main
main:	
	la $t0, leitura_1
	la $t1, leitura_2
	
	move $a0, $t0
	la $a1, first
	jal read_string
	
	move $a0, $t1
	la $a1, second
	jal read_string
	
	la $a0, first
	la $a1, second
	
	jal strcat
	
	la $a0, 'a'
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall
	
# strcat(dest[$a0]: address, source[$a1]) -> total_size[$v0]: int
#
# Concatenates source to destination, and returns final string size
strcat:
	move $t5, $ra
	
	# Saves into $t1 the first string
	# Saves into $t2 the size of the string
	move $t1, $a0
	jal get_size
	move $t2, $v0
	
	# Saves into $t3 the second string
	# Saves into $t4 the size of the string
	move $a0, $a1
	move $t3, $a1
	jal get_size
	move $t4, $v0
	
	add $v0, $t2, $t4
	
loop_copy_first:
	beqz $t2, loop_copy_second
	sb $t1, ($sp)
	subi $sp, $sp, 1
	subi $t2, $t2, 1
	j loop_copy_first
loop_copy_second:
	beqz $t4, end_copy
	sb $t3, ($sp)
	subi $sp, $sp, 1
	subi $t4, $t4, 1
	j loop_copy_second
end_copy:
	move $ra, $t5
	jr $ra

# get_size(str[$a0]: address) -> size[$v0]: int 
#
# Returns the strlen of str
get_size:
	li $v0, 0
	li $v1, -1
	li $t0, '\n'
get_size_loop:
	beqz $v1, end_get_size
	beq $v1, $t0, end_get_size
	lb $v1, ($a0)
	addi $v0, $v0, 1
	addi $a0, $a0, 1
	j get_size_loop
	
end_get_size:
	jr $ra
	

# read_string(request[$a0]: address, answer[$a1]: address)
# 
# Prints request and saves string answer to address
read_string:
	li $v0, 4
	syscall
	li $v0, 8
	move $a0, $a1
	li $a1, 20
	syscall
	jr $ra
