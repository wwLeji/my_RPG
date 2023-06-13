/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** save
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "player.h"
#include "pnj.h"
#include "save.h"
#include "constants.h"
#include "utils.h"
#include "my.h"
#include "window.h"

void text_for_mob1(player_t *player);
void text_for_mob2(player_t *player);
void text_for_grimoire(player_t *player);
void text_with_grimoire(player_t *player);
void text_for_end_game(player_t *player);
void text_for_end_game2(player_t *player);

void load_save_loop3(map_t *map, window_t *window, player_t *player, tmp_t *tmp)
{
    if (tmp->i == 41)
        window->is_in_menu = my_getnbr(tmp->line);
    if (tmp->i == 42) {
        for (int i = 0; i < 3; i++)
            sfSprite_setPosition(map->sprite_epi[i], (sfVector2f) {
                my_getnbr(tmp->line), 0});
    }
    if (tmp->i == 43) {
        for (int i = 0; i < 3; i++)
            sfSprite_setPosition(map->sprite_epi[i], (sfVector2f) {
                sfSprite_getPosition(map->sprite_epi[i]).x,
                my_getnbr(tmp->line)});
    }
    if (tmp->i == 44)
        player->quest_advencement = my_getnbr(tmp->line);
    if (tmp->i == 45)
        player->speed = my_getnbr(tmp->line);
    if (tmp->i == 46)
        player->force = my_getnbr(tmp->line);
    if (tmp->i == 47)
        player->lvl_exp = my_getnbr(tmp->line);
    if (tmp->i > 47 && tmp->i < 64) {
        int real_i = tmp->i - 48;
        if (real_i % 2 == 0) {
            real_i = real_i / 2;
            player->pnj[real_i]->already_talk = my_getnbr(tmp->line);
        } else {
            real_i = (real_i - 1) / 2;
            player->pnj[real_i]->has_quest = my_getnbr(tmp->line);
        }
    }
}

void load_save_loop2(player_t *player, map_t *map, window_t *window, tmp_t *tmp)
{
    if (tmp->i > 4 && tmp->i < 25) {
        if (tmp->i % 2 == 0) {
            tmp->pos.y = my_getnbr(tmp->line);
            tmp->k = (tmp->i != 5 && tmp->i != 6) ? tmp->k + 1 : 0;
            sfSprite_setPosition(player->mobs[tmp->k]->sprite, tmp->pos);
        } else {
            tmp->pos.x = my_getnbr(tmp->line);
        }
    }
    if (tmp->i > 24 && tmp->i < 41) {
        if (tmp->i % 2 == 0) {
            tmp->pos_pnj.y = my_getnbr(tmp->line);
            tmp->j = (tmp->i != 25 && tmp->i != 26) ? tmp->j + 1 : 0;
            sfSprite_setPosition(player->pnj[tmp->j]->sprite_pnj, tmp->pos_pnj);
            sfSprite_setPosition(player->pnj[tmp->j]->sprite_bubble,
            (sfVector2f) {
                tmp->pos_pnj.x + 110, tmp->pos_pnj.y + 23});
        } else
            tmp->pos_pnj.x = my_getnbr(tmp->line);
    } load_save_loop3(map, window, player, tmp);
}

void load_save_loop(player_t *player, map_t *map, window_t *window, tmp_t *tmp)
{
    if (tmp->i == 0)
            player->lvl_exp = my_getnbr(tmp->line);
    if (tmp->i == 1)
        player->state = my_getnbr(tmp->line);
    if (tmp->i == 2)
        *player->boxes->items = my_getnbr(tmp->line);
    if (tmp->i == 3) {
        sfVector2f pos = {my_getnbr(tmp->line), 0};
        for (int i = 0; i < 3; i++)
            sfSprite_setPosition(map->sprite_map[i], pos);
    }
    if (tmp->i == 4) {
        sfVector2f pos = {sfSprite_getPosition(map->sprite_map[0]).x,
        my_getnbr(tmp->line)};
        sfSprite_setPosition(map->sprite_map[0], pos);
        sfSprite_setPosition(map->sprite_map[1], pos);
        sfSprite_setPosition(map->sprite_map[2], pos);
    }
    load_save_loop2(player, map, window, tmp);
}

int load_save(player_t *player, map_t *map, window_t *window)
{
    FILE *file = fopen("saves/save.msc", "r");
    if (file == NULL) return (ERROR);
    char *line = NULL;
    size_t len = 0;
    int i = 0; int k = 0; int j = 0;
    sfVector2f pos = {0, 0};
    sfVector2f pos_pnj = {0, 0};
    tmp_t tmp = {i, k, j, pos, pos_pnj, line};
    while (getline(&((&tmp)->line), &len, file) != -1) {
        load_save_loop(player, map, window, &tmp);
        tmp.i++;
    }
    fclose(file);
    sfSprite_setTexture(player->sprite_player, player->texture_idle[0],
            sfTrue);
    sfSprite_setTextureRect(player->sprite_player, player->rect);
    if (player->quest_advencement >= 1)
        text_with_sword(player);
    if (player->quest_advencement >= 4)
        text_for_mob1(player);
    if (player->quest_advencement >= 6)
        text_for_grimoire(player);
    if (player->quest_advencement >= 8)
        text_with_grimoire(player);
    if (player->quest_advencement >= 10)
        text_for_mob2(player);
    if (player->quest_advencement >= 12)
        text_for_end_game(player);
    if (player->quest_advencement >= 13)
        text_for_end_game2(player);
    return (SUCCESS);
}

int save_game(player_t *player, map_t *map, window_t *window)
{
    FILE *file = fopen("saves/save.msc", "w");
    if (file == NULL)
        return (ERROR);

    char *level = my_itoa(player->lvl_exp);
    char *health = my_itoa(player->state);
    char *items = my_itoa(*player->boxes->items);
    sfVector2f pos = sfSprite_getPosition(*map->sprite_map);
    fwrite(level, sizeof(char), my_strlen(level), file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite(health, sizeof(char), my_strlen(health), file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite(items, sizeof(char), my_strlen(items), file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite(my_itoa(pos.x), sizeof(char), my_strlen(my_itoa(pos.x)), file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite(my_itoa(pos.y), sizeof(char), my_strlen(my_itoa(pos.y)), file);
    fwrite("\n", sizeof(char), 1, file);
    save_game2(player, map, window, file);
    return (SUCCESS);
}
