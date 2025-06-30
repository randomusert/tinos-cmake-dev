#include "../../include/text.h"
#include "../../include/io.h"
#include "../../include/scancodes.h"
#include "commands/ver.h"
#include "commands/clear.h"
#include "commands/help.h"
#include "commands/whoami.h"
#include "commands/uname.h"


//irq based keyboard input handling
#define KBD_BUF_SIZE 128
static char kbd_buf[KBD_BUF_SIZE];
static int kbd_buf_head = 0;
static int kbd_buf_tail = 0;

void kbd_buffer_push(char c) {
    int next = (kbd_buf_head + 1) % KBD_BUF_SIZE;
    if (next != kbd_buf_tail) {
        kbd_buf[kbd_buf_head] = c;
        kbd_buf_head = next;
    }
}

char read_char() {
    if (kbd_buf_head == kbd_buf_tail) return 0;
    char c = kbd_buf[kbd_buf_tail];
    kbd_buf_tail = (kbd_buf_tail + 1) % KBD_BUF_SIZE;
    return c;
}



void console() {
    char buffer[128];
    int pos = 0;

    print(">");

    while (1) {
        char c = read_char();
        if (!c) continue;

        if (c == '\b') {
            if (pos > 0) {
                pos--;
                print("\b \b");
            }
        } else if (c == '\n') {
            buffer[pos] = '\0';
            print("\n");

            if (strcmp(buffer, "ver") == 0) {
                ver();
            } else if (strcmp(buffer, "clear") == 0) {
                clear();
            } else if (strcmp(buffer, "help") == 0) {
                help();
            } else if (strcmp(buffer, "whoami") == 0) {
                whoami();
            } else if (strcmp(buffer, "uname") == 0) {
                uname();
            } else {
                print("Unknown command: ");
                print(buffer);
                print("\n");
            }

            print(">");
            pos = 0;
        } else if (pos < sizeof(buffer) - 1) {
            buffer[pos++] = c;
            putchar(c);
        }
    }
}

