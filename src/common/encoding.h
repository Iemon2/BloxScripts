#pragma once
 
#include <enet/enet.h>
#include <math/defines.h>
#include <stdint.h>

#define ENCODE_VALUE(value, buff, cap, index)   \
    _Generic((value),                           \
        u8: encode_uint8,                       \
        u16: encode_uint16,                     \
        u32: encode_uint32,                     \
        f32: encode_float,                      \
        vec2: encode_vec2                       \
    )(value, buf, cap, index)

#define DECODE_VALUE(value, raw, index)         \
    _Generic(*(value),                          \
        u8: decode_uint8,                       \
        u16: decode_uint16,                     \
        u32: decode_uint32,                     \
        f32: decode_float,                      \
        vec2: decode_vec2                       \
    )(value, raw, index)

void encode_uint8(u8 value, u8* buf, size_t cap, size_t* index);
void encode_uint16(u16 value, u8* buf, size_t cap, size_t* index);
void encode_uint32(u32 value, u8* buf, size_t cap, size_t* index);
void encode_float(f32 value, u8* buf, size_t cap, size_t* index);
void encode_vec2(vec2 value, u8* buf, size_t cap, size_t* index);

void decode_uint8(u8 *value, ENetPacket const *raw, size_t* index);
void decode_uint16(u16 *value, ENetPacket const *raw, size_t* index);
void decode_uint32(u32 *value, ENetPacket const *raw, size_t* index);
void decode_float(f32 *value, ENetPacket const *raw, size_t* index);
void decode_vec2(vec2 *value, ENetPacket const *raw, size_t* index);