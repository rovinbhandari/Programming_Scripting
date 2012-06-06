	.file	"l2p1b.c"
	.section	.rodata
	.align 4
.LC1:
	.string	"\n\n\tEnter the value of x in radians to calculate its sine : "
.LC2:
	.string	"%LG"
	.align 4
.LC3:
	.string	"\n\n\tThe value of sin(0.0) is : 0.0"
.LC5:
	.string	"\n%lu.\t%LG * %LG / %LG"
	.align 4
.LC10:
	.string	"\n\n\tsin(%LG) (computed upto 10^-5) = %LG\n\n"
	.align 8
.LC4:
	.long	0
	.long	-1074790400
	.align 8
.LC6:
	.long	-1598689907
	.long	1051772663
	.align 16
.LC7:
	.long	0
	.long	-198967296
	.long	16402
	.align 16
.LC8:
	.long	0
	.long	-1018167296
	.long	16399
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
	subl	$216, %esp
	movl	$0, %eax
	movl	$0, %edx
	movl	$0, %ecx
	movl	%eax, -56(%ebp)
	movl	%edx, -52(%ebp)
	movl	%ecx, -48(%ebp)
	movl	$0, %eax
	movl	$0, %edx
	movl	$0, %ecx
	movl	%eax, -72(%ebp)
	movl	%edx, -68(%ebp)
	movl	%ecx, -64(%ebp)
	movl	$1, -28(%ebp)
	movl	$.LC1, (%esp)
	call	printf
	leal	-88(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	scanf
	fldt	-88(%ebp)
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jp	.L13
	je	.L4
.L13:
	jmp	.L2
.L4:
	movl	$.LC3, (%esp)
	call	printf
	movl	$1, (%esp)
	call	exit
.L2:
	fldt	-72(%ebp)
	fldt	-56(%ebp)
	faddp	%st, %st(1)
	fstpt	-72(%ebp)
	movl	$2, -32(%ebp)
	movl	$1, -36(%ebp)
	jmp	.L5
.L6:
	movl	-36(%ebp), %eax
	imull	-32(%ebp), %eax
	movl	%eax, -36(%ebp)
	addl	$1, -32(%ebp)
.L5:
	movl	-28(%ebp), %eax
	addl	%eax, %eax
	subl	$1, %eax
	cmpl	-32(%ebp), %eax
	jae	.L6
	movl	-36(%ebp), %eax
	movl	$0, %edx
	pushl	%edx
	pushl	%eax
	fildll	(%esp)
	leal	8(%esp), %esp
	fstpt	-168(%ebp)
	movl	-28(%ebp), %eax
	addl	%eax, %eax
	subl	$1, %eax
	movl	$0, %edx
	pushl	%edx
	pushl	%eax
	fildll	(%esp)
	leal	8(%esp), %esp
	fldt	-88(%ebp)
	fstpl	-96(%ebp)
	fldl	-96(%ebp)
	fxch	%st(1)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fstpt	-152(%ebp)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	$0, %edx
	pushl	%edx
	pushl	%eax
	fildll	(%esp)
	leal	8(%esp), %esp
	fstpl	8(%esp)
	fldl	.LC4
	fstpl	(%esp)
	call	pow
	fldt	-168(%ebp)
	fstpt	32(%esp)
	fldt	-152(%ebp)
	fstpt	20(%esp)
	fstpt	8(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC5, (%esp)
	call	printf
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	$0, %edx
	pushl	%edx
	pushl	%eax
	fildll	(%esp)
	leal	8(%esp), %esp
	fstpl	8(%esp)
	fldl	.LC4
	fstpl	(%esp)
	call	pow
	fstpt	-136(%ebp)
	movl	-28(%ebp), %eax
	addl	%eax, %eax
	subl	$1, %eax
	movl	$0, %edx
	pushl	%edx
	pushl	%eax
	fildll	(%esp)
	leal	8(%esp), %esp
	fldt	-88(%ebp)
	fstpl	-96(%ebp)
	fldl	-96(%ebp)
	fxch	%st(1)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fldt	-136(%ebp)
	fmulp	%st, %st(1)
	movl	-36(%ebp), %eax
	movl	$0, %edx
	pushl	%edx
	pushl	%eax
	fildll	(%esp)
	leal	8(%esp), %esp
	fdivrp	%st, %st(1)
	fstpt	-56(%ebp)
	addl	$1, -28(%ebp)
	fldt	-56(%ebp)
	fstpl	-96(%ebp)
	fldl	-96(%ebp)
	fabs
	fldl	.LC6
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jae	.L2
	fldt	-72(%ebp)
	fldt	.LC7
	fmulp	%st, %st(1)
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -100(%ebp)
	fldcw	-100(%ebp)
	fistpll	-112(%ebp)
	fldcw	-98(%ebp)
	movl	-112(%ebp), %eax
	movl	-108(%ebp), %edx
	movl	%eax, %ecx
	movl	$-858993459, -172(%ebp)
	movl	-172(%ebp), %eax
	mull	%ecx
	movl	%edx, %eax
	shrl	$3, %eax
	movl	%eax, -116(%ebp)
	movl	-116(%ebp), %eax
	sall	$2, %eax
	addl	-116(%ebp), %eax
	addl	%eax, %eax
	movl	%ecx, %edx
	subl	%eax, %edx
	movl	%edx, -116(%ebp)
	cmpl	$4, -116(%ebp)
	jbe	.L9
	fldt	-72(%ebp)
	fldt	.LC8
	fmulp	%st, %st(1)
	fldcw	-100(%ebp)
	fistpll	-112(%ebp)
	fldcw	-98(%ebp)
	movl	-112(%ebp), %eax
	movl	-108(%ebp), %edx
	movl	$0, %edx
	pushl	%edx
	pushl	%eax
	fildll	(%esp)
	leal	8(%esp), %esp
	fld1
	faddp	%st, %st(1)
	fldt	.LC8
	fdivrp	%st, %st(1)
	fstpt	-72(%ebp)
	jmp	.L11
.L9:
	fldt	-72(%ebp)
	fldt	.LC8
	fmulp	%st, %st(1)
	fldcw	-100(%ebp)
	fistpll	-112(%ebp)
	fldcw	-98(%ebp)
	movl	-112(%ebp), %eax
	movl	-108(%ebp), %edx
	movl	$0, %edx
	pushl	%edx
	pushl	%eax
	fildll	(%esp)
	leal	8(%esp), %esp
	fldt	.LC8
	fdivrp	%st, %st(1)
	fstpt	-72(%ebp)
.L11:
	movl	-88(%ebp), %ebx
	movl	-84(%ebp), %esi
	movl	-80(%ebp), %edi
	movl	-72(%ebp), %eax
	movl	-68(%ebp), %edx
	movl	-64(%ebp), %ecx
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	movl	%ecx, 24(%esp)
	movl	%ebx, 4(%esp)
	movl	%esi, 8(%esp)
	movl	%edi, 12(%esp)
	movl	$.LC10, (%esp)
	call	printf
	addl	$216, %esp
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
