range a = 1..10;
range b = 1..5;
range c = 1..5;
dvar int+ x[a][b][c];

minimize 0;

subject to
{
forall(i in a, j in b)
   sum(k in c) x[i][j][k] + sum(m in c:m!=i) x[i][j][m] <= 1;
}