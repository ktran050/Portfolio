#include "param.h"
#include "types.h"
#include "defs.h"
#include "x86.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"

struct {
  struct spinlock lock;
  struct shm_page {
    uint id;
    char *frame;
    int refcnt;
  } shm_pages[64];
} shm_table;

void shminit() {
  int i;
  initlock(&(shm_table.lock), "SHM lock");
  acquire(&(shm_table.lock));
  for (i = 0; i< 64; i++) {
    shm_table.shm_pages[i].id =0;
    shm_table.shm_pages[i].frame =0;
    shm_table.shm_pages[i].refcnt =0;
  }
  release(&(shm_table.lock));
}

int shm_open(int id, char **pointer) {
  uint pageSeen=0;	// flag that an id has been seen
  struct proc *curproc=myproc();
  char *mem;
  int i;

  // Loop through the table
  initlock(&(shm_table.lock), "SHM lock");
  acquire(&(shm_table.lock));
  for(i = 0; i < 64; i++){
    if(shm_table.shm_pages[i].id==id){
      // Set flag
      pageSeen=1;
      // Increment counter
      shm_table.shm_pages[i].refcnt+=1;
      // Map the page
//      mappages(curproc->pgdir, (char*)(PGROUNDUP(curproc->sz)), PGSIZE, V2P(shm_table.shm_pages[i].frame), PTE_W|PTE_U);
      mem=shm_table.shm_pages[i].frame;
      mappages(curproc->pgdir, (char*)(PGROUNDUP(curproc->sz)), PGSIZE, V2P(mem), PTE_W|PTE_U);
      // Return pointer to virtual address
      *pointer=(char *)(curproc->sz);
      // Update size to reflect changes
      curproc->sz+=PGSIZE;
      // Release lock
      release(&(shm_table.lock));
      // Execution complete
      return 0;
    }
  }
  
  // case id not found
  if(pageSeen==0){
    // Loop through the table for the next available entry
    for(i=0; i < 64; i++){
      if(shm_table.shm_pages[i].id==0){
        // Set id
        shm_table.shm_pages[i].id=id;
	// Allocate a page
	mem=kalloc();
        // Set frame
        shm_table.shm_pages[i].frame=mem;
        // Increment page count
        shm_table.shm_pages[i].refcnt=1;
        // Map the page
        mappages(curproc->pgdir, (char*)(PGROUNDUP(curproc->sz)), PGSIZE, V2P(mem), PTE_W|PTE_U);
        // Return pointer to virtual address
        *pointer=(char*)(curproc->sz);
        // Increment the size
        curproc->sz+=PGSIZE;
      }
    }
  }
  // Release lock
  release(&(shm_table.lock));
  return 0; //added to remove compiler warning -- you should decide what to return
}


int shm_close(int id) {
  int i;

  initlock(&(shm_table.lock), "SHM lock");
  acquire(&(shm_table.lock));
  // Loop through the table looking for the id
  for(i=0; i <64; i++){
    if(shm_table.shm_pages[i].id==id){
      // Decrease reference count
      shm_table.shm_pages[i].refcnt-=1;
      // if refcnt is now empty clear the entry
      if(shm_table.shm_pages[i].refcnt==0){
        shm_table.shm_pages[i].id=0;
        shm_table.shm_pages[i].frame=0;	// refcount is already 0; no need to set it again
      }
    }
  }
  release(&(shm_table.lock));
  return 0; //added to remove compiler warning -- you should decide what to return
}
