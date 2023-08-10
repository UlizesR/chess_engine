#import "MACA/mac_delegate.h"

@implementation Mac_Delegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    if (globalDelegate == nil) {
        return;
    }
}

- (void)applicationWillTerminate:(NSNotification *)aNotification {
    if (globalDelegate == nil) {
        return;
    }
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender {
    if (globalDelegate == nil) {
        return NO;
    }
    return YES;
}

@end

Mac_Delegate* globalDelegate = nil;

Mac_Delegate* initDelegate() {
    if (globalDelegate == nil) {
        globalDelegate = [[Mac_Delegate alloc] init];
        globalDelegate.childWindows = [NSMutableArray array]; // Initialize the child windows array
    }
    
    return globalDelegate;
}

void terminateDelegate() {
    if (globalDelegate == nil) {
        return;
    }
    [NSApp terminate:globalDelegate];
    globalDelegate = nil;
}

void runDelegate() {
    if (globalDelegate == nil) {
        return;
    }
    NSEvent *event;
    do {
        event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                   untilDate:[NSDate distantPast]
                                   inMode:NSDefaultRunLoopMode
                                   dequeue:YES];
        if (event) {
            [NSApp sendEvent:event];
        }
    } while (event);
}