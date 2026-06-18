/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de validação de nomes que verifica se a entrada fornecida pelo
 * usuário contém apenas letras e espaços em branco, garantindo um formato
 * adequado para nomes de pessoas.
 *
 * FUNCIONAMENTO:
 * 1. Entrada: O usuário digita um nome com até 50 caracteres.
 * 2. Processamento: O programa percorre cada caractere da string informada.
 * 3. Validação: Cada caractere é analisado para verificar se é uma letra ou
 *    um espaço em branco.
 * 4. Verificação: Caso seja encontrado algum número, símbolo ou caractere
 *    inválido, o nome é rejeitado.
 * 5. Repetição: O usuário deve informar um novo nome até que a entrada seja
 *    considerada válida.
 * 6. Saída: Exibe uma mensagem de saudação utilizando o nome validado.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constante: Definição do tamanho máximo da string através da diretiva
 *   #define TAM 51.
 * - Strings: Utilização de um vetor de caracteres para armazenar o nome.
 * - Manipulação de Strings: Uso de fgets() para leitura da entrada e
 *   strcspn() para remoção do caractere de quebra de linha.
 * - Biblioteca ctype.h: Aplicação das funções isalpha() e isspace() para
 *   validação dos caracteres.
 * - Modularização: Separação da lógica de validação em uma função específica.
 * - Estruturas de Repetição: Uso de laço while para solicitar uma nova entrada
 *   enquanto o nome for inválido.
 * - Estruturas Condicionais: Verificação dos caracteres permitidos através de
 *   testes lógicos.
 * - Validação de Entrada: Garantia de que apenas letras e espaços sejam
 *   aceitos como parte do nome.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>
#define TAM 51

int validarNome(char name[]){
    int i;  
    for (i=0; name[i] != '\0'; i++){
        if (!isalpha(name[i]) && !isspace(name[i])){
            return 0;
        }
    }
    return 1;
}

int main(){
    char nome[TAM];
    
    printf("============================================\n");
    printf("Digite seu nome: ");
    fgets(nome, TAM, stdin);
    nome[strcspn(nome, "\n")] = '\0'; 
    
    while(validarNome(nome) == 0){
        printf("Nome inválido. Digite novamente: ");
        fgets(nome, TAM, stdin);
    }
    
    printf("Olá, %s, prazer em te conhecer!\n", nome);
    
    return 0;
}
