/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** game_init
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "save.h"
#include "window.h"
#include "menu.h"
#include "player.h"
#include "map.h"
#include "game.h"
#include "button.h"
#include "utils.h"

void game_init(window_t *window, menu_t *menu,
map_t *map, player_t *player)
{
    menu->color_fade = (sfColor) {0, 0, 0, 1};
    sfVideoMode mode = {1920, 1080, 32};
    window->window = sfRenderWindow_create(mode,
    "MSC QUEST", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->window, 60);
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    ini_struct_window(window);
    ini_struct_player(window, player);
    create_game(window, menu, map, player);
    player->quest_advencement = 0;
}

static void check_click_save(menu_t *menu, window_t *window, player_t *player,
map_t *map)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window->window);
    if (window->is_in_game_menu != 1)
        return;
    sfFloatRect btn_buttons = sfSprite_getGlobalBounds(menu->settings_sprite[7]);
    if (sfFloatRect_contains(&btn_buttons, pos_mouse.x, pos_mouse.y)) {
        save_game(player, map, window);
    }
}

static void check_click2(menu_t *menu, sfVector2i pos_mouse)
{
    if (pos_mouse.x >= 100 && pos_mouse.x <= 1000.5 && pos_mouse.y >= 500 &&
        pos_mouse.y <= 737.5) {
        menu->resolution = (sfVector2u) {2048, 1080};
    }
    if (pos_mouse.x >= 100 && pos_mouse.x <= 1000.5 && pos_mouse.y >= 200 &&
        pos_mouse.y <= 437.5) {
        menu->resolution = (sfVector2u) {1920, 1080};
    }
    sfFloatRect rect2 = {1175, 395, 135 / 2, 150 / 2};
    if (sfFloatRect_contains(&rect2, pos_mouse.x, pos_mouse.y)) {
        if (menu->new_volume < 100)
            menu->new_volume += 10;
    }
    sfFloatRect rect3 = {1095, 395, 135 / 2, 150 / 2};
    if (sfFloatRect_contains(&rect3, pos_mouse.x, pos_mouse.y)) {
        if (menu->new_volume > 0)
            menu->new_volume -= 10;
    }
}

static void check_click(window_t *window, menu_t *menu, sfVector2i pos_mouse)
{
    if (window->is_in_settings != 1)
        return;
    if (pos_mouse.x >= 1700 && pos_mouse.x <= 1767.5 && pos_mouse.y >= 950 &&
        pos_mouse.y <= 1025) {
        window->is_in_settings = 0;
        if (window->is_in_game != 0)
            window->is_in_menu = 0;
        menu->resolution = sfRenderWindow_getSize(window->window);
        menu->new_volume = menu->volume;
    }
    if (pos_mouse.x >= 1800 && pos_mouse.x <= 1867.5 && pos_mouse.y >= 950 &&
        pos_mouse.y <= 1025) {
        window->is_in_settings = 0;
        if (window->is_in_game != 0)
            window->is_in_menu = 0;
        sfRenderWindow_setSize(window->window, menu->resolution);
        menu->volume = menu->new_volume;
    }
    check_click2(menu, pos_mouse);
}

static void loop_event(window_t *window, menu_t *menu, player_t *player,
map_t *map)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)
    && window->is_left == 0) {
        if (window->event.type == sfEvtClosed) {
            window->is_left = 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)
        && window->is_in_game == 1 && window->is_in_settings == 0) {
            window->is_in_game_menu = 1;
        }
        if (window->event.type == sfEvtMouseButtonPressed
        && window->event.mouseButton.button == sfMouseLeft) {
            check_click(window, menu,
            sfMouse_getPositionRenderWindow(window->window));
            check_click_save(menu, window, player, map);
        }
        scroll_case(window);
    }
}

void game_loop(window_t *window, menu_t *menu, map_t *map, player_t *player)
{
    while (sfRenderWindow_isOpen(window->window) && window->is_left == 0) {
        window->seconds =
        sfClock_getElapsedTime(window->clock).microseconds / 1000000.0;
        loop_event(window, menu, player, map);
        animation_menu_1(window, player, menu);
        animation_player_menu(window, player);
        animation_menu_2(window, player, menu, map);
        create_game_layer_1(window, menu, map, player);
        create_game_layer_2(window, menu, map, player);
        check_death(player, window, menu, map);
        sfText_setString(player->text_exp, my_itoa(player->lvl_exp));
        sfText_setString(player->text_force, my_itoa(player->force));
        button_case_menu(window, menu, player, map);
        game_menu(window, menu, player, map);
        case_cursor(window);
        sfRenderWindow_display(window->window);
        sfRenderWindow_clear(window->window, sfBlack);
        check_update_force(player, window);
        end_animation(window, player, menu);
    }
}
