%macro printdata 2

	mov eax, 4
	mov ebx, 1
	mov ecx, %1
	mov edx, %2
	int 0x80

%endmacro 

section .data
	
	var db '1'
	arr db 2, 4, 3, 5, 6, 8
	arr1 db -1
	ptr_var db '0'
	trueval db 'negative value'
	tlen equ $-trueval
	falseval db 'positive value'
	flen equ $-falseval		
	
section .bss

section .text
global _start
_start:
	
	mov rbx, 0
	mov rdx, 6
	push rax
	mov eax, [arr1]
 	eax, 1
	pop rax			
	
		
	printloop:
		mov rax, [arr+rbx]
		add rax, '0'
		mov [ptr_var], rax
		push rax
		push rcx
		push rdx
		push rbx
		printdata ptr_var, 1
		pop rbx
		pop rdx
		pop rcx
		pop rax
		inc rbx
		dec rdx
		jnz printloop



	mov eax, 2
	mov ecx, 3
	mov ebx, 5
		
	mov eax, 1
	mov ebx, 0
	int 0x80
