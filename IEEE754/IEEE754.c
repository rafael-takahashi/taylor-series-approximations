#include <stdio.h>
#include <math.h>

typedef union floatIEEE{
    float x; // valor decimal float
    struct {
        //a ordem de defini��o dos seguintes campos � importante
        unsigned int f : 23; // 23 bits para a fra��o da mantissa (0.xxx...)
        unsigned int E : 8; // 8 bits para a o expoente enviezado por 127
        unsigned char s : 1;  //   1 bit para o sinal da mantissa
    }Fbits;
}floatIEEE; //estrutura para precis�o simples

typedef union doubleIEEE{
    float x; // valor decimal float
    struct {
        //a ordem de defini��o dos seguintes campos � importante
        unsigned long long int f : 52; // 23 bits para a fra��o da mantissa (0.xxx...)
        unsigned int E : 11; // 8 bits para a o expoente enviezado por 1023
        unsigned char s : 1;  //   1 bit para o sinal da mantissa
    }Dbits;
}doubleIEEE; //estrutura para precis�o dupla


int main()
{
   float ff; //fra��o da mantissa interpretada como um float
   unsigned int  fz; // fra��o da mantissa interpretada como um inteiro
   unsigned int EE; // expoente enviezado por 127  (E = e + 127)
   unsigned char sinal; // bit do sinal da mantissa (0 - positivo. 1 - negativo)

   const float y = 3.125;  //valor decimal que desejamos ver como PontoFlutuante

   floatIEEE bin = {y}; // � o mesmo que fazer bin.x = y;
                // Transforma o valor decimal real "y" em estrutura
                // de ponto flutuante IEEE754 na forma y = (-1)^s(1 + f)2^E

   sinal = bin.Fbits.s; // recuperando o sinal de y
   EE = bin.Fbits.E; // recuperando o valor do expoente somado com 127
   fz = bin.Fbits.f; // recuperando a fra��o da mantissa interpretada com um inteiro
   ff = (float)fz/(2<<22); // shiftar 2 para esquerda 22 vezes � o mesmo que pow(2,22)

    printf("\n     y   = %18.16f", y); // y � igual a bin.x
    printf("\n bin.x   = %18.16f", bin.x);
    printf("\nBit do Sinal  = %2d ('0' valor positivo. '1' valor negativo)", sinal);
    printf("\nExpoente + 127 = %4d. Expoente - 127 = %4d",  EE, EE-127);
    printf("\nfracao f da mantissa como inteiro fz =        %d ", fz );
    printf("\nValor da mantissa (1 + f) como inteiro 2^23 + fz = %d", fz + 2<<23 );
    printf("\nfracao da mantissa f como float   ff = %12.8f", ff );
    printf("\nValor da mantissa como float 1 + ff = %12.8f", ff + 1 );


 //   Como recuperar o valor decimal (real) do ponto flutuante
    // por meio da fra��o real da mantissa
    // o uso da fun��o pow abaixo � de baixa performance. Ao inv�s de
    //                    float xff = (1 + ff)*(pow(2.0,EE - 127));
    // para expoentes positivos, fa�a

     float xff = (1 + ff)*(1<<(EE - 127));

    printf("\nValor recuperado de y = %12.8f - pela fracao real da mantissa\n", xff);

    //  para inteiros de 64 bits use
    //  long long int y;
    //  y = 999999999999;
    //  printf("Valor da variavel: %lld\n", y);

    return 0;

}
