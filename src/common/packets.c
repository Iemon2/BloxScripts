#include <common/packets.h>

static void send_raw(ENetPeer *peer, PacketChannels channel, uint32_t flags, uint8_t const *data, size_t len) {
    ENetPacket *packet = enet_packet_create(data, len, flags);
    assert(enet_peer_send(peer, (uint8_t)channel, packet) == 0);
}

static void broadcast_raw(ENetHost *host, PacketChannels channel, uint32_t flags, uint8_t const *data, size_t len) {
    ENetPacket *packet = enet_packet_create(data, len, flags);
    enet_host_broadcast(host, (uint8_t)channel, packet);
}


//sends
void player_join_send(JoinPacket const* packet, ENetPeer *peer, u8 *buff, size_t cap) {
    size_t const len = join_packet_encode(packet, buff, cap);
    send_raw(peer, PACKET_CHANNEL_JOIN, ENET_PACKET_FLAG_RELIABLE, buff, len);
}

void message_send(MessagePacket const* packet, ENetPeer *peer, u8 *buff, size_t cap) {
    size_t const len = message_packet_encode(packet, buff, cap);
    send_raw(peer, PACKET_CHANNEL_JOIN, ENET_PACKET_FLAG_RELIABLE, buff, len);
}


//broadcasts
void message_broadcast(MessagePacket const* packet, ENetHost *host, u8 *buff, size_t cap) {
    size_t const len = message_packet_encode(packet, buff, cap);
    broadcast_raw(host, PACKET_CHANNEL_MESSAGE, ENET_PACKET_FLAG_RELIABLE, buff, len);
}