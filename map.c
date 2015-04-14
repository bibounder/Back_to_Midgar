/*
** map.c for  in 
** 
** Made by GROULEZ Florian
** Login   <groule_f@etna-alternance.net>
** 
** Started on  Fri Apr  3 04:33:34 2015 GROULEZ Florian
** Last update Wed Apr  8 03:51:39 2015 GROULEZ Florian
*/

#include	"lib/back_to_midgar.h"

void		my_pause()
{
  int		continuer;
  SDL_Event	event;

  continuer = 1;
  while (continuer)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
        {
	  continuer = 0;
        }
    }
}

int		load_map()
{
  SDL_Surface	*ecran;
  SDL_Surface	*imageDeFond;
  SDL_Rect positionFond;

  ecran = NULL;
  imageDeFond = NULL;
  positionFond.x = 0;
  positionFond.y = 0;
  SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(1024, 576, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Back to Midgar", NULL);
  imageDeFond = IMG_Load("./map/background.png");
  SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
  SDL_Flip(ecran);
  load_perso(ecran);
  my_pause();
  SDL_FreeSurface(imageDeFond);
  SDL_Quit();
  return EXIT_SUCCESS;   
}
