#ifndef HELP_H
#define HELP_H
#include "../../../include/text.h"

static inline void help(void) {
    print("Available commands:\n");
    print("  ver   - Show the version of the system\n");
    print("  clear - Clear the console screen\n");
    print("  help  - Show this help message\n");
    print("\n");
    print("Type a command and press Enter to execute it.\n");
}

#endif // HELP_H
