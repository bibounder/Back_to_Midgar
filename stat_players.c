/*
** stat_players.c for  in /home/novose_s
** 
** Made by GROULEZ Florian
** Login   <groule_f@etna-alternance.net>
** 
** Started on  Thu Apr  9 11:05:07 2015 GROULEZ Florian
** Last update Thu Apr  9 11:48:07 2015 GROULEZ Florian
*/

#include	"lib/back_to_midgar.h"

void		aff_stat_players(struct SDL_Surface *ecran)
{
  int		pos_x_stat[4] = {700, 800, 200, 300};
  int		pos_y_stat[4] = {100, 100, 100, 100};
  int		table_stat[4];

  table_stat[0] = player.pv_player;
  table_stat[1] = player.pm_player;
  table_stat[2] = ennemy.pv_ennemy;
  table_stat[3] = ennemy.pm_ennemy;
  stat_players(ecran, pos_x_stat, pos_y_stat, table_stat);

}

void		aff_mana_life(struct SDL_Surface *ecran)
{
  TTF_Font	*police;
  SDL_Surface	*texte;
  SDL_Rect	position;
  SDL_Color	black = {2,2,2,0};
  int		i;
  char		*table_pmv[6] = {"PV", "PM", "PV", "PM", "Sakhr", "You"};
  int		pos_x[6] = {650, 750, 150, 250, 200, 700};
  int		pos_y[6] = {100, 100, 100, 100, 57, 57};

  for (i = 0; i < 6; i++)
    {
      police = TTF_OpenFont("Chicken Butt.ttf", 40);
      texte = TTF_RenderText_Blended(police, table_pmv[i], black);
      position.x = pos_x[i];
      position.y = pos_y[i];
      SDL_BlitSurface(texte, NULL, ecran, &position);
      TTF_CloseFont(police);
      SDL_FreeSurface(texte);
      SDL_Flip(ecran);
    }
}

void		stat_players(struct SDL_Surface *ecran, int *pos_x_stat, int *pos_y_stat, int *table_stat)
{
  TTF_Font	*police;
  SDL_Surface	*texte;
  SDL_Rect	position;
  SDL_Color	black = {2,2,2,0};
  int		i;
  char		buffer[20];

  police = NULL;
  TTF_Init();
  for (i = 0; i < 4; i++)
    {
      aff_mana_life(ecran);
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
}
