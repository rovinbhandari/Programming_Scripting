	.file	"5.c"
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%d %d"
.LC2:
	.string	"%d %d\n"
.LC4:
	.string	"%d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$64, %esp
	movl	$0, 44(%esp)
	movl	$0, 36(%esp)
	movl	$.LC0, %eax
	leal	60(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	jmp	.L2
.L10:
	movl	$.LC1, %eax
	leal	52(%esp), %edx
	movl	%edx, 8(%esp)
	leal	56(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	52(%esp), %ecx
	movl	56(%esp), %edx
	movl	$.LC2, %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	52(%esp), %eax
	movl	%eax, 48(%esp)
	jmp	.L3
.L4:
	fildl	44(%esp)
	fstpl	16(%esp)
	fildl	48(%esp)
	fstpl	8(%esp)
	fldl	.LC3
	fstpl	(%esp)
	call	pow
	faddl	16(%esp)
	fnstcw	26(%esp)
	movzwl	26(%esp), %eax
	movb	$12, %ah
	movw	%ax, 24(%esp)
	fldcw	24(%esp)
	fistpl	44(%esp)
	fldcw	26(%esp)
	subl	$1, 48(%esp)
.L3:
	cmpl	$0, 48(%esp)
	jns	.L4
	movl	$.LC4, %eax
	movl	44(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	jmp	.L5
.L9:
	movl	$1, 32(%esp)
	jmp	.L6
.L7:
	movl	44(%esp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%ecx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, 40(%esp)
	movl	44(%esp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, 44(%esp)
	movl	32(%esp), %eax
	imull	40(%esp), %eax
	movl	%eax, 32(%esp)
.L6:
	cmpl	$0, 44(%esp)
	jg	.L7
	movl	56(%esp), %eax
	cmpl	%eax, 32(%esp)
	jne	.L8
	addl	$1, 36(%esp)
	movl	$.LC1, %eax
	movl	32(%esp), %edx
	movl	%edx, 8(%esp)
	movl	36(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
.L8:
	addl	$1, 44(%esp)
.L5:
	movl	52(%esp), %eax
	addl	$1, %eax
	movl	%eax, 28(%esp)
	fildl	28(%esp)
	fstpl	8(%esp)
	fldl	.LC3
	fstpl	(%esp)
	call	pow
	fnstcw	26(%esp)
	movzwl	26(%esp), %eax
	movb	$12, %ah
	movw	%ax, 24(%esp)
	fldcw	24(%esp)
	fistpl	28(%esp)
	fldcw	26(%esp)
	movl	28(%esp), %eax
	cmpl	44(%esp), %eax
	jg	.L9
	movl	$.LC4, %eax
	movl	36(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
.L2:
	movl	60(%esp), %eax
	testl	%eax, %eax
	setne	%dl
	subl	$1, %eax
	movl	%eax, 60(%esp)
	testb	%dl, %dl
	jne	.L10
	leave
	ret
	.size	main, .-main
	.section	.rodata
	.align 8
.LC3:
	.long	0
	.long	1076101120
	.ident	"GCC: (Ubuntu 4.4.1-4ubuntu9) 4.4.1"
	.section	.note.GNU-stack,"",@progbits
