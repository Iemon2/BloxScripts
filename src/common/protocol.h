#pragma once

#include <math/defines.h>
#include <common/encoding.h>
#include <string.h>

#define PROTOCOL_DECODE(packet, raw)                        \
    _Generic(*(packet),                                     \
        JoinPacket: join_packet_encode,                     \
        MessagePacket: message_packet_encode)(packet, raw)

typedef struct {
    u32 localID;
    char *username;
} JoinPlayerData;

typedef struct {
    JoinPlayerData playerData;
} JoinPacket;

typedef struct {
    char *username;
    char *message;
} MessagePacket;

//encode
size_t join_packet_encode(JoinPacket const *data, u8 *buf, size_t cap);
size_t message_packet_encode(MessagePacket const *data, u8 *buf, size_t cap);

//decode