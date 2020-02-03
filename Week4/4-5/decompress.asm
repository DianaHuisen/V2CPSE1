.cpu cortex-m0
.data
buffer_length = 100
buffer: .skip buffer_length
.text
.align 2
.global decompress


decompress:	    
                PUSH { R4, LR }
                LDR R5, =COMPRESSED_DATA
loop:
                LDRB R4, [R5]
                CMP R4, #0
                BEQ done
                CMP R4, #'@'
                BEQ match
                MOV R0, R4
                BL add_buffer
                ADD R5, #1
                B loop
done:   
                POP { R4, PC }


match:
                ADD R5, #1
                LDRB R6, [R5]
                ADD R5, #1
                LDRB R7, [R5]
                SUB R6, #'0'
                SUB R7, #'0'
                LDR R4, =buffer
match_loop:	
                LDRB R0, [R4, R6]
                BL add_buffer
                SUB R7, #1
                BNE match_loop
                ADD R5, #1
                B loop
add_buffer:	
                LDR R1, =buffer
                MOV R2, #buffer_length-1
add_buffer_loop:
                LDRB R3, [R1, R2]
                ADD R2, #1
                STRB R3, [R1, R2]
                SUB R2, #2
                BLT add_buffer_done
                B add_buffer_loop
add_buffer_done:
                STRB R0, [R1]
                B print_char
                MOV PC, LR
