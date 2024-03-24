#include "include/btree.h"

/* Common node header layout */
uint32_t NODE_TYPE_SIZE = sizeof(uint8_t);
uint32_t NODE_TYPE_OFFSET = 0;
uint32_t IS_ROOT_SIZE = NODE_TYPE_SIZE;
uint32_t IS_ROOT_OFFSET = NODE_TYPE_SIZE;
uint32_t PARENT_POINTER_SIZE = sizeof(uint32_t);
uint32_t PARENT_POINTER_OFFSET = IS_ROOT_OFFSET + IS_ROOT_SIZE;
uint32_t COMMON_NODE_HEADER_SIZE = NODE_TYPE_SIZE + IS_ROOT_SIZE + PARENT_POINTER_SIZE;

/* Leaf node header layout */
uint32_t LEAF_NODE_NUM_CELLS_SIZE = sizeof(uint32_t);
uint32_t LEAF_NODE_NUM_CELLS_OFFSET = COMMON_NODE_HEADER_SIZE;
uint32_t LEAF_NODE_HEADER_SIZE = COMMON_NODE_HEADER_SIZE + LEAF_NODE_NUM_CELLS_SIZE;