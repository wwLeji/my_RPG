/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** text_with_sword
*/

#include "player.h"

void text_with_grimoire(player_t *player)
{
    player->pnj[5]->text_quest = get_all_text_in_file("texts/pnj5_quest3.txt");
}

void text_with_sword(player_t *player)
{
    player->pnj[5]->text_quest = get_all_text_in_file("texts/pnj5_quest2.txt");
}

void text_for_mob1(player_t *player)
{
    player->pnj[5]->text_quest = get_all_text_in_file("texts/pnj5_quest_mob.txt");
}

void text_for_grimoire(player_t *player)
{
    player->pnj[5]->text_quest = get_all_text_in_file("texts/pnj5_quest_grim.txt");
}

void text_for_mob2(player_t *player)
{
    player->pnj[5]->text_quest = get_all_text_in_file("texts/pnj5_quest_mob2.txt");
}

void text_for_end_game(player_t *player)
{
    player->pnj[5]->text_quest = get_all_text_in_file("texts/pnj5_quest_end.txt");
}

void text_for_end_game2(player_t *player)
{
    player->pnj[4]->text_quest = get_all_text_in_file("texts/pnj5_quest_end2.txt");
}