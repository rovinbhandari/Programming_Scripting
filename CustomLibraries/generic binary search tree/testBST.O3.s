	.file	"testBST.cpp"
	.text
	.p2align 2,,3
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1295:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitD1Ev
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE1295:
	.section .rdata,"dr"
LC0:
	.ascii "\11\0"
LC1:
	.ascii "\11x\11\0"
	.section	.text$_ZN16BinarySearchTreeIiE38printtraversalinorderduplicatesallowedEP10BinaryNodeIiE,"x"
	.linkonce discard
	.align 2
	.p2align 2,,3
	.globl	__ZN16BinarySearchTreeIiE38printtraversalinorderduplicatesallowedEP10BinaryNodeIiE
	.def	__ZN16BinarySearchTreeIiE38printtraversalinorderduplicatesallowedEP10BinaryNodeIiE;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE38printtraversalinorderduplicatesallowedEP10BinaryNodeIiE:
LFB1280:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	80(%esp), %ebp
	movl	84(%esp), %eax
	testl	%eax, %eax
	je	L2
L57:
	movl	84(%esp), %eax
	movl	8(%eax), %eax
	movl	%eax, 36(%esp)
	testl	%eax, %eax
	je	L4
L58:
	movl	8(%eax), %eax
	movl	%eax, 32(%esp)
	testl	%eax, %eax
	je	L5
L59:
	movl	8(%eax), %eax
	movl	%eax, 28(%esp)
	testl	%eax, %eax
	je	L6
L60:
	movl	8(%eax), %eax
	movl	%eax, 40(%esp)
	testl	%eax, %eax
	je	L7
L61:
	movl	8(%eax), %eax
	movl	%eax, 44(%esp)
	testl	%eax, %eax
	je	L8
L62:
	movl	8(%eax), %eax
	movl	%eax, 24(%esp)
	testl	%eax, %eax
	je	L9
L63:
	movl	8(%eax), %eax
	movl	%eax, 20(%esp)
	testl	%eax, %eax
	je	L10
	.p2align 2,,3
L64:
	movl	8(%eax), %ebx
	testl	%ebx, %ebx
	jne	L65
	jmp	L11
	.p2align 2,,3
L78:
	movb	39(%edi), %al
L15:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
L12:
	movl	12(%ebx), %ebx
	testl	%ebx, %ebx
	je	L11
L65:
	movl	8(%ebx), %eax
	movl	%eax, 4(%esp)
	movl	%ebp, (%esp)
	call	__ZN16BinarySearchTreeIiE38printtraversalinorderduplicatesallowedEP10BinaryNodeIiE
	movl	4(%ebx), %esi
	testl	%esi, %esi
	jle	L12
	movl	(%ebx), %edi
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%edi, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %edi
	movl	$3, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	call	__ZNSolsEi
	movl	%eax, %esi
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%esi,%eax), %edi
	testl	%edi, %edi
	je	L76
	cmpb	$0, 28(%edi)
	jne	L78
	movl	%edi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%edi), %eax
	movl	$10, 4(%esp)
	movl	%edi, (%esp)
	call	*24(%eax)
	jmp	L15
	.p2align 2,,3
L11:
	movl	20(%esp), %eax
	movl	4(%eax), %ebx
	testl	%ebx, %ebx
	jle	L17
	movl	(%eax), %esi
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%esi, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %esi
	movl	$3, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L76
	cmpb	$0, 28(%esi)
	je	L19
	movb	39(%esi), %al
L20:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	20(%esp), %eax
L17:
	movl	12(%eax), %eax
	movl	%eax, 20(%esp)
	testl	%eax, %eax
	jne	L64
L10:
	movl	24(%esp), %eax
	movl	4(%eax), %ebx
	testl	%ebx, %ebx
	jle	L22
	movl	(%eax), %esi
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%esi, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %esi
	movl	$3, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L76
	cmpb	$0, 28(%esi)
	je	L24
	movb	39(%esi), %al
