	.file	"testBST.cpp"
.lcomm __ZStL8__ioinit,1,1
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Insertions:\0"
LC1:
	.ascii "\11---\0"
LC2:
	.ascii "Deletions:\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1223:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1223
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	andl	$-16, %esp
	subl	$48, %esp
	.cfi_offset 3, -12
	call	___main
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiEC1Ev
	leal	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
LEHB0:
	call	__ZNSirsERi
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	40(%esp), %eax
	movl	%eax, 44(%esp)
	jmp	L2
L3:
	leal	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZNSirsERi
	leal	36(%esp), %eax
	movl	%eax, 4(%esp)
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE6insertERKi
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE21printtraversalinorderEv
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
L2:
	cmpl	$0, 44(%esp)
	setne	%al
	decl	44(%esp)
	testb	%al, %al
	jne	L3
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	40(%esp), %eax
	movl	%eax, 44(%esp)
	jmp	L4
L5:
	leal	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZNSirsERi
	movl	$1, 8(%esp)
	leal	36(%esp), %eax
	movl	%eax, 4(%esp)
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE6removeERKi12REMOVEMETHOD
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE21printtraversalinorderEv
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
LEHE0:
L4:
	cmpl	$0, 44(%esp)
	setne	%al
	decl	44(%esp)
	testb	%al, %al
	jne	L5
	movl	$0, %ebx
	leal	20(%esp), %eax
	movl	%eax, (%esp)
LEHB1:
	call	__ZN16BinarySearchTreeIiED1Ev
LEHE1:
	movl	%ebx, %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_remember_state
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	.cfi_restore 3
	ret
L7:
	.cfi_restore_state
	movl	%eax, %ebx
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB2:
	call	__Unwind_Resume
LEHE2:
	.cfi_endproc
LFE1223:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA1223:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1223-LLSDACSB1223
LLSDACSB1223:
	.uleb128 LEHB0-LFB1223
	.uleb128 LEHE0-LEHB0
	.uleb128 L7-LFB1223
	.uleb128 0
	.uleb128 LEHB1-LFB1223
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB2-LFB1223
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
LLSDACSE1223:
	.text
	.section	.text$_ZN16BinarySearchTreeIiEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16BinarySearchTreeIiEC1Ev
	.def	__ZN16BinarySearchTreeIiEC1Ev;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiEC1Ev:
LFB1227:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	8(%ebp), %eax
	movb	$0, 4(%eax)
	movl	8(%ebp), %eax
	movl	$-11, 8(%eax)
	movl	8(%ebp), %eax
	movl	$-3, 12(%eax)
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
LFE1227:
	.section	.text$_ZN16BinarySearchTreeIiED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16BinarySearchTreeIiED1Ev
	.def	__ZN16BinarySearchTreeIiED1Ev;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiED1Ev:
LFB1230:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1230:
	.section	.text$_ZN16BinarySearchTreeIiE6insertERKi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16BinarySearchTreeIiE6insertERKi
	.def	__ZN16BinarySearchTreeIiE6insertERKi;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE6insertERKi:
LFB1234:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE6insertERP10BinaryNodeIiERKi
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1234:
	.section	.text$_ZN16BinarySearchTreeIiE21printtraversalinorderEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16BinarySearchTreeIiE21printtraversalinorderEv
	.def	__ZN16BinarySearchTreeIiE21printtraversalinorderEv;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE21printtraversalinorderEv:
LFB1235:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movb	4(%eax), %al
	testb	%al, %al
	je	L13
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE38printtraversalinorderduplicatesallowedEP10BinaryNodeIiE
	jmp	L12
L13:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE41printtraversalinorderduplicatesnotallowedEP10BinaryNodeIiE
L12:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1235:
	.section	.text$_ZN16BinarySearchTreeIiE6removeERKi12REMOVEMETHOD,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16BinarySearchTreeIiE6removeERKi12REMOVEMETHOD
	.def	__ZN16BinarySearchTreeIiE6removeERKi12REMOVEMETHOD;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE6removeERKi12REMOVEMETHOD:
LFB1236:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE6removeERP10BinaryNodeIiERKi12REMOVEMETHOD
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1236:
	.section	.text$_ZN16BinarySearchTreeIiE9makeemptyEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16BinarySearchTreeIiE9makeemptyEv
	.def	__ZN16BinarySearchTreeIiE9makeemptyEv;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE9makeemptyEv:
