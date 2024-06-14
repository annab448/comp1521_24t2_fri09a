PIC_HEIGHT=4
PIC_WIDTH=3
	.text
main:
# header comment
# Registers
# Frame: N/A
# Uses:
# Clobbers:

# Locals
# row	$t0
# col	$t1

# Structure

main__prologue:

	li	$t0, 0		# row = 0
main__row_loop_cond:
	bge	$t0, PIC_HEIGHT, main__row_loop_end	# while (row < PIC_HEIGHT)

	# column loop
	li	$t1, 0
main__col_loop_cond:
	bge	$t1, PIC_WIDTH, main__col_loop_end

	# get picture[row][col]
	mul	$t2, $t0, PIC_WIDTH	# $t2 = row * sizeof(row)
	add	$t2, $t2, $t1		# + col
	lb	$t3, picture($t2)	# $t3 = picture[row][col]

	li	$v0, 11
	move	$a0, $t3
	syscall


	addi	$t1, $t1, 1
	b main__col_loop_cond
main__col_loop_end:
	
	li	$v0, 11	
	li	$a0, '\n'
	syscall

	addi	$t0, $t0, 1
	b	main__row_loop_cond

main__row_loop_end:

main__epilogue:

	jr	$ra



	.data
picture:
	.byte	'*', ' ', '*'
	.byte	' ', '*', ' '
	.byte	' ', '*', '*'
	.byte	'*', '*', '*'
