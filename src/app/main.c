#ifdef _WIN32
#include <platform/win32.h>
#endif

#include <stdio.h>
#include <string.h>

#include <server/worker.h>
#include <enet/enet.h>

typedef struct {
    char *key;
    int val;
} ArguementList;


static ArguementList firstArgs[] = {
    {"connect", 1},
    {"host", 2}
};

int keyFromString(char *key, const ArguementList (*list)[], int size) {

    for (int i = 0; i < size; i++) {
        if (!strcmp((*list)[i].key, key)) {
            return (*list)[i].val;
        }
    }
    return -1;
}

void initServer() {
    ServerState state;
    pthread_t serverThread;

    startServer(&state, &serverThread, "127.0.0.1", 7777, MAX_PLAYERS);
    // if (!startServer(&state, &serverThread, "127.0.0.1", 7777, MAX_PLAYERS)) {
    //     fprintf(stderr, "failed to start server worker");
    // }
}

int main(int argc, char* argv[]) {

    int key = keyFromString(argv[1], &firstArgs, 2);
    switch (key) {
        case 1: {
            //connect(argv, argc);
            break;
        }
        case 2: {
            initServer();
            printf("host");
            break;
        }
    }
    
    return 0;
}