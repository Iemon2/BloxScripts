#include <server/players.h>

void* initPlayers(int maxPlayers) {
    Player *players[maxPlayers];
    for (int i = 0; i < maxPlayers; i++) {
        players[i]->ID = -1;
    }
    return *players;
}

void addPlayerToState(Player *players, ENetPeer *newPeer) {

    for (int i = 0; i < sizeof(players) + 1; i++) {
        if (players[i].ID = -1) {
            players[i].client = newPeer;
            //players[i].ID = mathRand12d();
            break;
        }
    }
}

void removePlayerFromState(Player *players, ENetPeer *disconnectedPlayer) {
    Player newPlayer;
    int *playerIDPtr = (int*)disconnectedPlayer->data;

    for (int i = 0; i < sizeof(players) + 1; i++) {
        int id = players[i].ID;
        if (id == *playerIDPtr) {
            players[i] = newPlayer;
        }
    }
}