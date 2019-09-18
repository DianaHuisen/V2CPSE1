   .cpu cortex-m0
   .text
   .align 2
   .global toggle_case
   

toggle_case:    PUSH { LR }
                LDR R6, ='Z'
                CMP R0, R6
                BLE checkupper
                LDR R6, ='z'
                CMP R0, R6
                BLE checklower
//                MOV R1, R0
                B done
checkupper:     LDR R6, ='A'
                CMP R0, R6
                BGE isupper
//                MOV R1, R0
                B done
isupper:        LDR R6, ='a'-'A'
                ADD R1, R0, R6
                B done
                
checklower:     LDR R6, ='a'
                CMP R0, R6
                BGE islower
//                MOV R1, R0
                B done
islower:        LDR R6, ='a'-'A'
                SUB R1, R0, R6
                B done
done:           POP { PC }


