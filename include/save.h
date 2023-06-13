/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** save
*/

#ifndef SAVE_H_
    #define SAVE_H_

    #include "player.h"
    #include "window.h"
    #include <SFML/System/Vector2.h>
    #include <stdio.h>

    typedef struct {
        int i;
        int j;
        int k;
        sfVector2f pos;
        sfVector2f pos_pnj;
        char *line;
    } tmp_t;

    int save_game(player_t *player, map_t *map, window_t *window);
    void save_game2(player_t *player, map_t *map, window_t *window, FILE *file);
    int load_save(player_t *player, map_t *map, window_t *window);

#endif /* !SAVE_H_ */
