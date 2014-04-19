//this is an example for sparse matrix data in OPl

tuple task{
	string taskID;
};

{task} Tasks = {
<"Task1">,
<"Task2">,
<"Task3">
};

tuple worker{
	key string workerID;
	string officeID;
	float  salary;
};

{worker} Workers = {
	<"Worker1", "Office1", 1000>,
	<"Worker2", "Office2", 1200>,
	<"Worker3", "Office3", 900>
};


tuple workTask{
	string workerID;
	string taskID;
};

{workTask} WorkerTasks = {
	<"Worker1", "Task1">,
	<"Worker1", "Task2">,
	<"Worker2", "Task1">,
	<"Worker2", "Task2">,
	<"Worker2", "Task3">,
	<"Worker3", "Task1">,
	<"Worker3", "Task3">
};

tuple workDay{
	string workerID;
	int    dayID;
};

{workDay} WorkerDays = {
<"Worker1", 1>,
<"Worker2", 2>,
<"Worker3", 3>,
<"Worker1", 3>,
<"Worker1", 2>,
<"Worker2", 1>,
<"Worker3", 2>
};

tuple taskDay{
	string taskID;
	int    dayID;
};

{taskDay} TaskDays = {
<"Task1", 1>,
<"Task1", 2>,
<"Task2", 1>,
<"Task3", 3>,
<"Task1", 3>,
<"Task2", 1>,
<"Task3", 2>
};

tuple workTaskDay{
	string workerID;
	string taskID;
	int    dayID;
};

{workTaskDay} WorkerTaskDays = {<w,t,d>|
<w,t> in WorkerTasks,<w,d> in WorkerDays,
<t,d> in TaskDays};

float dayPay[Workers] = [w:w.salary/30|w in Workers];

execute{
	writeln(WorkerTaskDays);
}


dvar boolean x[WorkerTaskDays];

minimize sum(<w,t,d> in WorkerTaskDays) x[<w,t,d>]*dayPay[<w>];

subject to
{
   forall(<t> in Tasks){
	assignTasks: sum(<w,t,d> in WorkerTaskDays) x[<w,t,d>] == 1;
   }
   forall(<w,d> in WorkerDays){
	assignWorkers:
		sum(<w,t,d> in WorkerTaskDays) x[<w,t,d>] <= 1;
   }
}

execute{
	for(var i in WorkerTaskDays){
		if(x[i]==1){
			writeln(i);
		}
	}
}
