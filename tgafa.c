/*

Código feito por Tiago Gurgel para a cadeira de Infraestrutura de Hardware do professor Fernando Ferreira de Carvalho

tgafa@cesar.school

Data de criação: 21/08/2024   10:59


Atualizações: 

21/08/2024 10:59 - Adicionada a função Binario
21/08/2024 11:05 - Adicionada a função Octal
21/08/2024 11:19 - Adicionada a função Hexa
21/08/2024 11:55 - Adicionada a função BCD
21/08/2024 14:09 - Adicionada a função Complemento2
21/08/2024 15:11 - Adicionada a função BitsFloat
21/08/2024 15:40 - Adicionada a função BitsDouble



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

void Binario(int n) { /*10:59 21/08/2024*/
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

void Octal(int n) {/*11:05 21/08/2024*/
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

void Hexa(int n) {/*11:19 21/08/2024*/
    int hexa[32];
    int i = 0;
    
    while (n > 0) {
        hexa[i] = n % 16;
        n = n / 16;
        i++;
    }
    
    printf("Número hexa: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", hexa[j]);
    }
    printf("\n");
}

void BCD(int n) {/*11:55 21/08/2024*/
    int bcd[32];
    int i = 0;
    
    while (n > 0) {
        int digito = n % 10;
        bcd[i] = digito;
        n = n / 10;
        i++;
    }
    
    printf("Número BCD: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%04d ", bcd[j]);
    }
    printf("\n");
}

void Complemento2(int n) {/*14:09 21/08/2024*/
    unsigned short complemento2[16];
    int i = 0;
    unsigned short num = (unsigned short)n;

    if (n < 0) {
        num = ~(-n) + 1;
    }

    while (num > 0) {
        complemento2[i] = num % 2;
        num = num / 2;
        i++;
    }

    printf("Número em complemento a 2 (16 bits): ");
    for (int j = 15; j >= 0; j--) {
        if (j >= i) {
            printf("0");
        } else {
            printf("%d", complemento2[j]);
        }
    }
    printf("\n");
}

void BitsFloat(float num) {/*15:11 21/08/2024*/
    union {
        float f;
        unsigned int bits;
    } floatUnion;
    
    floatUnion.f = num;
    
    unsigned int sinal = (floatUnion.bits >> 31) & 1;/*representa os 31 bits da forma inteiro do número float, >>31 avança
    31 bits para a direita, ou seja, pega o bit mais significativo que representa o sinal do número
    */
    unsigned int expoente = (floatUnion.bits >> 23) & 0xFF;/* os bits de expoente estão entre os bits 23 e 30, por isso
    é feito um shift de 23 bits para a direita e é feito um AND com 0xFF para pegar os 8 bits do expoente
    */
    unsigned int fracao = floatUnion.bits & 0x7FFFFF;/*extrai os 23 bits da fração do número float, que são os bits 0 a 22,
    a operação AND com 0x7FFFFF esconde todos menos esses 23 bits, isolando o valor da fração
    
    */
    
    printf("Float: %f\nSinal: %u\nExpoente: %u\nExpoente com viés: %d\nFração: %u\n", 
           num, sinal, expoente, expoente - 127, fracao);
}

void BitsDouble(double num) {/*15:40 20/08/2024*/
    union {
        double d;
        unsigned long long bits;
    } doubleUnion;
    
    doubleUnion.d = num;
    
    unsigned long long sinal = (doubleUnion.bits >> 63) & 1; /*representa os 64 bits da forma inteiro do número double, >>63 avança
    63 bits para a direita, ou seja, pega o bit mais significativo que representa o sinal do número
    */
    unsigned long long expoente = (doubleUnion.bits >> 52) & 0x7FF; /* os bits de expoente estão entre os bits 52 e 62, por isso
    é feito um shift de 52 bits para a direita e é feito um AND com 0x7FF para pegar os 11 bits do expoente
    
    */
    unsigned long long fracao = doubleUnion.bits & 0xFFFFFFFFFFFFF;/*extrai os 52 bits da fração do número double, que são os bits 0 a 51,
    a operação AND com 0xFFFFFFFFFFFFF esconde todos menos esses 52 bits, isolando o valor da fração
    
    */
    
    printf("Double: %lf\nSinal: %llu\nExpoente: %llu\nExpoente com viés: %lld\nFração: %llu\n", 
    num, sinal, expoente, expoente - 1023, fracao);
}

int main(){

int numero, escolha;

printf("Escolha uma operação para realizar: \n\t1 - Conversão de decimal para binário\n\t2 - Conversão de decimal para octal\n");
printf("\t3 - Conversão de decimal para hexadecimal\n\t4 - Conversão de decimal para BCD\n\t5 - Conversão de decimal para complemento a 2\n");
printf("\t6 - Conversão de decimal para float e double\n");

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
        
        Hexa(numero);
        break;

    case 4:

        BCD(numero);
        break;

    case 5:

        Complemento2(numero);
        break;

    case 6: 

        BitsFloat(numero);
        BitsDouble(numero);
        break;
    default:

    printf("Opção inválida\n");
        break;
    }


}