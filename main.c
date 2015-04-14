/*
** main.c for  in /home/groulef/Documents/Projet_Easter
** 
** Made by GROULEZ Florian
** Login   <groule_f@etna-alternance.net>
** 
** Started on  Thu Apr  2 10:05:27 2015 GROULEZ Florian
** Last update Fri Apr 10 03:53:06 2015 GROULEZ Florian
*/

#include	"lib/back_to_midgar.h"

int		main()
{
  player.pv_player = 125;
  player.pm_player = 30;
  ennemy.pv_ennemy = 150;
  ennemy.pm_ennemy = 20;
  ennemy.name_ennemy = "Sakhr";
  load_map();
  return (0);
}

