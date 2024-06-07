# Prints the square of a number
# x	$t0
# y	$t1
	.text
main:
	li	$v0, 4		# printf("Enter a number: ");
	la	$a0, prompt
	syscall

	li	$v0, 5		# scanf("%d", &x);
	syscall
	move	$t0, $v0

	mul	$t1, $t0, $t0	# y = x * x;

	li	$v0, 1		# printf("%d\n", y);
	move	$a0, $t1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

	li	$v0, 0
	jr	$ra		# return 0;

	.data
prompt:
	.asciiz	"Enter a number: "
