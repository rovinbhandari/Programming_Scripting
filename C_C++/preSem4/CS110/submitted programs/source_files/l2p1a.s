	.file	"l2p1a.c"
	.section	.rodata
	.align 4
.LC1:
	.string	"\n\n\tEnter the value of x in radians to calculate its sine : "
.LC2:
	.string	"%LG"
	.align 4
.LC3:
	.string	"\n\n\tThe value of sin(0.0) is : 0.0"
	.align 4
.LC4:
	.string	"\n\n\tEnter the value of the number of terms to compute\n\tin the expansinon of sin(x) : "
.LC5:
	.string	"%lu"
	.align 4
.LC6:
	.string	"\n\n\tPlease enter a natural number"
.LC8:
	.string	"\n%lu.\t%LG * %LG / %LG"
	.align 4
.LC9:
	.string	"\n\n\tsin(%LG) (computed till %lu terms) = %LG\n\n"
	.align 8
.LC7:
	.long	0
	.long	-1074790400
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	subl	$184, %esp
	movl	$1, -28(%ebp)
	movl	$0, %eax
	movl	$0, %edx
	movl	$0, %ecx
	movl	%eax, -56(%ebp)
	movl	%edx, -52(%ebp)
	movl	%ecx, -48(%ebp)
	movl	$.LC1, (%esp)
	call	printf
	leal	-72(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	scanf
	fldt	-72(%ebp)
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jp	.L14
	je	.L4
.L14:
	jmp	.L2
.L4:
	movl	$.LC3, (%esp)
	call	printf
	movl	$1, (%esp)
	call	exit
.L2:
	movl	$.LC4, (%esp)
	call	printf
	leal	-76(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC5, (%esp)
	call	scanf
	movl	-76(%ebp), %eax
	testl	%eax, %eax
	jne	.L7
	movl	$.LC6, (%esp)
	call	printf
	movl	$1, (%esp)
	call	exit
.L8:
	movl	$2, -32(%ebp)
	movl	$1, -36(%ebp)
	jmp	.L9
.L10:
	movl	-36(%ebp), %eax
	imull	-32(%ebp), %eax
	movl	%eax, -36(%ebp)
	addl	$1, -32(%ebp)
.L9:
	movl	-28(%ebp), %eax
	addl	%eax, %eax
	subl	$1, %eax
	cmpl	-32(%ebp), %eax
	jae	.L10
	movl	-36(%ebp), %eax
	movl	$0, %edx
	pushl	%edx
	pushl	%eax
	fildll	(%esp)
	leal	8(%esp), %esp
	fstpt	-152(%ebp)
	movl	-28(%ebp), %eax
	addl	%eax, %eax
	subl	$1, %eax
	movl	$0, %edx
	pushl	%edx
	pushl	%eax
	fildll	(%esp)
	leal	8(%esp), %esp
	fldt	-72(%ebp)
	fstpl	-96(%ebp)
	fldl	-96(%ebp)
	fxch	%st(1)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fstpt	-136(%ebp)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	$0, %edx
	pushl	%edx
	pushl	%eax
	fildll	(%esp)
	leal	8(%esp), %esp
	fstpl	8(%esp)
	fldl	.LC7
	fstpl	(%esp)
	call	pow
	fldt	-152(%ebp)
	fstpt	32(%esp)
	fldt	-136(%ebp)
	fstpt	20(%esp)
	fstpt	8(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC8, (%esp)
	call	printf
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	$0, %edx
	pushl	%edx
	pushl	%eax
	fildll	(%esp)
	leal	8(%esp), %esp
	fstpl	8(%esp)
	fldl	.LC7
	fstpl	(%esp)
	call	pow
	fstpt	-120(%ebp)
	movl	-28(%ebp), %eax
	addl	%eax, %eax
	subl	$1, %eax
	movl	$0, %edx
	pushl	%edx
	pushl	%eax
	fildll	(%esp)
	leal	8(%esp), %esp
	fldt	-72(%ebp)
	fstpl	-96(%ebp)
	fldl	-96(%ebp)
	fxch	%st(1)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fldt	-120(%ebp)
	fmulp	%st, %st(1)
	movl	-36(%ebp), %eax
	movl	$0, %edx
	pushl	%edx
	pushl	%eax
	fildll	(%esp)
	leal	8(%esp), %esp
	fdivrp	%st, %st(1)
	fldt	-56(%ebp)
	faddp	%st, %st(1)
	fstpt	-56(%ebp)
	addl	$1, -28(%ebp)
.L7:
	movl	-76(%ebp), %eax
	cmpl	%eax, -28(%ebp)
	jbe	.L8
	movl	-76(%ebp), %eax
	movl	%eax, -100(%ebp)
	movl	-72(%ebp), %ebx
	movl	-68(%ebp), %esi
	movl	-64(%ebp), %edi
	movl	-56(%ebp), %eax
	movl	-52(%ebp), %edx
	movl	-48(%ebp), %ecx
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	movl	%ecx, 28(%esp)
	movl	-100(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	%ebx, 4(%esp)
	movl	%esi, 8(%esp)
	movl	%edi, 12(%esp)
	movl	$.LC9, (%esp)
	call	printf
	addl	$184, %esp
	popl	%ecx
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.1 20061011 (Red Hat 4.1.1-30)"
	.section	.note.GNU-stack,"",@progbits
