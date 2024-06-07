# i	$t0
# j	$t1

main:

line_loop_init:
	li	$t0, 1		# i = 1
line_loop_cond:
	bgt	$t0, 10, line_loop_end # if (i > 10) goto end;

line_loop_body:

star_loop_init:
	li	$t1, 0		# j = 0

star_loop_cond:
	bge	$t1, $t0, star_loop_end	# if (j >= i) goto end
	
star_loop_body:
	li	$v0, 11		# printf("*");
	li	$a0, '*'
	syscall

star_loop_step:
	addi	$t1, $t1, 1	# j++
	b	star_loop_cond
star_loop_end:

	li	$v0, 11 		# printf("\n");
	li	$a0, '\n'
	syscall

line_loop_step:
	addi	$t0, $t0, 1	# i++;
	b	line_loop_cond

line_loop_end:
	li	$v0, 0		# return 0;
	jr	$ra
	
