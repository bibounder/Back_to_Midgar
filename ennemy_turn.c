/*
** ennemy_turn.c for  in /home/novose_s
** 
** Made by GROULEZ Florian
** Login   <groule_f@etna-alternance.net>
** 
** Started on  Fri Apr 10 04:15:29 2015 GROULEZ Florian
** Last update Fri Apr 10 04:15:33 2015 GROULEZ Florian
*/

#include	"lib/back_to_midgar.h"

int		turn()
{
  int		i;
  int		nombre_aleatoire;

  i = 1;
  while (i == 1)
    {
      nombre_aleatoire = (rand() % 3) + 1;
      if (nombre_aleatoire == 1)
	i = bite();
      else if (nombre_aleatoire == 2)
	i = earthquake();
      else
	i = doom();
    }
  return (0);
}

int		bite()
{
  player.pv_player -= 6;
  return (0);
}

int		earthquake()
{
  if (ennemy.pm_ennemy < 3)
    return(1);
  player.pv_player -= 15;
  ennemy.pv_ennemy -= 3;
  ennemy.pm_ennemy -= 3;
  return (0);
}

int		doom()
{
  if (ennemy.pm_ennemy < 5)
    return(1);
  ennemy.pm_ennemy -= 5;
  player.pv_player -= 11;
  return (0);
}
