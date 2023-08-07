#ifndef mac_error_h_
#define mac_error_h_


#ifdef __cplusplus
extern "C" {
#endif

#define MAC_SUCCESS 0
#define MAC_ERROR -1

typedef enum 
{
    MAC_ERROR_INIZIALIZATION_FAILED ,
    // window errors
    MAC_ERROR_WINDOW_CREATION_FAILED,
    MAC_ERROR_WINDOW_NOT_FOUND,
    MAC_ERROR_WINDOW_MEMORY_ALLOCATION_FAILED,
    // delegate errors
    MAC_ERROR_DELEGATE_INIT_FAILED,
    // subsystem errors
    MAC_ERROR_VIDEO_INIT_FAILED,
    MAC_ERROR_AUDIO_INIT_FAILED,
    MAC_ERROR_TIMER_INIT_FAILED,
    MAC_ERROR_JOYSTICK_INIT_FAILED,
    MAC_ERROR_HAPTIC_INIT_FAILED,
    MAC_ERROR_GAMECONTROLLER_INIT_FAILED,
    MAC_ERROR_EVENTS_INIT_FAILED,
    // device errors
    MAC_ERROR_NO_METAL_DEVICE_FOUND,
    // button errors
    MAC_ERROR_BUTTON_CREATION_FAILED,
    MAC_ERROR_BUTTON_NOT_FOUND,
    MAC_ERROR_BUTTON_MEMORY_ALLOCATION_FAILED,
    MAC_ERROR_BUTTON_FONT_SMALLER_THAN_HEIGHT,
    // label errors
    MAC_ERROR_LABEL_CREATION_FAILED,
    MAC_ERROR_LABEL_NOT_FOUND,
    MAC_ERROR_LABEL_MEMORY_ALLOCATION_FAILED,
    // image errors
    MAC_ERROR_IMAGE_CREATION_FAILED,
    MAC_ERROR_IMAGE_NOT_FOUND,
    MAC_ERROR_IMAGE_MEMORY_ALLOCATION_FAILED,
} MAC_Error;

/*!
    Prints the error to the console.
    @param error: the error to print
*/
void mac_printError(MAC_Error error);

#ifdef __cplusplus
}
#endif

#endif // mac_error_h_