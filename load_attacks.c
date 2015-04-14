/*
** load_attacks.c for  in /home/novose_s
** 
** Made by GROULEZ Florian
** Login   <groule_f@etna-alternance.net>
** 
** Started on  Tue Apr  7 05:37:12 2015 GROULEZ Florian
** Last update Fri Apr 10 04:13:54 2015 GROULEZ Florian
*/

#include	"./lib/back_to_midgar.h"

char *table_lien[8] = {"./attacks/fond_attack.png",
			"./attacks/attack.png",
			"./attacks/slash.png",
			"./attacks/fireball.png",
			"./attacks/eclair.png",
			"./attacks/exit_gate.png",
			"./attacks/bg_ennemy.png",
			"./attacks/bg_ally.png"};

int table_x[8] = {10,100,300,500,700,870,120,620};

int table_y[8] = {455,480,490,490,490,480,45,45};

int (*table_attacks[6])() = {attack, attack, slash, fire, thunder, my_exit};

int		load_attacks(struct SDL_Surface *ecran)
{
  int		i;
  SDL_Rect	positionAttack;
  SDL_Surface	*attack;

  for (i = 0; i < 8; i++)
    {
      attack = NULL;
      positionAttack.x = table_x[i];
      positionAttack.y = table_y[i];
      attack = IMG_Load(table_lien[i]);
      SDL_BlitSurface(attack, NULL, ecran, &positionAttack);
    }
  SDL_Flip(ecran);
  aff_stat_players(ecran);
  event_attacks(ecran);
  return EXIT_SUCCESS;
}


int		event_attacks(struct SDL_Surface *ecran)
{
  SDL_Event	event;
  int		continuer;
  int		i;

  continuer = win_lose(ecran);
  while (continuer)
    { 
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	exit(1);
      else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
	for (i = 1; i < 6; i++)
	  if ( event.button.x > table_x[i] && event.button.x < table_x[i] + 100 && 
	       event.button.y > table_y[i] && event.button.y < table_y[i] + 100)
	    {
	      table_attacks[i]();
	      load_attacks(ecran);
	      continuer = win_lose(ecran);
	    }
    }
  return EXIT_SUCCESS;
}
