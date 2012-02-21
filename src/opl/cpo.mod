using CP;

// 从100以内的整数里面取出10个互不相同的整数， 
// 然后对这些整数分别取倒数，然后求和，满足加起来等于1，同时这10个数要尽可能的小。
int m = ...;
int n = 50;

dvar int+ x[1..m];

minimize x[m];
//minimize sum(i in 1..m) x[i];

subject to {
   // 倒数和相加等于1
   sum (i in 1..m) 1/x[i] == 1;

   allDifferent(x);
   // 打破对称性, x[m] 最大
   forall(i in 1..m-1) x[i] < x[i+1];

   // 最大的x 也要小于或者等于n
   x[m] <= n;
}

main {
  a = new Array(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
 
  for (var i=0; i < a.length; i++){
     var source = new IloOplModelSource("cpo.mod");
     var cp = new IloCP();
     cp.param.LogVerbosity = "Quiet";
     cp.param.searchType = "DepthFirst";
     //cp.param.AllDiffInferenceLevel = "Medium";
     var def = new IloOplModelDefinition(source);
     var opl = new IloOplModel(def,cp);
     var data = new IloOplDataSource("cpo.dat");
     var data2= new IloOplDataElements();
     data2.m = a[i];
     opl.addDataSource(data2);
     opl.generate();
     writeln("100里面取" + data2.m + "个数的情况:")
     if (cp.solve()) {
        writeln(opl.printSolution());
     } else {
        writeln("No solution\n");
     }
     opl.end();
     data.end();
     def.end();
     cp.end();
     source.end();
  } 
}