L25:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	24(%esp), %eax
L22:
	movl	12(%eax), %eax
	movl	%eax, 24(%esp)
	testl	%eax, %eax
	jne	L63
L9:
	movl	44(%esp), %eax
	movl	4(%eax), %esi
	testl	%esi, %esi
	jle	L27
	movl	(%eax), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	$3, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L76
	cmpb	$0, 28(%esi)
	je	L29
	movb	39(%esi), %al
L30:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	44(%esp), %eax
L27:
	movl	12(%eax), %eax
	movl	%eax, 44(%esp)
	testl	%eax, %eax
	jne	L62
L8:
	movl	40(%esp), %eax
	movl	4(%eax), %esi
	testl	%esi, %esi
	jle	L32
	movl	(%eax), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	$3, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L76
	cmpb	$0, 28(%esi)
	je	L34
	movb	39(%esi), %al
L35:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	40(%esp), %eax
L32:
	movl	12(%eax), %eax
	movl	%eax, 40(%esp)
	testl	%eax, %eax
	jne	L61
L7:
	movl	28(%esp), %eax
	movl	4(%eax), %esi
	testl	%esi, %esi
	jle	L37
	movl	(%eax), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	$3, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L76
	cmpb	$0, 28(%esi)
	je	L39
	movb	39(%esi), %al
L40:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	28(%esp), %eax
L37:
	movl	12(%eax), %eax
	movl	%eax, 28(%esp)
	testl	%eax, %eax
	jne	L60
L6:
	movl	32(%esp), %eax
	movl	4(%eax), %esi
	testl	%esi, %esi
	jle	L42
	movl	(%eax), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	$3, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L76
	cmpb	$0, 28(%esi)
	je	L44
	movb	39(%esi), %al
L45:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	32(%esp), %eax
L42:
	movl	12(%eax), %eax
	movl	%eax, 32(%esp)
	testl	%eax, %eax
	jne	L59
L5:
	movl	36(%esp), %eax
	movl	4(%eax), %esi
	testl	%esi, %esi
	jle	L47
	movl	(%eax), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	$3, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L76
	cmpb	$0, 28(%esi)
	je	L49
	movb	39(%esi), %al
L50:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	36(%esp), %eax
L47:
	movl	12(%eax), %eax
	movl	%eax, 36(%esp)
	testl	%eax, %eax
	jne	L58
L4:
	movl	84(%esp), %eax
	movl	4(%eax), %esi
	testl	%esi, %esi
	jle	L52
	movl	(%eax), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	$3, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L76
	cmpb	$0, 28(%esi)
	je	L54
	movb	39(%esi), %al
L55:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	84(%esp), %eax
L52:
	movl	12(%eax), %eax
	movl	%eax, 84(%esp)
	testl	%eax, %eax
	jne	L57
L2:
	addl	$60, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 12
	.cfi_restore 6
	popl	%edi
	.cfi_def_cfa_offset 8
	.cfi_restore 7
	popl	%ebp
	.cfi_def_cfa_offset 4
	.cfi_restore 5
	ret
	.p2align 2,,3
L19:
	.cfi_restore_state
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L20
L24:
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L25
L29:
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L30
L76:
	call	__ZSt16__throw_bad_castv
L54:
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L55
L34:
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L35
L39:
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L40
L44:
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L45
L49:
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L50
	.cfi_endproc
LFE1280:
	.section	.text$_ZN16BinarySearchTreeIiE41printtraversalinorderduplicatesnotallowedEP10BinaryNodeIiE,"x"
	.linkonce discard
	.align 2
	.p2align 2,,3
	.globl	__ZN16BinarySearchTreeIiE41printtraversalinorderduplicatesnotallowedEP10BinaryNodeIiE
	.def	__ZN16BinarySearchTreeIiE41printtraversalinorderduplicatesnotallowedEP10BinaryNodeIiE;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE41printtraversalinorderduplicatesnotallowedEP10BinaryNodeIiE:
