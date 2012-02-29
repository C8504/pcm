range r1 = 1..5;
range r2 = 1..10;

dvar int+ x[r1][r1] in r2;

//minimize sum(i in r1) sum(j in r1) x[i][j];
minimize sum(i in r1, j in r1) x[i][j];

subject to
{
   
}