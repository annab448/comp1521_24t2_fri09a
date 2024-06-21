	.text

main:
	# Frame:    [...]
	# Uses:     [$a0, $a1, $v0]
	# Clobbers: [$a0, $a1, $v0]
	#
	#
	# Locals:
	#   - None
	#
	# Structure:
	#   main: 
	#   -> [prologue]
	#       -> body
	#   -> [epilogue]
main__prologue:
	begin
	push	$ra
main__body:
	la	$a0, numbers	# array = numbers
	li	$a1, 10		# length = 10
	jal	max		# $v0: max(array, 10)

	move	$a0, $v0	# printf("%d\n", max(array, 10));
	li	$v0, 1
	syscall

	li	$a0, '\n'
	li	$v0, 11
	syscall

main__epilogue:
	pop	$ra
	end

	jr	$ra

max:
	# Frame:    [$ra, $s0] 
	# Uses:     [$s0, $v0, $a0, $a1]
	# Clobbers: [$v0, $a0, $a1]
	#
	# Locals:
	#   - $s0: first_element
	#   - $v0: max_so_far
	#
	# Structure:
	#   max 
	#   -> [prologue]
	#       -> body
	#          -> max_recurse
	#   -> [epilogue]
	#
	# Arguments:
	# $a0: int array[]
	# $a1: int length
max__prologue:
	begin
	push	$ra
	push	$s0
max__body:
	lw	$s0, ($a0)	# int first_element = array[0];
#	move	$v0, $s0		# return 0
#	beq	$a1, 1, max_epilogue	# if (length == 1)

	bne	$a1, 1, max__recurse	# if (length == 1) {
	
	move	$v0, $s0		# return first_element;
	b	max__epilogue
max__recurse:				# else {
	
	add	$a0, $a0, 4		# $a0 = &array[1]
	sub	$a1, $a1, 1		# $a1 = length - 1
	jal max

	# max_so_far in $v0
	blt	$s0, $v0, max__epilogue	# if (first_element > max_so_far) {

	move	$v0, $s0		# max_so_far = first_element;
max__epilogue:
	pop	$s0
	pop	$ra
	end

	jr	$ra


	.data
numbers:
	.word	9, -4, 2, 5, 99, 42, 41, 433, 5, 0
