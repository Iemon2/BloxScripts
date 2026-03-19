#pragma once

#ifdef _WIN32
#include <platform/win32.h>
#endif

#include <enet/enet.h>
#include <math/defines.h>
#include <common/packets.h>

b8 clientCoreInitClient(ENetHost *client);