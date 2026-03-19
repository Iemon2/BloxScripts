#pragma once

#include <enet/enet.h>

typedef struct {
    ENetPeer *client;
    int ID;
    char *username;
} Player;

void* initPlayers(int maxPlayers);

void addPlayerToState(Player *players, ENetPeer *newPlayer);

void removePlayerFromState(Player *players, ENetPeer *disconnectedPlayer);