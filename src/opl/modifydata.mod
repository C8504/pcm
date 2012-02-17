float maxOfx = ...;
dvar float x;

maximize x;
subject to {
  x <= maxOfx;
}

main {
  a = new Array(1,2,3,4,5,6,7,8,9,10);
 
  for (var i=0; i < a.length; i++){
     var source = new IloOplModelSource("test.mod");
     var cplex = new IloCplex();
     var def = new IloOplModelDefinition(source);
     var opl = new IloOplModel(def,cplex);
     var data = new IloOplDataSource("data.dat");
     var data2= new IloOplDataElements();
     data2.maxOfx = a[i];
     opl.addDataSource(data2);
     opl.generate();
     if (cplex.solve()) {
        writeln("OBJ = " + cplex.getObjValue());

     } else {
        writeln("No solution");
     }
     opl.end();
     data.end();
     def.end();
     cplex.end();
     source.end();
  }
}