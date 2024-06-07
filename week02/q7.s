# x	$t0
main:

count3_loop_init:
	li	$t0, 24		# x = 24

count3_loop_cond:
	bge	$t0, 42, count3_loop_end # if (x >= 42) goto end
count3_loop_body:
	li	$v0, 1
	move	$a0, $t0
	syscall

count3_loop_step:
	addi	$t0, $t0, 3
	b	count3_loop_cond

count3_loop_end:
