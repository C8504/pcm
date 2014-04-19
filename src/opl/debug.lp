\ENCODING=ISO-8859-1
\Problem name: IloCplex

Minimize
 obj: 33.3333333333333 x({"Worker1","Task1",1})
      + 33.3333333333333 x({"Worker1","Task1",3})
      + 33.3333333333333 x({"Worker1","Task1",2})
      + 33.3333333333333 x({"Worker1","Task2",1}) + 40 x({"Worker2","Task1",2})
      + 40 x({"Worker2","Task1",1}) + 40 x({"Worker2","Task2",1})
      + 40 x({"Worker2","Task3",2}) + 30 x({"Worker3","Task1",3})
      + 30 x({"Worker3","Task1",2}) + 30 x({"Worker3","Task3",3})
      + 30 x({"Worker3","Task3",2}) + x13
Subject To
 assignTasks("Task1"):        x({"Worker1","Task1",1})
                              + x({"Worker1","Task1",3})
                              + x({"Worker1","Task1",2})
                              + x({"Worker2","Task1",2})
                              + x({"Worker2","Task1",1})
                              + x({"Worker3","Task1",3})
                              + x({"Worker3","Task1",2})  = 1
 assignTasks("Task2"):        x({"Worker1","Task2",1})
                              + x({"Worker2","Task2",1})  = 1
 assignTasks("Task3"):        x({"Worker2","Task3",2})
                              + x({"Worker3","Task3",3})
                              + x({"Worker3","Task3",2})  = 1
 assignWorkers("Worker1")(1): x({"Worker1","Task1",1})
                              + x({"Worker1","Task2",1}) <= 1
 assignWorkers("Worker2")(2): x({"Worker2","Task1",2})
                              + x({"Worker2","Task3",2}) <= 1
 assignWorkers("Worker3")(3): x({"Worker3","Task1",3})
                              + x({"Worker3","Task3",3}) <= 1
 assignWorkers("Worker1")(3): x({"Worker1","Task1",3}) <= 1
 assignWorkers("Worker1")(2): x({"Worker1","Task1",2}) <= 1
 assignWorkers("Worker2")(1): x({"Worker2","Task1",1})
                              + x({"Worker2","Task2",1}) <= 1
 assignWorkers("Worker3")(2): x({"Worker3","Task1",2})
                              + x({"Worker3","Task3",2}) <= 1
Bounds
 0 <= x({"Worker1","Task1",1}) <= 1
 0 <= x({"Worker1","Task1",3}) <= 1
 0 <= x({"Worker1","Task1",2}) <= 1
 0 <= x({"Worker1","Task2",1}) <= 1
 0 <= x({"Worker2","Task1",2}) <= 1
 0 <= x({"Worker2","Task1",1}) <= 1
 0 <= x({"Worker2","Task2",1}) <= 1
 0 <= x({"Worker2","Task3",2}) <= 1
 0 <= x({"Worker3","Task1",3}) <= 1
 0 <= x({"Worker3","Task1",2}) <= 1
 0 <= x({"Worker3","Task3",3}) <= 1
 0 <= x({"Worker3","Task3",2}) <= 1
      x13 = 0
Binaries
 x({"Worker1","Task1",1})  x({"Worker1","Task1",3})  x({"Worker1","Task1",2}) 
 x({"Worker1","Task2",1})  x({"Worker2","Task1",2})  x({"Worker2","Task1",1}) 
 x({"Worker2","Task2",1})  x({"Worker2","Task3",2})  x({"Worker3","Task1",3}) 
 x({"Worker3","Task1",2})  x({"Worker3","Task3",3})  x({"Worker3","Task3",2}) 
End
