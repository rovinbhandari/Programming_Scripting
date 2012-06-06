	.file	"a.c"
	.section	.rodata
.LC0:
	.string	"%s"
.LC1:
	.string	"done"
.LC2:
	.string	"%c"
.LC3:
	.string	"%d"
.LC4:
	.string	"\nholy fuck%sholy fuck%d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$48, %esp
	movl	%gs:20, %eax
	movl	%eax, 44(%esp)
	xorl	%eax, %eax
	movl	$.LC0, %eax
	leal	34(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC1, (%esp)
	call	puts
	movl	$.LC2, %eax
	leal	34(%esp), %edx
	addl	$2, %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC1, (%esp)
	call	puts
	movl	$.LC3, %eax
	leal	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	28(%esp), %edx
	movl	$.LC4, %eax
	movl	%edx, 8(%esp)
	leal	34(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	movl	44(%esp), %edx
	xorl	%gs:20, %edx
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.1-4ubuntu9) 4.4.1"
	.section	.note.GNU-stack,"",@progbits
