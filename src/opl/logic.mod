//this is an example for logic constraints in OPl

dvar boolean x;
dvar boolean y;
dvar boolean z;

maximize x + y + z;
subject to
{
   x + y == 1 => z == 1;
   z == 1 => x + y == 1;
}