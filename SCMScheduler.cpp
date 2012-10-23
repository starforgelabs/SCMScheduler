#include <SCMScheduler.h>

void SCMScheduler::run()
{
  selectNextProcess();
  processes[current]->execute();
}

// This is a very simple round robin scheduler
void SCMScheduler::selectNextProcess()
{
  if(current == NullIndex || count == 1)
    current = 0; 
  else
    current = (current+1) % count;
}

