%macro addbyte 3
	; first is memory location to output
	; second is the memory location of the string
	; third parameter is the base of the number
	mov 	eax, [%1]
	mov di, 0
%%loopagain:
	mov edx, 0
	div %3
	xchg eax, edx
	cmp		al, 0Ah
	js	%%addvalue
	add		al, 7
%%addvalue:
	add 	al,48
	mov [%2], al
		
	mov		al,[%1]
	and		al,0f0h
	shr		al,4
	cmp		al,09h
	js		%%addvalue2
	add		al,7
%%addvalue2:
	add		al,8
	mov [%2+di], al
	inc di
	xchg eax edx
	cmp al, 0
	js %%loopagain
%endmacro

	global _main
	extern _printf
	
	section .text
_main:
;addbyte number, numberstr
	
	mov		al,[number]
	and		al,0f0h
	shr		al,4
	cmp		al,09h
	js		addvalue2
	add		al,7
addvalue2:
	add		al,8
	
	push 	fmt
	push	message
	call	_printf
	add		esp,8
	
	ret
	
	section .data
fmt:
	db '%s', 10, 0
message:
	db 'Hello, my students',10,0
numberstr:
	times 11 db 0
number:
	dd	000004dAH
