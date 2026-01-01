#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "sysfunc.h"
#include "pstat.h"
#include "spinlock.h"

/* The following code was added/modified by Parth Thakur (PXT230028) 
 * System call interface for getpinfo.
 * It gets a pointer to a struct pstat using argptr
 * then calls kernel helper getpinfo() to fill in process statistics
 * */
int
sys_getpinfo(void)
{
  struct pstat *ps;
  //Extract the pointer to struct pstat from system call arguments using argptr
  //
  if(argptr(0, (void*)&ps, sizeof(ps)) < 0){
     return -1;
    }

  return getpinfo(ps);
}
/* End of the code added/modified*/




// The following code is added/modified by Parth Thakuar (PXT230028)
// implements system call interface for settickets
// Gets an integer argument from using argint
// then calls the kernel helper settickets() to set the ticket count
int
sys_settickets(void)
{
  int n;

  // Retrive the ticket count argument and validate
  if(argint(0,&n) < 0)
  {
    return -1;
  }
 
  // set tickets for the process using kernel helper settickets()
  return settickets(n);

}

/* End of the code added/modified*/


int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since boot.
int
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
