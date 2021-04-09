
#include <SDL.h>
#include <stdio.h>
#include<stdlib.h>

void SDL_ExitWithError(const char *message);
int main(int argc, char **argv) {
       SDL_Window *window = NULL;
       if( SDL_Init(SDL_INIT_VIDEO)!=0)
{ SDL_ExitWithError("Initialisation SDL");
	//SDL_Log("erreur: Initialisation SDL > %s\n",SDL_GetError());
	//exit(EXIT_FAILURE);
}
       /* SDL_version nb;
        SDL_VERSION(&nb);
        printf("bienvenue sur la SDL %d.%d.%d !\n", nb.major, nb.minor, nb.patch);
        */
        window = SDL_CreateWindow("Premiere fentre SDL 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,1800,1600,SDL_WINDOW_MOUSE_FOCUS);
        if(window == NULL)
        {
        	SDL_ExitWithError("Creation fenetre echouee");
         //SDL_Log("erreur: Creation fenetre echouee > %s\n",SDL_GetError());
	     //exit(EXIT_FAILURE);
        }
         SDL_Delay(6000);
         SDL_DestroyWindow(window);
         SDL_Quit();
        return EXIT_SUCCESS;
         //return 0; 
   }
   void SDL_ExitWithError(const char *message)
   {
   	SDL_Log("ERREUR: %s > %s\n",message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
   }