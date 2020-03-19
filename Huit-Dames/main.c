#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<pthread.h>
#define O 14
int** tab;
int result = 0;
int resultats[O] = {0};
bool testEightQueensMult(int* addr, int a, int ligne){
    for(int i = ligne-1 , j = 1; i >= 0 ; i-- , j++){
        if(addr[i] == a){
            return false;
        }
        if(addr[i]+j == a){
            return false;
        }
        if(addr[i]-j == a){
            return false;
        }
    }
    return true;
}
void eightQueensMult(int a, int* addr, int ligne){
    for(int i = 0 ; i < O ; i++){
        if(testEightQueensMult(addr, i, ligne)==true){
            if(ligne != O-1){
                addr[ligne] = i;
                eightQueensMult(a, addr, ligne+1);
            }else{
                resultats[a]+=1;
            }
        }
    }
}
void hdmult(int n){
    eightQueensMult(n, tab[n], 1);
}
int main(){
    tab = malloc(O*sizeof(int*));
    for(int i = 0 ; i < O ; i++){
        tab[i] = malloc((O-1)*sizeof(int));
        tab[i][0] = i;
    }
    time_t debut, fin;
    double temps = 0;
    debut = time(NULL);
    pthread_t thd[O];
    for(int i = 0 ; i < O ; ++i){
        pthread_create(&thd[i], NULL, hdmult,(int)i);
    }
    for(int i = 0 ; i < O ; ++i){
        pthread_join(thd[i], NULL);
    }
    for (int i = 0; i < O ; ++i) {
        result = result+resultats[i];
    }
    fin = time(NULL);
    temps = (double)(fin - debut);
    printf("huit dames mult : %d temps : %f\n",result, temps);
    return 0;
}
