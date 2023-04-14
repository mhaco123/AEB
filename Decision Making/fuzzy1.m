
a = newfis('fis1.fis'); %create a new FIS file

a = addvar(a, 'input', 'x', [2 9]);%add and input variable 'x' into the FIS
a = addmf(a, 'input', 1, 'A1', 'trimf', [2 5 8]);%add 2 MFs into the variable x
a = addmf(a, 'input', 1, 'A2', 'trimf', [3 6 9]);

a = addvar(a, 'input', 'y', [4 11]);%add and input variable 'y' into the FIS
a = addmf(a, 'input', 2, 'B1', 'trimf', [5 8 11]);%add 2 MFs into the variable y
a = addmf(a, 'input', 2, 'B2', 'trimf', [4 7 10]);

a = addvar(a, 'output', 'z', [1 9]);%add and output variable 'z' into the FIS
a = addmf(a, 'output', 1, 'C1', 'trimf', [1 4 7]);%add 2 MFs into the variable z
a = addmf(a, 'output', 1, 'C2', 'trimf', [3 6 9]);

rulelist = [1 1 1 1 1;
-1 2 2 1 1;]; %2 rule is defined and added into FIS
a = addrule(a, rulelist);

writefis(a, 'fis1.fis');
ruleview fis1 

b=readfis('fis1');
% outputs
out1=evalfis([5 8; 6 9; 8 10;3 5;5.5 7.7],b)

