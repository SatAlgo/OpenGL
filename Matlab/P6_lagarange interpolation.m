x = input("Enter xi values : ");
y = input("Enter yi values : ");
X = input("Enter the value of X : ");

n = length(x); 
Y = 0;        


for i = 1:n
    L = 1; 
    for j = 1:n
        if i ~= j
          
            L = L * (X - x(j)) / (x(i) - x(j));
        end
    end
    
    Y = Y + y(i) * L;
end


fprintf("Value of Y or f(%f) is : %f\n", X, Y);

lagarange interpolation
