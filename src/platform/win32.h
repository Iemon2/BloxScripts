#pragma once

#ifndef _WIN32
#error "win32: this header is for Windows only"
#endif

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define NOGDI
#define NOUSER

/* clang-format off */
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <enet/enet.h>
/* clang-format on */

/* I HATE WINDOWS API SO MUCH */
#ifdef Rectangle
#undef Rectangle
#endif
#ifdef CloseWindow
#undef CloseWindow
#endif
#ifdef ShowCursor
#undef ShowCursor
#endif
