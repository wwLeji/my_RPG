/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** move_player_direction
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "player.h"

void move_up(int count, int *walk, player_t *player, sfSprite **map)
{
    if (count > 1) {
        sfSprite_move(map[0], (sfVector2f){0, player->speed * 2}); sfSprite_move(map[1],
            (sfVector2f){0, player->speed * 2}); sfSprite_move(map[2], (sfVector2f){0, player->speed * 2});
        move_up_pnj(player, player->speed * 2);
        for (int i = 0; i < 10; i++)
            sfSprite_move(player->mobs[i]->sprite, (sfVector2f){0, player->speed * 2});
    } if (count == 1) {
        sfSprite_move(map[0], (sfVector2f){0, player->speed * 3}); sfSprite_move(map[1],
            (sfVector2f){0, player->speed * 3}); sfSprite_move(map[2], (sfVector2f){0, player->speed * 3});
        move_up_pnj(player, player->speed * 3);
        for (int i = 0; i < 10; i++)
            sfSprite_move(player->mobs[i]->sprite, (sfVector2f){0, player->speed * 3});
    } if (*walk != 3) {
        sfSprite_setTexture(player->sprite_player,
        player->texture_walk[0], sfTrue);
        *walk = 3;
        sfSprite_setTextureRect(player->sprite_player, player->rect);
        walk_on(player);
    }
}

void move_down(int count, int *walk, player_t *player, sfSprite **map)
{
    if (count > 1) {
        sfSprite_move(map[0], (sfVector2f){0, -player->speed * 2}); sfSprite_move(map[1],
            (sfVector2f){0, -player->speed * 2}); sfSprite_move(map[2], (sfVector2f){0, -player->speed * 2});
        move_down_pnj(player, player->speed * 2);
        for (int i = 0; i < 10; i++)
            sfSprite_move(player->mobs[i]->sprite, (sfVector2f){0, -player->speed * 2});
    } if (count == 1) {
        sfSprite_move(map[0], (sfVector2f){0, -player->speed * 3}); sfSprite_move(map[1],
            (sfVector2f){0, -player->speed * 3}); sfSprite_move(map[2], (sfVector2f){0, -player->speed * 3});
        move_down_pnj(player, player->speed * 3);
        for (int i = 0; i < 10; i++)
            sfSprite_move(player->mobs[i]->sprite, (sfVector2f){0, -player->speed * 3});
    } if (*walk != 4) {
        sfSprite_setTexture(player->sprite_player,
        player->texture_walk[1], sfTrue);
        *walk = 4;
        sfSprite_setTextureRect(player->sprite_player, player->rect);
        walk_on(player);
    }
}

void move_right(int count, int *walk, player_t *player, sfSprite **map)
{
    if (count > 1) {
        sfSprite_move(map[0], (sfVector2f){-player->speed * 2, 0}); sfSprite_move(map[1],
            (sfVector2f){-player->speed * 2, 0}); sfSprite_move(map[2], (sfVector2f){-player->speed * 2, 0});
        move_right_pnj(player, player->speed * 2);
        for (int i = 0; i < 10; i++)
            sfSprite_move(player->mobs[i]->sprite, (sfVector2f){-player->speed * 2, 0});
    } if (count == 1) {
        sfSprite_move(map[0], (sfVector2f){-player->speed * 3, 0}); sfSprite_move(map[1],
            (sfVector2f){-player->speed * 3, 0}); sfSprite_move(map[2], (sfVector2f){-player->speed * 3, 0});
        move_right_pnj(player, player->speed * 3);
        for (int i = 0; i < 10; i++)
            sfSprite_move(player->mobs[i]->sprite, (sfVector2f){-player->speed * 3, 0});
    } if (*walk != 1) {
        sfSprite_setTexture(player->sprite_player,
        player->texture_walk[2], sfTrue);
        *walk = 1;
        sfSprite_setTextureRect(player->sprite_player, player->rect);
        walk_on(player);
    }
}

void move_left(int count, int *walk, player_t *player, sfSprite **map)
{
    if (count > 1) {
        sfSprite_move(map[0], (sfVector2f){player->speed * 2, 0}); sfSprite_move(map[1],
            (sfVector2f){player->speed * 2, 0}); sfSprite_move(map[2], (sfVector2f){player->speed * 2, 0});
        move_left_pnj(player, player->speed * 2);
        for (int i = 0; i < 10; i++)
            sfSprite_move(player->mobs[i]->sprite, (sfVector2f){player->speed * 2, 0});
    } if (count == 1) {
        sfSprite_move(map[0], (sfVector2f){player->speed * 3, 0}); sfSprite_move(map[1],
            (sfVector2f){player->speed * 3, 0}); sfSprite_move(map[2], (sfVector2f){player->speed * 3, 0});
        move_left_pnj(player, player->speed * 3);
        for (int i = 0; i < 10; i++)
            sfSprite_move(player->mobs[i]->sprite, (sfVector2f){player->speed * 3, 0});
    } if (*walk != 2) {
        sfSprite_setTexture(player->sprite_player,
        player->texture_walk[3], sfTrue);
        *walk = 2;
        sfSprite_setTextureRect(player->sprite_player, player->rect);
        walk_on(player);
    }
}
