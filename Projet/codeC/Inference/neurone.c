#include <math.h>
#include "neurone.h"
#include <stdio.h>

void calcul_neurone(float poids[][784],int nbpoid, int nb_neural, float *biais, float *pixel, float *y_neural)
{
  
    for (int y = 0 ; y < nb_neural ; y++)
    {
      
        y_neural[y] =0;
        for (int i = 0 ; i < nbpoid ; i++)
        {
            y_neural[y] += poids[y][i]*pixel[i];
            //printf("%f y=%d i=%d\n",poids[y][i] ,y,i);
            //printf("%f y=%d i=%d\n",pixel[i] ,y,i);
        }
    y_neural[y] += biais[y];
      //printf("%f ",y_neural[y]);
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