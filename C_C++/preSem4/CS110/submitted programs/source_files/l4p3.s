	.file	"l4p3.c"
	.data
	.align 4
	.type	d.1782, @object
	.size	d.1782, 4
d.1782:
	.long	-1
	.text
.globl search
	.type	search, @function
search:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$32, %esp
	movl	16(%ebp), %eax
	movl	12(%ebp), %edx
	addl	%eax, %edx
	movl	%edx, %eax
	shrl	$31, %eax
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jge	.L2
	movl	-4(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	20(%ebp), %eax
	jne	.L4
	movl	-4(%ebp), %eax
	movl	%eax, d.1782
	jmp	.L2
.L4:
	movl	12(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	20(%ebp), %eax
	jne	.L6
	movl	12(%ebp), %eax
	movl	%eax, d.1782
	jmp	.L2
.L6:
	movl	16(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	20(%ebp), %eax
	jne	.L8
	movl	16(%ebp), %eax
	movl	%eax, d.1782
	jmp	.L2
.L8:
	movl	-4(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	20(%ebp), %eax
	jge	.L10
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, 12(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	search
	jmp	.L2
.L10:
	movl	-4(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	20(%ebp), %eax
	jle	.L2
	movl	-4(%ebp), %eax
	subl	$1, %eax
	movl	%eax, 16(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	search
.L2:
	movl	d.1782, %eax
	leave
	ret
	.size	search, .-search
	.section	.rodata
.LC0:
	.string	"\nEnter size of array"
.LC1:
	.string	"%d"
.LC2:
	.string	"\nEnter the data"
.LC3:
	.string	"\nAfter sorting, array is :"
.LC4:
	.string	"%d "
.LC5:
	.string	"\nEnter the element to search"
.LC6:
	.string	"\nElement not found"
	.align 4
.LC7:
	.string	"\nElement #%d# found at position : %d\n"
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
	subl	$452, %esp
	movl	$-1, -20(%ebp)
	movl	$.LC0, (%esp)
	call	puts
	leal	-436(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	movl	$.LC2, (%esp)
	call	puts
	movl	$0, -16(%ebp)
	jmp	.L15
.L16:
	movl	-16(%ebp), %eax
	sall	$2, %eax
	movl	%eax, %edx
	leal	-428(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	addl	$1, -16(%ebp)
.L15:
	movl	-436(%ebp), %eax
	cmpl	%eax, -16(%ebp)
	jl	.L16
	movl	$0, -16(%ebp)
	jmp	.L18
.L19:
	movl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	jmp	.L20
.L21:
	movl	-16(%ebp), %eax
	movl	-428(%ebp,%eax,4), %edx
	movl	-12(%ebp), %eax
	movl	-428(%ebp,%eax,4), %eax
	cmpl	%eax, %edx
	jle	.L22
	movl	-16(%ebp), %eax
	movl	-428(%ebp,%eax,4), %eax
	movl	%eax, -8(%ebp)
	movl	-16(%ebp), %edx
	movl	-12(%ebp), %eax
	movl	-428(%ebp,%eax,4), %eax
	movl	%eax, -428(%ebp,%edx,4)
	movl	-12(%ebp), %edx
	movl	-8(%ebp), %eax
	movl	%eax, -428(%ebp,%edx,4)
.L22:
	addl	$1, -12(%ebp)
.L20:
	movl	-436(%ebp), %eax
	cmpl	%eax, -12(%ebp)
	jl	.L21
	addl	$1, -16(%ebp)
.L18:
	movl	-436(%ebp), %eax
	cmpl	%eax, -16(%ebp)
	jl	.L19
	movl	$.LC3, (%esp)
	call	puts
	movl	$0, -16(%ebp)
	jmp	.L26
.L27:
	movl	-16(%ebp), %eax
	movl	-428(%ebp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	addl	$1, -16(%ebp)
.L26:
	movl	-436(%ebp), %eax
	cmpl	%eax, -16(%ebp)
	jl	.L27
	movl	-428(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	-436(%ebp), %eax
	subl	$1, %eax
	movl	-428(%ebp,%eax,4), %eax
	movl	%eax, -24(%ebp)
	movl	$.LC5, (%esp)
	call	puts
	leal	-432(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	movl	-432(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-428(%ebp), %eax
	movl	%eax, (%esp)
	call	search
	movl	%eax, -20(%ebp)
	cmpl	$-1, -20(%ebp)
	jne	.L29
	movl	$.LC6, (%esp)
	call	puts
	jmp	.L31
.L29:
	movl	-20(%ebp), %eax
	addl	$1, %eax
	movl	-432(%ebp), %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$.LC7, (%esp)
	call	printf
.L31:
	movl	$0, %eax
	addl	$452, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.1 20061011 (Red Hat 4.1.1-30)"
	.section	.note.GNU-stack,"",@progbits
