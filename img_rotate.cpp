

#define RANDOMIZE_CALLEE_REGISTERS __asm mov ebx, 0xAFAFAFAF \
                                   __asm mov esi, 0xAFAFAFAF \
                                   __asm mov edi, 0xAFAFAFAF 
#define RANDOMIZE_CALLER_REGISTERS __asm mov eax, 0xAFAFAFAF \
                                   __asm mov ecx, 0xAFAFAFAF \
                                   __asm mov edx, 0xAFAFAFAF


void imageRotation(unsigned char* image, int dim, unsigned char* image_out) {
    RANDOMIZE_CALLER_REGISTERS
    __asm 
    {
			GreaterLoop:	mov eax, dim
							cmp ebx, eax
							jge End
				
        GreatLoop: cmp ecx, 0
                    je BoundLoop
        
    BoundLoop:
        mov eax, dim
        mul ebx
        mov edi, eax
        add edi, ecx
        shl edi, 2
        mov eax, image
        add edi, eax
        mov edi, [edi]
        
        mov eax, dim
        mul ebx
        sub eax, dim
        add eax, ecx
        shl eax, 2
        mov edx, image
        add eax, edx
        mov eax, [eax]
        add edi, eax
        
        
        mov eax, dim
        mul ebx
        sub eax, dim
        add eax, ecx
        inc eax
        shl eax, 2
        mov edx, image
        add eax, edx
        mov eax, [eax]
        add edi, eax
        
        //5
        mov eax, dim
        mul ebx
        add eax, ecx
        inc eax
        shl eax, 2
        mov edx, image
        add eax, edx
        mov eax, [eax]
        add edi, eax
        //7
        mov eax, dim
        mul ebx
        add eax, dim
        add eax, ecx
        shl eax, 2
        mov edx, image
        add eax, edx
        mov eax, [eax]
        add edi, eax
        //8
        mov eax, dim
        mul ebx
        add eax, dim
        add eax, ecx
        inc eax
        shl eax, 2
        mov edx, image
        add eax, edx
        mov eax, [eax]
        add edi, eax
        
        //Average and move
        shr edi,
        
        mov eax, dim
        mul ebx
        add eax, ecx
        shl eax, 2
        mov edx, image_out
        add eax, edx
        mov [eax], edi
        
        
    NormalLoop:
        //itself
        mov eax, dim
        mul ebx
        mov edi, eax
        add edi, ecx
        shl edi, 2
        mov eax, image
        add edi, eax
        mov edi, [edi]
        //1
        mov eax, dim
        mul ebx
        sub eax, dim
        add eax, ecx
        dec eax
        shl eax, 2
        mov edx, image
        add eax, edx
        mov eax, [eax]
        add edi, eax
        
        //2
        mov eax, dim
        mul ebx
        sub eax, dim
        add eax, ecx
        shl eax, 2
        mov edx, image
        add eax, edx
        mov eax, [eax]
        add edi, eax
        
        //3
        mov eax, dim
        mul ebx
        sub eax, dim
        add eax, ecx
        inc eax
        shl eax, 2
        mov edx, image
        add eax, edx
        mov eax, [eax]
        add edi, eax
        //4
        mov eax, dim
        mul ebx
        add eax, ecx
        dec eax
        shl eax, 2
        mov edx, image
        add eax, edx
        mov eax, [eax]
        add edi, eax
        //5
        mov eax, dim
        mul ebx
        add eax, ecx
        inc eax
        shl eax, 2
        mov edx, image
        add eax, edx
        mov eax, [eax]
        add edi, eax
        //6
        mov eax, dim
        mul ebx
        add eax, dim
        add eax, ecx
        dec eax
        shl eax, 2
        mov edx, image
        add eax, edx
        mov eax, [eax]
        add edi, eax
        //7
        mov eax, dim
        mul ebx
        add eax, dim
        add eax, ecx
        shl eax, 2
        mov edx, image
        add eax, edx
        mov eax, [eax]
        add edi, eax
        //8
        mov eax, dim
        mul ebx
        add eax, dim
        add eax, ecx
        inc eax
        shl eax, 2
        mov edx, image
        add eax, edx
        mov eax, [eax]
        add edi, eax
        
        //Average and move
        shr edi, 3
        
        mov eax, dim
        mul ebx
        add eax, ecx
        shl eax, 2
        mov edx, image_out
        add eax, edx
        mov [eax], edi
        
        
        
			
			 				inc ecx 
							mov edx, dim
							sub edx, ebx
							dec edx 
							cmp ecx, edx
							jl GreatLoop
							inc ebx 
							jmp GreaterLoop
	
		End:
    }
}

