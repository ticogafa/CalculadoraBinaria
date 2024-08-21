/*
Código feito por Tiago Gurgel para a cadeira de Infraestrutura de Hardware do professor Fernando Ferreira de Carvalho

tgafa@cesar.school

Instruções: 

Construa uma calculadora programador didática,  implementada na linguagem C, que tenha as seguintes conversões
1 - de base 10 para:
a)base 2,
b) base 8,
c) base16, 
d) código BCD

2 - de base 10  para base com sinal com 16 bits, (complemento a 2)
3 - converter real em decimal para float e double, mostrando os respectivos bits de sinal , expoente, expoente com viés e fração 
OBS: deve ser entregue o executável com as iniciais do email e link do git com código.  
A cada questão implementada deve ser feito um comite no git . 
O codigo fonte deve conter um cabeçalho dos dados do autor e  revisões/ atualizações com datas e hora

 */
#include <stdio.h>
#include <stdlib.h>

void Binario(int n) {
    int binario[32];
    int i = 0;
    
    while (n > 0) {
        binario[i] = n % 2;
        n = n / 2;
        i++;
    }
    
    printf("Número binário: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

void Octal(int n) {
    int octal[32];
    int i = 0;
    
    while (n > 0) {
        octal[i] = n % 8;
        n = n / 8;
        i++;
    }
    
    printf("Número octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

int main(){

int numero, escolha;

printf("Escolha uma operação para realizar: \n");
printf("\t1 - Conversão de decimal para binário\n");
printf("\t2 - Conversão de decimal para octal\n");
printf("\t3 - Conversão de decimal para hexadecimal\n");
printf("\t4 - Conversão de decimal para BCD\n");

    scanf("%d", &escolha);
    printf("Digite um número decimal: ");
    scanf("%d", &numero);
    switch (escolha)
    {
    case 1:
    
        Binario(numero);
        break;
    
    case 2:
        
        Octal(numero);
        break;

    case 3:
        
        break;

    case 4:

        break;

    default:

    printf("Opção inválida\n");
        break;
    }


}