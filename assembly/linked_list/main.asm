.data
	insert_total_nodes: .asciiz "Quantos elementos deseja inserir na lista?\n"
	insert_value: .asciiz "Que frase que frase deseja inserir na lista?\n"
	confirm_insertion: .asciiz "Frase inserida com sucesso.\n"
	node_label: .asciiz "Id:"
	value_label: .asciiz " Valor: "
.text
.globl main


main:	
	li $v0, 4
	la $a0, insert_total_nodes
	syscall
	
	# i ($t0) = 0; scanf("%d", total_nodes) ($t1)
	# Read total elements in list, as well as instantiate indexation variable i
	li $v0, 5
	syscall
	move $t0, $zero
	move $t1, $v0
	
	# linked_list ($s0) = create_linked_list()
	# Create linked list and save pointer to $s0
	jal create_linked_list
	move $s0, $v0

# while i < total_nodes
main_loop:
	bge $t0, $t1, end_main

	# i++ ($t0)
	addi, $t0, $t0, 1

	# create_node(linked_list, i)
	# Creates a new node inside the given linked list, with pointer stored in the $s0 register.
	# Also instantiates the node id using the index variable i, stored in the $t0 register.
	move $a0, $s0
	move $a1, $t0
	jal create_node
	
	j main_loop

end_main:
	move $a0, $s0
	jal print_linked_list

	li $v0, 10
	syscall


# Node struct:
# struct Node_t {
# 	Node_t next_node;
#	int id;
#	char value[30];
# }
# void *create_linked_list() -> $v0 = linked list head
create_linked_list:
	# Allocate memory for temporary $t0 saved value, as well as 8 bytes for stack header values
	subi $sp, $sp, 12
	# Temporarily saves the value of $t0 into the stack memory, as to use the register for internal operations.
	sw $t0, ($sp) 
	
	# Starts list header with id = 0
	li $t0, 0
	sw $t0, 4($sp)
	# And instantiates next node address as -1, as there isn't any new node initially.
	li $t0, -1
	sw $t0, 8($sp)
	
	# Operations to prepare for function return, such as reloading the overwriten $t0 value, as well
	# as updating stack pointer to new position after linked list creation (linked list header has size of 8 bytes, or 2 integers).
	lw $t0, ($sp)
	addi $sp, $sp, 4
	
	# Loads into $v0 the stack pointer address, as to return its address
	la $v0, ($sp)
	jr $ra


# void create_node(void *$a0: Pointer to linked list head, int $a1: New node id)
create_node:
	# Allocate 40 bytes for node, 8 for id and next_node fields, and 32 for next multiple of 4 that can contain 31 characters.
	# Also allocate +12 bytes to keep track of the three registers overwritten during functino execution.
	subi $sp, $sp, 52

	# Temporarily saves the values of $t0, $t1, and $t2 into the end of the new node, as to allow them to be used for other purposes.
	sw $t0, 8($sp)
	sw $t1, 4($sp)
	sw $t2, ($sp)
	
	# t2 = -1
	# Loads into the $t2 register the next node address pointer, which is always -1 whenever a new node is created.
	li $t2, -1

	# t0 = current_node
	# Current node is initally set to the linked list header, as to allow traversal of list.
	move $t0, $a0

	# while current_node next_node field is not -1, keep traversing linked list.

find_last:
	# t1 = $t0.next_address
	# Saves into $t1 the value read at the next_node position inside current header ($t0)
	lw $t1, 4($t0)
	# $t1 (next_address) == -1 => goto write_after
	beq $t2, $t1, write_after
	
	# current_node = next_address
	move $t0, $t1
	j find_last

write_after:
	# Loads into current_node,next_node the current stack pointer position, onto which will be written the new node values.
	la $t1, 12($sp)
	sw $t1, 4($t0)

	# Writes to new node id field the given id (from function parameter $a1).
	# Also writes into next_id field the value -1.
	sw $a1, 12($sp)
	sw $t2, 16($sp)
	
	# Reads user input (31 bytes corresponding to 30 character string) from console and writes to value field (byte position = 8 after node start).
	# or 20 bytes on top of stack pointer, considering 8 bytes for id + next_node and the three externally used registers to keep track of, each with size of 4 bytes.
	li $v0, 4
	la $a0, insert_value
	syscall
	
	li $v0, 8
	addi $a0, $sp, 20
	addi $a1, $zero, 31
	syscall
	
	li $v0, 4
	la $a0, confirm_insertion
	syscall

end_write:
	# Reloads overwritten values back into corresponding registers, as well as updating stack pointer to next valid word position.
	lw $t0, 8($sp)
	lw $t1, 4($sp)
	lw $t2, ($sp)
	
	addi $sp, $sp, 12

	jr $ra


# void print_linked_list(void *$a0: Pointer to linked list head)
print_linked_list:
	# Saving to stack pointer values to be used internally, as to avoide them being overwritten.
	subi $sp, $sp, 16
	sw $t0, 12($sp)
	sw $t1, 8($sp)
	sw $t2, 4($sp)
	sw $ra, ($sp)
	
	# $t0 = current_node
	lw $t0, 4($a0)
	li $t1, -1

traverse_list:
	# Verify if current node is not empty,
	# print node otherwise and continue looping.
	beq $t1, $t0, end_print
	
	jal print_node
	
	lw $t0, 4($t0)
	j traverse_list

end_print:
	# Reload variables into original registers after function call
	lw $t0, 12($sp)
	lw $t1, 8($sp)
	lw $t2, 4($sp)
	lw $ra, ($sp)
	addi $sp, $sp, 12
	jr $ra


#void print_node(void *$a0: node pointer)
print_node:
	# Prints node id
	li $v0, 4
	la $a0, node_label
	syscall
	# Node id is stored in the first 4 bytes inside the node.
	li $v0, 1
	lw $a0, ($t0)
	syscall
	
	# Prints node value
	li $v0, 4
	la $a0, value_label
	syscall
	# Node value is stored in the 32 bytes after the 8 first bytes inside the node.
	li $v0, 4
	la $a0, 8($t0)
	syscall
	
	jr $ra
