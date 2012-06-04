	.file	"r002.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"\n\tThe sum of even-valued Fibonacci terms not\n\texceeding 4000000 is %ld\n\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	movl	$0, 28(%esp)
	movl	$1, 24(%esp)
	movl	$2, 20(%esp)
	jmp	.L2
.L4:
	movl	20(%esp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L3
	movl	20(%esp), %eax
	addl	%eax, 28(%esp)
.L3:
	movl	20(%esp), %eax
	movl	%eax, 16(%esp)
	movl	24(%esp), %eax
	addl	%eax, 20(%esp)
	movl	16(%esp), %eax
	movl	%eax, 24(%esp)
.L2:
	cmpl	$4000000, 20(%esp)
	jle	.L4
	movl	$.LC0, %eax
	movl	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.1-4ubuntu9) 4.4.1"
	.section	.note.GNU-stack,"",@progbits
