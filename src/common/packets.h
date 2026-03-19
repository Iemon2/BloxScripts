#pragma once

#include <enet/enet.h>
#include <assert.h>
#include <common/encoding.h>
#include <common/protocol.h>
#include <stdint.h>

typedef enum {
    PACKET_CHANNEL_JOIN,
    PACKET_CHANNEL_MESSAGE,
    PACKET_CHANNEL_COUNT
} PacketChannels;

void player_join_send(JoinPacket const* packet, ENetPeer *peer, u8 *buff, size_t cap);
void message_send(MessagePacket const* packet, ENetPeer *peer, u8 *buff, size_t cap);

void message_broadcast(MessagePacket const* packet, ENetHost *host, u8 *buff, size_t cap);