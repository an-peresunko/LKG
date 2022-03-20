
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define x = 0;
//#define a 84589
//#define c 45989

#define a 106
#define c 1283

unsigned int LKG(unsigned int x){
    unsigned int X = 0;
    X = ((a*x) + c);
    return X;
}

int main(int argc, const char * argv[]) {
    srand((unsigned int)(time(NULL)));
    unsigned int X = LKG(rand());
    
    unsigned int period = 0;
    unsigned int f_gen = X; //first generation – первое сгенерированное число, нужно, чтобы найти период
    
    // Хи-квадрат критерий
    
    // Покер критери
    
    // Проверка младших битов
    
    int i = 0;
    unsigned int tmp = X;
    while(i!=1){
        X = LKG(tmp);
        //printf("%u\n", X);
        if(X == f_gen){i = 1;}
        period++;
        tmp = X;
    }
    printf("period – %u", period);
    
    
    return 0;
}
