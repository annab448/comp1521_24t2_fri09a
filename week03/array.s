N_SIZE=10
# $t0	i
# $t2	numbers[i]
	.text
main:

loop_init:
	li	$t0, 0		# i = 0
loop_cond:
	bge	$t0, N_SIZE, loop_end	# while (i < N_SIZE) {

loop_body:
	# get numbers[i]
	mul	$t1, $t0, 4	# $t1 = array offset
	lw	$t2, numbers($t1)	# $t2 = numbers[i]

	bge	$t2, 0, loop_step	# if (numbers[i] < 0) { 
	
	add	$t2, $t2, 42
	sw	$t2, numbers($t1)
	
loop_step:
	addi	$t0, $t0, 1	# i++
	b	loop_cond

loop_end:

	li	$v0, 0		# retun 0
	jr	$ra


	.data
numbers:
	.word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9	# int numbers[N_SIZE] = {0, 1, 2, -3, 4, -5, 6, -7, 8,     9};
