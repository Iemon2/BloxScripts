#pragma once

#include <server/coreState.h>
#include <math/defines.h>
#include <pthread.h>

typedef struct {
    ServerState *state;
    b8 running;
} ServerWorker;

b8 startServer(ServerState *state, pthread_t *serverThread, char *host, enet_uint16 port, int maxPlayers);