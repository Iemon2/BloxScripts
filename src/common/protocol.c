#include <common/protocol.h>

size_t join_packet_encode(JoinPacket const *data, u8 *buf, size_t cap) {
    JoinPlayerData playerData = data->playerData;

    size_t index = 0;
    ENCODE_VALUE(playerData.localID, buf, cap , &index);

    u32 usernameLength = strlen(playerData.username);
    ENCODE_VALUE(usernameLength, buf, cap, &index);
    for (u32 i = 0; i < usernameLength; i++) {
        char *character = playerData.username + (i * sizeof(char));
        ENCODE_VALUE((u8) *character, buf, cap, &index);
    }
    return index;
}
size_t message_packet_encode(MessagePacket const *data, u8 *buf, size_t cap) {}

void join_packet_decode() {} 
void message_packet_decode() {}