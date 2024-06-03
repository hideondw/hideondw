.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
# Aqui has de introducir el codigo
    movl 8(%ebp), %eax;     
    movl $1, %ebx;           
for:
    cmpl 12(%ebp), %ebx;    
    jge end;
	movl (%eax, %ebx, 4), %ecx;
    cmpl -4(%ebp),%ecx; 
    jge endif;
    movl %ecx, -4(%ebp); 
endif:
    incl %ebx;
    jmp for;
end:
# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
