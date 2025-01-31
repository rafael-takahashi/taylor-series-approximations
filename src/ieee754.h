#ifndef IEEE754_H
#define IEEE754_H

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

#endif