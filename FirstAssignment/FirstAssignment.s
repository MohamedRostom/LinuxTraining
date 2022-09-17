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
	pushq	%rbx
	subq	$1032, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$1953069157, -1029(%rbp)
	movb	$0, -1025(%rbp)
	movl	$0, -1036(%rbp)
.L4:
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	stdin(%rip), %rdx
	leaq	-1024(%rbp), %rax
	movl	$1000, %esi
	movq	%rax, %rdi
	call	fgets@PLT
	leaq	-1024(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-1024(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rbx
	leaq	-1029(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	addq	$1, %rax
	cmpq	%rax, %rbx
	jne	.L4
	movzbl	-1024(%rbp), %edx
	movzbl	-1029(%rbp), %eax
	cmpb	%al, %dl
	jne	.L4
	movzbl	-1023(%rbp), %edx
	movzbl	-1028(%rbp), %eax
	cmpb	%al, %dl
	jne	.L4
	movzbl	-1022(%rbp), %edx
	movzbl	-1027(%rbp), %eax
	cmpb	%al, %dl
	jne	.L4
	movzbl	-1021(%rbp), %edx
	movzbl	-1026(%rbp), %eax
	cmpb	%al, %dl
	jne	.L4
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	addq	$1032, %rsp
	popq	%rbx
	popq	%rbp
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
