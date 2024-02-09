#ifndef ROW_H
#define ROW_H

#include <stdlib.h>
#include <stdint.h>

#define sizeofattribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)
#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255


/* * * * * ROW DATA STRUCT AND MEMORY REPRESENTATION * * * * */
typedef struct {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE+1];
    char email[COLUMN_EMAIL_SIZE+1];
} Row;

extern const uint32_t ID_SIZE;
extern const uint32_t USERNAME_SIZE;
extern const uint32_t EMAIL_SIZE;

extern const uint32_t ID_OFFSET;
extern const uint32_t USERNAME_OFFSET;
extern const uint32_t EMAIL_OFFSET;
extern const uint32_t ROW_SIZE;

void serialize_row(Row* source, void* destination);

void deserialize_row(void* source, Row* destination);
/* * * * * * * * * */

#endif