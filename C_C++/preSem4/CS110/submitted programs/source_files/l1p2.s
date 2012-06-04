	.file	"l1p2.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"\n\tPlease enter the values(floating point) of a,b,c"
.LC1:
	.string	"\ta = "
.LC2:
	.string	"%lf"
.LC3:
	.string	"\tb = "
.LC4:
	.string	"\tc = "
.LC6:
	.string	"\tSum of roots = %lf\n"
.LC7:
	.string	"\tProduct of roots = %lf\n"
.LC9:
	.string	"\n\t  IMAGINARY ROOTS"
.LC10:
	.string	"\t1st root = (%lf) + i(%lf)\n"
.LC11:
	.string	"\t2nd root = (%lf) + i(%lf)\n"
.LC12:
	.string	"\n\t  EQUAL ROOTS"
.LC13:
	.string	"\n\t  UNEQUAL ROOTS"
.LC14:
	.string	"\t1st root = %lf\n"
.LC15:
	.string	"\t2nd root = %lf\n"
	.align 8
.LC8:
	.long	0
	.long	-1072693248
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
	subl	$116, %esp
	movl	$.LC0, (%esp)
	call	puts
	movl	$.LC1, (%esp)
	call	printf
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	scanf
	movl	$.LC3, (%esp)
	call	printf
	leal	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	scanf
	movl	$.LC4, (%esp)
	call	printf
	leal	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	scanf
	fldl	-48(%ebp)
	fldz
	fsubp	%st, %st(1)
	fldl	-40(%ebp)
	fdivrp	%st, %st(1)
	fstpl	4(%esp)
	movl	$.LC6, (%esp)
	call	printf
	fldl	-56(%ebp)
	fldl	-40(%ebp)
	fdivrp	%st, %st(1)
	fstpl	4(%esp)
	movl	$.LC7, (%esp)
	call	printf
	fldl	-48(%ebp)
	fldl	-48(%ebp)
	fmulp	%st, %st(1)
	fldl	-40(%ebp)
	fldl	.LC8
	fmulp	%st, %st(1)
	fldl	-56(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-32(%ebp)
	fldl	-32(%ebp)
	fldz
	fucompp
	fnstsw	%ax
	sahf
	ja	.L4
	jmp	.L2
.L4:
	movl	$.LC9, (%esp)
	call	puts
	fldl	-32(%ebp)
	fstpl	-96(%ebp)
	movl	-96(%ebp), %eax
	movl	-92(%ebp), %edx
	andl	$2147483647, %edx
	movl	%eax, -80(%ebp)
	movl	%edx, -76(%ebp)
	fldl	-80(%ebp)
	fsqrt
	fstpl	-88(%ebp)
	fldl	-88(%ebp)
	fucomp	%st(0)
	fnstsw	%ax
	sahf
	jp	.L14
	je	.L5
.L14:
	fldl	-80(%ebp)
	fstpl	(%esp)
	call	sqrt
	fstpl	-88(%ebp)
.L5:
	fldl	-88(%ebp)
	fldz
	fsubp	%st, %st(1)
	fldl	-40(%ebp)
	fadd	%st(0), %st
	fdivrp	%st, %st(1)
	fldl	-48(%ebp)
	fldz
	fsubp	%st, %st(1)
	fldl	-40(%ebp)
	fadd	%st(0), %st
	fdivrp	%st, %st(1)
	fxch	%st(1)
	fstpl	12(%esp)
	fstpl	4(%esp)
	movl	$.LC10, (%esp)
	call	printf
	fldl	-32(%ebp)
	fabs
	fstpl	(%esp)
	call	sqrt
	fldz
	faddp	%st, %st(1)
	fldl	-40(%ebp)
	fadd	%st(0), %st
	fdivrp	%st, %st(1)
	fldl	-48(%ebp)
	fldz
	fsubp	%st, %st(1)
	fldl	-40(%ebp)
	fadd	%st(0), %st
	fdivrp	%st, %st(1)
	fxch	%st(1)
	fstpl	12(%esp)
	fstpl	4(%esp)
	movl	$.LC11, (%esp)
	call	printf
	jmp	.L12
.L2:
	fldl	-32(%ebp)
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jp	.L13
	je	.L9
.L13:
	jmp	.L7
.L9:
	movl	$.LC12, (%esp)
	call	puts
	jmp	.L10
.L7:
	movl	$.LC13, (%esp)
	call	puts
.L10:
	fldl	-48(%ebp)
	fldz
	fsubp	%st, %st(1)
	fstpl	-72(%ebp)
	fldl	-32(%ebp)
	fstpl	(%esp)
	call	sqrt
	fldl	-72(%ebp)
	fsubp	%st, %st(1)
	fldl	-40(%ebp)
	fadd	%st(0), %st
	fdivrp	%st, %st(1)
	fstpl	-24(%ebp)
	fldl	-48(%ebp)
	fldz
	fsubp	%st, %st(1)
	fstpl	-64(%ebp)
	fldl	-32(%ebp)
	fstpl	(%esp)
	call	sqrt
	fldl	-64(%ebp)
	faddp	%st, %st(1)
	fldl	-40(%ebp)
	fadd	%st(0), %st
	fdivrp	%st, %st(1)
	fstpl	-16(%ebp)
	fldl	-24(%ebp)
	fstpl	4(%esp)
	movl	$.LC14, (%esp)
	call	printf
	fldl	-16(%ebp)
	fstpl	4(%esp)
	movl	$.LC15, (%esp)
	call	printf
.L12:
	addl	$116, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.1 20061011 (Red Hat 4.1.1-30)"
	.section	.note.GNU-stack,"",@progbits
