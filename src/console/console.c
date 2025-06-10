#include "../include/text.h"
#include "../include/io.h"
#include "../include/scancodes.h"



void console() {

    //printing
    //print("test\n");
    //print("test2");

    //console. hurray! finally.
    char buffer[128];
    print(">");
    scanf(buffer, sizeof(buffer));
    if (buffer == "ver")
    {
        print("v0.0.2 alpha");
    }
    
}