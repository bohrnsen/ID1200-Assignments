#include <stdlib.h>
#include <unistd.h>

struct chunk {
	int size;
	struct chunk *next;
}

struct chunk* flist = NULL;

void *malloc(size_t size) {
	if(size == 0){
		return NULL;
	}

	struct chunk *next = flist;
	struct chunk 



	void *memory = sbrk(size);
	if(memory == (void *)-1){
		return NULL;
	} else {
		return memory;
	}
}

void free(void *memory){
	if (memory != NULL) {
		/* we're jumping back one chunk position */
		struct chunk *cnk = (struct chunk*)((struct chunk*) memory - 1);
		cnk->next = flist;
		flist = cnk;
	}
	return;
}
