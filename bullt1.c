#include <stdlib.h>
#include <SDL.h>
#include <stdio.h>
#define argumentsdef SDL_Rect TRB,SDL_Rect TRN,SDL_Rect PositionPionNoirV1,SDL_Rect PositionPionNoirV2 , SDL_Rect PositionPionNoirV3 ,SDL_Rect PositionPionNoirV4 ,SDL_Rect PositionPionNoirV5 ,SDL_Rect PositionPionNoirV6 , SDL_Rect PositionPionNoirV7 ,SDL_Rect PositionPionNoirV8, SDL_Rect PositionDameNoirV1,SDL_Rect PositionDameNoirV2 ,SDL_Rect PositionDameNoirV3 ,SDL_Rect PositionDameNoirV4 ,SDL_Rect PositionDameNoirV5 , SDL_Rect PositionDameNoirV6 ,SDL_Rect PositionDameNoirV7 ,SDL_Rect PositionDameNoirV8 ,SDL_Rect PositionPionBlancV1 ,SDL_Rect PositionPionBlancV2 ,SDL_Rect PositionPionBlancV3 ,SDL_Rect PositionPionBlancV4 ,SDL_Rect PositionPionBlancV5 ,SDL_Rect PositionPionBlancV6 ,SDL_Rect PositionPionBlancV7 ,SDL_Rect PositionPionBlancV8 ,SDL_Rect PositionDameBlancV1 ,SDL_Rect PositionDameBlancV2 ,SDL_Rect PositionDameBlancV3 ,SDL_Rect PositionDameBlancV4 ,SDL_Rect PositionDameBlancV5 ,SDL_Rect PositionDameBlancV6 ,SDL_Rect PositionDameBlancV7 ,SDL_Rect PositionDameBlancV8, SDL_Rect PositionPionNoirH1 ,SDL_Rect PositionPionNoirH2, SDL_Rect PositionPionNoirH3 , SDL_Rect PositionPionNoirH4 , SDL_Rect PositionPionNoirH5 ,SDL_Rect PositionPionNoirH6 ,SDL_Rect PositionPionNoirH7, SDL_Rect PositionPionBlancH1,SDL_Rect PositionPionBlancH2 ,SDL_Rect PositionPionBlancH3 ,SDL_Rect PositionPionBlancH4 ,SDL_Rect PositionPionBlancH5 ,SDL_Rect PositionPionBlancH6 ,SDL_Rect PositionPionBlancH7 
#define arguments TRB,TRN, PositionPionNoirV1, PositionPionNoirV2 ,  PositionPionNoirV3 , PositionPionNoirV4 , PositionPionNoirV5 , PositionPionNoirV6 ,  PositionPionNoirV7 , PositionPionNoirV8,  PositionDameNoirV1, PositionDameNoirV2 , PositionDameNoirV3 , PositionDameNoirV4 , PositionDameNoirV5 ,  PositionDameNoirV6 , PositionDameNoirV7 , PositionDameNoirV8 , PositionPionBlancV1 , PositionPionBlancV2 , PositionPionBlancV3 , PositionPionBlancV4 , PositionPionBlancV5 , PositionPionBlancV6 , PositionPionBlancV7 , PositionPionBlancV8 , PositionDameBlancV1 , PositionDameBlancV2 , PositionDameBlancV3 , PositionDameBlancV4 , PositionDameBlancV5 , PositionDameBlancV6 , PositionDameBlancV7 , PositionDameBlancV8,  PositionPionNoirH1 , PositionPionNoirH2,  PositionPionNoirH3 ,  PositionPionNoirH4 , PositionPionNoirH5 , PositionPionNoirH6 , PositionPionNoirH7, PositionPionBlancH1, PositionPionBlancH2 , PositionPionBlancH3 , PositionPionBlancH4 , PositionPionBlancH5 , PositionPionBlancH6 , PositionPionBlancH7 


//déclaration des fonctions
int chercherselection(int x,int y, argumentsdef);
void moveRoi(SDL_Rect *roi);
void movePionNoirV(SDL_Rect *PionNoirV);
void movePionBlancV(SDL_Rect *PionBlancV);
void movePionNoirH(SDL_Rect *pionNH);
void movePionBlancH(SDL_Rect *pionBH);
void moveDameNoirV(SDL_Rect *DameNoirV);
void movePionBlanc(SDL_Rect *pionBH);
void movePionNoir(SDL_Rect *pionNH);
void moveDameNoirH(SDL_Rect *DameNoirH);
void moveDameNoir(SDL_Rect *pionNH);
void moveDameBlanc(SDL_Rect *pionNH);
void moveDameBlancV(SDL_Rect *DameBlancV);
void moveDameBlancH(SDL_Rect *DameBlancH);

