
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
    float V = 0;
    short k = 16;
    unsigned long int Y[16] = {0};
//    unsigned int np = 268435456;

    while(1){
        unsigned int tmp = LKG(X);
        X = tmp;
//        printf("%u \n", tmp);
        if(period == 0){f_gen = X;/*printf("--\n ");*/}
        if((X == f_gen)&&(period!=0)){/*printf("++\n ");*/break;}
        period++;
        if((0<=X)&&(X<252645135)){Y[0]++;}
        else if((252645134<X)&&(X<505290270)){Y[1]++;}
        else if((505290269<X)&&(X<757935405)){Y[2]++;}
        else if((757935404<X)&&(X<1010580540)){Y[3]++;}
        else if((1010580539<X)&&(X<1263225675)){Y[4]++;}
        else if((1263225674<X)&&(X<1515870810)){Y[5]++;}
        else if((1515870809<X)&&(X<1768515945)){Y[6]++;}
        else if((1768515944<X)&&(X<2021161080)){Y[7]++;}
        else if((2021161079<X)&&(X<2273806215)){Y[8]++;}
        else if((2273806214<X)&&(X<2526451350)){Y[9]++;}
        else if((2526451349<X)&&(X<2779096485)){Y[10]++;}
        else if((2779096484<X)&&(X<3284386755)){Y[11]++;}
        else if((3284386754<X)&&(X<3537031890)){Y[12]++;}
        else if((3537031889<X)&&(X<3789677025)){Y[13]++;}
        else if((3789677024<X)&&(X<4042322160)){Y[14]++;}
        else if((4042322159<X)&&(X<=4294967295)){Y[15]++;}
//        i++;
//        if(period%10000==0){printf("%lu\n", period);}
//        if(period==34359738368){printf("++");}
    }
//    printf("period – %lu\n", period);
    for(int i=0; i<16; i++){
        printf("Y[%d] = %lu\n",i, Y[i]);
    }
    
    return 0;
}
