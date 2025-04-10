#include <stdio.h>

int main()
{

    int diaria1, acres, dia;

    scanf("%d %d %d", &diaria1, &acres, &dia);

    int resultado;

    dia -= 1;
    if(dia > 1){
        resultado = (diaria1 + (dia * acres)) * (31 - dia);
    }else{
        resultado = 31 * diaria1;
    }

    printf("%d", resultado);

    return 0;
}