LFB1281:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	80(%esp), %edi
	movl	84(%esp), %edx
	testl	%edx, %edx
	je	L79
L125:
	movl	84(%esp), %eax
	movl	8(%eax), %eax
	movl	%eax, 28(%esp)
	testl	%eax, %eax
	je	L81
L126:
	movl	8(%eax), %eax
	movl	%eax, 36(%esp)
	testl	%eax, %eax
	je	L82
L127:
	movl	8(%eax), %eax
	movl	%eax, 32(%esp)
	testl	%eax, %eax
	je	L83
L128:
	movl	8(%eax), %eax
	movl	%eax, 40(%esp)
	testl	%eax, %eax
	je	L84
L129:
	movl	8(%eax), %eax
	movl	%eax, 44(%esp)
	testl	%eax, %eax
	je	L85
L130:
	movl	8(%eax), %eax
	movl	%eax, 24(%esp)
	testl	%eax, %eax
	je	L86
	.p2align 2,,3
L131:
	movl	8(%eax), %ebp
	testl	%ebp, %ebp
	je	L87
	.p2align 2,,3
L132:
	movl	8(%ebp), %ebx
	testl	%ebx, %ebx
	jne	L133
	jmp	L88
	.p2align 2,,3
L145:
	movb	39(%eax), %al
L91:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	12(%ebx), %ebx
	testl	%ebx, %ebx
	je	L88
L133:
	movl	8(%ebx), %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	__ZN16BinarySearchTreeIiE41printtraversalinorderduplicatesnotallowedEP10BinaryNodeIiE
	movl	(%ebx), %esi
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%esi, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %esi
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%esi,%eax), %eax
	testl	%eax, %eax
	je	L144
	cmpb	$0, 28(%eax)
	jne	L145
	movl	%eax, (%esp)
	movl	%eax, 20(%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	20(%esp), %eax
	movl	(%eax), %edx
	movl	$10, 4(%esp)
	movl	%eax, (%esp)
	call	*24(%edx)
	jmp	L91
	.p2align 2,,3
L88:
	movl	0(%ebp), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L144
	cmpb	$0, 28(%esi)
	je	L94
	movb	39(%esi), %al
L95:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	12(%ebp), %ebp
	testl	%ebp, %ebp
	jne	L132
L87:
	movl	24(%esp), %eax
	movl	(%eax), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L144
	cmpb	$0, 28(%esi)
	je	L98
	movb	39(%esi), %al
L99:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	24(%esp), %eax
	movl	12(%eax), %eax
	movl	%eax, 24(%esp)
	testl	%eax, %eax
	jne	L131
L86:
	movl	44(%esp), %eax
	movl	(%eax), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L144
	cmpb	$0, 28(%esi)
	je	L102
	movb	39(%esi), %al
L103:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	44(%esp), %eax
	movl	12(%eax), %eax
	movl	%eax, 44(%esp)
	testl	%eax, %eax
	jne	L130
L85:
	movl	40(%esp), %eax
	movl	(%eax), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L144
	cmpb	$0, 28(%esi)
	je	L106
	movb	39(%esi), %al
L107:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	40(%esp), %eax
	movl	12(%eax), %eax
	movl	%eax, 40(%esp)
	testl	%eax, %eax
	jne	L129
L84:
	movl	32(%esp), %eax
	movl	(%eax), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L144
	cmpb	$0, 28(%esi)
	je	L110
	movb	39(%esi), %al
L111:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	32(%esp), %eax
	movl	12(%eax), %eax
	movl	%eax, 32(%esp)
	testl	%eax, %eax
	jne	L128
L83:
	movl	36(%esp), %eax
	movl	(%eax), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L144
	cmpb	$0, 28(%esi)
	je	L114
	movb	39(%esi), %al
L115:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	36(%esp), %eax
	movl	12(%eax), %eax
	movl	%eax, 36(%esp)
	testl	%eax, %eax
	jne	L127
L82:
	movl	28(%esp), %eax
	movl	(%eax), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L144
	cmpb	$0, 28(%esi)
	je	L118
	movb	39(%esi), %al
L119:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	28(%esp), %eax
	movl	12(%eax), %eax
	movl	%eax, 28(%esp)
	testl	%eax, %eax
	jne	L126
L81:
	movl	84(%esp), %eax
	movl	(%eax), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %ebx
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%ebx,%eax), %esi
	testl	%esi, %esi
	je	L144
	cmpb	$0, 28(%esi)
	je	L122
	movb	39(%esi), %al
