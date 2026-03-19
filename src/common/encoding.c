#include <assert.h>
#include <common/encoding.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#ifdef _WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
#endif

#if !defined(__x86_64__) && !defined(__aarch64__) && !defined(__powerpc64__)
#error "net: unsupported architecture"
#endif

static_assert(sizeof(f32) == sizeof(u32), "net: f32 is not 32 bits");

void encode_uint8(u8 value, u8* buf, size_t cap, size_t* index) {
  size_t const next_index = *index + sizeof(value);
  assert(next_index <= cap);

  memcpy(&buf[*index], &value, sizeof(value));
  *index = next_index;
}

void encode_uint16(u16 value, u8* buf, size_t cap, size_t* index) {
  u16 const net_value = htons(value);

  size_t const next_index = *index + sizeof(net_value);
  assert(next_index <= cap);

  memcpy(&buf[*index], &net_value, sizeof(net_value));
  *index = next_index;
}

void encode_uint32(u32 value, u8* buf, size_t cap, size_t* index) {
  u32 const net_value = htonl(value);

  size_t const next_index = *index + sizeof(net_value);
  assert(next_index <= cap);

  memcpy(&buf[*index], &net_value, sizeof(net_value));
  *index = next_index;
}

void encode_f32(f32 value, u8* buf, size_t cap, size_t* index) {
  u32 bits;
  memcpy(&bits, &value, sizeof(value));
  encode_uint32(bits, buf, cap, index);
}

void encode_vec2(vec2 value, u8* buf, size_t cap, size_t* index) {
  encode_f32(value.x, buf, cap, index);
  encode_f32(value.y, buf, cap, index);
}

void decode_uint8(u8* value, ENetPacket const *raw, size_t* index) {
  size_t const next_index = *index + sizeof(*value);
  assert(next_index <= raw->dataLength);

  memcpy(value, &raw->data[*index], sizeof(*value));
  *index = next_index;
}

void decode_uint16(u16* value, ENetPacket const* raw, size_t* index) {
  size_t const next_index = *index + sizeof(*value);
  assert(next_index <= raw->dataLength);

  memcpy(value, &raw->data[*index], sizeof(*value));
  *value = ntohs(*value);
  *index = next_index;
}

void decode_uint32(u32* value, ENetPacket const* raw, size_t* index) {
  size_t const next_index = *index + sizeof(*value);
  assert(next_index <= raw->dataLength);

  memcpy(value, &raw->data[*index], sizeof(*value));
  *value = ntohl(*value);
  *index = next_index;
}

void decode_f32(f32* value, ENetPacket const* raw, size_t* index) {
  u32 bits;
  decode_uint32(&bits, raw, index);
  memcpy(value, &bits, sizeof(bits));
}

void decode_vec2(vec2* value, ENetPacket const* raw, size_t* index) {
  decode_f32(&value->x, raw, index);
  decode_f32(&value->y, raw, index);
}
