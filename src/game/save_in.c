/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** save_in
*/

#include <stdio.h>

#include "game.h"
#include "save.h"
#include "my.h"
#include "utils.h"

static void write_nb(char *nb, FILE *file)
{
    fwrite(nb, sizeof(char), my_strlen(nb), file);
    fwrite("\n", sizeof(char), 1, file);
}

static void save_player(player_t *player, FILE *file)
{
    write_nb(my_itoa(player->quest_advencement), file);
    write_nb(my_itoa(player->speed), file);
    write_nb(my_itoa(player->force), file);
    write_nb(my_itoa(player->lvl_exp), file);
    for (int i = 0; i < 8; i++) {
        write_nb(my_itoa(player->pnj[i]->already_talk), file);
        write_nb(my_itoa(player->pnj[i]->has_quest), file);
    }
}

void save_game3(map_t *map, window_t *window, player_t *player, FILE *file)
{
    fwrite(my_itoa(window->is_in_menu), sizeof(char),
    my_strlen(my_itoa(window->is_in_menu)), file);
    fwrite("\n", sizeof(char), 1, file);
    sfVector2f pos_epi = sfSprite_getPosition(*map->sprite_epi);
    fwrite(my_itoa(pos_epi.x), sizeof(char),
    my_strlen(my_itoa(pos_epi.x)), file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite(my_itoa(pos_epi.y), sizeof(char),
    my_strlen(my_itoa(pos_epi.y)), file);
    fwrite("\n", sizeof(char), 1, file);
    save_player(player, file);
}

void save_game2(player_t *player, map_t *map, window_t *window, FILE *file)
{
    for (int i = 0; i < 10; i++) {
        sfVector2f pos_mob = sfSprite_getPosition(player->mobs[i]->sprite);
        fwrite(my_itoa(pos_mob.x), sizeof(char),
        my_strlen(my_itoa(pos_mob.x)), file);
        fwrite("\n", sizeof(char), 1, file);
        fwrite(my_itoa(pos_mob.y), sizeof(char),
        my_strlen(my_itoa(pos_mob.y)), file);
        fwrite("\n", sizeof(char), 1, file);
    }
    for (int i = 0; i < 8; i++) {
        sfVector2f pos_pnj = sfSprite_getPosition(player->pnj[i]->sprite_pnj);
        write_nb(my_itoa(pos_pnj.x), file);
        write_nb(my_itoa(pos_pnj.y), file);
    }
    save_game3(map, window, player, file);
}
