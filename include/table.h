#ifndef TABLE_H
#define TABLE_H

#include <stdint.h>
#include "include/pager.h"

#define PAGE_SIZE 4096
#define ROWS_PER_PAGE (PAGE_SIZE / ROW_SIZE)
#define TABLE_MAX_ROWS (ROWS_PER_PAGE * TABLE_MAX_PAGES)

typedef struct {
    Pager* pager;
    uint32_t num_rows;
} Table;

void* cursor_value(Table* table, uint32_t row_num);

Table* open_db(const char* filename);

#endif