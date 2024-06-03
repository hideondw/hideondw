.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo

    movl $0, -4(%ebp);
    movl 8(%ebp), %eax;
    xorl %ebx, %ebx;
for1:
    cmpl $3, %ebx;
    jge endfor1;
    xorl %ecx, %ecx;
for2:
    cmpl $3, %ecx;
    jge endfor2;
    imul $3, %ebx, %edx;
    addl %ebx, %edx;
    movl (%eax, %edx, 4), %edx;
    addl %ecx, %edx;
    subl %edx, -4(%ebp)
    incl %ecx;
    jmp for2;
endfor2:
    addl 12(%ebp), %ebx;
    jmp for1;
endfor1:

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx	
	movl %ebp,%esp
	popl %ebp
	ret
