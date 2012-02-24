dvar int x[1..20] in 0..20;
minimize max(i in 1..20) x[i];

subject to
{
 sum(i in 1..20) x[i]==30;  
}