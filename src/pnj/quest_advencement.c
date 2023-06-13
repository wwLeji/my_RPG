/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** quest_advencement
*/

#include "window.h"
#include "player.h"
#include "menu.h"

void witch_pnj_has_quest(player_t *player)
{
    //printf("quest_advencement = %d\n", player->quest_advencement);
    if (player->quest_advencement == 0)
        if (player->pnj[0]->has_quest == 0) {
            player->pnj[0]->has_quest = 1;
            player->pnj[5]->has_quest = 1;
        }
    if (player->quest_advencement == 1) {
        if (player->pnj[0]->has_quest == 1)
            player->pnj[0]->has_quest = 0;
        if (player->pnj[1]->has_quest == 0)
            player->pnj[1]->has_quest = 1;
    }
    if (player->quest_advencement == 2) {
        if (player->pnj[1]->has_quest == 1)
            player->pnj[1]->has_quest = 0;
    }
    if (player->quest_advencement == 3) {
        if (player->pnj[2]->has_quest == 0)
            player->pnj[2]->has_quest = 1;
    }
    if (player->quest_advencement == 4) {
        if (player->pnj[2]->has_quest == 1)
            player->pnj[2]->has_quest = 0;
    }
    if (player->quest_advencement == 7) {
        if (player->pnj[4]->has_quest == 0)
            player->pnj[4]->has_quest = 1;
    }
    if (player->quest_advencement == 8) {
        if (player->pnj[4]->has_quest == 1)
            player->pnj[4]->has_quest = 0;
    }
    if (player->quest_advencement == 9) {
        if (player->pnj[3]->has_quest == 0)
            player->pnj[3]->has_quest = 1;
    }
    if (player->quest_advencement == 10) {
        if (player->pnj[3]->has_quest == 1)
            player->pnj[3]->has_quest = 0;
    }
    if (player->quest_advencement == 13) {
        if (player->pnj[4]->has_quest == 0)
            player->pnj[4]->has_quest = 1;
    }
}

void change_bubble_text(player_t *player, int i)
{
    if (player->pnj[i]->has_quest == 0)
        if (sfSprite_getTexture(player->pnj[i]->sprite_bubble) !=
            player->pnj[i]->texture_bubble[0])
            sfSprite_setTexture(player->pnj[i]->sprite_bubble,
                player->pnj[i]->texture_bubble[0], sfTrue);
    if (player->pnj[i]->has_quest == 1)
        if (sfSprite_getTexture(player->pnj[i]->sprite_bubble) !=
            player->pnj[i]->texture_bubble[1])
            sfSprite_setTexture(player->pnj[i]->sprite_bubble,
                player->pnj[i]->texture_bubble[1], sfTrue);

}

void check_pot(player_t *player)
{
    if (player->pnj[2]->already_talk == 1) {
        player->state = SIX;
        if (player->pnj[2]->is_talk == 0)
            player->pnj[2]->already_talk = 0;
    }
}

void end_game(player_t *player)
{
    printf("FIN DU JEU\n");
    player->end_game = 1;
    //printf("FIN DU JEU\n");
    player->quest_advencement = 1000;
}

void check_speed(player_t *player)
{
    if (player->boxes->items[1] == 1)
        if (player->speed == 2)
            player->speed = 3;
}

void check_quest_advencement(player_t *player)
{
    check_speed(player);
    check_pot(player);
    //printf("kill_mob = %d\n", player->kill_mob);
    //printf("cecile already talk = %d\n", player->pnj[5]->already_talk);
    //premier dialogue avec cecile
    if (player->quest_advencement == 0)
        if (player->pnj[5]->already_talk == 1)
            player->quest_advencement = 1;
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
        end_game(player);
    //dialogue avec le forgeron
    if (player->quest_advencement == 1) {
        if (player->pnj[1]->already_talk == 1) {
            player->boxes->items[0] = 1;
            text_with_sword(player);
            item_sound(player);
        }
        if (player->pnj[1]->already_talk == 1 && player->pnj[1]->is_talk == 0)
            player->quest_advencement = 2;
            player->pnj[5]->already_talk = 0;
    }

    //redialogue avec cecile
    if (player->quest_advencement == 2)
        if (player->pnj[5]->already_talk == 1) {
            player->quest_advencement = 3;
            player->pnj[2]->already_talk = 0;
        }

    //dialogue avec eud
    if (player->quest_advencement == 3)
        if (player->pnj[2]->already_talk == 1) {
            player->quest_advencement = 4;
            player->pnj[5]->already_talk = 0;
            text_for_mob1(player);
        }

    //redialogue avec cecile
    if (player->quest_advencement == 4)
        if (player->pnj[5]->already_talk == 1) {
            player->quest_advencement = 5;
            player->kill_mob = 0;
        }

    //tuer 10 ennemis
    if (player->quest_advencement == 5)
        if (player->kill_mob == 3) {
            player->kill_mob = 0;
            player->pnj[5]->already_talk = 0;
            player->quest_advencement = 6;
            text_for_grimoire(player);
        }
    
    //dialogue avec cecile
    if (player->quest_advencement == 6)
        if (player->pnj[5]->already_talk == 1) {
            player->quest_advencement = 7;
            player->pnj[5]->already_talk = 0;
        }

    //dialogue avec grimoire
    if (player->quest_advencement == 7) {
        if (player->pnj[4]->already_talk == 1) {
            player->boxes->items[1] = 1;
            player->pnj[5]->already_talk = 0;
            text_with_grimoire(player);
            item_sound(player);
        }
        if (player->pnj[4]->already_talk == 1 && player->pnj[4]->is_talk == 0)
            player->quest_advencement = 8;
    }

    //dialogue avec cecile
    if (player->quest_advencement == 8)
        if (player->pnj[5]->already_talk == 1) {
            player->quest_advencement = 9;
            player->pnj[5]->already_talk = 0;
            player->pnj[3]->already_talk = 0;
            player->boxes->items[2] = 1;
        }

    //donner boots au chauve
    if (player->quest_advencement == 9)
        if (player->pnj[3]->already_talk == 1) {
            player->quest_advencement = 10;
            player->pnj[5]->already_talk = 0;
            player->boxes->items[2] = 0;
            text_for_mob2(player);
        }
    
    //dialogue avec cecile
    if (player->quest_advencement == 10)
        if (player->pnj[5]->already_talk == 1) {
            player->quest_advencement = 11;
            player->pnj[5]->already_talk = 0;
        }

    //tuer 5 ennemis
    if (player->quest_advencement == 11)
        if (player->kill_mob == 5) {
            player->kill_mob = 0;
            player->quest_advencement = 12;
            player->pnj[5]->already_talk = 0;
            text_for_end_game(player);
        }
    
    //dialogue avec cecile
    if (player->quest_advencement == 12)
        if (player->pnj[5]->already_talk == 1) {
            player->quest_advencement = 13;
            player->pnj[5]->already_talk = 0;
            player->pnj[4]->already_talk = 0;
            text_for_end_game2(player);
        }

    //dialogue avec grimoire
    if (player->quest_advencement == 13)
        if (player->pnj[4]->already_talk == 1) {
            end_game(player);
            player->pnj[5]->already_talk = 0;
        }
    witch_pnj_has_quest(player);
    for (int i = 0; i < 8; i++)
        change_bubble_text(player, i);
}