int main(int argc, char ** argv)
{
    int quit = 0;
    SDL_Event event;
//initialisation d'une fenetre SDL

    SDL_Init(SDL_INIT_VIDEO);

// creation d'une fenetre SDL

    SDL_Window * window = SDL_CreateWindow("BULLTRICKER",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 870, 870, 0);

// creation d'un rendu d'affichage

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

// declaration et création de la surface et texture principales 

    SDL_Surface * image = SDL_LoadBMP("src/table.bmp");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Rect dstrect = {0, 0, 870, 870 };
    
//initialisation des positions initiales des pieces

SDL_Rect PositionPionNoirV1 = {0,150,30,90},PositionPionNoirV2 ={120,150,30,90},PositionPionNoirV3 ={240,150,30,90},PositionPionNoirV4 ={360,150,30,90},PositionPionNoirV5 ={480,150,30,90},PositionPionNoirV6 ={600,150,30,90},PositionPionNoirV7 ={720,150,30,90},PositionPionNoirV8 ={840,150,30,90};
SDL_Rect PositionDameNoirV1 = {0,30,30,90}, PositionDameNoirV2 ={120,30,30,90},PositionDameNoirV3 ={240,30,30,90},PositionDameNoirV4 ={360,30,30,90},PositionDameNoirV5 ={480,30,30,90},PositionDameNoirV6 ={600,30,30,90},PositionDameNoirV7 ={720,30,30,90},PositionDameNoirV8 ={840,30,30,90};
SDL_Rect PositionPionBlancV1 = {0,630,30,90}, PositionPionBlancV2 ={120,630,30,90},PositionPionBlancV3 ={240,630,30,90},PositionPionBlancV4 ={360,630,30,90},PositionPionBlancV5 ={480,630,30,90},PositionPionBlancV6 ={600,630,30,90},PositionPionBlancV7 ={720,630,30,90},PositionPionBlancV8 ={840,630,30,90};
SDL_Rect PositionDameBlancV1 = {0,750,30,90}, PositionDameBlancV2 ={120,750,30,90},PositionDameBlancV3 ={240,750,30,90},PositionDameBlancV4 ={360,750,30,90},PositionDameBlancV5 ={480,750,30,90},PositionDameBlancV6 ={600,750,30,90},PositionDameBlancV7 ={720,750,30,90},PositionDameBlancV8 ={840,750,30,90};
SDL_Rect PositionPionNoirH1 = {30,120,90,30}, PositionPionNoirH2 ={150,120,90,30},PositionPionNoirH3 ={270,120,90,30},PositionPionNoirH4 ={390,120,90,30},PositionPionNoirH5 ={510,120,90,30},PositionPionNoirH6 ={630,120,90,30},PositionPionNoirH7 ={750,120,90,30};
SDL_Rect PositionPionBlancH1 = {30,720,90,30}, PositionPionBlancH2 ={150,720,90,30},PositionPionBlancH3 ={270,720,90,30},PositionPionBlancH4 ={390,720,90,30},PositionPionBlancH5 ={510,720,90,30},PositionPionBlancH6 ={630,720,90,30},PositionPionBlancH7 ={750,720,90,30};
SDL_Rect TRN = {390,30,90,90};
SDL_Rect TRB = {390,750,90,90};


// dévlaration des surfaces

 SDL_Surface  *RB =NULL, *RN = NULL, *PionNoirV1 = NULL, *PionNoirV2 = NULL,*PionNoirV3 = NULL,*PionNoirV4 = NULL,*PionNoirV5 = NULL,*PionNoirV6 = NULL,*PionNoirV7 = NULL,*PionNoirV8 = NULL,*PionNoirH1 = NULL,*PionNoirH2 = NULL,*PionNoirH3 = NULL,*PionNoirH4 = NULL,*PionNoirH5 = NULL,*PionNoirH6 = NULL, *PionNoirH7 = SDL_LoadBMP("src/PNH.bmp"), *PionBlancV1 = SDL_LoadBMP("src/PBV.bmp"), *PionBlancV2 = SDL_LoadBMP("src/PBV.bmp"), *PionBlancV3 = NULL, *PionBlancV4 = NULL, *PionBlancV5 = NULL, *PionBlancV6 = NULL, *PionBlancV7 = NULL, *PionBlancV8 = NULL, *PionBlancH1 = NULL,*PionBlancH2 = NULL, *PionBlancH3 = NULL, *PionBlancH4 = NULL,*PionBlancH5 = NULL, *PionBlancH6 = NULL,*PionBlancH7 = NULL;
 SDL_Surface *DameNoirV1 = NULL,*DameNoirV2 = NULL,*DameNoirV3 = NULL,*DameNoirV4 = NULL,*DameNoirV5 = NULL,*DameNoirV6 = NULL,*DameNoirV7 = NULL,*DameNoirV8 = NULL, *DameBlancV1 = NULL, *DameBlancV2 = NULL, *DameBlancV3 = NULL, *DameBlancV4 = NULL, *DameBlancV5 = NULL, *DameBlancV6 = NULL, *DameBlancV7 = NULL, *DameBlancV8 = NULL;

//cahrgement des images

RB = SDL_LoadBMP("src/RB.bmp");
RN = SDL_LoadBMP("src/RN.bmp");
PionNoirV1 = SDL_LoadBMP("src/PNV.bmp");
PionNoirV2 = SDL_LoadBMP("src/PNV.bmp");
PionNoirV3 = SDL_LoadBMP("src/PNV.bmp");
PionNoirV4 = SDL_LoadBMP("src/PNV.bmp");
PionNoirV5 = SDL_LoadBMP("src/PNV.bmp");
PionNoirV6 = SDL_LoadBMP("src/PNV.bmp");
PionNoirV7 = SDL_LoadBMP("src/PNV.bmp");
PionNoirV8 = SDL_LoadBMP("src/PNV.bmp");

PionNoirH1 = SDL_LoadBMP("src/PNH.bmp");
PionNoirH2 = SDL_LoadBMP("src/PNH.bmp");
PionNoirH3 = SDL_LoadBMP("src/PNH.bmp");
PionNoirH4 = SDL_LoadBMP("src/PNH.bmp");
PionNoirH5 = SDL_LoadBMP("src/PNH.bmp");
PionNoirH6 = SDL_LoadBMP("src/PNH.bmp");
PionNoirH7 = SDL_LoadBMP("src/PNH.bmp");

PionBlancV1 = SDL_LoadBMP("src/PBV.bmp");
PionBlancV2 = SDL_LoadBMP("src/PBV.bmp");
PionBlancV3 = SDL_LoadBMP("src/PBV.bmp");
PionBlancV4 = SDL_LoadBMP("src/PBV.bmp");
PionBlancV5 = SDL_LoadBMP("src/PBV.bmp");
PionBlancV6 = SDL_LoadBMP("src/PBV.bmp");
PionBlancV7 = SDL_LoadBMP("src/PBV.bmp");
PionBlancV8 = SDL_LoadBMP("src/PBV.bmp");

PionBlancH1 = SDL_LoadBMP("src/PBH.bmp");
PionBlancH2 = SDL_LoadBMP("src/PBH.bmp");
PionBlancH3 = SDL_LoadBMP("src/PBH.bmp");
PionBlancH4 = SDL_LoadBMP("src/PBH.bmp");
PionBlancH5 = SDL_LoadBMP("src/PBH.bmp");
PionBlancH6 = SDL_LoadBMP("src/PBH.bmp");
PionBlancH7 = SDL_LoadBMP("src/PBH.bmp");

DameNoirV1 = SDL_LoadBMP("src/DN.bmp");
DameNoirV2 = SDL_LoadBMP("src/DN.bmp");
DameNoirV3 = SDL_LoadBMP("src/DN.bmp");
DameNoirV4 = SDL_LoadBMP("src/DN.bmp");
DameNoirV5 = SDL_LoadBMP("src/DN.bmp");
DameNoirV6 = SDL_LoadBMP("src/DN.bmp");
DameNoirV7 = SDL_LoadBMP("src/DN.bmp");
DameNoirV8 = SDL_LoadBMP("src/DN.bmp");

DameBlancV1 = SDL_LoadBMP("src/DB.bmp");
DameBlancV2 = SDL_LoadBMP("src/DB.bmp");
DameBlancV3 = SDL_LoadBMP("src/DB.bmp");
DameBlancV4 = SDL_LoadBMP("src/DB.bmp");
DameBlancV5 = SDL_LoadBMP("src/DB.bmp");
DameBlancV6 = SDL_LoadBMP("src/DB.bmp");
DameBlancV7 = SDL_LoadBMP("src/DB.bmp");
DameBlancV8 = SDL_LoadBMP("src/DB.bmp");


// création des textures des differentes pieces
     
     SDL_Texture * texRN = SDL_CreateTextureFromSurface(renderer, RN),* texRB = SDL_CreateTextureFromSurface(renderer, RB),*texPNV1 = SDL_CreateTextureFromSurface(renderer, PionNoirV1),*texPNV2 = SDL_CreateTextureFromSurface(renderer, PionNoirV2), *texPNV3 = SDL_CreateTextureFromSurface(renderer, PionNoirV3), *texPNV4 = SDL_CreateTextureFromSurface(renderer, PionNoirV4), *texPNV5 = SDL_CreateTextureFromSurface(renderer, PionNoirV5),*texPNV6 = SDL_CreateTextureFromSurface(renderer, PionNoirV6),*texPNV7 = SDL_CreateTextureFromSurface(renderer, PionNoirV7),*texPNV8 = SDL_CreateTextureFromSurface(renderer, PionNoirV8);
     SDL_Texture * texPBV1 = SDL_CreateTextureFromSurface(renderer, PionBlancV1), *texPBV2 = SDL_CreateTextureFromSurface(renderer, PionBlancV2), *texPBV3 = SDL_CreateTextureFromSurface(renderer, PionBlancV3), *texPBV4 = SDL_CreateTextureFromSurface(renderer, PionBlancV4), *texPBV5 = SDL_CreateTextureFromSurface(renderer, PionBlancV5),*texPBV6 = SDL_CreateTextureFromSurface(renderer, PionBlancV6),*texPBV7 = SDL_CreateTextureFromSurface(renderer, PionBlancV7),*texPBV8 = SDL_CreateTextureFromSurface(renderer, PionBlancV8);
     SDL_Texture * texDNV1 = SDL_CreateTextureFromSurface(renderer, DameNoirV1), *texDNV2 = SDL_CreateTextureFromSurface(renderer, DameNoirV2), *texDNV3 = SDL_CreateTextureFromSurface(renderer, DameNoirV3), *texDNV4 = SDL_CreateTextureFromSurface(renderer, DameNoirV4), *texDNV5 = SDL_CreateTextureFromSurface(renderer, DameNoirV5),*texDNV6 = SDL_CreateTextureFromSurface(renderer, DameNoirV6),*texDNV7 = SDL_CreateTextureFromSurface(renderer, DameNoirV7),*texDNV8 = SDL_CreateTextureFromSurface(renderer, DameNoirV8);
     SDL_Texture * texDBV1 = SDL_CreateTextureFromSurface(renderer, DameBlancV1), *texDBV2 = SDL_CreateTextureFromSurface(renderer, DameBlancV2), *texDBV3 = SDL_CreateTextureFromSurface(renderer, DameBlancV3), *texDBV4 = SDL_CreateTextureFromSurface(renderer, DameBlancV4), *texDBV5 = SDL_CreateTextureFromSurface(renderer, DameBlancV5),*texDBV6 = SDL_CreateTextureFromSurface(renderer, DameBlancV6),*texDBV7 = SDL_CreateTextureFromSurface(renderer, DameBlancV7),*texDBV8 = SDL_CreateTextureFromSurface(renderer, DameBlancV8);
     SDL_Texture * texPNH1 = SDL_CreateTextureFromSurface(renderer, PionNoirH1),*texPNH2 = SDL_CreateTextureFromSurface(renderer, PionNoirH2), *texPNH3 = SDL_CreateTextureFromSurface(renderer, PionNoirH3), *texPNH4 = SDL_CreateTextureFromSurface(renderer, PionNoirH4), *texPNH5 = SDL_CreateTextureFromSurface(renderer, PionNoirH5),*texPNH6 = SDL_CreateTextureFromSurface(renderer, PionNoirH6),*texPNH7 = SDL_CreateTextureFromSurface(renderer, PionNoirH7);
     SDL_Texture * texPBH1 = SDL_CreateTextureFromSurface(renderer, PionBlancH1),*texPBH2 = SDL_CreateTextureFromSurface(renderer, PionBlancH2), *texPBH3 = SDL_CreateTextureFromSurface(renderer, PionBlancH3), *texPBH4 = SDL_CreateTextureFromSurface(renderer, PionBlancH4), *texPBH5 = SDL_CreateTextureFromSurface(renderer, PionBlancH5),*texPBH6 = SDL_CreateTextureFromSurface(renderer, PionBlancH6),*texPBH7 = SDL_CreateTextureFromSurface(renderer, PionBlancH7);
    int select=0;

//boucle d'execution
    
    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
            case SDL_MOUSEBUTTONDOWN :
            			// selection de la piece grace à la fonction chercherselection
            			select= chercherselection(event.button.x,event.button.y,arguments);
						printf("%d\n",select);
                        switch(select)
                        {
						 case 1:	moveRoi(&TRB);break;
						 case 2:    moveRoi(&TRN);break;
						 case 3:    movePionNoir(&PositionPionNoirV1);break;
                         case 4:    movePionNoir(&PositionPionNoirV2);break;
                         case 5:    movePionNoir(&PositionPionNoirV3);break;
                         case 6:    movePionNoir(&PositionPionNoirV4);break;
                         case 7:    movePionNoir(&PositionPionNoirV5);break;
                         case 8:    movePionNoir(&PositionPionNoirV6);break;
                         case 9:    movePionNoir(&PositionPionNoirV7);break;
                         case 10:   movePionNoir(&PositionPionNoirV8);break;
                         case 11:   movePionBlanc(&PositionPionBlancV1);break;
                         case 12:   movePionBlanc(&PositionPionBlancV2);break;
                         case 13:   movePionBlanc(&PositionPionBlancV3);break;
                         case 14:   movePionBlanc(&PositionPionBlancV4);break;
                         case 15:   movePionBlanc(&PositionPionBlancV5);break;
                         case 16:   movePionBlanc(&PositionPionBlancV6);break;
                         case 17:   movePionBlanc(&PositionPionBlancV7);break;
                         case 18:   movePionBlanc(&PositionPionBlancV8);break;
                         case 19:   movePionBlanc(&PositionPionBlancH1);break;
                         case 20:   movePionBlanc(&PositionPionBlancH2);break;
                         case 21:   movePionBlanc(&PositionPionBlancH3);break;
                         case 22:   movePionBlanc(&PositionPionBlancH4);break;
                         case 23:   movePionBlanc(&PositionPionBlancH5);break;
                         case 24:   movePionBlanc(&PositionPionBlancH6);break;
                         case 25:   movePionBlanc(&PositionPionBlancH7);break;
                         case 26:   movePionNoir(&PositionPionNoirH1);break;
                         case 27:   movePionNoir(&PositionPionNoirH2);break;
                         case 28:   movePionNoir(&PositionPionNoirH3);break;
                         case 29:   movePionNoir(&PositionPionNoirH4);break;
                         case 30:   movePionNoir(&PositionPionNoirH5);break;
                         case 31:   movePionNoir(&PositionPionNoirH6);break;
                         case 32:   movePionNoir(&PositionPionNoirH7);break;
                         case 33:   moveDameNoir(&PositionDameNoirV1);break;
                         case 34:   moveDameNoir(&PositionDameNoirV2);break;
                         case 35:   moveDameNoir(&PositionDameNoirV3);break;
                         case 36:   moveDameNoir(&PositionDameNoirV4);break;
                         case 37:   moveDameNoir(&PositionDameNoirV5);break;
                         case 38:   moveDameNoir(&PositionDameNoirV6);break;
                         case 39:   moveDameNoir(&PositionDameNoirV7);break;
                         case 40:   moveDameNoir(&PositionDameNoirV8);break;
                         case 41:   moveDameBlanc(&PositionDameBlancV1);break;
                         case 42:   moveDameBlanc(&PositionDameBlancV2);break;
                         case 43:   moveDameBlanc(&PositionDameBlancV3);break;
                         case 44:   moveDameBlanc(&PositionDameBlancV4);break;
                         case 45:   moveDameBlanc(&PositionDameBlancV5);break;
                         case 46:   moveDameBlanc(&PositionDameBlancV6);break;
                         case 47:   moveDameBlanc(&PositionDameBlancV7);break;
                         case 48:   moveDameBlanc(&PositionDameBlancV8);break;
                        }                           
                           break;
            case SDL_QUIT:
                quit = 1;
                break;   
        }
         
        // rafraichissement de l'affichage

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        
        SDL_RenderCopy(renderer, texRN, NULL, &TRN);
        SDL_RenderCopy(renderer, texRB, NULL, &TRB);

        SDL_RenderCopy(renderer, texPNV1, NULL, &PositionPionNoirV1);
        SDL_RenderCopy(renderer, texPNV2, NULL, &PositionPionNoirV2);
        SDL_RenderCopy(renderer, texPNV3, NULL, &PositionPionNoirV3);
        SDL_RenderCopy(renderer, texPNV4, NULL, &PositionPionNoirV4);
        SDL_RenderCopy(renderer, texPNV5, NULL, &PositionPionNoirV5);
        SDL_RenderCopy(renderer, texPNV6, NULL, &PositionPionNoirV6);
        SDL_RenderCopy(renderer, texPNV7, NULL, &PositionPionNoirV7);
        SDL_RenderCopy(renderer, texPNV8, NULL, &PositionPionNoirV8);

        SDL_RenderCopy(renderer, texPBV1, NULL, &PositionPionBlancV1);
        SDL_RenderCopy(renderer, texPBV2, NULL, &PositionPionBlancV2);
        SDL_RenderCopy(renderer, texPBV3, NULL, &PositionPionBlancV3);
        SDL_RenderCopy(renderer, texPBV4, NULL, &PositionPionBlancV4);
        SDL_RenderCopy(renderer, texPBV5, NULL, &PositionPionBlancV5);
        SDL_RenderCopy(renderer, texPBV6, NULL, &PositionPionBlancV6);
        SDL_RenderCopy(renderer, texPBV7, NULL, &PositionPionBlancV7);
        SDL_RenderCopy(renderer, texPBV8, NULL, &PositionPionBlancV8);

        SDL_RenderCopy(renderer, texDNV1, NULL, &PositionDameNoirV1);
        SDL_RenderCopy(renderer, texDNV2, NULL, &PositionDameNoirV2);
        SDL_RenderCopy(renderer, texDNV3, NULL, &PositionDameNoirV3);
        SDL_RenderCopy(renderer, texDNV4, NULL, &PositionDameNoirV4);
        SDL_RenderCopy(renderer, texDNV5, NULL, &PositionDameNoirV5);
        SDL_RenderCopy(renderer, texDNV6, NULL, &PositionDameNoirV6);
        SDL_RenderCopy(renderer, texDNV7, NULL, &PositionDameNoirV7);
        SDL_RenderCopy(renderer, texDNV8, NULL, &PositionDameNoirV8);

        SDL_RenderCopy(renderer, texDBV1, NULL, &PositionDameBlancV1);
        SDL_RenderCopy(renderer, texDBV2, NULL, &PositionDameBlancV2);
        SDL_RenderCopy(renderer, texDBV3, NULL, &PositionDameBlancV3);
        SDL_RenderCopy(renderer, texDBV4, NULL, &PositionDameBlancV4);
        SDL_RenderCopy(renderer, texDBV5, NULL, &PositionDameBlancV5);
        SDL_RenderCopy(renderer, texDBV6, NULL, &PositionDameBlancV6);
        SDL_RenderCopy(renderer, texDBV7, NULL, &PositionDameBlancV7);
        SDL_RenderCopy(renderer, texDBV8, NULL, &PositionDameBlancV8);

        SDL_RenderCopy(renderer, texPNH1, NULL, &PositionPionNoirH1);
        SDL_RenderCopy(renderer, texPNH2, NULL, &PositionPionNoirH2);
        SDL_RenderCopy(renderer, texPNH3, NULL, &PositionPionNoirH3);
        SDL_RenderCopy(renderer, texPNH4, NULL, &PositionPionNoirH4);
        SDL_RenderCopy(renderer, texPNH5, NULL, &PositionPionNoirH5);
        SDL_RenderCopy(renderer, texPNH6, NULL, &PositionPionNoirH6);
        SDL_RenderCopy(renderer, texPNH7, NULL, &PositionPionNoirH7);
        
        SDL_RenderCopy(renderer, texPBH1, NULL, &PositionPionBlancH1);
        SDL_RenderCopy(renderer, texPBH2, NULL, &PositionPionBlancH2);
        SDL_RenderCopy(renderer, texPBH3, NULL, &PositionPionBlancH3);
        SDL_RenderCopy(renderer, texPBH4, NULL, &PositionPionBlancH4);
        SDL_RenderCopy(renderer, texPBH5, NULL, &PositionPionBlancH5);
        SDL_RenderCopy(renderer, texPBH6, NULL, &PositionPionBlancH6);
        SDL_RenderCopy(renderer, texPBH7, NULL, &PositionPionBlancH7);
        
        SDL_RenderPresent(renderer);
    }
