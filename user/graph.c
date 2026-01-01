#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

/*The following code was added/modified by Parth Thakur (PXT230028)
 * In settickets(), each child spins forever  to simulate CPU load.
 * Using getpinfo(), print PID, ticket count, and running ticks for each process
 * Finally, kill all processes and exit
 *
 */
int main(){


  int pid;

  //First child
  //Allocate 30 tickets and spin forever
  pid=fork();
  if (pid==0)
  {
    settickets(30);
    while(1);
  }


  
  //second child
  //allocate 20 tickets and spin forever
  pid=fork();

  if(pid==0)
  {
    settickets(20);
    while(1);

  }


 // Third child
 // allocate 10 tickets and spin forever
  pid=fork();

  if (pid ==0)
  {
    settickets(10);
    while(1);
  }


 // Allow children to run for a while
  sleep(500);

  // Gather process statistics
  struct pstat stat;


  //fill stat with process statistic
  getpinfo(&stat);

  int i;

  printf(1, "PID\tTickets\tTicks\n");

 // Loop over all the entries in the table
  for (i=0; i < NPROC; i++){

   if(stat.inuse[i])
   {
     // Display PID, assigned tickets, and ticks of the proces
     printf(1, "%d\t%d\t%d\n",stat.pid[i],stat.tickets[i], stat.ticks[i]);


   }

  }
  

  //Terminate all child processes
  kill(-1);

  exit();//Exit the parent process
  


}

/*End of code added/modified*/
