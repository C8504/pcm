import cplex
import numpy as np
 
prob = cplex.Cplex()
N = 50  
M = 14  

numerical_adjuster = 1 
var_names = ['x' + str(i) for i in range(1, 1 + N)]
 
#obj_coef = range(1, 1 + N)
obj_coef = np.zeros(N).tolist()
prob.variables.add(obj=obj_coef, types=['B'] * N, names=var_names)
prob.variables.add(obj=[1], names=['alpha'])
 
const_1_coef = [numerical_adjuster / float(i) for i in range(1, 1 + N)]
const_2_coef = np.ones(N).tolist()
constraints = [[var_names, const_1_coef], [var_names, const_2_coef]]
c_senses = ['E', 'E']
c_names = ['c_sum_to_1', 'c_n_var']
c_rhs = [numerical_adjuster, M]
for i in range(N):
    temp_vars = ['alpha', 'x' + str(i + 1)]
    temp_constraint = [temp_vars, [1, -(i + 1)]]
    constraints.append(temp_constraint)
    c_senses.append('G')
    c_names.append('c' + str(i + 1))
    c_rhs.append(0)
 
prob.linear_constraints.add(lin_expr=constraints,
                            senses=c_senses,
                            rhs=c_rhs,
                            names=c_names)
 
prob.parameters.emphasis.numerical.set(1)
prob.parameters.mip.tolerances.integrality.set(0);
prob.write('test.lp')
prob.solve()
 
x = prob.solution.get_values(var_names)
for i in range(N):
    if x[i] > 1e-4:
        print(i + 1)
print x
 
obj = prob.solution.get_objective_value()
print obj
