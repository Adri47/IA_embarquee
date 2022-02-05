//#ifdef NEURONE_H
//#define NEURONE_H

void calcul_neurone(float *poids, float *biais, int *pixel, int nb_biais, int nb_poids);
void relu(float *donnee, int nb_donnee);
void softmax(float *donnee, int nb_donnee);

//#endif