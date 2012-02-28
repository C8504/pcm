using CP;

dvar boolean x1;
dvar boolean x2;
dvar boolean x3;
dvar boolean x4;
dvar int+ x5;
//dvar float  x5;

minimize x1 + x2 + x3 + x4 + x5;

subject to
{
   x1 + x2 == 1;
   
   x5 <= (3*x1 + 4*x2)*(x3 + x4);
    
   //z=x*y <=> z<=x z<=y z>=x+y-1
   
   /*x3 + x4 == 1 => x5 <= 3*x1 + 4*x2;
   x3 + x4 == 0 => x5 <= 0;
   x3 + x4 == 2 => x5 <= 2*(3*x1 + 4*x2);*/
}
