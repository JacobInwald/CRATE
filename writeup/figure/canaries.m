; start of main()
push   %rbp             ; preserves previous return pointer
mov    %rsp,%rbp       ; save return pointer to %rbp
sub    $0x40,%rsp      ; makes sure there's space for local variables
mov    %edi,-0x34(%rbp)
mov    %rsi,-0x40(%rbp)
; inserted code
mov    %fs:0x28,%rax  ; load canary value into %rax
mov    %rax,-0x8(%rbp)  ; store canary value 8 bytes before the return address
xor    %eax,%eax

; start code block for main, left unchanged 
;                       ...
; end code block for main

; inserted code 
mov    -0x8(%rbp),%rdx  ; load canary value into %rdx
sub    %fs:0x28,%rdx    ; compare with saved canary value
je     0x4011c9 <main+147>  ; skip error if not broken
call   0x401030 <__stack_chk_fail@plt> ; throw stack smashing error  
; unchanged 
leave
ret    ; exit