#include <stdio.h>

int main()
{
    int amendoin = 0;
    int chocolate_branco = 0;
    int chocolate_ao_leite = 0;

    scanf("%d %d %d", &amendoin, &chocolate_branco, &chocolate_ao_leite);

    int crocante = 0;
    int misto = 0;
    int tradicional = 0;

    if (amendoin >= 5)
    {
        (crocante = (amendoin / 5));
        if (chocolate_ao_leite >= (crocante * 20) && chocolate_branco >= (crocante * 25))
        {
            chocolate_ao_leite -= (crocante * 20);
            chocolate_branco -= (crocante * 25);
        }
        else
        {
            crocante = 0;
        }
    };

    if (chocolate_branco >= 25)
    {
        misto = (chocolate_branco / 25);
        if (chocolate_ao_leite >= (misto * 25))
        {
            chocolate_ao_leite -= (misto * 25);
        }
        else
        {
            misto = 0;
        };
    };

    if (chocolate_ao_leite >= 50)
    {
        tradicional = (chocolate_ao_leite / 50);
    };

    int especial = 0;
    int predileta = 0;
    int sortida = 0;

    if (tradicional >= 10 && misto >= 10 && crocante >= 10)
    {
        sortida = (tradicional / 10);
        misto -= (sortida * 10);
        crocante -= (sortida * 10);
    };

    if (misto >= 20 && crocante >= 10)
    {
        predileta = (misto / 20);
        crocante -= (predileta * 10);
    };

    if (crocante >= 30)
    {
        especial = (crocante / 30);
    };

    printf("%d %d %d", especial, predileta, sortida);

    return 0;
}