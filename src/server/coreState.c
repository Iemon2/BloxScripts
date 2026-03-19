#include <server/coreState.h>

//events
void serverCoreConnect(ServerState *state, ENetPeer *peer) {
    printf("New client connected:  %x:%u\n",
        peer->address.host,
        peer->address.port
    );
    
}

void serverCoreDisconnect(ServerState *state, ENetPeer *peer) {
    printf("Client disconnected:  %x:%u\n",
        peer->address.host,
        peer->address.port
    );
    removePlayerFromState(state->players, peer);
}

void serverCorePacketHandler(ServerState *state, ENetEvent const *e) {
    switch (e->channelID) {
        case PACKET_CHANNEL_JOIN: {
            break;
        }
        case PACKET_CHANNEL_MESSAGE: {
            break;
        }   
    }
}


static void serverCoreNetworkEventCallback(ServerState *state, ENetEvent const *event) {
    switch (event->type) {
        case ENET_EVENT_TYPE_CONNECT: {
            serverCoreConnect(state, event->peer);
            break;
        }
        case ENET_EVENT_TYPE_DISCONNECT: {
            serverCoreDisconnect(state, event->peer);
            break;
        }
        case ENET_EVENT_TYPE_RECEIVE: {
            serverCorePacketHandler(state, event);
            break;
        }
    }
}


b8 serverCoreStateInit(ServerState *state, char *host, enet_uint16 port) {
    #ifndef MAX_PLAYERS
    fprintf(stderr,
    "MAX_PLAYERS not defined");
    #endif
    ENetAddress add;
    enet_address_set_host(&add, host);
    add.port = port;

    ENetHost *enet_server = enet_host_create(
        &add,
        MAX_PLAYERS,
        PACKET_CHANNEL_COUNT,
        0,
        0
    );

    if (enet_server != NULL) {
        fprintf(stderr,
        "failed to initiate server");
        return false;
    };

    ServerState newState = {
        enet_server,
        (Player*)initPlayers(MAX_PLAYERS),
        NULL
    };

    *state = newState;

    return true;
}

