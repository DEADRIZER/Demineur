// Bienvenue sur le code de mon Demineur realiser pour Monsieur Ben ahmed pourle 25/09/20


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N, NbMines, i, j, choix;
char PLATEAU[8][8];
char MINES[8][8];

void PlaceMines(){
  int CompteMines;
  for (CompteMines=0;CompteMines<NbMines;CompteMines++){  
    i=rand()%8;
    j=rand()%8;
    if(MINES[i][j]=='0'){
      MINES[i][j]='M';
    }
    else{
      NbMines++;
    }
  }
}


void AfficheJeu()
{
   printf("\n\n");
   printf("   |1 |2 |3 |4 |5 |6 |7 |8\n");
   printf("___|_______________________\n");
   for(i=0;i<8;i++){
      if(i<9)
          printf(" %d | ",i+1);
      else
          printf("%d | ",i+1);
      for(j=0;j<8;j++){                
        printf("%c  ",PLATEAU[i][j]);
      }
      printf("\n");
   }
}

void Init(){
 for(i=0;i<8;i++){
     for(j=0;j<8;j++){
        PLATEAU[i][j]='-';
        MINES[i][j]='0';                            
     }           
   }
}


int NbMinesAutour(){
   N=0;
   if(MINES[i][j]=='M'){
      printf("Looser !\n\n");
      printf("   |1 |2 |3 |4 |5 |6 |7 |8\n");
      printf("___|_______________________\n");
      for(i=0;i<8;i++){
          if(i<9)
          printf(" %d | ",i+1);
          else
          printf("%d | ",i+1);
          for(j=0;j<8;j++)                
          printf("%c  ",MINES[i][j]);
          printf("\n");
      }            
   }
    else{
      if (i==0){
         if (j==0){
            if(MINES[i][j+1]=='M')
            N++;
            if(MINES[i+1][j]=='M')
            N++;
            if(MINES[i+1][j+1]=='M')
            N++;                       
         }
         else{
           if(j==8){ 
              if(MINES[i][j-1]=='M')
              N++;
              if(MINES[i+1][j-1]=='M')
              N++;
              if(MINES[i+1][j]='M')
              N++; 
           }else{
               if(MINES[i][j-1]=='M')
               N++;
               if(MINES[i][j+1]=='M')
               N++;
               if(MINES[i+1][j-1]=='M')
               N++;
               if(MINES[i+1][j]=='M')
               N++;
               if(MINES[i+1][j+1]=='M')
               N++;
           }
         }
      }else{
          if (i==8){
             if (j==0){
                if(MINES[i-1][j]=='M')
                N++;
                if(MINES[i-1][j+1]=='M')
                N++;
                if(MINES[i][j+1]=='M')
                N++;                       
             }
             else{
               if(j==8){ 
                  if(MINES[i-1][j-1]=='M')
                  N++;
                  if(MINES[i-1][j]=='M')
                  N++;
                  if(MINES[i][j-1]=='M')
                  N++; 
               }else{
                   if(MINES[i-1][j-1]=='M')
                   N++;
                   if(MINES[i-1][j]=='M')
                   N++;
                   if(MINES[i-1][j+1]=='M')
                   N++;
                   if(MINES[i][j-1]=='M')
                   N++;
                   if(MINES[i][j+1]=='M')
                   N++;
               }
             }
          } else {
              if(MINES[i-1][j-1]=='M')
              N++;
              if(MINES[i-1][j]=='M')
              N++;
              if(MINES[i-1][j+1]=='M')
              N++;
              if(MINES[i][j-1]=='M')
              N++;
              if(MINES[i][j+1]=='M')
              N++;
              if(MINES[i+1][j-1]=='M')
              N++;
              if(MINES[i+1][j]=='M')
              N++;
              if(MINES[i+1][j+1]=='M')
              N++;
          }                            
      }    
      return(N);
   }
}


void Jouer(){
    char NbMinesTexte[2]; 
    switch (choix){
        case 1 : 
           NbMinesAutour();
           if (N!=0){
              printf("%d\n\n",N);
              sprintf(NbMinesTexte,"%d",N);
              PLATEAU[i][j]=NbMinesTexte[0];
           }else{
              PLATEAU[i][j]='0';
              for(i=i-1;i<i+2;i++){
                for(j=j-1;j<j+2;j++)
                NbMinesAutour();
              }
           }
           break;
        case 2 : PLATEAU[i][j]='D';
        break;
     }
}
     
void Choisir(){
     printf("\n\nCoordonnees de la case [x+ESPACE+y]: "); 
     scanf("%d %d",&i,&j);
     printf("Que voulez-vous faire ? \nCase (%d,%d)\n",i,j);
     i=i-1;
     j=j-1;
     printf("\t1: Decouvrir\n");
     printf("\t2: Drapeau");
     do{
        printf("\n\n\t\tVotre choix : ");
        scanf("%d",&choix);
     }while (choix<0 || choix>2);
}

int main(){ 
       int c;
       srand(time(NULL));
       printf("<-|- Demineur -|->\n");
       Init();
       do{
          printf("\nCombien voulez vous de mines ?\n>>> ");
          scanf("%d",&NbMines);
       }while(NbMines>=30);
       printf("- %d mines sur la grille\n", NbMines);       
       PlaceMines();
       printf("Les mines:\n");
       for(i=0;i<8;i++){
         printf("\t\t\t");
         for(j=0;j<8;j++){
            printf("%c  ",MINES[i][j]);
         }
         printf("\n");
       }
       printf("--- Grille ---");
       AfficheJeu();
       for(c=0;c<(100-NbMines);c++)
       {
         Choisir();
         Jouer();
         AfficheJeu();          
       }
       printf("\n\n\t\tGG !");
       system("pause");
       return 0;
}
