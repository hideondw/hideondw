.text
	.align 4
	.globl procesar
	.type	procesar, @function
procesar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

# Aqui has de introducir el codigo

	movl 8(%ebp), %eax      #mata
    movl 12(%ebp), %ebx     #matb
    movl 16(%ebp), %ecx     #matc
    movl 20(%ebp), %esi     #n

    imul %esi, %esi
    addl %ecx, %esi

for:
    cmpl %esi, %ecx
    jge fi

    movb (%eax), %dl
    subb (%ebx), %dl
    cmpb $0, %dl
    jle else
    movb $255, (%ecx)
    jmp fi_if

else:
    movb $0, (%ecx)

fi_if:
    incl %eax
    incl %ebx
    incl %ecx

    jmp for
fi:

# El final de la rutina ya esta programado
	popl %edi
	popl %esi
	popl %ebx
	movl %ebp,%esp
	popl %ebp
	ret
	