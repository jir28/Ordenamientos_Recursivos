#include <stdio.h>

void o_rapido(int *array, int ult, int prim){
    int pivote, i, j, temp;
    if(ult < prim) {
        pivote = ult;
        i = ult;
        j = prim;
        while(i < j) {
            while(array[i] <= array[pivote] && i <= prim)
                i++;
            while(array[j] > array[pivote] && j >= ult)
                j--;
            if(i < j) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[j];
        array[j] = array[pivote];
        array[pivote] = temp;

        o_rapido(array, ult, j - 1);
        o_rapido(array, j+1, prim);
    }
}


void intercambiar_M(int *rArr, const int *auxA, int n, const int *ori, int n_M){
    int x = 0, y = 0;

    for(int i = 0; i < n_M + n; i++){
        if (x == n){
            rArr[i] = ori[y++];
        }
        else if (y == n_M){
            rArr[i] = auxA[x++];
        }
        else if (auxA[x] <= ori[y]) {
            rArr[i] = auxA[x++];
        }
        else{ rArr[i] = ori[y++];}
    }
}

void O_Mezcla(int Arr[], int n){
    if (n > 1) {
        int mitad = n / 2;
        int ARRaUX[mitad], AR[n - mitad];

        for (int i = 0; i < mitad; i++) ARRaUX[i] = Arr[i];
        for (int i = 0; i < n - mitad; i++) AR[i] = Arr[i + mitad];

        O_Mezcla(ARRaUX, mitad);
        O_Mezcla(AR, n - mitad);

        intercambiar_M(Arr, ARRaUX, mitad, AR, n - mitad);
    }
}
void print_list(int Ar[],int n){
    for (int i = 0;i<n;i++){
        printf("\n%d",Ar[i]);
    }

}

int main() {

    int A[10] ={9,8,7,6,5,4,3,2,1,0};
    int sizeA = sizeof(A)/sizeof(A[0]);

    printf("El arreglo ingresado es ");
    print_list(A,sizeA-1);
    o_rapido(A,0,sizeA-1);
    printf("\nEl arreglo ordenado es");
    print_list(A,sizeA-1);
    //O_Mezcla(A,sizeA);


    return 0;
}
