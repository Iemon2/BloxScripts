#pragma once

#include <stdio.h>
#include <enet/enet.h>
#include <common/packets.h>
#include <server/world.h>
#include <server/players.h>
#include <math/defines.h>

typedef struct {
    ENetHost *host;
    Player *players;
    World *world;
} ServerState;

#define MAX_PLAYERS 10

b8 serverCoreStateInit(ServerState *state, char *host, enet_uint16 port);

static void serverCoreNetworkEventCallback(ServerState *state, ENetEvent const *event);