# Programa RISC-V 32 bits para converter string ASCII para hexadecimal
# Para rodar no RARS

.data
    buffer:     .space 33          # Buffer para armazenar a string (32 chars + '\0')
    hex_chars:  .string "0123456789abcdef"  # Tabela de caracteres hexadecimais
    newline:    .string "\n"

.text
.globl main

main:
    # Lê a string de entrada
    la a0, buffer           # endereço do buffer
    li a1, 33               # tamanho máximo (32 + '\0')
    li a7, 8                # syscall read_string
    ecall
    
    # Inicializa ponteiro para o buffer
    la t0, buffer           # t0 = endereço do buffer
    li t1, 0                # t1 = contador de caracteres
    
process_loop:
    lb t2, 0(t0)            # Carrega o byte atual
    
    # Verifica se é '\n', '\r' ou '\0' (fim da string)
    beqz t2, end_process    # Se for '\0', termina
    li t3, 10               # '\n'
    beq t2, t3, end_process
    li t3, 13               # '\r'
    beq t2, t3, end_process
    
    # Converte o caractere atual para hexadecimal
    # Primeiro nibble (4 bits superiores)
    srli t3, t2, 4          # Desloca 4 bits para direita
    andi t3, t3, 0x0F       # Mantém apenas os 4 bits inferiores
    la t4, hex_chars        # Carrega endereço da tabela hex
    add t4, t4, t3          # Offset para o caractere hex
    lb a0, 0(t4)            # Carrega o caractere hex
    
    # Imprime o primeiro dígito hex
    li a7, 11               # syscall print_char
    ecall
    
    # Segundo nibble (4 bits inferiores)
    andi t3, t2, 0x0F       # Mantém apenas os 4 bits inferiores
    la t4, hex_chars        # Carrega endereço da tabela hex
    add t4, t4, t3          # Offset para o caractere hex
    lb a0, 0(t4)            # Carrega o caractere hex
    
    # Imprime o segundo dígito hex
    li a7, 11               # syscall print_char
    ecall
    
    # Avança para o próximo caractere
    addi t0, t0, 1
    addi t1, t1, 1
    j process_loop

end_process:
    # Imprime newline
    la a0, newline
    li a7, 4                # syscall print_string
    ecall
    
    # Encerra o programa
    li a7, 10               # syscall exit
    ecall
