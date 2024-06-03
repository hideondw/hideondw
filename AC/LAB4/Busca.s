 .text
	.align 4
	.globl Buscar
	.type Buscar,@function
Buscar: 	
		pushl %ebp
		movl %esp, %ebp
		subl $16, %esp
		pushl %ebx
		pushl %esi
		# inici de la subrutina
	
		movl $-1, -4(%ebp)		# trobat <- -1
		movl $0, -16(%ebp)		# low = 0

		movl $0, -8(%ebp)		# mid = 0
		movl 24(%ebp), %ebx		# ecx <- N
		decl %ebx 			# ecx <- N - 1
		movl %ebx, -12(%ebp)		# high <- N - 1

while: 	
		movl -16(%ebp), %esi	
		cmpl -12(%ebp), %esi		# low < high ?
		jg end_while
		pushl 8(%ebp)			# v[]
		pushl 20(%ebp)			# X.m
		pushl 16(%ebp)			# X.k
		pushl 12(%ebp)			# X.c
		leal -8(%ebp), %eax 	# eax <- mid
		pushl %eax			# &mid
		leal -12(%ebp), %eax 		# eax <- high
		pushl %eax 			# &high
		leal -16(%ebp), %eax 		# eax <- low
		pushl %eax			# &low
		call BuscarElemento
		addl $28, %esp
		movl %eax, -4(%ebp)		# trobat <- eax
if: 		
		cmpl $0, %eax		# trobat < 0 ?
		jl while

end_while: 	
		movl -4(%ebp), %eax 		# eax <- trobat

		# final de la subrutina
end: 	popl %esi
		popl %ebx
		movl %ebp, %esp
		popl %ebp
		ret	
