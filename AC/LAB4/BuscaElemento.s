 .text
	.align 4
	.globl BuscarElemento
	.type BuscarElemento,@function
BuscarElemento:
        # Aqui viene vuestro codigo
		pushl %ebp
		movl %esp, %ebp
		pushl %ebx			# registre aux
		pushl %esi 			# registre aux
		# inici de la funcio

 		movl 16(%ebp), %eax		# eax <- &mid
		movl (%eax), %eax		# eax <- *mid
		movl 32(%ebp), %ebx		# ebx <- @v[]
		imul $12, %eax, %esi	#el principal problema era esta multiplicacion
		movl 4(%ebx,%esi), %ebx	# ebx <- v[*mid].k
if: 	cmpl 24(%ebp), %ebx		# ebx < X.k
		jne else
		# res a fer
		jmp end_if
else: 		
		movl 16(%ebp), %esi		# esi <- &mid
		movl 12(%ebp), %ebx		# ebx <- &high
		movl (%ebx), %ebx		# ebx <- *high
if2: 		cmpl %ebx, (%esi)			# *mid < *high ? 
		jge else2
		movl %ebx, (%esi)		# *mid <- *high
		movl 8(%ebp), %eax		# eax <- &low
		incl (%eax)			# *low <- *low + 1
		jmp end_if2
else2:		movl 8(%ebp), %eax		# eax <- &low 
		movl (%eax), %eax 		# eax <- *low
		movl %eax, (%esi)		# *mid <- *low
		movl 12(%ebp), %eax		# eax <- &high
		decl (%eax)			# *high <- *high - 1
end_if2:	movl $-1, %eax
end_if:
		# final de la funcio
		popl %esi
		popl %ebx
		movl %ebp, %esp
		popl %ebp
		ret
		