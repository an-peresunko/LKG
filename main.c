
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define a 84589
#define c 45989
//#define m 217728

unsigned int LKG(unsigned int x){
    unsigned int X = 0;
    X = ((a*x) + c);
    return X;
}



int main(int argc, const char * argv[]) {
    srand((unsigned int)(time(NULL)));
    unsigned int X = (rand());
//
    unsigned long int period = 0;
    unsigned int f_gen = X; //first generation – первое сгенерированное число, нужно, чтобы найти период

    while(1){
        unsigned int tmp = LKG(X);
        X = tmp;
//        printf("%u \n", tmp);
        if(period == 0){f_gen = X;/*printf("--\n ");*/}
        if((X == f_gen)&&(period!=0)){/*printf("++\n ");*/break;}
        period++;
//        i++;
        if(period%10000==0){printf("%lu\n", period);}
//        if(period==34359738368){printf("++");}
    }
    printf("period – %lu\n", period);
    
    return 0;
}