//supression avant sortie du jeu
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
// fonction de choix de la pièce à jouer
int chercherselection(int x,int y,argumentsdef){

	if (x<TRB.x+90 && x>TRB.x && y<TRB.y+90 && y>TRB.y){
		return 1;
	}
	if (x<TRN.x+90 && x>TRN.x && y<TRN.y+90 && y>TRN.y){
		return 2;
	}
	if (x<PositionPionNoirV1.x+ PositionPionNoirV1.w && x>PositionPionNoirV1.x && y<PositionPionNoirV1.y+PositionPionNoirV1.h && y>PositionPionNoirV1.y)
	{
		return 3;
	}
	if (x<PositionPionNoirV2.x+ PositionPionNoirV2.w && x>PositionPionNoirV2.x && y<PositionPionNoirV2.y+PositionPionNoirV2.h && y>PositionPionNoirV2.y)
	{
		return 4;
	}
	if (x<PositionPionNoirV3.x+ PositionPionNoirV3.w && x>PositionPionNoirV3.x && y<PositionPionNoirV3.y+PositionPionNoirV3.h && y>PositionPionNoirV3.y)
	{
		return 5;
	}
	if (x<PositionPionNoirV4.x+ PositionPionNoirV4.w && x>PositionPionNoirV4.x && y<PositionPionNoirV4.y+PositionPionNoirV4.h && y>PositionPionNoirV4.y)
	{
		return 6;
	}
	if (x<PositionPionNoirV5.x+ PositionPionNoirV5.w && x>PositionPionNoirV5.x && y<PositionPionNoirV5.y+PositionPionNoirV5.h && y>PositionPionNoirV5.y)
	{
		return 7;
	}if (x<PositionPionNoirV6.x+ PositionPionNoirV6.w && x>PositionPionNoirV6.x && y<PositionPionNoirV6.y+PositionPionNoirV6.h && y>PositionPionNoirV6.y)
	{
		return 8;
	}
	if (x<PositionPionNoirV7.x+ PositionPionNoirV7.w && x>PositionPionNoirV7.x && y<PositionPionNoirV7.y+PositionPionNoirV7.h && y>PositionPionNoirV7.y)
	{
		return 9;
	}
	if (x<PositionPionNoirV8.x+ PositionPionNoirV8.w && x>PositionPionNoirV8.x && y<PositionPionNoirV8.y+PositionPionNoirV8.h && y>PositionPionNoirV8.y)
	{
		return 10;
	}
	if (x<PositionPionBlancV1.x+PositionPionBlancV1.w && x>PositionPionBlancV1.x && y<PositionPionBlancV1.y+PositionPionBlancV1.h && y>PositionPionBlancV1.y)
	{
		return 11;
	}
	if (x<PositionPionBlancV2.x+PositionPionBlancV2.w && x>PositionPionBlancV2.x && y<PositionPionBlancV2.y+PositionPionBlancV2.h && y>PositionPionBlancV2.y)
	{
		return 12;
	}
	if (x<PositionPionBlancV3.x+PositionPionBlancV3.w && x>PositionPionBlancV3.x && y<PositionPionBlancV3.y+PositionPionBlancV3.h && y>PositionPionBlancV3.y)
	{
		return 13;
	}
	if (x<PositionPionBlancV4.x+PositionPionBlancV4.w && x>PositionPionBlancV4.x && y<PositionPionBlancV4.y+PositionPionBlancV4.h && y>PositionPionBlancV4.y)
	{
		return 14;
	}
	if (x<PositionPionBlancV5.x+PositionPionBlancV5.w && x>PositionPionBlancV5.x && y<PositionPionBlancV5.y+PositionPionBlancV5.h && y>PositionPionBlancV5.y)
	{
		return 15;
	}if (x<PositionPionBlancV6.x+PositionPionBlancV6.w && x>PositionPionBlancV6.x && y<PositionPionBlancV6.y+PositionPionBlancV6.h && y>PositionPionBlancV6.y)
	{
		return 16;
	}
	if (x<PositionPionBlancV7.x+PositionPionBlancV7.w && x>PositionPionBlancV7.x && y<PositionPionBlancV7.y+PositionPionBlancV7.h && y>PositionPionBlancV7.y)
	{
		return 17;
	}
	if (x<PositionPionBlancV8.x+PositionPionBlancV8.w && x>PositionPionBlancV8.x && y<PositionPionBlancV8.y+PositionPionBlancV8.h && y>PositionPionBlancV8.y)
	{
		return 18;
	}
	if (x<PositionPionBlancH1.x+PositionPionBlancH1.w && x>PositionPionBlancH1.x && y<PositionPionBlancH1.y+PositionPionBlancH1.h && y>PositionPionBlancH1.y)
	{
		return 19;
	}
	if (x<PositionPionBlancH2.x+PositionPionBlancH2.w && x>PositionPionBlancH2.x && y<PositionPionBlancH2.y+PositionPionBlancH2.h && y>PositionPionBlancH2.y)
	{
		return 20;
	}
	if (x<PositionPionBlancH3.x+PositionPionBlancH3.w && x>PositionPionBlancH3.x && y<PositionPionBlancH3.y+PositionPionBlancH3.h && y>PositionPionBlancH3.y)
	{
		return 21;
	}
	if (x<PositionPionBlancH4.x+PositionPionBlancH4.w && x>PositionPionBlancH4.x && y<PositionPionBlancH4.y+PositionPionBlancH4.h && y>PositionPionBlancH4.y)
	{
		return 22;
	}
	if (x<PositionPionBlancH5.x+PositionPionBlancH5.w && x>PositionPionBlancH5.x && y<PositionPionBlancH5.y+PositionPionBlancH5.h && y>PositionPionBlancH5.y)
	{
		return 23;
	}
	if (x<PositionPionBlancH6.x+PositionPionBlancH6.w && x>PositionPionBlancH6.x && y<PositionPionBlancH6.y+PositionPionBlancH6.h && y>PositionPionBlancH6.y)
	{
		return 24;
	}
	if (x<PositionPionBlancH7.x+PositionPionBlancH7.w && x>PositionPionBlancH7.x && y<PositionPionBlancH7.y+PositionPionBlancH7.h && y>PositionPionBlancH7.y)
	{
		return 25;
	}
    if (x<PositionPionNoirH1.x+PositionPionNoirH1.w && x>PositionPionNoirH1.x && y<PositionPionNoirH1.y+PositionPionNoirH1.h && y>PositionPionNoirH1.y)
	{
		return 26;
	}
	if (x<PositionPionNoirH2.x+PositionPionNoirH2.w && x>PositionPionNoirH2.x && y<PositionPionNoirH2.y+PositionPionNoirH2.h && y>PositionPionNoirH2.y)
	{
		return 27;
	}
	if (x<PositionPionNoirH3.x+PositionPionNoirH3.w && x>PositionPionNoirH3.x && y<PositionPionNoirH3.y+PositionPionNoirH3.h && y>PositionPionNoirH3.y)
	{
		return 28;
	}
	if (x<PositionPionNoirH4.x+PositionPionNoirH4.w && x>PositionPionNoirH4.x && y<PositionPionNoirH4.y+PositionPionNoirH4.h && y>PositionPionNoirH4.y)
	{
		return 29;
	}
	if (x<PositionPionNoirH5.x+PositionPionNoirH5.w && x>PositionPionNoirH5.x && y<PositionPionNoirH5.y+PositionPionNoirH5.h && y>PositionPionNoirH5.y)
	{
		return 30;
	}
	if (x<PositionPionNoirH6.x+PositionPionNoirH6.w && x>PositionPionNoirH6.x && y<PositionPionNoirH6.y+PositionPionNoirH6.h && y>PositionPionNoirH6.y)
	{
		return 31;
	}
	if (x<PositionPionNoirH7.x+PositionPionNoirH7.w && x>PositionPionNoirH7.x && y<PositionPionNoirH7.y+PositionPionNoirH7.h && y>PositionPionNoirH7.y)
	{
		return 32;
	}
	if (x<PositionDameNoirV1.x+PositionDameNoirV1.w && x>PositionDameNoirV1.x && y<PositionDameNoirV1.y+PositionDameNoirV1.h && y>PositionDameNoirV1.y)
	{
		return 33;
	}
	if (x<PositionDameNoirV2.x+PositionDameNoirV2.w && x>PositionDameNoirV2.x && y<PositionDameNoirV2.y+PositionDameNoirV2.h && y>PositionDameNoirV2.y)
	{
		return 34;
	}
	if (x<PositionDameNoirV3.x+PositionDameNoirV3.w && x>PositionDameNoirV3.x && y<PositionDameNoirV3.y+PositionDameNoirV3.h && y>PositionDameNoirV3.y)
	{	return 35;
	}
	if (x<PositionDameNoirV4.x+PositionDameNoirV4.w && x>PositionDameNoirV4.x && y<PositionDameNoirV4.y+PositionDameNoirV4.h && y>PositionDameNoirV4.y)
	{
		return 36;
	}
	if (x<PositionDameNoirV5.x+PositionDameNoirV5.w && x>PositionDameNoirV5.x && y<PositionDameNoirV5.y+PositionDameNoirV5.h && y>PositionDameNoirV5.y)
	{
		return 37;
	}if (x<PositionDameNoirV6.x+PositionDameNoirV6.w && x>PositionDameNoirV6.x && y<PositionDameNoirV6.y+PositionDameNoirV6.h && y>PositionDameNoirV6.y)
	{
		return 38;
	}
	if (x<PositionDameNoirV7.x+PositionDameNoirV7.w && x>PositionDameNoirV7.x && y<PositionDameNoirV7.y+PositionDameNoirV7.h && y>PositionDameNoirV7.y)
	{
		return 39;
	}
	if (x<PositionDameNoirV8.x+PositionDameNoirV8.w && x>PositionDameNoirV8.x && y<PositionDameNoirV8.y+PositionDameNoirV8.h && y>PositionDameNoirV8.y)
	{
		return 40;
	}
	 if (x<PositionDameBlancV1.x+PositionDameBlancV1.w && x>PositionDameBlancV1.x && y<PositionDameBlancV1.y+PositionDameBlancV1.h && y>PositionDameBlancV1.y)
	{
		return 41;
	}
	if (x<PositionDameBlancV2.x+PositionDameBlancV2.w && x>PositionDameBlancV2.x && y<PositionDameBlancV2.y+PositionDameBlancV2.h && y>PositionDameBlancV2.y)
	{
		return 42;
	}
	if (x<PositionDameBlancV3.x+PositionDameBlancV3.w && x>PositionDameBlancV3.x && y<PositionDameBlancV3.y+PositionDameBlancV3.h && y>PositionDameBlancV3.y)
	{
		return 43;
	}
	if (x<PositionDameBlancV4.x+PositionDameBlancV4.w && x>PositionDameBlancV4.x && y<PositionDameBlancV4.y+PositionDameBlancV4.h && y>PositionDameBlancV4.y)
	{
		return 44;
	}
	if (x<PositionDameBlancV5.x+PositionDameBlancV5.w && x>PositionDameBlancV5.x && y<PositionDameBlancV5.y+PositionDameBlancV5.h && y>PositionDameBlancV5.y)
	{
		return 45;
	}if (x<PositionDameBlancV6.x+PositionDameBlancV6.w && x>PositionDameBlancV6.x && y<PositionDameBlancV6.y+PositionDameBlancV6.h && y>PositionDameBlancV6.y)
	{
		return 46;
	}
	if (x<PositionDameBlancV7.x+PositionDameBlancV7.w && x>PositionDameBlancV7.x && y<PositionDameBlancV7.y+PositionDameBlancV7.h && y>PositionDameBlancV7.y)
	{
		return 47;
	}
	if (x<PositionDameBlancV8.x+PositionDameBlancV8.w && x>PositionDameBlancV8.x && y<PositionDameBlancV8.y+PositionDameBlancV8.h && y>PositionDameBlancV8.y)
	{
		return 48;
	}
return -1;
}

