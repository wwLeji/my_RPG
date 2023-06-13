/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** menu_settings
*/


/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdbool.h>
#include <stdlib.h>

/* LOCAL INCLUDES */
#include "window.h"
#include "menu.h"
#include "my.h"
#include "utils.h"

static void create_text(sfText **text)
{
    sfVector2f pos_text = {785, 20};

    *text = sfText_create();
    static sfFont *font = NULL;
    if (font == NULL)
        font = sfFont_createFromFile("assets/fonts/font_pixel.ttf");
    sfText_setFont(*text, font);
    sfText_setString(*text, "SETTINGS");
    sfText_setCharacterSize(*text, 75);
    sfText_setFillColor(*text, sfWhite);
    sfText_setOutlineColor(*text, sfBlack);
    sfText_setOutlineThickness(*text, 2);
    sfText_setPosition(*text, pos_text);
}

void draw_settings2(window_t *window, char *str, sfText *text_volume,
sfVector2f pos_text)
{
    static sfFont *font = NULL;
    if (font == NULL)
        font = sfFont_createFromFile("assets/fonts/font_pixel.ttf");
    sfText_setFont(text_volume, font);
    sfText_setString(text_volume, str);
    sfText_setCharacterSize(text_volume, 75);
    sfText_setFillColor(text_volume, sfWhite);
    sfText_setOutlineColor(text_volume, sfBlack);
    sfText_setOutlineThickness(text_volume, 2);
    sfText_setPosition(text_volume, pos_text);
    sfRenderWindow_drawText(window->window, text_volume, NULL);
    sfText_destroy(text_volume);
}

static void draw_settings(window_t *window, menu_t *menu)
{
    sfRenderWindow_drawSprite(window->window, menu->settings_sprite[4], NULL);
    sfRenderWindow_drawSprite(window->window, menu->settings_sprite[0], NULL);
    sfRenderWindow_drawSprite(window->window, menu->settings_sprite[1], NULL);
    sfRenderWindow_drawSprite(window->window, menu->settings_sprite[2], NULL);
    sfRenderWindow_drawSprite(window->window, menu->settings_sprite[3], NULL);
    sfRenderWindow_drawSprite(window->window, menu->settings_sprite[5], NULL);
    sfRenderWindow_drawSprite(window->window, menu->settings_sprite[6], NULL);
    sfText *text = NULL;
    create_text(&text);
    sfRenderWindow_drawText(window->window, text, NULL);
    sfText *text_volume = NULL;
    char *str = malloc(sizeof(char) * 10);
    my_strcpy(str, "VOLUME:");
    my_strcat(str, my_itoa(menu->new_volume));
    sfVector2f pos_text = {1100, 300};
    text_volume = sfText_create();
    draw_settings2(window, str, text_volume, pos_text);
}

void menu_settings(window_t *window, menu_t *menu)
{
    if (window->is_in_settings == 1) {
        draw_settings(window, menu);
    }
}
