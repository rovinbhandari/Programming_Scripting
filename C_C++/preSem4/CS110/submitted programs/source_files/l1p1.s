	.file	"l1p1.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"\n\tEnter the value(floating point) of temperature in Fahrenheit scale : "
.LC1:
	.string	"%lf"
	.align 4
.LC4:
	.string	"\n\tValue of temperature in Celcius scale is : %lf degrees\n\n"
	.align 8
.LC2:
	.long	0
	.long	1077936128
	.align 8
.LC3:
	.long	1908874354
	.long	1071761180
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$36, %esp
	movl	$.LC0, (%esp)
	call	printf
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	fldl	-24(%ebp)
	fldl	.LC2
	fsubrp	%st, %st(1)
	fldl	.LC3
	fmulp	%st, %st(1)
	fstpl	-16(%ebp)
	fldl	-16(%ebp)
	fstpl	4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	addl	$36, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.1 20061011 (Red Hat 4.1.1-30)"
	.section	.note.GNU-stack,"",@progbits
