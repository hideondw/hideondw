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
    movl 24(%ebp), %edi     #si esta aligned o no

    imul %esi, %esi
    addl %ecx, %esi
    cmp $0, %edi
    jne for_aligned

for:
    cmpl %esi, %ecx
    jge fi

    movdqu (%eax), %xmm0
    movdqu (%ebx), %xmm1

    pcmpgtb %xmm1, %xmm0    #mirar si esta bien hacer solo la comparacion i no restar

    movdqu %xmm0, (%ecx)

    addl $16, %eax
    addl $16, %ebx
    addl $16, %ecx

    jmp for

for_aligned:
    cmpl %esi, %ecx
    jge fi

    movdqa (%eax), %xmm0
    movdqa (%ebx), %xmm1

    pcmpgtb %xmm1, %xmm0    #mirar si esta bien hacer solo la comparacion i no restar

    movdqa %xmm0, (%ecx)

    addl $16, %eax
    addl $16, %ebx
    addl $16, %ecx

    jmp for_aligned

fi:

# El final de la rutina ya esta programado

	emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