LFB1239:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1239:
	.section	.text$_ZN16BinarySearchTreeIiE6insertERP10BinaryNodeIiERKi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16BinarySearchTreeIiE6insertERP10BinaryNodeIiERKi
	.def	__ZN16BinarySearchTreeIiE6insertERP10BinaryNodeIiERKi;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE6insertERP10BinaryNodeIiERKi:
LFB1243:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L18
	.cfi_offset 3, -12
	movl	$16, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$1, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN10BinaryNodeIiEC1EiiPS0_S1_
	movl	12(%ebp), %eax
	movl	%ebx, (%eax)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	jmp	L19
L18:
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jge	L20
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	8(%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE6insertERP10BinaryNodeIiERKi
	jmp	L19
L20:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jge	L21
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	12(%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE6insertERP10BinaryNodeIiERKi
	jmp	L19
L21:
	movl	8(%ebp), %eax
	movb	4(%eax), %al
	testb	%al, %al
	je	L22
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	4(%eax), %edx
	incl	%edx
	movl	%edx, 4(%eax)
L22:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
L19:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
LFE1243:
	.section .rdata,"dr"
LC3:
	.ascii "\11\0"
LC4:
	.ascii "\11x\11\0"
	.section	.text$_ZN16BinarySearchTreeIiE38printtraversalinorderduplicatesallowedEP10BinaryNodeIiE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16BinarySearchTreeIiE38printtraversalinorderduplicatesallowedEP10BinaryNodeIiE
	.def	__ZN16BinarySearchTreeIiE38printtraversalinorderduplicatesallowedEP10BinaryNodeIiE;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE38printtraversalinorderduplicatesallowedEP10BinaryNodeIiE:
LFB1244:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	cmpl	$0, 12(%ebp)
	je	L27
	.cfi_offset 3, -16
	.cfi_offset 6, -12
L24:
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE38printtraversalinorderduplicatesallowedEP10BinaryNodeIiE
	movl	12(%ebp), %eax
	movl	4(%eax), %eax
	testl	%eax, %eax
	jle	L26
	movl	12(%ebp), %eax
	movl	4(%eax), %ebx
	movl	12(%ebp), %eax
	movl	(%eax), %esi
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$LC4, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
L26:
	movl	12(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE38printtraversalinorderduplicatesallowedEP10BinaryNodeIiE
	jmp	L23
L27:
	nop
L23:
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
LFE1244:
	.section	.text$_ZN16BinarySearchTreeIiE41printtraversalinorderduplicatesnotallowedEP10BinaryNodeIiE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16BinarySearchTreeIiE41printtraversalinorderduplicatesnotallowedEP10BinaryNodeIiE
	.def	__ZN16BinarySearchTreeIiE41printtraversalinorderduplicatesnotallowedEP10BinaryNodeIiE;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE41printtraversalinorderduplicatesnotallowedEP10BinaryNodeIiE:
LFB1245:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	cmpl	$0, 12(%ebp)
	je	L31
	.cfi_offset 3, -12
L29:
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE41printtraversalinorderduplicatesnotallowedEP10BinaryNodeIiE
	movl	12(%ebp), %eax
	movl	(%eax), %ebx
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	12(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE41printtraversalinorderduplicatesnotallowedEP10BinaryNodeIiE
	jmp	L28
L31:
	nop
L28:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
LFE1245:
	.section	.text$_ZN16BinarySearchTreeIiE6removeERP10BinaryNodeIiERKi12REMOVEMETHOD,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16BinarySearchTreeIiE6removeERP10BinaryNodeIiERKi12REMOVEMETHOD
	.def	__ZN16BinarySearchTreeIiE6removeERP10BinaryNodeIiERKi12REMOVEMETHOD;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE6removeERP10BinaryNodeIiERKi12REMOVEMETHOD:
LFB1246:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L40
L33:
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jge	L35
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	8(%eax), %edx
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE6removeERP10BinaryNodeIiERKi12REMOVEMETHOD
	jmp	L32
L35:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jge	L36
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	12(%eax), %edx
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE6removeERP10BinaryNodeIiERKi12REMOVEMETHOD
	jmp	L32
L36:
	movl	8(%ebp), %eax
	movb	4(%eax), %al
	testb	%al, %al
	je	L37
	cmpl	$0, 20(%ebp)
	jne	L37
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	jle	L37
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE10deletelazyERP10BinaryNodeIiE
	jmp	L32
L37:
	movl	8(%ebp), %eax
	movb	4(%eax), %al
	testb	%al, %al
	je	L38
	cmpl	$1, 20(%ebp)
	jne	L38
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	4(%eax), %eax
	cmpl	$1, %eax
	jle	L38
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE10deletelazyERP10BinaryNodeIiE
	jmp	L32
L38:
	movl	8(%ebp), %eax
	movb	4(%eax), %al
	xorl	$1, %eax
	testb	%al, %al
	je	L39
	cmpl	$0, 20(%ebp)
	jne	L39
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	cmpl	%eax, %edx
	jle	L39
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE10deletelazyERP10BinaryNodeIiE
	jmp	L32
L39:
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE10deletehardERP10BinaryNodeIiE
	jmp	L32
L40:
	nop
L32:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1246:
	.section	.text$_ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	.def	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE:
LFB1248:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	je	L42
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	12(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE9makeemptyEP10BinaryNodeIiE
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L42:
	movl	$0, 12(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1248:
	.section	.text$_ZN10BinaryNodeIiEC1EiiPS0_S1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10BinaryNodeIiEC1EiiPS0_S1_
	.def	__ZN10BinaryNodeIiEC1EiiPS0_S1_;	.scl	2;	.type	32;	.endef
__ZN10BinaryNodeIiEC1EiiPS0_S1_:
LFB1253:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	20(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	24(%ebp), %edx
	movl	%edx, 12(%eax)
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
LFE1253:
	.section	.text$_ZN16BinarySearchTreeIiE10deletelazyERP10BinaryNodeIiE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16BinarySearchTreeIiE10deletelazyERP10BinaryNodeIiE
	.def	__ZN16BinarySearchTreeIiE10deletelazyERP10BinaryNodeIiE;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE10deletelazyERP10BinaryNodeIiE:
LFB1254:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	4(%eax), %edx
	decl	%edx
	movl	%edx, 4(%eax)
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
LFE1254:
	.section	.text$_ZN16BinarySearchTreeIiE10deletehardERP10BinaryNodeIiE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16BinarySearchTreeIiE10deletehardERP10BinaryNodeIiE
	.def	__ZN16BinarySearchTreeIiE10deletehardERP10BinaryNodeIiE;	.scl	2;	.type	32;	.endef
__ZN16BinarySearchTreeIiE10deletehardERP10BinaryNodeIiE:
LFB1255:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN10BinaryNodeIiE10isfullnodeEv
	testb	%al, %al
	je	L46
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$12, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK16BinarySearchTreeIiE17findminbinarynodeERP10BinaryNodeIiE
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	movl	(%edx), %edx
	movl	(%edx), %edx
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	movl	(%edx), %edx
	movl	4(%edx), %edx
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16BinarySearchTreeIiE10deletehardERP10BinaryNodeIiE
	jmp	L45
L46:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%eax), %eax
	testl	%eax, %eax
	je	L48
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%eax), %eax
	jmp	L49
L48:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%eax), %eax
L49:
	movl	12(%ebp), %edx
	movl	%eax, (%edx)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L45:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1255:
	.section	.text$_ZN10BinaryNodeIiE10isfullnodeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10BinaryNodeIiE10isfullnodeEv
	.def	__ZN10BinaryNodeIiE10isfullnodeEv;	.scl	2;	.type	32;	.endef
__ZN10BinaryNodeIiE10isfullnodeEv:
LFB1256:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	testl	%eax, %eax
	je	L51
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	testl	%eax, %eax
	je	L51
	movb	$1, %al
	jmp	L52
L51:
	movb	$0, %al
L52:
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
LFE1256:
	.section	.text$_ZNK16BinarySearchTreeIiE17findminbinarynodeERP10BinaryNodeIiE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK16BinarySearchTreeIiE17findminbinarynodeERP10BinaryNodeIiE
	.def	__ZNK16BinarySearchTreeIiE17findminbinarynodeERP10BinaryNodeIiE;	.scl	2;	.type	32;	.endef
__ZNK16BinarySearchTreeIiE17findminbinarynodeERP10BinaryNodeIiE:
LFB1257:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%eax), %eax
	testl	%eax, %eax
	jne	L54
	movl	12(%ebp), %eax
	jmp	L55
L54:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK16BinarySearchTreeIiE17findminbinarynodeERP10BinaryNodeIiE
L55:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1257:
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1259:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1259:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB1258:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L57
	cmpl	$65535, 12(%ebp)
	jne	L57
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L57:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1258:
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
LFB1260:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1260:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
