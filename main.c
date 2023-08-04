// main.c
#include "mac.h"
#include "mac_window.h"
#include <stdbool.h>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // Initialize the application
    if(MAC_Init(0) != 0) {
        fprintf(stderr, "Failed to initialize the application\n");
        return 1;
    }

    // Create a window
    MAC_Window* mainWindow = createWindow(800, 600, "Main Window");

    // Add a content view to the window with a blue background
    Mac_View* contentView = addContentView(mainWindow, MAC_COLOR_BLUE);

    // Add a subview to the content view with a red background
    Mac_View* subView = addSubView(mainWindow, 200, 200, 100, 100, MAC_COLOR_RED);

    // Main loop
    bool running = true;
    MAC_Event event;
    while (running) {
        runWindow();
        while (MAC_PollEvent(&event)) {
            switch (event.type) {
                case MAC_KEYBOARDEVENT:
                    if (event.keycode == MAC_KEY_ESCAPE) {
                        running = false;
                    }
                    break;
                case MAC_MOUSEEVENT:
                    if (event.button == MAC_BUTTON_LEFT) {
                        printf("Left mouse button pressed at (%d, %d)\n", event.x, event.y);
                    }
                    break;
                case MAC_NOEVENT:
                default:
                    break;
            }
        }
        if(!isWindowOpen(mainWindow)) {
            running = false;
        }
    }

    // Cleanup
    destroyView(subView);
    destroyView(contentView);
    destroyWindow(mainWindow);
    MAC_Quit();

    return MAC_SUCCESS;
}
