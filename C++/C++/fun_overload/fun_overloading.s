	.file	"fun_overloading.cpp"
	.text
.globl _Z3Addii
	.type	_Z3Addii, @function
_Z3Addii:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	leal	(%edx,%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	_Z3Addii, .-_Z3Addii
.globl _Z3Addff
	.type	_Z3Addff, @function
_Z3Addff:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	flds	8(%ebp)
	fadds	12(%ebp)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	_Z3Addff, .-_Z3Addff
.globl _Z3Adddif
	.type	_Z3Adddif, @function
_Z3Adddif:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	flds	20(%ebp)
	faddl	-8(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	_Z3Adddif, .-_Z3Adddif
.globl main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$7, -4(%ebp)
	movl	$67, -8(%ebp)
	movl	$0x40e77cee, %eax
	movl	%eax, -12(%ebp)
	movl	$0x41bd999a, %eax
	movl	%eax, -16(%ebp)
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (SUSE Linux) 4.5.0 20100604 [gcc-4_5-branch revision 160292]"
	.section	.comment.SUSE.OPTs,"MS",@progbits,1
	.string	"ospwg"
	.section	.note.GNU-stack,"",@progbits
