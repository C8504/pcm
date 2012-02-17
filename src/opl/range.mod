using CP;
range i=1..5;
dvar int x[i] in 1..13;

subject to{
   forall(index in i)
      x[index] in {j | j in 1..3} union {j | j in 5..8} union {j | j in 11..13};
}