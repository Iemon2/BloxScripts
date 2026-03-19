#pragma once

#include <server/players.h>
#include <math/defines.h>
#include <server/coreState.h>

typedef struct {
    
} Player;

typedef u16 PlayerID;
typedef u32 PlayerBitmap;

bool player_bitmap_full(PlayerBitmap bitmap) {
    return (POPCNT(bitmap) >= MAX_PLAYERS)
}