/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** button_create_other
*/

#include <stdlib.h>
#include <stdbool.h>

#include "menu.h"
#include "constants.h"
#include "save.h"

void create_button_quit_settings(sfTexture *texture,
sfSprite **sprite, sfVector2f pos)
{
    sfVector2f scale = {1.5, 1.5};
    sfIntRect pos_rect = {185, 433, 37, 36};
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, texture, sfTrue);
    sfSprite_setTextureRect(*sprite, pos_rect);
    sfSprite_setPosition(*sprite, pos);
    sfSprite_setScale(*sprite, scale);
}

void init_settings_button(menu_t *menu)
{
    sfTexture *texture = sfTexture_createFromFile(
    "assets/menu/button/settings_Sheet.png", NULL);
    sfTexture *texture2 = sfTexture_createFromFile(
    "assets/menu/button/reso1.png", NULL);
    sfTexture *texture3 = sfTexture_createFromFile(
    "assets/menu/button/reso2.png", NULL);
    sfTexture *texture4 = sfTexture_createFromFile(
    "assets/menu/button/greySheet_Save.png", NULL);
    menu->settings_sprite = malloc(sizeof(sfSprite *) * 8);
    create_button_settings(texture2, &menu->settings_sprite[0],
    (sfVector2f){100, 200}, (sfIntRect){0, 0, 901, 475});
    create_button_settings(texture3, &menu->settings_sprite[1],
    (sfVector2f){100, 500}, (sfIntRect){0, 0, 901, 475});
    create_button_settings(texture, &menu->settings_sprite[2],
    (sfVector2f){1700, 950}, (sfIntRect){275, 150, 135, 150});
    create_button_settings(texture, &menu->settings_sprite[3],
    (sfVector2f){1800, 950}, (sfIntRect){425, 150, 135, 150});
    create_button_settings(texture, &menu->settings_sprite[5],
    (sfVector2f){1095, 395}, (sfIntRect){275, 150, 135, 150});
    create_button_settings(texture, &menu->settings_sprite[6],
    (sfVector2f){1175, 395}, (sfIntRect){425, 150, 135, 150});
    create_button_menu(texture4, &menu->settings_sprite[7], (sfVector2f){650, 450});
}

void buttons_new_load2(window_t *window, button_t *button,
player_t *player, map_t *map)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window->window);
    sfIntRect pos_rect_origin = {0, 49, 190, 49};
    sfIntRect pos_rect_second = {0, 98, 190, 45};
    sfIntRect pos_rect_third = {0, 143, 190, 45};
    if ((window->menu_anim_1 == 0 && window->menu_anim_2 == 0
    && window->is_in_game == 0 && window->is_in_settings == 0
    && window->is_in_how_play == 0 && window->is_in_load_new == 1
    && pos_mouse.x > 1000 && pos_mouse.x < 1275)
    && pos_mouse.y > 450 && pos_mouse.y < 522) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == true &&
        load_save(player, map, window) != ERROR) {
            sfSprite_setTextureRect(button->sprite_load_save[1],
            pos_rect_second);
            window->is_in_load_new = 0; window->is_in_game = 1;
        } else
            sfSprite_setTextureRect(button->sprite_load_save[1],
            pos_rect_third);
    } else
        sfSprite_setTextureRect(button->sprite_load_save[1],
        pos_rect_origin);
}

void init_buttons_load_new(menu_t *menu)
{
    menu->button->texture_load_save = malloc(sizeof(sfTexture *) * 2);
    menu->button->texture_load_save[0] = sfTexture_createFromFile(
    "assets/menu/button/greySheet_NewGame.png", NULL);
    menu->button->texture_load_save[1] = sfTexture_createFromFile(
    "assets/menu/button/greySheet_LoadGame.png", NULL);
    menu->button->sprite_load_save = malloc(sizeof(sfSprite *) * 2);
    create_button_menu(menu->button->texture_load_save[0],
    &menu->button->sprite_load_save[0], (sfVector2f){650, 450});
    create_button_menu(menu->button->texture_load_save[1],
    &menu->button->sprite_load_save[1], (sfVector2f){1000, 450});
}
