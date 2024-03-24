#ifndef CURSOR_H
#define CURSOR_H

#include <stdint.h>
#include <stdbool.h>
#include "include/table.h"

typedef struct {
    Table* table;
    uint32_t row_num;
    bool end_of_table;
} Cursor;

Cursor* table_start(Table* table);

Cursor* table_end(Table* table);

void advance_cursor(Cursor* cursor);

#endif