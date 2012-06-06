	.file	"l4p2.c"
	.section	.rodata
.LC0:
	.string	"\nEnter size of square matrix"
.LC1:
	.string	"%d"
	.align 4
.LC2:
	.string	"\nEnter the elements of the matrix"
.LC3:
	.string	"\nROW %d\n\t"
.LC4:
	.string	"\n\t"
.LC5:
	.string	"\nThe matrix A is : "
.LC6:
	.string	"%d "
.LC7:
	.string	"\nTranspose of A is : "
.LC8:
	.string	"\n\nA*A^T ="
.LC9:
	.string	"\n\tThus A is NOT ORTHOGONAL\n"
.LC10:
	.string	"\n\tThus A is ORTHOGONAL\n"
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
	subl	$80040, %esp
	movl	$.LC0, (%esp)
	call	puts
	leal	-80032(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	movl	$.LC2, (%esp)
	call	puts
	movl	$0, -24(%ebp)
	jmp	.L2
.L3:
	movl	-24(%ebp), %eax
	addl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	movl	$0, -20(%ebp)
	jmp	.L4
.L5:
	leal	-40028(%ebp), %ecx
	movl	-24(%ebp), %eax
	imull	$100, %eax, %edx
	movl	-20(%ebp), %eax
	leal	(%edx,%eax), %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	movl	$.LC4, (%esp)
	call	printf
	addl	$1, -20(%ebp)
.L4:
	movl	-80032(%ebp), %eax
	cmpl	%eax, -20(%ebp)
	jl	.L5
	addl	$1, -24(%ebp)
.L2:
	movl	-80032(%ebp), %eax
	cmpl	%eax, -24(%ebp)
	jl	.L3
	movl	$.LC5, (%esp)
	call	puts
	movl	$0, -24(%ebp)
	jmp	.L8
.L9:
	movl	$0, -20(%ebp)
	jmp	.L10
.L11:
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	imull	$100, %eax, %eax
	addl	%edx, %eax
	movl	-40028(%ebp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$.LC6, (%esp)
	call	printf
	addl	$1, -20(%ebp)
.L10:
	movl	-80032(%ebp), %eax
	cmpl	%eax, -20(%ebp)
	jl	.L11
	movl	$10, (%esp)
	call	putchar
	addl	$1, -24(%ebp)
.L8:
	movl	-80032(%ebp), %eax
	cmpl	%eax, -24(%ebp)
	jl	.L9
	movl	$.LC7, (%esp)
	call	puts
	movl	$0, -24(%ebp)
	jmp	.L14
.L15:
	movl	$0, -20(%ebp)
	jmp	.L16
.L17:
	movl	-20(%ebp), %eax
	movl	-24(%ebp), %edx
	imull	$100, %eax, %eax
	addl	%edx, %eax
	movl	-40028(%ebp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$.LC6, (%esp)
	call	printf
	addl	$1, -20(%ebp)
.L16:
	movl	-80032(%ebp), %eax
	cmpl	%eax, -20(%ebp)
	jl	.L17
	movl	$10, (%esp)
	call	putchar
	addl	$1, -24(%ebp)
.L14:
	movl	-80032(%ebp), %eax
	cmpl	%eax, -24(%ebp)
	jl	.L15
	movl	$0, -24(%ebp)
	jmp	.L20
.L21:
	movl	$0, -28(%ebp)
	jmp	.L22
.L23:
	movl	-24(%ebp), %eax
	movl	-28(%ebp), %edx
	imull	$100, %eax, %eax
	addl	%edx, %eax
	movl	$0, -80028(%ebp,%eax,4)
	movl	$0, -20(%ebp)
	jmp	.L24
.L25:
	movl	-24(%ebp), %ebx
	movl	-28(%ebp), %esi
	movl	-24(%ebp), %eax
	movl	-28(%ebp), %edx
	imull	$100, %eax, %eax
	addl	%edx, %eax
	movl	-80028(%ebp,%eax,4), %edi
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	imull	$100, %eax, %eax
	addl	%edx, %eax
	movl	-40028(%ebp,%eax,4), %ecx
	movl	-20(%ebp), %eax
	movl	-28(%ebp), %edx
	imull	$100, %eax, %eax
	addl	%edx, %eax
	movl	-40028(%ebp,%eax,4), %eax
	imull	%ecx, %eax
	leal	(%edi,%eax), %edx
	imull	$100, %ebx, %eax
	addl	%esi, %eax
	movl	%edx, -80028(%ebp,%eax,4)
	addl	$1, -20(%ebp)
.L24:
	movl	-80032(%ebp), %eax
	cmpl	%eax, -20(%ebp)
	jl	.L25
	addl	$1, -28(%ebp)
.L22:
	movl	-80032(%ebp), %eax
	cmpl	%eax, -28(%ebp)
	jl	.L23
	addl	$1, -24(%ebp)
.L20:
	movl	-80032(%ebp), %eax
	cmpl	%eax, -24(%ebp)
	jl	.L21
	movl	$.LC8, (%esp)
	call	puts
	movl	$0, -24(%ebp)
	jmp	.L29
.L30:
	movl	$0, -20(%ebp)
	jmp	.L31
.L32:
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	imull	$100, %eax, %eax
	addl	%edx, %eax
	movl	-80028(%ebp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$.LC6, (%esp)
	call	printf
	addl	$1, -20(%ebp)
.L31:
	movl	-80032(%ebp), %eax
	cmpl	%eax, -20(%ebp)
	jl	.L32
	movl	$10, (%esp)
	call	putchar
	addl	$1, -24(%ebp)
.L29:
	movl	-80032(%ebp), %eax
	cmpl	%eax, -24(%ebp)
	jl	.L30
	movl	$0, -24(%ebp)
	jmp	.L35
.L36:
	movl	$0, -20(%ebp)
	jmp	.L37
.L38:
	movl	-24(%ebp), %eax
	cmpl	-20(%ebp), %eax
	jne	.L39
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	imull	$100, %eax, %eax
	addl	%edx, %eax
	movl	-40028(%ebp,%eax,4), %eax
	cmpl	$1, %eax
	jne	.L41
.L39:
	movl	-24(%ebp), %eax
	cmpl	-20(%ebp), %eax
	je	.L42
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	imull	$100, %eax, %eax
	addl	%edx, %eax
	movl	-40028(%ebp,%eax,4), %eax
	testl	%eax, %eax
	je	.L42
.L41:
	movl	$.LC9, (%esp)
	call	puts
	movl	$0, %eax
	movl	%eax, -80036(%ebp)
	jmp	.L1
.L42:
	addl	$1, -20(%ebp)
.L37:
	movl	-80032(%ebp), %eax
	cmpl	%eax, -20(%ebp)
	jl	.L38
	addl	$1, -24(%ebp)
.L35:
	movl	-80032(%ebp), %eax
	cmpl	%eax, -24(%ebp)
	jl	.L36
	movl	$.LC10, (%esp)
	call	puts
	jmp	.L46
.L1:
	movl	-80036(%ebp), %eax
.L46:
	addl	$80040, %esp
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
