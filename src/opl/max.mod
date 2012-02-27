
dvar int+ x[1..5] in 1..5;

maximize sum (i in 1..5) x[i];

subject to
{
1 <= max (i in 1..3) x[i] <= 3;
}