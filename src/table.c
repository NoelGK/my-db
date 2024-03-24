#include <stdint.h>
#include "include/row.h"
#include "include/table.h"
#include "include/pager.h"
#include "include/cursor.h"

void* cursor_value(Cursor* cursor){
    uint32_t row_num = cursor->row_num;
    uint32_t page_num = row_num / ROWS_PER_PAGE;
    void* page = get_page(cursor->table->pager, page_num);

    uint32_t row_offset = row_num % ROWS_PER_PAGE;
    uint32_t byte_offset = row_offset * ROW_SIZE;

    return page + byte_offset;
}

Table* open_db(const char* filename) {
    Pager* pager = open_pager(filename);
    uint32_t num_rows = pager->file_length / ROW_SIZE;
    
    Table* table = malloc(sizeof(Table));
    table->pager = pager;
    table->num_rows = num_rows;

    return table;
}