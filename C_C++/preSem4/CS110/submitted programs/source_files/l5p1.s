	.file	"l5p1.c"
	.section	.rodata
.LC0:
	.string	"\nEnter the amount of currency"
.LC1:
	.string	"%d"
	.align 4
.LC2:
	.string	"\nThe number of different notes to be given for an amount of %d are : \n"
.LC3:
	.string	"%d\tX\t%d\n"
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	subl	$112, %esp
	movl	$0, -12(%ebp)
	movl	$100, -48(%ebp)
	movl	$50, -44(%ebp)
	movl	$25, -40(%ebp)
	movl	$20, -36(%ebp)
	movl	$10, -32(%ebp)
	movl	$5, -28(%ebp)
	movl	$1, -24(%ebp)
	movl	$.LC0, (%esp)
	call	puts
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	movl	-20(%ebp), %eax
	movl	%eax, -16(%ebp)
	jmp	.L2
.L3:
	cmpl	$2, -12(%ebp)
	jne	.L4
	addl	$1, -12(%ebp)
.L4:
	movl	-12(%ebp), %ecx
	movl	-12(%ebp), %eax
	movl	-48(%ebp,%eax,4), %eax
	movl	-16(%ebp), %edx
	movl	%eax, %ebx
	movl	%edx, %eax
	sarl	$31, %edx
	idivl	%ebx
	movl	%eax, -76(%ebp,%ecx,4)
	movl	-12(%ebp), %eax
	movl	-48(%ebp,%eax,4), %eax
	movl	-16(%ebp), %edx
	movl	%eax, %ecx
	movl	%edx, %eax
	sarl	$31, %edx
	idivl	%ecx
	movl	%edx, -16(%ebp)
	addl	$1, -12(%ebp)
.L2:
	cmpl	$0, -16(%ebp)
	jne	.L3
	jmp	.L7
.L8:
	movl	-68(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -68(%ebp)
	movl	-64(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -64(%ebp)
	movl	-56(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -56(%ebp)
.L7:
	movl	-64(%ebp), %eax
	movl	-56(%ebp), %ebx
	movl	%ebx, -96(%ebp)
	movl	%eax, -92(%ebp)
	movl	-96(%ebp), %eax
	cmpl	%eax, -92(%ebp)
	jle	.L9
	movl	-96(%ebp), %edx
	movl	%edx, -92(%ebp)
.L9:
	cmpl	$0, -92(%ebp)
	jne	.L8
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	$0, -12(%ebp)
	jmp	.L11
.L12:
	movl	-12(%ebp), %eax
	movl	-76(%ebp,%eax,4), %edx
	movl	-12(%ebp), %eax
	movl	-48(%ebp,%eax,4), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	addl	$1, -12(%ebp)
.L11:
	cmpl	$6, -12(%ebp)
	jle	.L12
	movl	$0, %eax
	addl	$112, %esp
	popl	%ecx
	popl	%ebx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.1 20061011 (Red Hat 4.1.1-30)"
	.section	.note.GNU-stack,"",@progbits
