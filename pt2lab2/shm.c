#include "param.h"
#include "types.h"
#include "defs.h"
#include "x86.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"
#include <stdbool.h>

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
  struct proc *curproc = myproc();
  bool shm_pg_seen = false;
  int i;
  char *mem;
  
  initlock(&(shm_table.lock), "SHM lock");
  acquire(&(shm_table.lock));

  // look through shm_table
  for(i = 0; i< 64; i++){

    // if (seg id)
    if(shm_table.shm_pages[i].id == id){

      // ref count++
      shm_table.shm_pages[i].refcnt++;

      // mark the id as seen
      shm_pg_seen = true;

      //grab the physical address of the page
//      mem=shm_table.shm_pages[i].frame;

      // map virtual addresses to physical addresses (use mappages)
      mappages(curproc->pgdir, (char*)(PGROUNDUP(curproc->sz)), PGSIZE, V2P(mem), PTE_W|PTE_U);
      
      // return virtual address using pointer
      *pointer=(char *)(PGROUNDUP(curproc->sz));
      release(&(shm_table.lock));
      return 0; 
    }
  }
  release(&(shm_table.lock));

  // if the seg id doesn't exist yet
  if(shm_pg_seen == false){
    // grab lock
    acquire(&(shm_table.lock));

    // store page in shm_table
    for(i = 0; i< 64; ++i){
      if(shm_table.shm_pages[i].id==0){
        shm_table.shm_pages[i].id = id;	// set id
        shm_table.shm_pages[i].refcnt=1;  // set reference count
        mem=kalloc();	// allocate the page
        shm_table.shm_pages[i].frame=mem;
        // map the page
        mappages(curproc->pgdir, (char*)(PGROUNDUP(curproc->sz)), PGSIZE, V2P(mem), PTE_W|PTE_U);
 
        // return virtual address using pointer
        curproc->sz=+PGSIZE;
        *pointer=(char *)(PGROUNDUP(curproc->sz));
        curproc->sz=+PGSIZE;
        release(&(shm_table.lock));
        return 0; 
      }  
    }

    // release lock
    release(&(shm_table.lock));
  }
}

int shm_close(int id) {
  int i, a;

  initlock(&(shm_table.lock), "SHM lock");
  acquire(&(shm_table.lock));

  // look through shm_table
  for(i = 0; i< 64; i++){

    // if (seg_id){
    if(shm_table.shm_pages[i].id == id){
  
      // refcount --
      shm_table.shm_pages[i].refcnt--;

      // if refcount ==0
      if(!shm_table.shm_pages[i].refcnt){

        // clear table 
        for (a = 0; a< 64; a++) {
          shm_table.shm_pages[i].id =0;
          shm_table.shm_pages[i].frame =0;
          shm_table.shm_pages[i].refcnt =0;
        }   
        break;
      }
    }  
  }
  release(&(shm_table.lock));
return 0; //added to remove compiler warning -- you should decide what to return
}
