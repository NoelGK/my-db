#ifndef PAGER_H
#define PAGER_H

#include <stdint.h>

#define TABLE_MAX_PAGES 100

typedef struct {
    int file_descriptor;
    uint32_t file_length;
    void* pages[TABLE_MAX_PAGES];
} Pager;

void* get_page(Pager* pager, uint32_t page_num);

Pager* open_pager(const char* filename);

#endif