// fonction de déplacement du roi

void moveRoi(SDL_Rect *roi){
        SDL_Event event;
        while(1){
        
        SDL_WaitEvent(&event);
        if(event.type == SDL_MOUSEBUTTONDOWN){
        
        if (event.button.x<=(*roi).x+90 && event.button.x>=(*roi).x && event.button.y>=(*roi).y-120 && event.button.y<=(*roi).y-30)
                {
                    (*roi).y=(*roi).y-120;
                    printf("s %d\n",(*roi).y);
                    return;
                }
        if(event.button.x <= (*roi).x + 90 && event.button.x >= (*roi).x && event.button.y <= (*roi).y +210 && event.button.y >= (*roi).y +120 )
                {
                    (*roi).y = (*roi).y +120;
                    printf("s %d\n",(*roi).y);
                    return;
                }
        if(event.button.x <= (*roi).x -30 && event.button.x >= (*roi).x -120 && event.button.y <= (*roi).y +90 && event.button.y >= (*roi).y)
                {
                    (*roi).x = (*roi).x -120;
                    printf("s %d\n", (*roi).x);
                    return;
                                
                }
        if(event.button.x <= (*roi).x +210 && event.button.x >= (*roi).x +120 && event.button.y <= (*roi).y +90 && event.button.y >= (*roi).y){
                            (*roi).x = (*roi).x +120;
                                printf("s %d\n", (*roi).x);
                                return;
                            }
                        }
                        
                        }
}

