	.file	"l6p1.c"
	.section	.rodata
.LC0:
	.string	"\nEnter the filename :\t"
.LC1:
	.string	"%s"
.LC2:
	.string	"w"
	.align 4
.LC3:
	.string	"\nEnter the number of lines to be entered :\t"
.LC4:
	.string	"%d"
.LC5:
	.string	"\nEnter lines :"
	.text
.globl newfile
	.type	newfile, @function
newfile:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$184, %esp
	movl	$.LC0, (%esp)
	call	printf
	leal	-54(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	movl	$.LC2, 4(%esp)
	leal	-54(%ebp), %eax
	movl	%eax, (%esp)
	call	fopen
	movl	%eax, -4(%ebp)
	movl	$.LC3, (%esp)
	call	printf
	leal	-160(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	scanf
	movl	$.LC5, (%esp)
	call	puts
	jmp	.L2
.L3:
	movl	stdin, %eax
	movl	%eax, 8(%esp)
	movl	$100, 4(%esp)
	leal	-154(%ebp), %eax
	movl	%eax, (%esp)
	call	fgets
	movl	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-154(%ebp), %eax
	movl	%eax, (%esp)
	call	fputs
	movl	-160(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160(%ebp)
.L2:
	movl	-160(%ebp), %eax
	testl	%eax, %eax
	jns	.L3
	movl	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	fclose
	leave
	ret
	.size	newfile, .-newfile
	.section	.rodata
.LC6:
	.string	"r"
.LC7:
	.string	"\nError retrieving file"
.LC8:
	.string	"%c"
	.text
.globl displayfile
	.type	displayfile, @function
displayfile:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$88, %esp
	movl	$.LC0, (%esp)
	call	printf
	leal	-54(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	movl	$.LC6, 4(%esp)
	leal	-54(%ebp), %eax
	movl	%eax, (%esp)
	call	fopen
	movl	%eax, -4(%ebp)
	cmpl	$0, -4(%ebp)
	jne	.L10
	movl	$.LC7, (%esp)
	call	puts
	jmp	.L9
.L11:
	leal	-55(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC8, 4(%esp)
	movl	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	fscanf
	movzbl	-55(%ebp), %eax
	movsbl	%al,%eax
	movl	%eax, (%esp)
	call	putchar
.L10:
	movl	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	feof
	testl	%eax, %eax
	je	.L11
.L9:
	movl	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	fclose
	leave
	ret
	.size	displayfile, .-displayfile
	.section	.rodata
.LC9:
	.string	"Enter the filename :\t"
	.align 4
.LC10:
	.string	"\nEnter the line number to display (first line entered = line no. 1) :\t"
.LC11:
	.string	"\n%s"
	.text
.globl findline
	.type	findline, @function
findline:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	subl	$196, %esp
	movl	$0, -8(%ebp)
	movl	$.LC9, (%esp)
	call	printf
	leal	-62(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	movl	$.LC6, 4(%esp)
	leal	-62(%ebp), %eax
	movl	%eax, (%esp)
	call	fopen
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	.L14
	movl	$.LC7, (%esp)
	call	puts
	jmp	.L16
.L14:
	movl	$.LC10, (%esp)
	call	printf
	leal	-168(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	scanf
	jmp	.L17
.L18:
	leal	-162(%ebp), %eax
	movl	$-1, %ecx
	movl	%eax, -184(%ebp)
	movl	$0, %eax
	cld
	movl	-184(%ebp), %edi
	repnz
	scasb
	movl	%ecx, %eax
	notl	%eax
	subl	$1, %eax
	subl	$1, %eax
	movzbl	-162(%ebp,%eax), %eax
	cmpb	$10, %al
	jne	.L19
	leal	-162(%ebp), %eax
	movl	$-1, %ecx
	movl	%eax, -188(%ebp)
	movl	$0, %eax
	cld
	movl	-188(%ebp), %edi
	repnz
	scasb
	movl	%ecx, %eax
	notl	%eax
	subl	$1, %eax
	subl	$1, %eax
	movb	$0, -162(%ebp,%eax)
.L19:
	movl	-168(%ebp), %eax
	cmpl	%eax, -8(%ebp)
	jne	.L21
	leal	-162(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC11, (%esp)
	call	printf
.L21:
	addl	$1, -8(%ebp)
.L17:
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$100, 4(%esp)
	leal	-162(%ebp), %eax
	movl	%eax, (%esp)
	call	fgets
	testl	%eax, %eax
	jne	.L18
.L16:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	fclose
	addl	$196, %esp
	popl	%edi
	popl	%ebp
	ret
	.size	findline, .-findline
	.section	.rodata
	.align 4
.LC12:
	.string	"\nEnter the number of lines to be inserted :\t"
.LC13:
	.string	"abc.txt"
	.align 4
.LC14:
	.string	"\nEnter the position at which line is to be inserted (first line entered = line no. 1) :\t"
.LC15:
	.string	"\nEnter the line :"
.LC16:
	.string	"%s\n"
	.text
.globl insertlines
	.type	insertlines, @function
insertlines:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	subl	$292, %esp
	movl	$.LC0, (%esp)
	call	printf
	leal	-66(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	movl	$.LC12, (%esp)
	call	printf
	leal	-276(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	scanf
	jmp	.L25
.L26:
	movl	$.LC6, 4(%esp)
	leal	-66(%ebp), %eax
	movl	%eax, (%esp)
	call	fopen
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	jne	.L27
	movl	$.LC7, (%esp)
	call	puts
	jmp	.L29
.L27:
	movl	$.LC2, 4(%esp)
	movl	$.LC13, (%esp)
	call	fopen
	movl	%eax, -12(%ebp)
	movl	$1, -8(%ebp)
	movl	$.LC14, (%esp)
	call	printf
	leal	-272(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	scanf
	movl	$.LC15, (%esp)
	call	puts
	leal	-266(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	jmp	.L30
.L31:
	leal	-166(%ebp), %eax
	movl	$-1, %ecx
	movl	%eax, -280(%ebp)
	movl	$0, %eax
	cld
	movl	-280(%ebp), %edi
	repnz
	scasb
	movl	%ecx, %eax
	notl	%eax
	subl	$1, %eax
	subl	$1, %eax
	movzbl	-166(%ebp,%eax), %eax
	cmpb	$10, %al
	jne	.L32
	leal	-166(%ebp), %eax
	movl	$-1, %ecx
	movl	%eax, -284(%ebp)
	movl	$0, %eax
	cld
	movl	-284(%ebp), %edi
	repnz
	scasb
	movl	%ecx, %eax
	notl	%eax
	subl	$1, %eax
	subl	$1, %eax
	movb	$0, -166(%ebp,%eax)
.L32:
	leal	-166(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC16, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	fprintf
	movl	-272(%ebp), %eax
	cmpl	%eax, -8(%ebp)
	jne	.L34
	leal	-266(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC16, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	fprintf
.L34:
	addl	$1, -8(%ebp)
.L30:
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$100, 4(%esp)
	leal	-166(%ebp), %eax
	movl	%eax, (%esp)
	call	fgets
	testl	%eax, %eax
	jne	.L31
.L29:
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	fclose
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	fclose
	leal	-66(%ebp), %eax
	movl	%eax, (%esp)
	call	remove
	leal	-66(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC13, (%esp)
	call	rename
	movl	-276(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -276(%ebp)
.L25:
	movl	-276(%ebp), %eax
	testl	%eax, %eax
	jg	.L26
	addl	$292, %esp
	popl	%edi
	popl	%ebp
	ret
	.size	insertlines, .-insertlines
	.section	.rodata
	.align 4
.LC17:
	.string	"\nEnter the number of lines to be deleted :\t"
	.align 4
.LC18:
	.string	"\nEnter the position of line which is to be deleted (first line entered = line no. 1) :\t"
.LC19:
	.string	"\nLine deleted!"
	.text
.globl deletelines
	.type	deletelines, @function
deletelines:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	subl	$196, %esp
	movl	$.LC0, (%esp)
	call	printf
	leal	-66(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	movl	$.LC17, (%esp)
	call	printf
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	scanf
	jmp	.L39
.L40:
	movl	$.LC6, 4(%esp)
	leal	-66(%ebp), %eax
	movl	%eax, (%esp)
	call	fopen
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	jne	.L41
	movl	$.LC7, (%esp)
	call	puts
	jmp	.L43
.L41:
	movl	$.LC2, 4(%esp)
	movl	$.LC13, (%esp)
	call	fopen
	movl	%eax, -12(%ebp)
	movl	$1, -8(%ebp)
	movl	$.LC18, (%esp)
	call	printf
	leal	-172(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	scanf
	jmp	.L44
.L45:
	leal	-166(%ebp), %eax
	movl	$-1, %ecx
	movl	%eax, -184(%ebp)
	movl	$0, %eax
	cld
	movl	-184(%ebp), %edi
	repnz
	scasb
	movl	%ecx, %eax
	notl	%eax
	subl	$1, %eax
	subl	$1, %eax
	movzbl	-166(%ebp,%eax), %eax
	cmpb	$10, %al
	jne	.L46
	leal	-166(%ebp), %eax
	movl	$-1, %ecx
	movl	%eax, -188(%ebp)
	movl	$0, %eax
	cld
	movl	-188(%ebp), %edi
	repnz
	scasb
	movl	%ecx, %eax
	notl	%eax
	subl	$1, %eax
	subl	$1, %eax
	movb	$0, -166(%ebp,%eax)
.L46:
	leal	-166(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC16, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	fprintf
	movl	-172(%ebp), %eax
	cmpl	%eax, -8(%ebp)
	jne	.L48
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$100, 4(%esp)
	leal	-166(%ebp), %eax
	movl	%eax, (%esp)
	call	fgets
	movl	$.LC19, (%esp)
	call	puts
.L48:
	addl	$1, -8(%ebp)
.L44:
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$100, 4(%esp)
	leal	-166(%ebp), %eax
	movl	%eax, (%esp)
	call	fgets
	testl	%eax, %eax
	jne	.L45
.L43:
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	fclose
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	fclose
	leal	-66(%ebp), %eax
	movl	%eax, (%esp)
	call	remove
	leal	-66(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC13, (%esp)
	call	rename
	movl	-176(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -176(%ebp)
.L39:
	movl	-176(%ebp), %eax
	testl	%eax, %eax
	jg	.L40
	addl	$196, %esp
	popl	%edi
	popl	%ebp
	ret
	.size	deletelines, .-deletelines
	.section	.rodata
.LC20:
	.string	"\n\n\t\t\tFILE   OPERATIONS\n"
	.align 4
.LC21:
	.string	"\nEnter your choice :\n\n\t#1# Enter text to a new file\n\t#2# Display text of a file\n\t#3# Find and display a line of a file\n\t#4# Insert n lines to a file\n\t#5# Delete n lines from a file\n\t#6# Exit"
	.align 4
.LC22:
	.string	"\nIncorrect Choice. Exiting...\n"
	.align 4
.LC23:
	.string	"\nDo another operation?\n\t#1# Yes\n\t#2# No"
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
	movl	$.LC20, (%esp)
	call	puts
.L53:
	movl	$.LC21, (%esp)
	call	puts
	leal	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	scanf
	movl	-8(%ebp), %eax
	cmpl	$1, %eax
	jne	.L54
	call	newfile
	jmp	.L56
.L54:
	movl	-8(%ebp), %eax
	cmpl	$2, %eax
	jne	.L57
	call	displayfile
	jmp	.L56
.L57:
	movl	-8(%ebp), %eax
	cmpl	$3, %eax
	jne	.L59
	call	findline
	jmp	.L56
.L59:
	movl	-8(%ebp), %eax
	cmpl	$4, %eax
	jne	.L61
	call	insertlines
	jmp	.L56
.L61:
	movl	-8(%ebp), %eax
	cmpl	$5, %eax
	jne	.L63
	call	deletelines
	jmp	.L56
.L63:
	movl	-8(%ebp), %eax
	cmpl	$6, %eax
	jne	.L65
	movl	$0, -24(%ebp)
	jmp	.L67
.L65:
	movl	$.LC22, (%esp)
	call	puts
	movl	$0, -24(%ebp)
	jmp	.L67
.L56:
	movl	$.LC23, (%esp)
	call	puts
	leal	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	scanf
	movl	-12(%ebp), %eax
	cmpl	$1, %eax
	je	.L53
	movl	$0, -24(%ebp)
.L67:
	movl	-24(%ebp), %eax
	addl	$36, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.1 20061011 (Red Hat 4.1.1-30)"
	.section	.note.GNU-stack,"",@progbits
