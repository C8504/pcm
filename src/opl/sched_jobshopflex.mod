// --------------------------------------------------------------------------
// Licensed Materials - Property of IBM
//
// 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55
// Copyright IBM Corporation 1998, 2013. All Rights Reserved.
//
// Note to U.S. Government Users Restricted Rights:
// Use, duplication or disclosure restricted by GSA ADP Schedule
// Contract with IBM Corp.
// --------------------------------------------------------------------------

using CP;

int nbJobs = ...;
int nbMchs = ...;

range Jobs = 1..nbJobs;
range Mchs = 1..nbMchs; 

tuple Operation {
  int id;    // Operation id
  int jobId; // Job id
  int pos;   // Position in job
};

tuple Mode {
  int opId; // Operation id
  int mch;  // Machine
  int pt;   // Processing time
};

{Operation} Ops   = ...;
{Mode}      Modes = ...;

// Position of last operation of job j
int jlast[j in Jobs] = max(o in Ops: o.jobId==j) o.pos;

dvar interval ops  [Ops]; 
dvar interval modes[md in Modes] optional size md.pt;
dvar sequence mchs[m in Mchs] in all(md in Modes: md.mch == m) modes[md];

execute {
  		cp.param.TimeLimit = 60;
}

minimize max(j in Jobs, o in Ops: o.pos==jlast[j]) endOf(ops[o]);
subject to {
  forall (j in Jobs, o1 in Ops, o2 in Ops: o1.jobId==j && o2.jobId==j && o2.pos==1+o1.pos)
    endBeforeStart(ops[o1],ops[o2]);
  forall (o in Ops)
    alternative(ops[o], all(md in Modes: md.opId==o.id) modes[md]);
  forall (m in Mchs)
    noOverlap(mchs[m]);
}

execute {
  for (var m in Modes) {
    if (modes[m].present)
      writeln("Operation " + m.opId + " on machine " + m.mch + " starting at " + modes[m].start);
  }
}
