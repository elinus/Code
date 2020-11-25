	.file	"Clazz.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZN6ClazzA3fooEv,"axG",@progbits,_ZN6ClazzA3fooEv,comdat
	.align 2
	.weak	_ZN6ClazzA3fooEv
	.type	_ZN6ClazzA3fooEv, @function
_ZN6ClazzA3fooEv:
.LFB1522:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1522:
	.size	_ZN6ClazzA3fooEv, .-_ZN6ClazzA3fooEv
	.section	.text._ZN6ClazzA3barEv,"axG",@progbits,_ZN6ClazzA3barEv,comdat
	.align 2
	.weak	_ZN6ClazzA3barEv
	.type	_ZN6ClazzA3barEv, @function
_ZN6ClazzA3barEv:
.LFB1523:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1523:
	.size	_ZN6ClazzA3barEv, .-_ZN6ClazzA3barEv
	.section	.text._ZN6ClazzB3fooEv,"axG",@progbits,_ZN6ClazzB3fooEv,comdat
	.align 2
	.weak	_ZN6ClazzB3fooEv
	.type	_ZN6ClazzB3fooEv, @function
_ZN6ClazzB3fooEv:
.LFB1524:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1524:
	.size	_ZN6ClazzB3fooEv, .-_ZN6ClazzB3fooEv
	.section	.text._ZN6ClazzB4fizzEv,"axG",@progbits,_ZN6ClazzB4fizzEv,comdat
	.align 2
	.weak	_ZN6ClazzB4fizzEv
	.type	_ZN6ClazzB4fizzEv, @function
_ZN6ClazzB4fizzEv:
.LFB1525:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1525:
	.size	_ZN6ClazzB4fizzEv, .-_ZN6ClazzB4fizzEv
	.section	.text._ZN6ClazzAC2Ev,"axG",@progbits,_ZN6ClazzAC5Ev,comdat
	.align 2
	.weak	_ZN6ClazzAC2Ev
	.type	_ZN6ClazzAC2Ev, @function
_ZN6ClazzAC2Ev:
.LFB1529:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	leaq	16+_ZTV6ClazzA(%rip), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1529:
	.size	_ZN6ClazzAC2Ev, .-_ZN6ClazzAC2Ev
	.weak	_ZN6ClazzAC1Ev
	.set	_ZN6ClazzAC1Ev,_ZN6ClazzAC2Ev
	.section	.text._ZN6ClazzBC2Ev,"axG",@progbits,_ZN6ClazzBC5Ev,comdat
	.align 2
	.weak	_ZN6ClazzBC2Ev
	.type	_ZN6ClazzBC2Ev, @function
_ZN6ClazzBC2Ev:
.LFB1531:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN6ClazzAC2Ev
	leaq	16+_ZTV6ClazzB(%rip), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1531:
	.size	_ZN6ClazzBC2Ev, .-_ZN6ClazzBC2Ev
	.weak	_ZN6ClazzBC1Ev
	.set	_ZN6ClazzBC1Ev,_ZN6ClazzBC2Ev
	.text
	.globl	main
	.type	main, @function
main:
.LFB1526:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movl	$8, %edi
	call	_Znwm@PLT
	movq	%rax, %rbx
	movq	%rbx, %rdi
	call	_ZN6ClazzBC1Ev
	movq	%rbx, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rdx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	*%rdx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN6ClazzB4fizzEv
	movq	-32(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	*%rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN6ClazzA3barEv
	movl	$0, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1526:
	.size	main, .-main
	.weak	_ZTV6ClazzB
	.section	.data.rel.ro.local._ZTV6ClazzB,"awG",@progbits,_ZTV6ClazzB,comdat
	.align 8
	.type	_ZTV6ClazzB, @object
	.size	_ZTV6ClazzB, 24
_ZTV6ClazzB:
	.quad	0
	.quad	_ZTI6ClazzB
	.quad	_ZN6ClazzB3fooEv
	.weak	_ZTV6ClazzA
	.section	.data.rel.ro.local._ZTV6ClazzA,"awG",@progbits,_ZTV6ClazzA,comdat
	.align 8
	.type	_ZTV6ClazzA, @object
	.size	_ZTV6ClazzA, 24
_ZTV6ClazzA:
	.quad	0
	.quad	_ZTI6ClazzA
	.quad	_ZN6ClazzA3fooEv
	.weak	_ZTI6ClazzB
	.section	.data.rel.ro._ZTI6ClazzB,"awG",@progbits,_ZTI6ClazzB,comdat
	.align 8
	.type	_ZTI6ClazzB, @object
	.size	_ZTI6ClazzB, 24
_ZTI6ClazzB:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS6ClazzB
	.quad	_ZTI6ClazzA
	.weak	_ZTS6ClazzB
	.section	.rodata._ZTS6ClazzB,"aG",@progbits,_ZTS6ClazzB,comdat
	.align 8
	.type	_ZTS6ClazzB, @object
	.size	_ZTS6ClazzB, 8
_ZTS6ClazzB:
	.string	"6ClazzB"
	.weak	_ZTI6ClazzA
	.section	.data.rel.ro._ZTI6ClazzA,"awG",@progbits,_ZTI6ClazzA,comdat
	.align 8
	.type	_ZTI6ClazzA, @object
	.size	_ZTI6ClazzA, 16
_ZTI6ClazzA:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS6ClazzA
	.weak	_ZTS6ClazzA
	.section	.rodata._ZTS6ClazzA,"aG",@progbits,_ZTS6ClazzA,comdat
	.align 8
	.type	_ZTS6ClazzA, @object
	.size	_ZTS6ClazzA, 8
_ZTS6ClazzA:
	.string	"6ClazzA"
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2013:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L11
	cmpl	$65535, -8(%rbp)
	jne	.L11
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L11:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2013:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2014:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2014:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
