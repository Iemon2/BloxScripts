#import <Cocoa/Cocoa.h>
#import <platform/macos.h>

void macos_begin_activity_user_interactive(void) {
  NSProcessInfo* proc_info = [NSProcessInfo processInfo];

#ifdef NSActivityUserInteractive
  NSActivityOptions const opts = NSActivityUserInteractive | NSActivityLatencyCritical;
#else
  NSActivityOptions const opts = NSActivityUserInitiated | NSActivityLatencyCritical;
#endif

  [proc_info beginActivityWithOptions:(opts) reason:@"real-time game loop"];
}