//fonction de déplacement d'un pion Noir Vertical
void movePionNoirV(SDL_Rect *PionNoirV){
        SDL_Event event;
        while(1){
        
        SDL_WaitEvent(&event);
        if(event.type == SDL_MOUSEBUTTONDOWN){
        
        if (event.button.x<=(*PionNoirV).x+30 && event.button.x>=(*PionNoirV).x && event.button.y>=(*PionNoirV).y+120 && event.button.y<=(*PionNoirV).y+210)
                {
                    (*PionNoirV).y=(*PionNoirV).y+120;
                    printf("s %d\n",(*PionNoirV).y);
                    return;
                }
        if(event.button.x <= (*PionNoirV).x+120 && event.button.x >= (*PionNoirV).x+30 && event.button.y <= (*PionNoirV).y +120 && event.button.y >= (*PionNoirV).y +90 )
                {
                    (*PionNoirV).x = (*PionNoirV).x +30;
                    (*PionNoirV).y = (*PionNoirV).y +90;
                    (*PionNoirV).h =30;
                    (*PionNoirV).w =90;
                     
                
                    printf("s %d\n",(*PionNoirV).y);
                    return;
                }
        if(event.button.x <= (*PionNoirV).x && event.button.x >= (*PionNoirV).x-90 && event.button.y <= (*PionNoirV).y +120 && event.button.y >= (*PionNoirV).y+90)
                {
                    (*PionNoirV).x = (*PionNoirV).x-90;
                    (*PionNoirV).y = (*PionNoirV).y +90;
                    (*PionNoirV).h =30;
                    (*PionNoirV).w =90;
                    printf("s %d\n", (*PionNoirV).x);
                    return;
                                
                }
       
           }
// prise
           else if (event.type == SDL_KEYUP) 
   			   {
   				  	if (SDLK_s){
   			  		printf("keybord is working\n");
   			  		(*PionNoirV).h=0;
    		 		(*PionNoirV).x=0;
    		 		return;
     			    }
                }
                        
       }
}

