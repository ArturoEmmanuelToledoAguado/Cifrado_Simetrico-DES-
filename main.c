#include <stdio.h>

int pInicial[]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,
                12,4,62,54,46,38,30,22,14,6,64,56,48,
                40,32,24,16,8,57,49,41,33,25,17,9,1,
                59,51,43,35,27,19,11,3,61,53,45,37,29,
                21,13,5,63,55,47,39,31,23,15,7};
int tEliminacionP[]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,
                     10,2,59,51,43,35,27,19,11,3,60,52,44,
                     36,63,55,47,39,31,23,15,7,62,54,46,38,
                     30,22,14,6,61,53,45,37,29,21,13,5,28,
                     20,12,4};
int tCompresionC[]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,
                    12,4,26,8,16,7,27,20,13,2,41,52,31,
                    37,47,55,30,40,51,45,33,48,44,49,39,56,
                    34,53,46,42,50,36,29,32};

int main() {
    int entrada[64]={0,0,0,1,0,1,1,0,1,0,1,1,1,1,0,1,
                     0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,
                     0,1,0,1,1,0,1,0,0,0,1,0,1,0,0,
                     1,1,1,0,0,0,1,0,1,0,0,1,1,1,1,
                     0,1,1};
    int llave[64]={1,1,1,0,0,0,0,1,1,0,1,0,0,1,0,0,
                   1,0,1,1,1,0,1,1,1,0,0,1,1,0,1,
                   1,1,1,0,0,0,0,1,0,1,1,1,0,0,0,
                   1,1,0,0,1,0,0,1,0,0,1,0,1,1,1,
                   0,1,1};

    //Permutación
    int permutation[64];
    for(int i=0;i<64;i++){
        permutation[i]=entrada[pInicial[i]-1];
        //printf("%i ",permutation);
    }

    //Llave
    //Eliminamos la periodicidad
    int key[56];
    for(int i=0;i<56;i++){
        key[i]=llave[tEliminacionP[i]-1];
        //printf("%i\n",key[i]);
    }
    int L[28],R[28];
    //L y R
    for(int i=0;i<28;i++){
        L[i]=key[i];
        R[i]=key[28+i];
        //printf("%i\t%i\n",L[i],R[i]);
    }
    //Recorrimientos
    //L y R
    int auxL=0, auxR=0;
    for(int i=0;i<28;i++){
        if(i==0) {
            auxL=L[i];
            auxR=R[i];
            L[i]=L[i+1];
            R[i]=R[i+1];
        }else if(i==27) {
            L[i]=auxL;
            R[i]=auxR;
        }else{
            L[i]=L[i+1];
            R[i]=R[i+1];}
        //printf("%i\t%i\n",L[i],R[i]);
    }
    //Se rehace Key a partir de L y R desplazadas
    for(int i=0;i<56;i++){
        if(i<28)
            key[i]=L[i];
        else
            key[i]=R[i-28];
        printf("%i\n",key[i]);
    }
    //Tabla de compresion de clave
    /*int cClave[48];
    for(int i=0;i<48;i++){

    }*/
    return 0;
}
