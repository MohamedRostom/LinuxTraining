	.file	"FirstAssignment.c"
	.text
	.section	.rodata
.LC0:
	.string	"Enter your statment : "
.LC1:
	.string	"You said: %s\n"
.LC2:
	.string	"Exiting, Goodbye......... "
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1024, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1953069157, -1013(%rbp)
	movb	$0, -1009(%rbp)
	movl	$0, -1020(%rbp)
.L4:
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	stdin(%rip), %rdx
	leaq	-1008(%rbp), %rax
	movl	$1000, %esi
	movq	%rax, %rdi
	call	fgets@PLT
	leaq	-1008(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movzbl	-1008(%rbp), %edx
	movzbl	-1013(%rbp), %eax
	cmpb	%al, %dl
	jne	.L4
	movzbl	-1007(%rbp), %edx
	movzbl	-1012(%rbp), %eax
	cmpb	%al, %dl
	jne	.L4
	movzbl	-1006(%rbp), %edx
	movzbl	-1011(%rbp), %eax
	cmpb	%al, %dl
	jne	.L4
	movzbl	-1005(%rbp), %edx
	movzbl	-1010(%rbp), %eax
	cmpb	%al, %dl
	jne	.L4
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
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
