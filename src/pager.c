#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/pager.h"
#include "include/table.h"

void* get_page(Pager* pager, uint32_t page_num){
    if (page_num > TABLE_MAX_PAGES){
        printf("Tried to access page number out of bounds.\n");
        exit(EXIT_FAILURE);
    }
    
    if (pager->pages[page_num] == NULL){
        void* page = malloc(PAGE_SIZE);
        uint32_t num_pages = pager->file_length / PAGE_SIZE;
        
        if (pager->file_length % PAGE_SIZE){
            num_pages += 1;
        }

        if (page_num <= num_pages){
            lseek(pager->file_descriptor, page_num * PAGE_SIZE, SEEK_SET);
            ssize_t bytes_read = read(pager->file_descriptor, page, PAGE_SIZE);
            if (bytes_read == -1){
                printf("Error reading file: %d\n", errno);
                exit(EXIT_FAILURE);
            }
        }        

        pager->pages[page_num] = page;
    }

    return pager->pages[page_num];
}

Pager* open_pager(const char* filename){
    int fd = open(
        filename,
        O_RDWR | 
            O_CREAT,
        S_IWUSR |
            S_IRUSR
    );

    if (fd == -1){
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    off_t file_length = lseek(fd, 0, SEEK_END);

    Pager* pager = malloc(sizeof(Pager));
    pager->file_descriptor = fd;
    pager->file_length = file_length;
    
    for (uint32_t i=0; i<TABLE_MAX_PAGES; i++){
        pager->pages[i] = NULL;
    }

    return pager;
}