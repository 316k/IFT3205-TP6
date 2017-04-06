/*------------------------------------------------------*/
/* Prog    : Tp6_IFT3205.c                              */
/* Auteurs  : Guillaume Riou et Nicolas Hurtubise       */
/*
  ____       _ _ _                              ____  _             
 / ___|_   _(_) | | __ _ _   _ _ __ ___   ___  |  _ \(_) ___  _   _ 
| |  _| | | | | | |/ _` | | | | '_ ` _ \ / _ \ | |_) | |/ _ \| | | |
| |_| | |_| | | | | (_| | |_| | | | | | |  __/ |  _ <| | (_) | |_| |
 \____|\__,_|_|_|_|\__,_|\__,_|_| |_| |_|\___| |_| \_\_|\___/ \__,_|
                                                                    
  ___   
 ( _ )  
 / _ \/\
| (_>  <
 \___/\/
        
 _   _ _           _             _   _            _         _     _          
| \ | (_) ___ ___ | | __ _ ___  | | | |_   _ _ __| |_ _   _| |__ (_)___  ___ 
|  \| | |/ __/ _ \| |/ _` / __| | |_| | | | | '__| __| | | | '_ \| / __|/ _ \
| |\  | | (_| (_) | | (_| \__ \ |  _  | |_| | |  | |_| |_| | |_) | \__ \  __/
|_| \_|_|\___\___/|_|\__,_|___/ |_| |_|\__,_|_|   \__|\__,_|_.__/|_|___/\___|
                                                                             
  ___   
 ( _ )  
 / _ \/\
| (_>  <
 \___/\/
        
 ____            _   _ _ _ _                 
|  _ \ ___ _ __ | |_(_) | (_) ___  _ __  ___ 
| |_) / _ \ '_ \| __| | | | |/ _ \| '_ \/ __|
|  _ <  __/ |_) | |_| | | | | (_) | | | \__ \
|_| \_\___| .__/ \__|_|_|_|_|\___/|_| |_|___/
          |_|                                


 */
/* Date    : --/--/2010                                 */
/* version :                                            */ 
/* langage : C                                          */
/* labo    : DIRO                                       */
/*------------------------------------------------------*/

/*------------------------------------------------*/
/* FICHIERS INCLUS -------------------------------*/
/*------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "FonctionDemo6.h"

/*------------------------------------------------*/
/* DEFINITIONS -----------------------------------*/   
/*------------------------------------------------*/
#define NAME_VISUALISER "./ViewSig.sh "

/*------------------------------------------------*/
/* PROTOTYPE DE FONCTIONS  -----------------------*/   
/*------------------------------------------------*/

/*------------------------------------------------*/
/* PROGRAMME PRINCIPAL   -------------------------*/                     
/*------------------------------------------------*/
int main(int argc,char **argv)
 {
  int i,j,k;
  int length;
  char BufSystVisuSig[100];

  //===============================
  //Question 2.1.(a)
  //===============================
  float*  Sign1=LoadSignalDat("moteur1",&length);
  float*  Sign1I=fmatrix_allocate_1d(length);
  float*  Sign1M=fmatrix_allocate_1d(length);

  int N = 8192;
  int t = 11025;
  float delta_t = t /(float) N;
  float delta_nu = 1.0/t;
  
  FFT1D(Sign1,Sign1I,length);
  ModVct(Sign1M,Sign1,Sign1I,length);
  // CenterVct(Sign1M,length);
  SaveSignalDat("FFT_Moteur1",Sign1M,length);  
  
  int i1, i2;
  float max1 = 0, max2 = 0;
  
  for(i=0; i<N/2; i++) {

      if(max1 < Sign1M[i]) {
          max2 = max1;
          max1 = Sign1M[i];
          i2 = i1;
          i1 = i;
      } else if(max2 < Sign1M[i]) {
          max2 = Sign1M[i];
          i2 = i;
      }
  }
  
  printf("Le moteur : %d : %f\n", i1, 1 / (i1 * delta_nu * 2));
  
  printf("Le clic : %d : %f\n", i2, 1 / (i2 * delta_nu));
  
  
  
  //Visu
  strcpy(BufSystVisuSig,NAME_VISUALISER);
  strcat(BufSystVisuSig,"FFT_Moteur1.dat&");
  printf(" %s",BufSystVisuSig);
  system(BufSystVisuSig);
  
  //==End=========================================================
  //==============================================================

  //retour sans probleme
  printf("\n C'est fini ... \n\n");
  return 0; 	 
}


