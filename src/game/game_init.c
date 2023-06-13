/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** game_init
*/


/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>

/* LOCAL INCLUDES */
#include "game.h"
#include "window.h"
#include "player.h"
#include "menu.h"
#include "utils.h"


void create_stat_game_menu(sfText **text, sfFont *font,
sfVector2f pos_text, char *txt)
{
    *text = sfText_create();
    sfText_setFont(*text, font);
    sfText_setString(*text, txt);
    sfText_setCharacterSize(*text, 25);
    sfText_setPosition(*text, pos_text);
}

static void create_game_menu(menu_t *menu)
{
    menu->font_settings = sfFont_createFromFile("assets/fonts/font_pixel.ttf");
    create_text_game_menu(menu);
    create_stat_game_menu(&menu->speed, menu->font_settings,
    (sfVector2f){700, 300}, "SPEED        =   1");
    create_stat_game_menu(&menu->force, menu->font_settings,
    (sfVector2f){700, 375}, "FORCE        =   4");
    create_stat_game_menu(&menu->health, menu->font_settings,
    (sfVector2f){700, 450}, "HEALTH       =   6");
    create_stat_game_menu(&menu->experience, menu->font_settings,
    (sfVector2f){700, 525}, "EXPERIENCE   =");
}

void create_end(menu_t *menu, player_t *player)
{
    menu->end = malloc(sizeof(sfSprite *) * 4);
    menu->texture_end = malloc(sizeof(sfTexture *) * 4);
    menu->texture_end[0] = sfTexture_createFromFile("assets/end/title.png", NULL);
    menu->texture_end[1] = sfTexture_createFromFile("assets/end/names.png", NULL);
    menu->texture_end[2] = sfTexture_createFromFile("assets/end/prochainement.png", NULL);
    menu->texture_end[3] = sfTexture_createFromFile("assets/end/maybe.png", NULL);
    for (int i = 0; i < 4; i++) {
        menu->end[i] = sfSprite_create();
        sfSprite_setTexture(menu->end[i], menu->texture_end[i], sfTrue);
    }
    sfSprite_setPosition(menu->end[0], (sfVector2f){1600, 0});
    sfSprite_setPosition(menu->end[1], (sfVector2f){0, 800});
    sfSprite_setPosition(menu->end[2], (sfVector2f){0, 300});
    sfSprite_setPosition(menu->end[3], (sfVector2f){0, 300});
}

void create_game(window_t *window, menu_t *menu,
map_t *map, player_t *player)
{
    create_player(player->texture_walk[2], &player->sprite_player);
    create_pnj(player);
    create_mobs(player);
    create_menu(menu, menu->color_fade);
    create_health_bar(player);
    create_experience(&player->texture_exp, &player->sprite_exp);
    create_text_exp(&player->text_exp, &player->font_exp);
    create_text_force(&player->text_force, &player->font_exp);
    game_inventory(player);
    create_world(map);
    ini_button_menu(menu);
    create_htp_fade(menu);
    create_music(window);
    create_sounds(player);
    create_music_exp(player);
    create_cursor(window);
    create_game_menu(menu);
    create_zoom(window);
    create_end(menu, player);
    create_illustration_game_menu(menu); create_up_force(player);
}

void ini_struct_player(window_t *window, player_t *player)
{
    player->rect = (sfIntRect){0, 0, 48, 48};
    player->rect_mobs = (sfIntRect){0, 0, 32, 32};
    player->state = SIX;
    player->is_attacking = 0;
    player->already_talk = 0;
    player->lvl_exp = 0;
    player->is_in_menu_p = &window->is_in_menu;
    player->is_dead = 0;
    player->respawn_done = 0;
    player->kill_mob = 0;
    player->speed = 2;
    player->end_game = 0;
    player->end_timer = 0;
}

void ini_struct_window(window_t *window)
{
    window->clock = sfClock_create();
    window->menu_anim_fade = 0;
    window->menu_anim_1 = 0;
    window->menu_anim_2 = 0;
    window->is_in_menu = 1;
    window->is_in_game = 0;
    window->is_in_game_menu = 0;
    window->is_in_settings = 0;
    window->is_in_how_play = 0;
    window->is_left = 0;
    window->rect_index = 0;
    window->walk = 0;
    window->music_state = 1;
    window->zoom_level = 1.0;
    window->attack_index = 0;
}
