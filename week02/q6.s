# x	$t0

main:
	
	li	$v0, 4		# printf("Enter a number: ");
	la	$a0, prompt
	syscall

	li	$v0, 5
	syscall
	move	$t0, $v0

	ble	$t0, 100, print_small_big	# if (x <= 100) goto print_small_big;
	bge	$t0, 1000, print_small_big	# if (x >= 1000) goto print_small_big;

print_medium:
	li	$v0, 4		# printf("medium\n");
	la	$a0, med_msg
	syscall
	
	b	epilogue	#  goto epilogue;

print_small_big:
	li	$v0, 4		#  printf("small/big\n");
	la	$a0, small_big_msg
	syscall

epilogue:
	
	li	$v0, 0		# return 0;
	jr	$ra
	
	.data
prompt:
	.asciiz	"Enter a number: "
med_msg:
	.asciiz "medium\n"
small_big_msg:
	.asciiz "small/big\n"
