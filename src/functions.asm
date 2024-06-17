; функции из варианта №9

section .data
    two dd 2
    three dd 3
    six dd 6  
    
    half dq 0.5

section .text
global func_1, func_2, func_3, dfunc_1, dfunc_2, dfunc_3
func_1:     ; 3 / ((x - 1) ^ 2 + 1)
    enter 0, 0
    
    finit
    fld qword [ebp + 8]
    fld1
    fsubp
    fmul st0, st0
    fld1
    faddp
    fidivr dword [three]
    
    leave
    ret
    
func_2:     ; sqrt(x + 0.5)
    enter 0, 0
    
    finit
    fld qword [ebp + 8]
    fld qword [half]
    faddp
    fsqrt
    
    leave
    ret

func_3:     ; e^(-x)
     enter 0, 0 
     
     finit 
     fldl2e 
     fld qword [ebp + 8] 
     fmulp 
     fld st0 
     frndint 
     fxch st1 
     fsub st0, st1 
     f2xm1 
     fld1 
     faddp st1, st0 
     fscale      
     fld1
     fdivr
     
     leave 
     ret
     
dfunc_1:    ; -(6 * x - 6) / (x ^ 4 - 4 * x ^ 3 + 8 * x ^ 2 - 8 * x + 4)
    enter 0, 0
    
    finit
    fld qword [ebp + 8]
    fld1
    fsubp
    fst
    fmul st0, st0
    fld1
    faddp
    fmul st0, st0
    fdiv
    fimul dword [six]
    fchs

    leave
    ret
    
dfunc_2:    ; 1 / (sqrt(2) * sqrt(2 * x + 1))
    enter 0, 0
    
    finit
    fld qword [ebp + 8]
    fld qword [half]
    faddp
    fsqrt
    fimul dword [two]
    fld1
    fdivr
    
    leave
    ret
    
dfunc_3:    ; -e ^ (-x)
     enter 0, 0 
     
     finit 
     fldl2e 
     fld qword [ebp + 8] 
     fmulp 
     fld st0 
     frndint 
     fxch st1 
     fsub st0, st1 
     f2xm1 
     fld1 
     faddp st1, st0 
     fscale      
     fld1
     fdivr
     fchs
     
     leave 
     ret