L123:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	84(%esp), %eax
	movl	12(%eax), %eax
	movl	%eax, 84(%esp)
	testl	%eax, %eax
	jne	L125
L79:
	addl	$60, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 12
	.cfi_restore 6
	popl	%edi
	.cfi_def_cfa_offset 8
	.cfi_restore 7
	popl	%ebp
	.cfi_def_cfa_offset 4
	.cfi_restore 5
	ret
	.p2align 2,,3
L94:
	.cfi_restore_state
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L95
L98:
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L99
L144:
	call	__ZSt16__throw_bad_castv
L102:
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L103
L106:
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L107
L118:
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L119
L122:
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L123
L110:
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L111
L114:
	movl	%esi, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	$10, 4(%esp)
	movl	%esi, (%esp)
	call	*24(%eax)
	jmp	L115
	.cfi_endproc
LFE1281:
	.section	.text$_ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE,"x"
	.linkonce discard
	.align 2
	.p2align 2,,3
	.globl	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	.def	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE:
LFB1284:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	64(%esp), %ebx
	movl	68(%esp), %esi
	testl	%esi, %esi
	je	L146
	movl	8(%esi), %edi
	testl	%edi, %edi
	je	L148
	movl	8(%edi), %ebp
	testl	%ebp, %ebp
	je	L149
	movl	8(%ebp), %eax
	testl	%eax, %eax
	je	L150
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L151
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L151:
	movl	12(%eax), %edx
	testl	%edx, %edx
	je	L152
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L152:
	movl	%eax, (%esp)
	call	__ZdlPv
L150:
	movl	12(%ebp), %eax
	testl	%eax, %eax
	je	L153
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L154
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L154:
	movl	12(%eax), %edx
	testl	%edx, %edx
	je	L155
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L155:
	movl	%eax, (%esp)
	call	__ZdlPv
L153:
	movl	%ebp, (%esp)
	call	__ZdlPv
L149:
	movl	12(%edi), %ebp
	testl	%ebp, %ebp
	je	L156
	movl	8(%ebp), %eax
	movl	%eax, 28(%esp)
	testl	%eax, %eax
	je	L157
	movl	8(%eax), %eax
	testl	%eax, %eax
	je	L158
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L159
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L159:
	movl	12(%eax), %edx
	testl	%edx, %edx
	je	L160
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L160:
	movl	%eax, (%esp)
	call	__ZdlPv
L158:
	movl	28(%esp), %edx
	movl	12(%edx), %eax
	testl	%eax, %eax
	je	L161
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L162
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L162:
	movl	12(%eax), %edx
	testl	%edx, %edx
	je	L163
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L163:
	movl	%eax, (%esp)
	call	__ZdlPv
L161:
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L157:
	movl	12(%ebp), %edx
	movl	%edx, 28(%esp)
	testl	%edx, %edx
	je	L164
	movl	8(%edx), %eax
	testl	%eax, %eax
	je	L165
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L166
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L166:
	movl	12(%eax), %edx
	testl	%edx, %edx
	je	L167
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L167:
	movl	%eax, (%esp)
	call	__ZdlPv
