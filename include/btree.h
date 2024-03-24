#ifndef BTREE_H
#define BTREE_H

#include <stdint.h>

/* Common node header layout */
extern uint32_t NODE_TYPE_SIZE = sizeof(uint8_t);
extern uint32_t NODE_TYPE_OFFSET = 0;
extern uint32_t IS_ROOT_SIZE = NODE_TYPE_SIZE;
extern uint32_t IS_ROOT_OFFSET = NODE_TYPE_SIZE;
extern uint32_t PARENT_POINTER_SIZE = sizeof(uint32_t);
extern uint32_t PARENT_POINTER_OFFSET = IS_ROOT_OFFSET + IS_ROOT_SIZE;
extern uint32_t COMMON_NODE_HEADER_SIZE = NODE_TYPE_SIZE + IS_ROOT_SIZE + PARENT_POINTER_SIZE;

/* Leaf node header layout */
extern uint32_t LEAF_NODE_NUM_CELLS_SIZE = sizeof(uint32_t);
extern uint32_t LEAF_NODE_NUM_CELLS_OFFSET = COMMON_NODE_HEADER_SIZE;
extern uint32_t LEAF_NODE_HEADER_SIZE = COMMON_NODE_HEADER_SIZE + LEAF_NODE_NUM_CELLS_SIZE;

typedef enum { NODE_INTERNAL, NODE_LEAF } NodeType;

/* Leaf node body layout */
extern uint32_t LEAF_NODE_KEY_SIZE;
extern uint32_t LEAF_NODE_KEY_OFFSET;
extern uint32_t LEAF_NODE_VALUE_SIZE;
extern uint32_t LEAF_NODE_VALUE_OFFSET;
extern uint32_t LEAF_NODE_CELL_SIZE;
extern uint32_t LEAF_NODE_SPACE_FOR_CELLS;
extern uint32_t LEAF_NODE_MAX_CELLS;

#endif