#import "MIA/m_delegate.h"

@implementation M_MacDelegate // Updated class name

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

M_MacDelegate* globalDelegate = nil; // Updated class name

M_MacDelegate* initDelegate() { // Updated class name
    if (globalDelegate == nil) {
        globalDelegate = [[M_MacDelegate alloc] init]; // Updated class name
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
