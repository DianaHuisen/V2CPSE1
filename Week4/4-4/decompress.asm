.cpu cortex-m0
.data
buffer_length = 100
buffer: .skip buffer_length
.text
.align 2
.global decompress


decompress:	    
                PUSH { R4-R7, LR }      //push R4-R7 onto the stack
                LDR R5, =COMPRESSED_DATA    //pointer to the start of the data
loop:
                LDRB R4, [R5]   //load compressed_data char from R5 into R4
                CMP R4, #0
                BEQ done        //if end, then done
                CMP R4, #'@' 
                BEQ match       //if character == @, then match.
                MOV R0, R4      //copy R4 content to R0
                BL add_buffer   
                ADD R5, #1      //move the compressed_data pointer to next char
                B loop
done:   
                POP { R4-R7, PC } //pop R4-R7 from stack


match:
                ADD R5, #1      //move the compressed_data pointer to next char
                LDRB R6, [R5]   //load R5 compressed_data char into R6, offset
                ADD R5, #1      //move the compressed_data pointer to next char
                LDRB R7, [R5]   //load R5 compressed_data char into R7, length
                SUB R6, #'0'    
                SUB R7, #'0'
                LDR R4, =buffer    //load pointer to buffer in R4
match_loop:	
                LDRB R0, [R4, R6]   //load buffer and offset in R0
                BL add_buffer
                SUB R7, #1          //R7, length -1
                BNE match_loop      //if SUB ANSWER not 1, then match_loop
                ADD R5, #1          //move the compressed_data pointer to next char
                B loop
add_buffer:	
                LDR R1, =buffer             //load buffer into R1
                MOV R2, #buffer_length    //load length (i=length)value into R2
add_buffer_loop:
                SUB R2, #1                  //i-1, so R2=i-1
                LDRB R3, [R1, R2]           //load buffer+i into R3
                ADD R2, #1                 //increases i by 1 so R2=i
                STRB R3, [R1, R2]           //store buffer+i into R3
                SUB R2, #1                  //i -1, so R2 is --i
                BLT add_buffer_done         //sub ANSWER signed less than #2, then buffer_done
                B add_buffer_loop           //else: buffer_loop
add_buffer_done:
                STRB R0, [R1]               //store bufferdata in R0
                B print_char                //print char
                MOV PC, LR                  