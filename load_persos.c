/*
** load_persos.c for  in /home/novose_s
** 
** Made by GROULEZ Florian
** Login   <groule_f@etna-alternance.net>
** 
** Started on  Fri Apr  3 09:07:02 2015 GROULEZ Florian
** Last update Fri Apr 10 04:15:00 2015 GROULEZ Florian
*/

#include	"lib/back_to_midgar.h"

char *table_lien1[2] = {"./persos/drake.png","./persos/fire_mage.png"};

int table_x1[2] = {230,490};

int table_y1[2] = {180,0};

int		load_perso(struct SDL_Surface *ecran)
{
  int		i;
  SDL_Rect	position;
  SDL_Surface	*perso;


  for (i = 0; i < 2; i++)
    {
      perso = NULL;
      position.x = table_x1[i];
      position.y = table_y1[i];
      perso = IMG_Load(table_lien1[i]);
      SDL_BlitSurface(perso, NULL, ecran, &position);
    }
  load_attacks(ecran);
  return EXIT_SUCCESS;
}
