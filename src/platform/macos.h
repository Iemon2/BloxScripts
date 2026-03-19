#pragma once

#ifndef __APPLE__
#error "macos: this header is for macOS only"
#endif

void macos_begin_activity_user_interactive(void);