L165:
	movl	28(%esp), %edx
	movl	12(%edx), %eax
	testl	%eax, %eax
	je	L168
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L169
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L169:
	movl	12(%eax), %edx
	testl	%edx, %edx
	je	L170
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L170:
	movl	%eax, (%esp)
	call	__ZdlPv
L168:
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L164:
	movl	%ebp, (%esp)
	call	__ZdlPv
L156:
	movl	%edi, (%esp)
	call	__ZdlPv
L148:
	movl	12(%esi), %edi
	testl	%edi, %edi
	je	L171
	movl	8(%edi), %ebp
	testl	%ebp, %ebp
	je	L172
	movl	8(%ebp), %edx
	movl	%edx, 28(%esp)
	testl	%edx, %edx
	je	L173
	movl	8(%edx), %eax
	testl	%eax, %eax
	je	L174
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L175
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L175:
	movl	12(%eax), %edx
	testl	%edx, %edx
	je	L176
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L176:
	movl	%eax, (%esp)
	call	__ZdlPv
L174:
	movl	28(%esp), %edx
	movl	12(%edx), %eax
	testl	%eax, %eax
	je	L177
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L178
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L178:
	movl	12(%eax), %edx
	testl	%edx, %edx
	je	L179
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L179:
	movl	%eax, (%esp)
	call	__ZdlPv
L177:
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L173:
	movl	12(%ebp), %edx
	movl	%edx, 28(%esp)
	testl	%edx, %edx
	je	L180
	movl	8(%edx), %eax
	testl	%eax, %eax
	je	L181
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L182
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L182:
	movl	12(%eax), %edx
	testl	%edx, %edx
	je	L183
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L183:
	movl	%eax, (%esp)
	call	__ZdlPv
L181:
	movl	28(%esp), %edx
	movl	12(%edx), %eax
	testl	%eax, %eax
	je	L184
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L185
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L185:
	movl	12(%eax), %edx
	testl	%edx, %edx
	je	L186
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L186:
	movl	%eax, (%esp)
	call	__ZdlPv
L184:
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L180:
	movl	%ebp, (%esp)
	call	__ZdlPv
L172:
	movl	12(%edi), %ebp
	testl	%ebp, %ebp
	je	L187
	movl	8(%ebp), %edx
	movl	%edx, 28(%esp)
	testl	%edx, %edx
	je	L188
	movl	8(%edx), %eax
	testl	%eax, %eax
	je	L189
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L190
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L190:
	movl	12(%eax), %edx
	testl	%edx, %edx
	je	L191
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L191:
	movl	%eax, (%esp)
	call	__ZdlPv
L189:
	movl	28(%esp), %edx
	movl	12(%edx), %eax
	testl	%eax, %eax
	je	L192
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L193
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L193:
	movl	12(%eax), %edx
	testl	%edx, %edx
	je	L194
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L194:
	movl	%eax, (%esp)
	call	__ZdlPv
L192:
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L188:
	movl	12(%ebp), %edx
	movl	%edx, 28(%esp)
	testl	%edx, %edx
	je	L195
	movl	8(%edx), %eax
	testl	%eax, %eax
	je	L196
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L197
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L197:
	movl	12(%eax), %edx
	testl	%edx, %edx
	je	L198
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L198:
	movl	%eax, (%esp)
	call	__ZdlPv
