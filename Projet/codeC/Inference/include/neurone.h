#ifndef NEURONE_H
#define NEURONE_H

void calcul_neurone(float poids[][784], int nb_neural, float *biais, int *pixel, float *y_neural);
void relu(float *donnee, int nb_donnee);
void softmax(float *input, int input_len);

#endif