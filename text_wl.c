/*
** text_wl.c for  in /home/novose_s
** 
** Made by GROULEZ Florian
** Login   <groule_f@etna-alternance.net>
** 
** Started on  Fri Apr 10 04:15:49 2015 GROULEZ Florian
** Last update Fri Apr 10 04:15:52 2015 GROULEZ Florian
*/

#include	"lib/back_to_midgar.h"

void		text_lose(struct SDL_Surface *ecran)
{
  TTF_Font	*police;
  SDL_Surface	*texte;
  SDL_Rect	position;
  SDL_Color	black = {2,2,2,0};
  int		i;

  for (i = 0; i < 6; i++)
    {
      police = TTF_OpenFont("Chicken Butt.ttf", 100);
      texte = TTF_RenderText_Blended(police, "YOU LOSE", black);
      position.x = 300;
      position.y = 200;
      SDL_BlitSurface(texte, NULL, ecran, &position);
      TTF_CloseFont(police);
      SDL_FreeSurface(texte);
      SDL_Flip(ecran);
    }
}

void		text_win(struct SDL_Surface *ecran)
{
  TTF_Font	*police;
  SDL_Surface	*texte;
  SDL_Rect	position;
  SDL_Color	black = {2,2,2,0};
  int		i;

  for (i = 0; i < 6; i++)
    {
      police = TTF_OpenFont("Chicken Butt.ttf", 100);
      texte = TTF_RenderText_Blended(police, "YOU WIN", black);
      position.x = 300;
      position.y = 200;
      SDL_BlitSurface(texte, NULL, ecran, &position);
      TTF_CloseFont(police);
      SDL_FreeSurface(texte);
      SDL_Flip(ecran);
    }
}
