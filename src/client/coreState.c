#include <client/coreState.h>

b8 clientCoreInitClient(ENetHost *client) {
    ENetHost *newClient = enet_host_create(NULL,
        1,
        PACKET_CHANNEL_COUNT,
        0,
        0
    );

    *client = *newClient;
    return true;
}