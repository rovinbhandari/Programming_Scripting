	.file	"l4p1.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"\n\tCOVERSION FROM BINARY TO DECIMAL"
	.align 4
.LC2:
	.string	"\n\tThe Number in Decimal is : %d\n\n"
	.align 8
.LC1:
	.long	0
	.long	1073741824
	.text
.globl BtoD
	.type	BtoD, @function
BtoD:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	$0, -8(%ebp)
	movl	$.LC0, (%esp)
	call	puts
	movl	$0, -12(%ebp)
	jmp	.L2
.L3:
	addl	$1, -12(%ebp)
.L2:
	movl	-12(%ebp), %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L3
	subl	$1, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	.L5
.L6:
	movl	-16(%ebp), %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$48, %al
	jne	.L7
	movl	$0, -4(%ebp)
	jmp	.L9
.L7:
	movl	-16(%ebp), %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$49, %al
	jne	.L9
	movl	$1, -4(%ebp)
.L9:
	fildl	-8(%ebp)
	fstpl	-40(%ebp)
	fildl	-4(%ebp)
	fstpl	-32(%ebp)
	fildl	-12(%ebp)
	fstpl	8(%esp)
	fldl	.LC1
	fstpl	(%esp)
	call	pow
	fmull	-32(%ebp)
	faddl	-40(%ebp)
	fnstcw	-18(%ebp)
	movzwl	-18(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -20(%ebp)
	fldcw	-20(%ebp)
	fistpl	-8(%ebp)
	fldcw	-18(%ebp)
	subl	$1, -12(%ebp)
	addl	$1, -16(%ebp)
.L5:
	movl	-16(%ebp), %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L6
	movl	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	leave
	ret
	.size	BtoD, .-BtoD
	.section	.rodata
	.align 4
.LC4:
	.string	"\n\tCOVERSION FROM DECIMAL TO BINARY"
	.align 4
.LC5:
	.string	"\n\tThe number in Binary is : \n\n\t"
.LC6:
	.string	"%d"
.LC7:
	.string	"\n"
	.text
.globl DtoB
	.type	DtoB, @function
DtoB:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$228, %esp
	movl	$0, -8(%ebp)
	movl	$.LC4, (%esp)
	call	puts
	jmp	.L14
.L15:
	movl	-8(%ebp), %ebx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	movl	%eax, %ecx
	shrl	$31, %ecx
	leal	(%edx,%ecx), %eax
	andl	$1, %eax
	subl	%ecx, %eax
	movl	%eax, -208(%ebp,%ebx,4)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	shrl	$31, %eax
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, 8(%ebp)
	addl	$1, -8(%ebp)
.L14:
	cmpl	$0, 8(%ebp)
	jne	.L15
	movl	$.LC5, (%esp)
	call	printf
	subl	$1, -8(%ebp)
	jmp	.L17
.L18:
	movl	-8(%ebp), %eax
	movl	-208(%ebp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$.LC6, (%esp)
	call	printf
	subl	$1, -8(%ebp)
.L17:
	cmpl	$0, -8(%ebp)
	jns	.L18
	movl	$.LC7, (%esp)
	call	puts
	addl	$228, %esp
	popl	%ebx
	popl	%ebp
	ret
	.size	DtoB, .-DtoB
	.section	.rodata
	.align 4
.LC8:
	.string	"\nCOVERSION FROM HEX TO DECIMAL"
	.align 4
.LC10:
	.string	"\n\tThe number in Hexadecimal is  : %d\n\n"
	.align 8
.LC9:
	.long	0
	.long	1076887552
	.text
.globl HtoD
	.type	HtoD, @function
HtoD:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	$0, -8(%ebp)
	movl	$.LC8, (%esp)
	call	puts
	movl	$0, -12(%ebp)
	jmp	.L22
.L23:
	addl	$1, -12(%ebp)
.L22:
	movl	-12(%ebp), %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L23
	subl	$1, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	.L25
.L26:
	movl	-16(%ebp), %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$57, %al
	jg	.L27
	movl	-16(%ebp), %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al,%eax
	subl	$48, %eax
	movl	%eax, -4(%ebp)
	jmp	.L29
.L27:
	movl	-16(%ebp), %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$58, %al
	jle	.L30
	movl	-16(%ebp), %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$71, %al
	jg	.L30
	movl	-16(%ebp), %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al,%eax
	subl	$55, %eax
	movl	%eax, -4(%ebp)
	jmp	.L29
.L30:
	movl	-16(%ebp), %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al,%eax
	subl	$87, %eax
	movl	%eax, -4(%ebp)
.L29:
	fildl	-8(%ebp)
	fstpl	-40(%ebp)
	fildl	-4(%ebp)
	fstpl	-32(%ebp)
	fildl	-12(%ebp)
	fstpl	8(%esp)
	fldl	.LC9
	fstpl	(%esp)
	call	pow
	fmull	-32(%ebp)
	faddl	-40(%ebp)
	fnstcw	-18(%ebp)
	movzwl	-18(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -20(%ebp)
	fldcw	-20(%ebp)
	fistpl	-8(%ebp)
	fldcw	-18(%ebp)
	subl	$1, -12(%ebp)
	addl	$1, -16(%ebp)
.L25:
	movl	-16(%ebp), %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L26
	movl	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC10, (%esp)
	call	printf
	leave
	ret
	.size	HtoD, .-HtoD
	.section	.rodata
	.align 4
.LC12:
	.string	"\n\tCOVERSION FROM DECIMAL TO HEX"
	.align 4
.LC13:
	.string	"\n\tThe number in Hexadecimal is : \n\n\t"
	.text
.globl DtoH
	.type	DtoH, @function
DtoH:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$72, %esp
	movl	$.LC12, (%esp)
	call	puts
	movl	$0, -8(%ebp)
	jmp	.L36
.L37:
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	movl	%eax, %ecx
	shrl	$28, %ecx
	leal	(%edx,%ecx), %eax
	andl	$15, %eax
	subl	%ecx, %eax
	movl	%eax, -4(%ebp)
	cmpl	$9, -4(%ebp)
	jle	.L38
	movl	-8(%ebp), %edx
	movl	-4(%ebp), %eax
	addl	$55, %eax
	movb	%al, -58(%ebp,%edx)
	jmp	.L40
.L38:
	movl	-8(%ebp), %edx
	movl	-4(%ebp), %eax
	addl	$48, %eax
	movb	%al, -58(%ebp,%edx)
.L40:
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$28, %eax
	addl	%edx, %eax
	sarl	$4, %eax
	movl	%eax, 8(%ebp)
	addl	$1, -8(%ebp)
.L36:
	cmpl	$0, 8(%ebp)
	jne	.L37
	movl	$.LC13, (%esp)
	call	printf
	subl	$1, -8(%ebp)
	jmp	.L42
.L43:
	movl	-8(%ebp), %eax
	movzbl	-58(%ebp,%eax), %eax
	movsbl	%al,%eax
	movl	%eax, (%esp)
	call	putchar
	subl	$1, -8(%ebp)
.L42:
	cmpl	$0, -8(%ebp)
	jns	.L43
	movl	$.LC7, (%esp)
	call	puts
	leave
	ret
	.size	DtoH, .-DtoH
	.section	.rodata
	.align 4
.LC14:
	.string	"\n\nEnter your choice :\n#1# Binary to decimal\n#2# Decimal to binary\n#3# Decimal to HEX\n#4# HEX to decimal"
.LC15:
	.string	"\n\nEnter the Number"
.LC16:
	.string	"%s"
.LC17:
	.string	"/n/n/tWRONG INPUT/n/n"
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
	subl	$84, %esp
	movl	$.LC14, (%esp)
	call	puts
	leal	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC6, (%esp)
	call	scanf
	movl	$.LC15, (%esp)
	call	puts
	movl	-12(%ebp), %eax
	cmpl	$1, %eax
	je	.L47
	movl	-12(%ebp), %eax
	cmpl	$4, %eax
	jne	.L49
.L47:
	leal	-66(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC16, (%esp)
	call	scanf
	movl	$0, -8(%ebp)
	jmp	.L50
.L51:
	movl	-8(%ebp), %eax
	movzbl	-66(%ebp,%eax), %eax
	cmpb	$47, %al
	jle	.L52
	movl	-8(%ebp), %eax
	movzbl	-66(%ebp,%eax), %eax
	cmpb	$57, %al
	jle	.L54
.L52:
	movl	-8(%ebp), %eax
	movzbl	-66(%ebp,%eax), %eax
	cmpb	$64, %al
	jle	.L55
	movl	-8(%ebp), %eax
	movzbl	-66(%ebp,%eax), %eax
	cmpb	$70, %al
	jle	.L54
.L55:
	movl	-8(%ebp), %eax
	movzbl	-66(%ebp,%eax), %eax
	cmpb	$96, %al
	jle	.L57
	movl	-8(%ebp), %eax
	movzbl	-66(%ebp,%eax), %eax
	cmpb	$102, %al
	jle	.L54
.L57:
	movl	$.LC17, (%esp)
	call	printf
	movl	$0, -76(%ebp)
	jmp	.L59
.L54:
	addl	$1, -8(%ebp)
.L50:
	movl	-8(%ebp), %eax
	movzbl	-66(%ebp,%eax), %eax
	testb	%al, %al
	jne	.L51
	jmp	.L61
.L49:
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC6, (%esp)
	call	scanf
.L61:
	movl	-12(%ebp), %eax
	movl	%eax, -72(%ebp)
	cmpl	$2, -72(%ebp)
	je	.L64
	cmpl	$2, -72(%ebp)
	jg	.L67
	cmpl	$1, -72(%ebp)
	je	.L63
	jmp	.L62
.L67:
	cmpl	$3, -72(%ebp)
	je	.L65
	cmpl	$4, -72(%ebp)
	je	.L66
	jmp	.L62
.L63:
	leal	-66(%ebp), %eax
	movl	%eax, (%esp)
	call	BtoD
	jmp	.L68
.L64:
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	DtoB
	jmp	.L68
.L65:
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	DtoH
	jmp	.L68
.L66:
	leal	-66(%ebp), %eax
	movl	%eax, (%esp)
	call	HtoD
	jmp	.L68
.L62:
	movl	$0, -76(%ebp)
	jmp	.L59
.L68:
	jmp	.L46
.L59:
	movl	-76(%ebp), %eax
	movl	%eax, -80(%ebp)
.L46:
	movl	-80(%ebp), %eax
	addl	$84, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.1 20061011 (Red Hat 4.1.1-30)"
	.section	.note.GNU-stack,"",@progbits
