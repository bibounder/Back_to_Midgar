/*
** player_attacks.c for  in /home/novose_s
** 
** Made by GROULEZ Florian
** Login   <groule_f@etna-alternance.net>
** 
** Started on  Fri Apr 10 04:15:37 2015 GROULEZ Florian
** Last update Fri Apr 10 04:15:40 2015 GROULEZ Florian
*/

#include	"lib/back_to_midgar.h"

int		attack()
 {
  ennemy.pv_ennemy -= 7;
  turn();
  return (0);
}

int		slash()
{
  ennemy.pv_ennemy -= 10;
  player.pv_player -= 2;
  turn();
  return (0);
}

int		fire()
{
  if (player.pm_player < 3)
    return (0);
  ennemy.pv_ennemy -= 10;
  player.pm_player -= 3;
  turn();
  return (0);
}

int		thunder()
{
  if (player.pm_player < 5)
    return (0);
  ennemy.pv_ennemy -= 15;
  player.pm_player -= 5;
  player.pv_player += 3;
  turn();
  return (0);
}

int		my_exit()
{
  exit(1);
  return (0);
}
