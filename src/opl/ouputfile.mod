dvar int x in 1..5;
dvar int y in 1..5;

minimize x + y;

subject to{
   x - y == 1;
}

execute {
  var f = new IloOplOutputFile("result.txt");
  f.writeln("x = " + x);
  f.writeln("y = " + y);  
  f.close();
}