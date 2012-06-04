	.file	"arrayinitialization3.c"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$4000016, %esp
	movl	$1000000, 8(%esp)
	movl	$-1, 4(%esp)
	leal	16(%esp), %eax
	movl	%eax, (%esp)
	call	memset
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
