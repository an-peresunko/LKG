
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define a 84589
#define c 45989
#define m 217728

unsigned int LKG(unsigned int x){
    unsigned int X = 0;
    X = ((a*x) + c);
    return X;
}

int main(int argc, const char * argv[]) {
    srand((unsigned int)(time(NULL)));
    unsigned int X = (rand());

//    unsigned int count = 0;
    unsigned int f_gen = X; //first generation – первое сгенерированное число, нужно, чтобы найти период
    short k = 16;
    unsigned int Y[16] = {0};
//    float np[16] = {0};
    double V[17] = {0};
//    unsigned long int period = 0;
    double np0 = 10000/16;
    
    
    //Хи-квадрат
    for(unsigned long int count = 0; count<10000; count++){
        unsigned int tmp = LKG(X);
        X = tmp;
        if(count == 0){f_gen = X;}
        if((X == f_gen)&&(count!=0)){break;}
        if((0<=X)&&(X<252645135)){Y[0]++;}
        else if((252645134<=X)&&(X<=505290270)){Y[1]++;}
        else if((505290270<=X)&&(X<=757935405)){Y[2]++;}
        else if((757935405<=X)&&(X<=1010580540)){Y[3]++;}
        else if((1010580540<=X)&&(X<=1263225675)){Y[4]++;}
        else if((1263225675<=X)&&(X<=1515870810)){Y[5]++;}
        else if((1515870810<=X)&&(X<=1768515945)){Y[6]++;}
        else if((1768515945<=X)&&(X<=2021161080)){Y[7]++;}
        else if((2021161080<=X)&&(X<=2273806215)){Y[8]++;}
        else if((2273806215<=X)&&(X<2526451350)){Y[9]++;}
        else if((2526451350<=X)&&(X<=2779096485)){Y[10]++;}
        else if((2779096485<=X)&&(X<=3284386755)){Y[11]++;}
        else if((3284386755<=X)&&(X<=3537031890)){Y[12]++;}
        else if((3537031890<=X)&&(X<=3789677025)){Y[13]++;}
        else if((3789677025<=X)&&(X<=4042322160)){Y[14]++;}
        else if((4042322160<=X)&&(X<=4294967295)){Y[15]++;}
        for(int i=0; i<k; i++){
            if(Y[i]>np0){V[i] = (((double)Y[i]-np0)*((double)Y[i]-np0)/np0);}
            else{V[i] = (((np0-(double)Y[i])*(np0-(double)Y[i]))/np0);}
        }
//        i++;
//        if(period%10000==0){printf("%lu\n", period);}
//        if(period==34359738368){printf("++");}
    }
    for(int i=0; i<k; i++){
        printf("Y[%d] = %u\t V[%d] = %f\n", i, Y[i], i, V[i]);
        V[16] = V[16] + V[i];
    }
    printf("V = %f\n", V[16]);
    return 0;
}