L196:
	movl	28(%esp), %edx
	movl	12(%edx), %eax
	testl	%eax, %eax
	je	L199
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L200
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L200:
	movl	12(%eax), %edx
	testl	%edx, %edx
	je	L201
	movl	8(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	12(%edx), %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	24(%esp), %edx
	movl	%edx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
L201:
	movl	%eax, (%esp)
	call	__ZdlPv
L199:
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L195:
	movl	%ebp, (%esp)
	call	__ZdlPv
L187:
	movl	%edi, (%esp)
	call	__ZdlPv
L171:
	movl	%esi, 64(%esp)
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 12
	.cfi_restore 6
	popl	%edi
	.cfi_def_cfa_offset 8
	.cfi_restore 7
	popl	%ebp
	.cfi_def_cfa_offset 4
	.cfi_restore 5
	jmp	__ZdlPv
	.p2align 2,,3
L146:
	.cfi_restore_state
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 12
	.cfi_restore 6
	popl	%edi
	.cfi_def_cfa_offset 8
	.cfi_restore 7
	popl	%ebp
	.cfi_def_cfa_offset 4
	.cfi_restore 5
	ret
	.cfi_endproc
LFE1284:
	.section	.text$_ZN16BinarySearchTreeIiE10deletehardERP10BinaryNodeIiE,"x"
	.linkonce discard
	.align 2
	.p2align 2,,3
	.globl	__ZN16BinarySearchTreeIiE10deletehardERP10BinaryNodeIiE
	.def	__ZN16BinarySearchTreeIiE10deletehardERP10BinaryNodeIiE;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE10deletehardERP10BinaryNodeIiE:
LFB1291:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	20(%esp), %edi
	movl	(%edi), %ebx
	movl	8(%ebx), %eax
	testl	%eax, %eax
	je	L212
	movl	12(%ebx), %ecx
	testl	%ecx, %ecx
	je	L217
	movl	8(%ecx), %eax
	testl	%eax, %eax
	jne	L216
	jmp	L218
	.p2align 2,,3
L214:
	movl	%eax, %ecx
	movl	%edx, %eax
L216:
	addl	$8, %ecx
	movl	8(%eax), %edx
	testl	%edx, %edx
	jne	L214
	movl	%eax, %edx
	movl	%ecx, %edi
L208:
	movl	(%eax), %esi
	movl	%esi, (%ebx)
	movl	4(%eax), %eax
	movl	%eax, 4(%ebx)
	movl	8(%edx), %ecx
	testl	%ecx, %ecx
	je	L203
	movl	12(%edx), %ecx
	testl	%ecx, %ecx
	je	L219
	movl	%edx, %ebx
	movl	8(%ecx), %eax
	testl	%eax, %eax
	jne	L216
L218:
	movl	%ecx, %edx
	movl	%ecx, %eax
	leal	12(%ebx), %edi
	jmp	L208
L212:
	movl	%ebx, %edx
	.p2align 2,,3
L203:
	movl	12(%edx), %eax
L211:
	movl	%eax, (%edi)
	movl	%edx, 16(%esp)
	popl	%ebx
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 8
	.cfi_restore 6
	popl	%edi
	.cfi_def_cfa_offset 4
	.cfi_restore 7
	jmp	__ZdlPv
	.p2align 2,,3
L219:
	.cfi_restore_state
	xorl	%eax, %eax
	movl	%eax, (%edi)
	movl	%edx, 16(%esp)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	jmp	__ZdlPv
L217:
	.cfi_restore_state
	movl	%ebx, %edx
	jmp	L211
	.cfi_endproc
LFE1291:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC2:
	.ascii "Insertions:\0"
LC3:
	.ascii "\11---\0"
LC4:
	.ascii "Deletions:\0"
	.section	.text.startup,"x"
	.p2align 2,,3
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1259:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1259
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$64, %esp
	.cfi_offset 3, -20
	.cfi_offset 6, -16
	.cfi_offset 7, -12
	call	___main
	movl	$0, 40(%esp)
	movb	$0, 44(%esp)
	movl	$-11, 48(%esp)
	movl	$-3, 52(%esp)
	leal	56(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	leal	40(%esp), %eax
	movl	%eax, 28(%esp)
LEHB0:
	call	__ZNSirsERi
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	leal	40(%esp), %eax
	movl	%eax, 28(%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, (%esp)
	leal	40(%esp), %eax
	movl	%eax, 28(%esp)
	call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movl	56(%esp), %eax
	movl	%eax, 24(%esp)
	leal	40(%esp), %eax
	movl	%eax, 28(%esp)
	movl	24(%esp), %esi
	testl	%esi, %esi
	je	L274
	.p2align 2,,3
L237:
	leal	60(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZNSirsERi
	movl	60(%esp), %edx
	movl	28(%esp), %ebx
	.p2align 2,,3
L270:
	movl	(%ebx), %eax
	testl	%eax, %eax
	je	L275
L223:
	cmpl	(%eax), %edx
	jge	L226
	leal	8(%eax), %ebx
	movl	(%ebx), %eax
	testl	%eax, %eax
	jne	L223
L275:
	movl	$16, (%esp)
	call	__Znwj
	movl	60(%esp), %edx
	movl	%edx, (%eax)
	movl	$1, 4(%eax)
	movl	$0, 8(%eax)
	movl	$0, 12(%eax)
	movl	%eax, (%ebx)
	cmpb	$0, 44(%esp)
	jne	L224
L225:
	movl	40(%esp), %esi
	testl	%esi, %esi
	jne	L267
	jmp	L229
	.p2align 2,,3
L277:
	movb	39(%ebx), %al
L232:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	12(%esi), %esi
	testl	%esi, %esi
	je	L229
L267:
	movl	8(%esi), %eax
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE41printtraversalinorderduplicatesnotallowedEP10BinaryNodeIiE
	movl	(%esi), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %edi
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%edi,%eax), %ebx
	testl	%ebx, %ebx
	je	L276
	cmpb	$0, 28(%ebx)
	jne	L277
	movl	%ebx, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	$10, 4(%esp)
	movl	%ebx, (%esp)
	call	*24(%eax)
	jmp	L232
	.p2align 2,,3
L226:
	jle	L228
	leal	12(%eax), %ebx
	jmp	L270
	.p2align 2,,3
L228:
	cmpb	$0, 44(%esp)
	je	L225
	incl	4(%eax)
L224:
	movl	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE38printtraversalinorderduplicatesallowedEP10BinaryNodeIiE
L229:
	movl	$4, 8(%esp)
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	__ZSt4cout, %eax
	movl	-12(%eax), %eax
	movl	__ZSt4cout+124(%eax), %ebx
	testl	%ebx, %ebx
	je	L278
	cmpb	$0, 28(%ebx)
	je	L235
	movb	39(%ebx), %al
L236:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	decl	24(%esp)
	movl	24(%esp), %esi
	testl	%esi, %esi
	jne	L237
L274:
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, (%esp)
	call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, (%esp)
	call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movl	$LC4, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, (%esp)
	call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movl	56(%esp), %eax
	movl	%eax, 24(%esp)
	movl	24(%esp), %ebx
	testl	%ebx, %ebx
	je	L279
	.p2align 2,,3
L261:
	leal	60(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZNSirsERi
	movl	60(%esp), %ecx
	movl	28(%esp), %edx
	.p2align 2,,3
L271:
	movl	(%edx), %eax
	testl	%eax, %eax
	je	L273
L240:
	cmpl	(%eax), %ecx
	jge	L242
	leal	8(%eax), %edx
	movl	(%edx), %eax
	testl	%eax, %eax
	jne	L240
L273:
	movb	44(%esp), %al
	testb	%al, %al
	jne	L246
	movl	40(%esp), %esi
	testl	%esi, %esi
	jne	L266
	jmp	L248
	.p2align 2,,3
L281:
	movb	39(%ebx), %al
L256:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	movl	12(%esi), %esi
	testl	%esi, %esi
	je	L248
L266:
	movl	8(%esi), %eax
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE41printtraversalinorderduplicatesnotallowedEP10BinaryNodeIiE
	movl	(%esi), %ebx
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %edi
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%edi,%eax), %ebx
	testl	%ebx, %ebx
	je	L280
	cmpb	$0, 28(%ebx)
	jne	L281
	movl	%ebx, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	$10, 4(%esp)
	movl	%ebx, (%esp)
	call	*24(%eax)
	jmp	L256
	.p2align 2,,3
L235:
	movl	%ebx, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	$10, 4(%esp)
	movl	%ebx, (%esp)
	call	*24(%eax)
	jmp	L236
	.p2align 2,,3
L242:
	jle	L244
	leal	12(%eax), %edx
	jmp	L271
	.p2align 2,,3
L248:
	movl	$4, 8(%esp)
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	__ZSt4cout, %eax
	movl	-12(%eax), %eax
	movl	__ZSt4cout+124(%eax), %ebx
	testl	%ebx, %ebx
	je	L282
	cmpb	$0, 28(%ebx)
	je	L259
	movb	39(%ebx), %al
L260:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
	decl	24(%esp)
	movl	24(%esp), %ebx
	testl	%ebx, %ebx
	jne	L261
L279:
	movl	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	xorl	%eax, %eax
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.p2align 2,,3
L244:
	.cfi_restore_state
	cmpb	$0, 44(%esp)
	je	L245
	movl	4(%eax), %ecx
	cmpl	$1, %ecx
	jle	L245
	decl	%ecx
	movl	%ecx, 4(%eax)
	.p2align 2,,3
L246:
	movl	40(%esp), %esi
	testl	%esi, %esi
	jne	L272
	jmp	L248
	.p2align 2,,3
L284:
	movb	39(%ebx), %al
L252:
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	__ZNSo3putEc
	movl	%eax, (%esp)
	call	__ZNSo5flushEv
L249:
	movl	12(%esi), %esi
	testl	%esi, %esi
	je	L248
L272:
	movl	8(%esi), %eax
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE38printtraversalinorderduplicatesallowedEP10BinaryNodeIiE
	movl	4(%esi), %ebx
	testl	%ebx, %ebx
	jle	L249
	movl	(%esi), %edi
	movl	$1, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%edi, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	%eax, %edi
	movl	$3, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	call	__ZNSolsEi
	movl	%eax, %edi
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%edi,%eax), %ebx
	testl	%ebx, %ebx
	je	L283
	cmpb	$0, 28(%ebx)
	jne	L284
	movl	%ebx, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	$10, 4(%esp)
	movl	%ebx, (%esp)
	call	*24(%eax)
	jmp	L252
	.p2align 2,,3
L259:
	movl	%ebx, (%esp)
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	$10, 4(%esp)
	movl	%ebx, (%esp)
	call	*24(%eax)
	jmp	L260
	.p2align 2,,3
L245:
	movl	%edx, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE10deletehardERP10BinaryNodeIiE
	jmp	L273
L276:
	call	__ZSt16__throw_bad_castv
LEHE0:
L265:
	movl	%eax, %ebx
	movl	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	%ebx, (%esp)
LEHB1:
	call	__Unwind_Resume
LEHE1:
L280:
LEHB2:
	call	__ZSt16__throw_bad_castv
L282:
	call	__ZSt16__throw_bad_castv
L283:
	call	__ZSt16__throw_bad_castv
L278:
	call	__ZSt16__throw_bad_castv
LEHE2:
	.cfi_endproc
LFE1259:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA1259:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1259-LLSDACSB1259
LLSDACSB1259:
	.uleb128 LEHB0-LFB1259
	.uleb128 LEHE0-LEHB0
	.uleb128 L265-LFB1259
	.uleb128 0
	.uleb128 LEHB1-LFB1259
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB2-LFB1259
	.uleb128 LEHE2-LEHB2
	.uleb128 L265-LFB1259
	.uleb128 0
LLSDACSE1259:
	.section	.text.startup,"x"
	.p2align 2,,3
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
LFB1296:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE1296:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
.lcomm __ZStL8__ioinit,1,1
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	__ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
