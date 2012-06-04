	.file	"l2p2.c"
	.section	.rodata
.LC0:
	.string	"\n\tThe reqiured pattern is:\n"
.LC1:
	.string	"\t "
.LC2:
	.string	"  "
.LC3:
	.string	"%d "
.LC4:
	.string	"5 "
.LC5:
	.string	" 5 "
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
	call	puts
	movl	$0, -16(%ebp)
	jmp	.L2
.L3:
	movl	$.LC1, (%esp)
	call	printf
	movl	$0, -8(%ebp)
	jmp	.L4
.L5:
	movl	$.LC2, (%esp)
	call	printf
	addl	$1, -8(%ebp)
.L4:
	movl	-8(%ebp), %eax
	cmpl	-16(%ebp), %eax
	jl	.L5
	movl	$10, -12(%ebp)
	jmp	.L7
.L8:
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	subl	$1, -12(%ebp)
.L7:
	movl	-16(%ebp), %eax
	addl	$5, %eax
	cmpl	-12(%ebp), %eax
	jl	.L8
	cmpl	$5, -16(%ebp)
	je	.L10
	movl	$.LC4, (%esp)
	call	printf
	jmp	.L12
.L10:
	movl	$.LC5, (%esp)
	call	printf
.L12:
	movl	$4, %eax
	subl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	jmp	.L13
.L14:
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	subl	$1, -12(%ebp)
.L13:
	cmpl	$0, -12(%ebp)
	jns	.L14
	movl	$10, (%esp)
	call	putchar
	addl	$1, -16(%ebp)
.L2:
	cmpl	$5, -16(%ebp)
	jle	.L3
	addl	$36, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.1 20061011 (Red Hat 4.1.1-30)"
	.section	.note.GNU-stack,"",@progbits