//fonction de déplacement d'un pion Blanc Vertical

void movePionBlancV(SDL_Rect *PionBlancV){
        SDL_Event event;
        while(1){
        
        SDL_WaitEvent(&event);
        if(event.type == SDL_MOUSEBUTTONDOWN){
        
        if (event.button.x<=(*PionBlancV).x+30 && event.button.x>=(*PionBlancV).x && event.button.y>=(*PionBlancV).y-120 && event.button.y<=(*PionBlancV).y-30)
                {
                    (*PionBlancV).y=(*PionBlancV).y-120;
                    printf("s %d\n",(*PionBlancV).y);
                    return;
                }
        if(event.button.x <= (*PionBlancV).x+120 && event.button.x >= (*PionBlancV).x+30 && event.button.y <= (*PionBlancV).y && event.button.y >= (*PionBlancV).y-30 )
                {
                    (*PionBlancV).x = (*PionBlancV).x+30;
                    (*PionBlancV).y = (*PionBlancV).y-30;
                    (*PionBlancV).h =30;
                    (*PionBlancV).w =90;
                    printf("s %d\n",(*PionBlancV).y);
                    return;
                }
        if(event.button.x <= (*PionBlancV).x && event.button.x >= (*PionBlancV).x-90 && event.button.y <= (*PionBlancV).y && event.button.y >= (*PionBlancV).y-30)
                {
                    (*PionBlancV).x = (*PionBlancV).x-90;
                    (*PionBlancV).y = (*PionBlancV).y-30;
                    (*PionBlancV).h =30;
                    (*PionBlancV).w =90;
                    printf("s %d\n", (*PionBlancV).x);
                    return;
                                
                }
       
                }
// prise
                else if (event.type == SDL_KEYUP) 
   			       {
   				  	   if (SDLK_s){
   			  		   printf("keybord is working\n");
   			  		   (*PionBlancV).h=0;
    		 		   (*PionBlancV).x=0;
    		 		   return;
     			    }
                }
                        
            }
}

//fonction de déplacement d'un pion Noir Horizontal

void movePionNoirH(SDL_Rect *pionNH){
    SDL_Event event;
        while(1){
            SDL_WaitEvent(&event);
            if(event.type == SDL_MOUSEBUTTONDOWN){

                if(event.button.y <= (*pionNH).y + 150 && event.button.y >= (*pionNH).y+ 120 && event.button.x >= (*pionNH).x && event.button.x <= (*pionNH).x + 90 ){
                    (*pionNH).y = (*pionNH).y + 120;
                        printf("s %d\n", (*pionNH).y);
                        return;
                }
                if(event.button.y <= (*pionNH).y + 120 && event.button.y >= (*pionNH).y+ 30 && event.button.x >= (*pionNH).x-30 && event.button.x <= (*pionNH).x  ){
                    (*pionNH).x = (*pionNH).x -30;
                    (*pionNH).y= (*pionNH).y +30;
                       { (*pionNH).h= 90;
                         (*pionNH).w= 30;
                        }
                        printf("s %d\n", (*pionNH).y);
                        return;
                }
                if(event.button.y <= (*pionNH).y + 120 && event.button.y >= (*pionNH).y+ 30 && event.button.x >= (*pionNH).x + 90 && event.button.x <= (*pionNH).x + 120  ){
                    (*pionNH).x = (*pionNH).x + 90;
                    (*pionNH).y= (*pionNH).y + 30;
                    (*pionNH).h= 90;
                    (*pionNH).w= 30;
                        printf("s %d\n", (*pionNH).y);
                        return;
                }
            }
            if(event.type == event.key.keysym.sym){
                if(event.key.keysym.sym== SDLK_s)
                (*pionNH).y+=1000; 
            }
// prise
            else if (event.type == SDL_KEYUP) 
   			   {
   				  	if (SDLK_s){
   			  		printf("keybord is working\n");
   			  		(*pionNH).h=0;
    		 		(*pionNH).x=0;
    		 		return;
     			    }
                }
        }
}

// fonction de choix de déplacement selon l'etat du Pion

void movePionNoir(SDL_Rect *pionNH){
    if ((*pionNH).h==30){
        movePionNoirH(pionNH);
    }
    else  movePionNoirV(pionNH);
}
void movePionBlanc(SDL_Rect *pionBH){
    if ((*pionBH).h==30){
        movePionBlancH(pionBH);
    }
    else  movePionBlancV(pionBH);
}

//fonction de déplacement d'un pion Blanc Horizontal

void movePionBlancH(SDL_Rect *pionBH){
    SDL_Event event;
        while(1){
            SDL_WaitEvent(&event);
            if(event.type == SDL_MOUSEBUTTONDOWN){
                if(event.button.y <= (*pionBH).y - 90 && event.button.y >= (*pionBH).y- 120 && event.button.x >= (*pionBH).x && event.button.x <= (*pionBH).x + 90 ){
                    (*pionBH).y = (*pionBH).y - 120;
                        printf("s %d\n", (*pionBH).y);
                        return;
                }
                if(event.button.y <= (*pionBH).y && event.button.y >= (*pionBH).y - 90 && event.button.x >= (*pionBH).x - 30 && event.button.x <= (*pionBH).x  ){
                   
                    (*pionBH).x = (*pionBH).x -30;
                    (*pionBH).y= (*pionBH).y - 90;
                    (*pionBH).h= 90;
                    (*pionBH).w= 30;
                
                        printf("s %d\n", (*pionBH).y);
                        return;
                }
                if(event.button.y <= (*pionBH).y  && event.button.y >= (*pionBH).y - 90 && event.button.x >= (*pionBH).x + 90 && event.button.x <= (*pionBH).x+120){
                    (*pionBH).x = (*pionBH).x + 90;
                    (*pionBH).y= (*pionBH).y - 90;
                    (*pionBH).h= 90;
                    (*pionBH).w= 30;
                        printf("s %d\n", (*pionBH).y);
                        return;
                }
            }
// prise
            else if (event.type == SDL_KEYUP) 
   			   {
   				  	if (SDLK_s){
   			  		printf("keybord is working\n");
   			  		(*pionBH).h=0;
    		 		(*pionBH).x=0;
    		 		return;
     			    }
                }  
        }
}

