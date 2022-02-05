#include <math.h>
#include "neurone.h"


void calcul_neurone(float poids[][784], int nb_neural, float *biais, int *pixel, float *y_neural)
{
    float somme = 0;
    for (int y = 0 ; y < nb_neural ; y++)
    {
        somme = 0;
        for (int i = 0 ; i < 784 ; i++)
        {
            somme = somme + poids[y][i]*pixel[i];
        }
    y_neural[y] = somme + biais[y];
    }
}

void relu(float *donnee, int nb_donnee)
{
    for (int i = 0 ; i < nb_donnee - 1 ; i++)
    {
        if ( donnee[i] < 0 )
        {
            donnee[i] = 0;
        }
    }
}

void softmax(float* input, int size) {

	

	int i;
	float m, sum, constant;

	m = -INFINITY;
	for (i = 0; i < size; ++i) {
		if (m < input[i]) {
			m = input[i];
		}
	}

	sum = 0.0;
	for (i = 0; i < size; ++i) {
		sum += exp(input[i] - m);
	}

	constant = m + log(sum);
	for (i = 0; i < size; ++i) {
		input[i] = exp(input[i] - constant);
	}

}