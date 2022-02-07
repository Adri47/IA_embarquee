/*******************************************************
Nom ......... : main.c
Role ........ : Programme principal executant la phase
                d'inférence d'un rédeau de neurones
                artificiels

Compilation :
make veryclean
make
Pour exécuter, tapez : ./all
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Bmp2Matrix.h"
#include "neurone.h"


void FillMatrix(float matrix[][784],int size_r, int size_c,FILE*p)
{
  float carac;
  for(int i=0; i<size_r;i++)
   {
     for(int j=0; j<size_c;j++)
     {
        fscanf(p,"%f ",&carac);
        matrix[i][j]=carac;
        //printf("%d %d %f\n",i,j,carac);
     }
   }
}

void OpenFile(FILE**p, const char* path)
{
  *p=fopen(path,"rb");
  if(p==NULL){
    printf("%s\n",path);
    printf("Erreur dans la lecture du fichiers\n");
  }else{
    printf("%s\n",path);
    printf("lecture du fichiers réussite\n");
  }
}

void LoadImageInVector(float *tab_image_vecteur, int len)
{
  BMP bitmap;
  FILE *pImage=NULL;
  OpenFile(&pImage,"../../../Database/Prof/Images/bmpProcessedSeuil/0_0.bmp");
  LireBitmap(pImage, &bitmap);
  fclose(pImage);
  ConvertRGB2Gray(&bitmap);
   for(int i = 0 ;i<28;i++){
      for(int j = 0 ;j<28;j++){
        tab_image_vecteur[i*28+j]= (float)(bitmap.mPixelsGray[i][j])/255;
        //printf("%d\n",i*28+j);
        //printf("%d", tab_image_vecteur[i*28+j]);
      }
   }
    //printf("\n");
    DesallouerBMP(&bitmap);
}

int main(int argc, char* argv[]){
   float carac;
   float tab_image_vecteur_float[784];
   float layer1_neural[128];
   float layer2_neural[10];
   float poid1[128][784];
   float poid2[10][784];
   float biais1[128];
   float biais2[10];
   FILE* ppoid1=NULL;
   FILE* ppoid2=NULL;
   FILE* pbiais1=NULL;
   FILE* pbiais2=NULL;
   LoadImageInVector(tab_image_vecteur_float,784);
   OpenFile(&ppoid1,"../files/poids_1.txt");
   FillMatrix(poid1,128,784,ppoid1);
   fclose(ppoid1);
   OpenFile(&ppoid2,"../files/poids_2.txt");
   FillMatrix(poid1,10,128,ppoid1);
   fclose(ppoid2);
   OpenFile(&pbiais1,"../files/biais_1.txt");
   for(int i = 0 ;i<128;i++){
     fscanf(pbiais1,"%f ",&carac);
     biais1[i]=carac;
     //printf("%d %f\n",i,biais1[i]);
   }
   fclose(pbiais1);

   OpenFile(&pbiais2,"../files/biais_2.txt");
   for(int i = 0 ;i<10;i++){
     fscanf(pbiais2,"%f ",&carac);
     biais2[i]=carac;
     //printf("%d %f\n",i,biais2[i]);
   }
   fclose(pbiais2);
   


   calcul_neurone(poid1,784,128,biais1,tab_image_vecteur_float,layer1_neural);
  
   relu(layer1_neural,128);
   
   
   calcul_neurone(poid2,128,10,biais2,layer1_neural,layer2_neural);
   softmax(layer2_neural,10);
   printf("layer1_neural\n\n");
   for(int i = 0 ;i<128;i++){
     printf("%f ",layer1_neural[i]);
   }
   printf("\n\n");
   printf("layer2_neural\n\n");
   for(int i = 0 ;i<10;i++){
     printf("%f ",layer2_neural[i]);
   }
   printf("\n\n");
  return 0;
}
