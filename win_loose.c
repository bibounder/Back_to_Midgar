/*
** win_loose.c for  in /home/novose_s
** 
** Made by GROULEZ Florian
** Login   <groule_f@etna-alternance.net>
** 
** Started on  Fri Apr 10 04:15:58 2015 GROULEZ Florian
** Last update Fri Apr 10 04:15:59 2015 GROULEZ Florian
*/

#include	"lib/back_to_midgar.h"

void		stat_pv(struct SDL_Surface *ecran, int *table_stat)
{
  TTF_Font	*police;
  SDL_Surface	*texte;
  SDL_Rect	position;
  SDL_Color	black = {2,2,2,0};
  int		i;
  char		buffer[20];
  int		pos_x_stat[4] = {700, 800, 200, 300};
  int		pos_y_stat[4] = {100, 100, 100, 100};

  police = NULL;
  TTF_Init();
  for (i = 0; i < 4; i++)
    {
      sprintf(buffer, "%d", table_stat[i]);
      police = TTF_OpenFont("Chicken Butt.ttf", 40);
      texte = TTF_RenderText_Blended(police, buffer, black);
      position.x = pos_x_stat[i];
      position.y = pos_y_stat[i];
      SDL_BlitSurface(texte, NULL, ecran, &position);
      TTF_CloseFont(police);
      SDL_FreeSurface(texte);
      SDL_Flip(ecran);
    }
  TTF_Quit();
}

void		lose(struct SDL_Surface *ecran)
{
  SDL_Rect	positionEnd;
  SDL_Surface	*end;

  end = NULL;
  positionEnd.x = 200;
  positionEnd.y = 100;
  end = IMG_Load("map/win_or_loose.png");
  SDL_BlitSurface(end, NULL, ecran, &positionEnd);
  SDL_Flip(ecran);
  text_lose(ecran);
}

void		win(struct SDL_Surface *ecran)
{
  SDL_Rect	positionEnd;
  SDL_Surface	*end;

  end = NULL;
  positionEnd.x = 200;
  positionEnd.y = 100;
  end = IMG_Load("map/win_or_loose.png");
  SDL_BlitSurface(end, NULL, ecran, &positionEnd);
  SDL_Flip(ecran);
  text_win(ecran);
}


int		win_lose(struct SDL_Surface *ecran)
{
  int		action;
  int		table_stat[4];

  table_stat[0] = player.pv_player;
  table_stat[1] = player.pm_player;
  table_stat[2] = ennemy.pv_ennemy;
  table_stat[3] = ennemy.pm_ennemy;
  action = 1;
  stat_pv(ecran, table_stat);
  if (player.pv_player <= 0)
    {
      action = 0;
      lose(ecran);
      return (action);
    }
  else if (ennemy.pv_ennemy <= 0)
    {
      action = 0;
      win(ecran);
      return (action);
    }
  return (action);
}
