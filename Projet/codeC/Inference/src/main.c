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

 
void FillMatrix(float **matrix,int size_r, int size_c, FILE*p)
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
    printf("lecture du fichiers\n");
  }
}


int main(int argc, char* argv[]){
   unsigned char tab_image_vecteur[784];
   //float poid1[128][784];
   //float **poid2;
   //float *biais1;
   //float *biais2;
   BMP bitmap;
   FILE *pImage=NULL;
   //FILE* ppoid1=NULL;
   //FILE* ppoid2=NULL;
   //pImage=fopen("../../../Database/Prof/Images/bmpProcessedSeuil/0_1.bmp", "rb");
   OpenFile(&pImage,"../../../Database/Prof/Images/bmpProcessedSeuil/0_1.bmp");
  
   //ppoid1=fopen("poids_1.txt", "r");
  // ppoid2=fopen("poids_2.txt", "r");
   
   LireBitmap(pImage, &bitmap);
   printf("ok\n");
   fclose(pImage);
   
   ConvertRGB2Gray(&bitmap);  
   printf("%d\n", bitmap.mPixelsGray[10][10]);
   for(int i = 0 ;i<28;i++){
      for(int j = 0 ;j<28;j++){
        tab_image_vecteur[i*28+j]= (bitmap.mPixelsGray[i][j])/225;
        //printf("%d\n",i*28+j);
      }
   }
   /*for(int i = 0 ;i<783;i++){
     printf("%d",tab_image_vecteur[i]);
   }*/
   //printf("\n");

  //FillMatrix(poid1,128,784,ppoid1);
  //printf("%f\n",poid1[0][0]);
  //printf("%f\n",poid1[127][783]);
  //FillMatrix(poid1,128,784,ppoid2);
   
  
   
  
   


   //fclose(ppoid1);
   //fclose(ppoid2);
   DesallouerBMP(&bitmap);
  return 0;
}
