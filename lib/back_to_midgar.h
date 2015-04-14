#ifndef         BACK_TO_MIDGAR_H
# define        BAKC_TO_MIDGAR_H

#include	<stdio.h>
#include	<time.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdarg.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_image.h>
#include	<SDL/SDL_ttf.h>

void		my_pause();
int		load_map();
int		attack();
int		slash();
int		fire();
int		thunder();
int		load_perso(struct SDL_Surface *ecran);
void		stat_players(struct SDL_Surface *ecran, int *pos_x_stat, int *pos_y_stat, int *table_stat);
void		aff_stat_players(struct SDL_Surface *ecran);
int		win_lose(struct SDL_Surface *ecran);
int		load_attacks(struct SDL_Surface *ecran);
void		text_lose(struct SDL_Surface *ecran);
void		text_win(struct SDL_Surface *ecran);
int             event_attacks(struct SDL_Surface *ecran);
int		bite();
int		earthquake();
int		doom();
int		turn();
int		my_exit();

typedef struct s_stat_player
{
  char	*name_player;
  int	pv_player;
  int	pm_player;
}		t_player;

typedef struct s_stat_ennemy
{
  char	*name_ennemy;
  int	pv_ennemy;
  int	pm_ennemy;
}		t_ennemy;

t_player       	player;
t_ennemy	ennemy;

#endif
