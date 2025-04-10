#include <stdio.h>
#include <string.h>

int converte(int num)
{
    char res[1000] = "";
    while (num >= 1000)
    {
        strcat(res, "M");
        num -= 1000;
    }
    while (num >= 900)
    {
        strcat(res, "CM");
        num -= 900;
    }
    while (num >= 500)
    {
        strcat(res, "D");
        num -= 500;
    }
    while (num >= 400)
    {
        strcat(res, "CD");
        num -= 400;
    }
    while (num >= 100)
    {
        strcat(res, "C");
        num -= 100;
    }
    while (num >= 90)
    {
        strcat(res, "XC");
        num -= 90;
    }
    while (num >= 50)
    {
        strcat(res, "L");
        num -= 50;
    }
    while (num >= 40)
    {
        strcat(res, "XL");
        num -= 40;
    }
    while (num >= 10)
    {
        strcat(res, "X");
        num -= 10;
    }
    while (num >= 9)
    {
        strcat(res, "IX");
        num -= 9;
    }
    while (num >= 5)
    {
        strcat(res, "V");
        num -= 5;
    }
    while (num >= 4)
    {
        strcat(res, "IV");
        num -= 4;
    }
    while (num >= 1)
    {
        strcat(res, "I");
        num -= 1;
    }
    printf("%s\n", res);
    return 0;
};

int main()
{
    int n;
    scanf("%d", &n);
    int vet[n];

    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        vet[i] = num;
    }
    for (int i = 0; i < n; i++)
    {
        converte(vet[i]);
    };

    return 0;
}

