
#ifndef IO_H
#define IO_H

#include "types.h"


unsigned char inb(unsigned short port);
void outb(unsigned short port, unsigned char val);


void scanf(char* buffer, size_t max_len);

int strcmp(const char* s1, const char* s2);


#endif
