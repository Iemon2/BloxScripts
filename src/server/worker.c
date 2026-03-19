#include <server/worker.h>

void* workerLoop(void *worker) {
    ServerWorker *serverWorker = (ServerWorker *) worker;
    ServerState *state = serverWorker->state;

    ENetEvent e;
    b8 eventStatus = false;
    while (serverWorker->running) {
        while (enet_host_service (state->host, &e, 0) > 0) {
            eventStatus = true;
            serverCoreNetworkEventCallback(state, &e);
        }
    }
}

b8 startServer(ServerState *state, pthread_t *serverThread, char *host, enet_uint16 port, int maxPlayers) {

    if (!serverCoreStateInit(state, host, port)) {
        fprintf( stderr,
            "failed to initialize server on: %u: %x",
            host,
            port
        );
        return false;
    }
    ServerWorker worker = {
        state,
        true
    };

    if (pthread_create(serverThread, NULL, workerLoop, &worker) != 0) {
        fprintf(stderr,
            "failed to create thread"
        );
        return false;
    };

    return true;
}
