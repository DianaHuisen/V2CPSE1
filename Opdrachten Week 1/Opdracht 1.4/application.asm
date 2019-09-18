   .cpu cortex-m0
   .text
   tekst:
   .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"
   .align 2
   .global application
   
application:    PUSH { LR }
                LDR R0, =tekst
                BL print_asciz
                POP { PC }