// fonction de choix de déplacement selon etat de la Dame 

void moveDameNoir(SDL_Rect *pionNH){
    if ((*pionNH).h==30){
        moveDameNoirH(pionNH);
    }
    else  moveDameNoirV(pionNH);
}
void moveDameBlanc(SDL_Rect *pionNH){
    if ((*pionNH).h==30){
        moveDameBlancH(pionNH);
    }
    else  moveDameBlancV(pionNH);
}

//fonction de déplacement de la Dame Noir Vertical

void moveDameNoirV(SDL_Rect *DameNoirV){
        int N;
        SDL_Event event;
        while(1){
        
        SDL_WaitEvent(&event);
        if(event.type == SDL_MOUSEBUTTONDOWN){
        // avant et arriere
        if (event.button.x<=(*DameNoirV).x+30 && event.button.x>=(*DameNoirV).x)
                {  N=(event.button.y-(*DameNoirV).y)/120;
                    if((event.button.y-(*DameNoirV).y)<0)
                        N=N-1;
                    (*DameNoirV).y=(*DameNoirV).y+(N*120);
                    printf("s %d\n",(*DameNoirV).y);
                    return;
                }
         // avant gauche       
        if(event.button.x <= (*DameNoirV).x+120 && event.button.x >= (*DameNoirV).x+30 && event.button.y <= (*DameNoirV).y +120 && event.button.y >= (*DameNoirV).y +90 )
                {
                    (*DameNoirV).x = (*DameNoirV).x +30;
                    (*DameNoirV).y = (*DameNoirV).y +90;
                    (*DameNoirV).h =30;
                    (*DameNoirV).w =90;
                     
                
                    printf("s %d\n",(*DameNoirV).y);
                    return;
                }
        // avant droit
        if(event.button.x <= (*DameNoirV).x && event.button.x >= (*DameNoirV).x-90 && event.button.y <= (*DameNoirV).y +120 && event.button.y >= (*DameNoirV).y+90)
                {
                    (*DameNoirV).x = (*DameNoirV).x-90;
                    (*DameNoirV).y = (*DameNoirV).y +90;
                    (*DameNoirV).h =30;
                    (*DameNoirV).w =90;
                    printf("s %d\n", (*DameNoirV).x);
                    return;
                                
                }

        
        // arriere droit
        if(event.button.x <= (*DameNoirV).x && event.button.x >= (*DameNoirV).x-90 && event.button.y <= (*DameNoirV).y && event.button.y >= (*DameNoirV).y-30)
                {
                    (*DameNoirV).x = (*DameNoirV).x-90;
                    (*DameNoirV).y = (*DameNoirV).y-30;
                    (*DameNoirV).h =30;
                    (*DameNoirV).w =90;
                    printf("s %d\n", (*DameNoirV).x);
                    return;
                                
                }
        // arriere gauche
        if(event.button.x <= (*DameNoirV).x+120 && event.button.x >= (*DameNoirV).x+30 && event.button.y <= (*DameNoirV).y && event.button.y >= (*DameNoirV).y-30 )
                {
                    (*DameNoirV).x = (*DameNoirV).x+30;
                    (*DameNoirV).y = (*DameNoirV).y-30;
                    (*DameNoirV).h =30;
                    (*DameNoirV).w =90;
                    printf("s %d\n",(*DameNoirV).y);
                    return;
                }
        // lateral gauche et droite
        if(event.button.y <= (*DameNoirV).y+90 && event.button.y >= (*DameNoirV).y)
                { 
                    N=(event.button.x-(*DameNoirV).x)/120;
                    if((event.button.x-(*DameNoirV).x)<0)
                        N=N-1;
                    (*DameNoirV).x = (*DameNoirV).x+(N*120);
                    (*DameNoirV).y = (*DameNoirV).y;
                    
                    printf("s %d\n", (*DameNoirV).x);
                    return;
                                
                }


     }
// prise
     else if (event.type == SDL_KEYUP) 
   			   {
   				  	if (SDLK_s){
   			  		printf("keybord is working\n");
   			  		(*DameNoirV).h=0;
    		 		(*DameNoirV).x=0;
    		 		return;
     			    }
                }  
 }}

 //fonction de déplacement de la Dame Noir Horizontale

 void moveDameNoirH(SDL_Rect *DameNoirH){
int N;
SDL_Event event;
        while(1){
        
        SDL_WaitEvent(&event);
        if(event.type == SDL_MOUSEBUTTONDOWN){

        // arriere droit
        if(event.button.y <= (*DameNoirH).y && event.button.y >= (*DameNoirH).y - 90 && event.button.x >= (*DameNoirH).x - 30 && event.button.x <= (*DameNoirH).x  ){
                   
                    (*DameNoirH).x = (*DameNoirH).x -30;
                    (*DameNoirH).y= (*DameNoirH).y - 90;
                    (*DameNoirH).h= 90;
                    (*DameNoirH).w= 30;
                
                        printf("s %d\n", (*DameNoirH).y);
                        return;
                }
        // arriere gauche
        if(event.button.y <= (*DameNoirH).y  && event.button.y >= (*DameNoirH).y - 90 && event.button.x >= (*DameNoirH).x + 90 && event.button.x <= (*DameNoirH).x+120){
                    (*DameNoirH).x = (*DameNoirH).x + 90;
                    (*DameNoirH).y= (*DameNoirH).y - 90;
                    (*DameNoirH).h= 90;
                    (*DameNoirH).w= 30;
                        printf("s %d\n", (*DameNoirH).y);
                        return;
                }
         // avant et arriere

        if (event.button.x<=(*DameNoirH).x+90 && event.button.x>=(*DameNoirH).x)
                {  N=(event.button.y-(*DameNoirH).y)/120;
                    if((event.button.y-(*DameNoirH).y)<0)
                        N=N-1;
                    (*DameNoirH).y=(*DameNoirH).y+(N*120);
                    printf("s %d\n",(*DameNoirH).y);
                    return;
                }
        
        // avant droit 

        if(event.button.y <= (*DameNoirH).y + 120 && event.button.y >= (*DameNoirH).y+ 30 && event.button.x >= (*DameNoirH).x-30 && event.button.x <= (*DameNoirH).x  ){
                    (*DameNoirH).x = (*DameNoirH).x -30;
                    (*DameNoirH).y= (*DameNoirH).y +30;
                       { (*DameNoirH).h= 90;
                         (*DameNoirH).w= 30;
                        }
                        printf("s %d\n", (*DameNoirH).y);
                        return;
                }
        // avant gauche

        if(event.button.y <= (*DameNoirH).y + 120 && event.button.y >= (*DameNoirH).y+ 30 && event.button.x >= (*DameNoirH).x + 90 && event.button.x <= (*DameNoirH).x + 120  ){
                    (*DameNoirH).x = (*DameNoirH).x + 90;
                    (*DameNoirH).y= (*DameNoirH).y + 30;
                    (*DameNoirH).h= 90;
                    (*DameNoirH).w= 30;
                        printf("s %d\n", (*DameNoirH).y);
                        return;
                }
         // lateral gauche et droite

        if(event.button.y <= (*DameNoirH).y+30 && event.button.y >= (*DameNoirH).y)
                { 
                    N=(event.button.x-(*DameNoirH).x)/120;
                    if((event.button.x-(*DameNoirH).x)<0)
                        N=N-1;
                    (*DameNoirH).x = (*DameNoirH).x+(N*120);
                    (*DameNoirH).y = (*DameNoirH).y;
                    
                    printf("s %d\n", (*DameNoirH).x);
                    return;
                                
                }       

         }
// prise
         else if (event.type == SDL_KEYUP) 
   			   {
   				  	if (SDLK_s){
   			  		printf("keybord is working\n");
   			  		(*DameNoirH).h=0;
    		 		(*DameNoirH).x=0;
    		 		return;
     			    }
                }

                        
     }
}

