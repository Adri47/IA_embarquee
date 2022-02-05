#include <math.h>
#include "neurone.h"

/*
void calcul_neurone(float **poids, int nb_col_poids, int nb_ligne_poids, float *biais, int *pixel, float *y_neural)
{
    float somme = 0;
    for (int y = 0 ; y < 128 ; y++)
    {
        somme = 0;
        for (int i = 0 ; i < 784 ; i++)
        {
            somme = somme + poids[i][y]*pixel[i];
        }
    y_neural[y] = somme + biais[y];
    }
}*/

void relu(float *donnee, int nb_donnee)
{
    for (int i = 0 ; i < nb_donnee - 1 ; i++)
    {
        if ( donnee[i] < 0 )
        {
            donnee[i] = 0;
        }
        else
        {
            donnee[i] = donnee[i];
        }
    }
}

void softmax(float *donnee, int nb_donnee)
{
    int somme = 0;

    for(int j = 0 ; j < nb_donnee - 1 ; j++)
    {
        for(int k = 0 ; k < nb_donnee - 1 ; k++)
        {
            somme = somme + expf(donnee[k]);
        }
        donnee[j] = donnee[j]/somme;
        somme = 0;
    }
}