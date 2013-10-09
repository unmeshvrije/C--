	.file	"void_ptr.c"
	.section	.rodata
.LC0:
	.string	"%x"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	movl	$-1430532899, 28(%esp)
	movl	$287454020, 32(%esp)
	leal	28(%esp), %eax
	movl	%eax, 36(%esp)
	addl	$1, 36(%esp)
	movl	36(%esp), %eax
	movl	%eax, 40(%esp)
	movl	40(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 44(%esp)
	movl	$.LC0, %eax
	movl	44(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