//fonction de déplacement de la Dame Blanche Horizontale

void moveDameBlancH(SDL_Rect *DameBlancH){
int N;
SDL_Event event;
        while(1){
        
        SDL_WaitEvent(&event);
        if(event.type == SDL_MOUSEBUTTONDOWN){

        // avant gauche
        if(event.button.y <= (*DameBlancH).y && event.button.y >= (*DameBlancH).y - 90 && event.button.x >= (*DameBlancH).x - 30 && event.button.x <= (*DameBlancH).x  ){
                   
                    (*DameBlancH).x = (*DameBlancH).x -30;
                    (*DameBlancH).y= (*DameBlancH).y - 90;
                    (*DameBlancH).h= 90;
                    (*DameBlancH).w= 30;
                
                        printf("s %d\n", (*DameBlancH).y);
                        return;
                }
        // avant droit
        if(event.button.y <= (*DameBlancH).y  && event.button.y >= (*DameBlancH).y - 90 && event.button.x >= (*DameBlancH).x + 90 && event.button.x <= (*DameBlancH).x+120){
                    (*DameBlancH).x = (*DameBlancH).x + 90;
                    (*DameBlancH).y= (*DameBlancH).y - 90;
                    (*DameBlancH).h= 90;
                    (*DameBlancH).w= 30;
                        printf("s %d\n", (*DameBlancH).y);
                        return;
                }
         // avant et arriere

        if (event.button.x<=(*DameBlancH).x+90 && event.button.x>=(*DameBlancH).x)
                {  N=(event.button.y-(*DameBlancH).y)/120;
                    if((event.button.y-(*DameBlancH).y)<0)
                        N=N-1;
                    (*DameBlancH).y=(*DameBlancH).y+(N*120);
                    printf("s %d\n",(*DameBlancH).y);
                    return;
                }
        
        // arriere gauche

        if(event.button.y <= (*DameBlancH).y + 120 && event.button.y >= (*DameBlancH).y+ 30 && event.button.x >= (*DameBlancH).x-30 && event.button.x <= (*DameBlancH).x  ){
                    (*DameBlancH).x = (*DameBlancH).x -30;
                    (*DameBlancH).y= (*DameBlancH).y +30;
                       { (*DameBlancH).h= 90;
                         (*DameBlancH).w= 30;
                        }
                        printf("s %d\n", (*DameBlancH).y);
                        return;
                }
        // arriere droit

        if(event.button.y <= (*DameBlancH).y + 120 && event.button.y >= (*DameBlancH).y+ 30 && event.button.x >= (*DameBlancH).x + 90 && event.button.x <= (*DameBlancH).x + 120  ){
                    (*DameBlancH).x = (*DameBlancH).x + 90;
                    (*DameBlancH).y= (*DameBlancH).y + 30;
                    (*DameBlancH).h= 90;
                    (*DameBlancH).w= 30;
                        printf("s %d\n", (*DameBlancH).y);
                        return;
                }
         // lateral gauche et droite

        if(event.button.y <= (*DameBlancH).y+30 && event.button.y >= (*DameBlancH).y)
                { 
                    N=(event.button.x-(*DameBlancH).x)/120;
                    if((event.button.x-(*DameBlancH).x)<0)
                        N=N-1;
                    (*DameBlancH).x = (*DameBlancH).x+(N*120);
                    (*DameBlancH).y = (*DameBlancH).y;
                    
                    printf("s %d\n", (*DameBlancH).x);
                    return;
                                
                }       

            }
// prise 
            else if (event.type == SDL_KEYUP) 
   			   {
   				  	if (SDLK_s){
   			  		printf("keybord is working\n");
   			  		(*DameBlancH).h=0;
    		 		(*DameBlancH).x=0;
    		 		return;
     			    }
                }
                        
        }
}

//fonction de déplacement de la Dame Blanche Verticale

void moveDameBlancV(SDL_Rect *DameBlancV){
        int N;
        SDL_Event event;
        while(1){
        
        SDL_WaitEvent(&event);
        if(event.type == SDL_MOUSEBUTTONDOWN){
        // avant et arriere
        if (event.button.x<=(*DameBlancV).x+30 && event.button.x>=(*DameBlancV).x)
                {  N=(event.button.y-(*DameBlancV).y)/120;
                    if((event.button.y-(*DameBlancV).y)<0)
                        N=N-1;
                    (*DameBlancV).y=(*DameBlancV).y+(N*120);
                    printf("s %d\n",(*DameBlancV).y);
                    return;
                }
         // arriere droit       
        if(event.button.x <= (*DameBlancV).x+120 && event.button.x >= (*DameBlancV).x+30 && event.button.y <= (*DameBlancV).y +120 && event.button.y >= (*DameBlancV).y +90 )
                {
                    (*DameBlancV).x = (*DameBlancV).x +30;
                    (*DameBlancV).y = (*DameBlancV).y +90;
                    (*DameBlancV).h =30;
                    (*DameBlancV).w =90;
                     
                
                    printf("s %d\n",(*DameBlancV).y);
                    return;
                }
        // arriere gauche
        if(event.button.x <= (*DameBlancV).x && event.button.x >= (*DameBlancV).x-90 && event.button.y <= (*DameBlancV).y +120 && event.button.y >= (*DameBlancV).y+90)
                {
                    (*DameBlancV).x = (*DameBlancV).x-90;
                    (*DameBlancV).y = (*DameBlancV).y +90;
                    (*DameBlancV).h =30;
                    (*DameBlancV).w =90;
                    printf("s %d\n", (*DameBlancV).x);
                    return;
                                
                }

        
        // avant gauche
        if(event.button.x <= (*DameBlancV).x && event.button.x >= (*DameBlancV).x-90 && event.button.y <= (*DameBlancV).y && event.button.y >= (*DameBlancV).y-30)
                {
                    (*DameBlancV).x = (*DameBlancV).x-90;
                    (*DameBlancV).y = (*DameBlancV).y-30;
                    (*DameBlancV).h =30;
                    (*DameBlancV).w =90;
                    printf("s %d\n", (*DameBlancV).x);
                    return;
                                
                }
        // avant droit
        if(event.button.x <= (*DameBlancV).x+120 && event.button.x >= (*DameBlancV).x+30 && event.button.y <= (*DameBlancV).y && event.button.y >= (*DameBlancV).y-30 )
                {
                    (*DameBlancV).x = (*DameBlancV).x+30;
                    (*DameBlancV).y = (*DameBlancV).y-30;
                    (*DameBlancV).h =30;
                    (*DameBlancV).w =90;
                    printf("s %d\n",(*DameBlancV).y);
                    return;
                }
        // lateral gauche et droite
        if(event.button.y <= (*DameBlancV).y+90 && event.button.y >= (*DameBlancV).y)
                { 
                    N=(event.button.x-(*DameBlancV).x)/120;
                    if((event.button.x-(*DameBlancV).x)<0)
                        N=N-1;
                    (*DameBlancV).x = (*DameBlancV).x+(N*120);
                    (*DameBlancV).y = (*DameBlancV).y;
                    
                    printf("s %d\n", (*DameBlancV).x);
                    return;
                                
                }



     }
// prise
     else if (event.type == SDL_KEYUP) 
     {
     	if (SDLK_s){
     		printf("keybord is working\n");
     		(*DameBlancV).h=0;
     		(*DameBlancV).x=0;
     		return;
     	}
     }
 }}


