	.text
FLAG_ROWS = 6
FLAG_COLS = 12

main:
	# row $t0
	# col $t1
main__prologue:
main__body:
	
	li	$t0, 0
main__row_loop_cond:
	bge	$t0, FLAG_ROWS, main__row_loop_end

	li	$t1, 0
main__col_loop_cond:
	bge	$t1, FLAG_COLS, main__col_loop_end
	# get &flag[row][col]
	mul	$t2, $t0, FLAG_COLS		# row * sizeof(row)
	add	$t2, $t2, $t1			# + col
	lb	$a0, flag($t2)			# $a0 = flag[row][col]

	li	$v0, 11				#  printf("%c", flag[row][col]);
	syscall

	add	$t1, $t1, 1
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
flag:
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
