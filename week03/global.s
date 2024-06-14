	.text
main:
	lw	$t0, x
	lw	$t1, y
	lw	$t2, z

	# ans = ((x*x + y*y) - x*y) * z;
	mul	$t3, $t0, $t0	# x*x
	mul	$t4, $t1, $t1,	# y*y
	add	$t3, $t3, $t4	# x*x + y*y
	mul	$t4, $t0, $t1	# y*x
	sub	$t4, $t3, $t4
	mul	$t4, $t4, $t2

	sw	$t4, ans	# ans = 


	.data
x:	.word	8	# int x = 8;
y:	.word	7	# int y = 7
z:	.word	10	# z = 10
ans:	.space	4	# int ans
