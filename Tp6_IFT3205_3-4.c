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

#include <time.h>

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
int main1(int argc,char **argv)
 {
  int i,j,k;
  int length;
  char BufSystVisuSig[100];

  //===============================
  //Question 2.1.(a)
  //===============================
  float*  Sign1=LoadSignalDat("Spectre",&length);
  float*  Sign1I=fmatrix_allocate_1d(length);
  float*  Sign1M=fmatrix_allocate_1d(length);
  
  FFT1D(Sign1,Sign1I,length);
  ModVct(Sign1M,Sign1,Sign1I,length);
  CenterVct(Sign1M,length);
  SaveSignalDat("FFT_Spectre",Sign1M,length);  
  
  //Visu
  strcpy(BufSystVisuSig,NAME_VISUALISER);
  strcat(BufSystVisuSig,"FFT_Spectre.dat&");
  printf(" %s",BufSystVisuSig);
  system(BufSystVisuSig);

  //==End=========================================================
  //==============================================================

  //retour sans probleme
  printf("\n C'est fini ... \n\n");
  return 0; 	 
}


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

 ( _ )  
 / _ \/\
| (_>  <
 \___/\/
        
 _            __  __                                                           
| |__  _   _ / _|/ _|_ __ ___   ___  ___   ___   ___   ___  _   _ 
| '_ \| | | | |_| |_| '_ ` _ \ / _ \/ _ \ / _ \ / _ \ / _ \| | | |
| |_) | |_| |  _|  _| | | | | | (_)  (_) | (_) | (_) | (_) | |_| |
|_.__/ \__,_|_| |_| |_| |_| |_|\___/\___/ \___/ \___/ \___/ \__, |
                                                            |___/ 


 */
/* Date    : --/--/2010                                 */
/* version :                                            */ 
/* langage : C                                          */
/* labo    : DIRO                                       */
/*------------------------------------------------------*/

/*------------------------------------------------*/
/* FICHIERS INCLUS -------------------------------*/
/*------------------------------------------------*/

/*------------------------------------------------*/
/* PROTOTYPE DE FONCTIONS  -----------------------*/   
/*------------------------------------------------*/

/*------------------------------------------------*/
/* PROGRAMME PRINCIPAL   -------------------------*/                     
/*------------------------------------------------*/
int main2(int argc,char **argv)
 {
  int i,j,k;
  int length;
  char BufSystVisuSig[100];

  //===============================
  //Question 2.1.(a)
  //===============================
  float*  Sign1=LoadSignalDat("Spectre",&length);
  float*  Sign1I=fmatrix_allocate_1d(length);
  float*  Sign1M=fmatrix_allocate_1d(length);

  float* buff = fmatrix_allocate_1d(512);
  float* buffi = fmatrix_allocate_1d(512); // contre les vampires
  
  float* buffmoy = fmatrix_allocate_1d(512);
  float* buffmoyi = fmatrix_allocate_1d(512);
  
  for(j=0; j<512; j++) {
      buffmoy[j] = 0;
      buffmoyi[j] = 0;
  }

  
  k=0;
  
  for(i=0; i<length - 256; i += 256) {
      k++;
      for(j=0; j<512; j++) {
          buff[j] = Sign1[i + j];
          buffi[j] = 0;
      }

      FFT1D(buff, buffi, 512);
      
      for(j=0; j<512; j++) {
          buffmoy[j] += fabs(buff[j]);
          buffmoyi[j] += fabs(buffi[j]);
      }
  }

  for(j=0; j<512; j++) {
      buffmoy[j] /= (float)k;
      buffmoyi[j] /= (float)k;
  }
  
  ModVct(buff, buffmoy, buffmoyi, 512);
  CenterVct(buff, 512);
  SaveSignalDat("FFT_Spectre_PermMoy",buff,512);  
  
  //Visu
  strcpy(BufSystVisuSig,NAME_VISUALISER);
  strcat(BufSystVisuSig,"FFT_Spectre_PermMoy.dat&");
  printf(" %s",BufSystVisuSig);
  system(BufSystVisuSig);

  //==End=========================================================
  //==============================================================

  //retour sans probleme
  printf("\n C'est fini ... \n\n");
  return 0; 	 
}


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

 ( _ )  
 / _ \/\
| (_>  <
 \___/\/
        
 _            __  __                                                           
| |__  _   _ / _|/ _|_ __ ___   ___  ___   ___   ___   ___  _   _ 
| '_ \| | | | |_| |_| '_ ` _ \ / _ \/ _ \ / _ \ / _ \ / _ \| | | |
| |_) | |_| |  _|  _| | | | | | (_)  (_) | (_) | (_) | (_) | |_| |
|_.__/ \__,_|_| |_| |_| |_| |_|\___/\___/ \___/ \___/ \___/ \__, |
                                                            |___/ 


 */

/* Date    : --/--/2010                                 */
/* version :                                            */ 
/* langage : C                                          */
/* labo    : DIRO                                       */
/*------------------------------------------------------*/

/*------------------------------------------------*/
/* PROTOTYPE DE FONCTIONS  -----------------------*/   
/*------------------------------------------------*/
float hamming(int t) {
    return 0.54 - 0.46 * cos(2*PI * t/512.0);
}
/*------------------------------------------------*/
/* PROGRAMME PRINCIPAL   -------------------------*/                     
/*------------------------------------------------*/
int main3(int argc,char **argv)
 {
  int i,j,k;
  int length;
  char BufSystVisuSig[100];

  //===============================
  //Question 2.1.(a)
  //===============================
  float*  Sign1=LoadSignalDat("Spectre",&length);
  float*  Sign1I=fmatrix_allocate_1d(length);
  float*  Sign1M=fmatrix_allocate_1d(length);

  float* buff = fmatrix_allocate_1d(512);
  float* buffi = fmatrix_allocate_1d(512); // contre les vampires
  
  float* buffmoy = fmatrix_allocate_1d(512);
  float* buffmoyi = fmatrix_allocate_1d(512);
  
  for(j=0; j<512; j++) {
      buffmoy[j] = 0;
      buffmoyi[j] = 0;
  }
  
  k=0;
  
  for(i=0; i<length - 256; i += 256) {
      k++;
      for(j=0; j<512; j++) {
          buff[j] = hamming(j) * Sign1[i + j];
          buffi[j] = 0;
      }
      
      FFT1D(buff, buffi, 512);
      
      for(j=0; j<512; j++) {
          buffmoy[j] += fabs(buff[j]);
          buffmoyi[j] += fabs(buffi[j]);
      }
  }

  for(j=0; j<512; j++) {
      buffmoy[j] /= (float)k;
      buffmoyi[j] /= (float)k;
  }
  
  ModVct(buff, buffmoy, buffmoyi, 512);
  CenterVct(buff, 512);
  SaveSignalDat("FFT_Spectre_PermMoyHann", buff, 512);
  
  //Visu
  strcpy(BufSystVisuSig,NAME_VISUALISER);
  strcat(BufSystVisuSig,"FFT_Spectre_PermMoyHann.dat&");
  printf(" %s",BufSystVisuSig);
  system(BufSystVisuSig);

  //==End=========================================================
  //==============================================================

  //retour sans probleme
  printf("\n C'est fini ... \n\n");
  return 0; 	 
}


int main(int argc,char **argv) {

    main1(argc, argv);
    sleep(3);
    main2(argc, argv);
    sleep(3);
    main3(argc, argv);
    
}
