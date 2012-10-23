#ifndef SCM_SCHEDULER_H
#define SCM_SCHEDULER_H

#include "Arduino.h"
#include <SCMProcess.h>

class SCMScheduler
{
  private:
  typedef int8_t ProcessIndex;
  static const ProcessIndex NullIndex = -1;

  public:
  SCMScheduler(SCMProcess** aProcessList, byte aProcessCount) :
    processes(aProcessList), count(aProcessCount), current(NullIndex) {}
  
  void run();
  
  private:
  void selectNextProcess();
  
  // Currently-running process
  ProcessIndex  current;
  // Array of processes available to run 
  SCMProcess** processes;
  // Number of processes in the array
  byte count;
};

#endif // SCM_SCHEDULER_H

