	.file	"l5p2.c"
	.section	.rodata
.LC0:
	.string	"\nEnter the main string"
.LC1:
	.string	"\nEnter the test string"
	.align 4
.LC2:
	.string	"\n The test string is a substring of the main string"
	.align 4
.LC3:
	.string	"\nThe test string is NOT a substring of the main string"
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
	subl	$1028, %esp
	movl	$1, -16(%ebp)
	movl	$.LC0, (%esp)
	call	puts
	leal	-1016(%ebp), %eax
	movl	%eax, (%esp)
	call	gets
	movl	$.LC1, (%esp)
	call	puts
	leal	-516(%ebp), %eax
	movl	%eax, (%esp)
	call	gets
	movl	$0, -12(%ebp)
	jmp	.L2
.L3:
	movl	-12(%ebp), %eax
	movzbl	-1016(%ebp,%eax), %edx
	movzbl	-516(%ebp), %eax
	cmpb	%al, %dl
	jne	.L4
	movl	$1, -8(%ebp)
	jmp	.L6
.L7:
	movl	-8(%ebp), %eax
	movzbl	-516(%ebp,%eax), %edx
	movl	-8(%ebp), %eax
	addl	-12(%ebp), %eax
	movzbl	-1016(%ebp,%eax), %eax
	cmpb	%al, %dl
	je	.L8
	movl	$1, -16(%ebp)
	jmp	.L10
.L8:
	movl	$0, -16(%ebp)
	addl	$1, -8(%ebp)
.L6:
	movl	-8(%ebp), %eax
	movzbl	-516(%ebp,%eax), %eax
	testb	%al, %al
	jne	.L7
.L10:
	cmpl	$0, -16(%ebp)
	je	.L11
.L4:
	addl	$1, -12(%ebp)
.L2:
	movl	-12(%ebp), %eax
	movzbl	-1016(%ebp,%eax), %eax
	testb	%al, %al
	jne	.L3
.L11:
	cmpl	$0, -16(%ebp)
	jne	.L12
	movl	$.LC2, (%esp)
	call	puts
	jmp	.L14
.L12:
	movl	$.LC3, (%esp)
	call	puts
.L14:
	movl	$0, %eax
	addl	$1028, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.1 20061011 (Red Hat 4.1.1-30)"
	.section	.note.GNU-stack,"",@progbits
