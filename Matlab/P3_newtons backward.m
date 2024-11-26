x = input("Enter xi values: ");
y = input("Enter yi values: ");
X = input("Enter the value of X: ");
n = length(x)
h = x(2) - x(1)
D = zeros(n)
for i = 1:n
    D(i,1) = y(i)
end
for j = 2:n
    for i = n:-1:j
        D(i,j) = D(i,j-1) - D(i -1, j-1)
    end
end
Y = y(n)
product = 1
fact = 1
u = (X -x(n))/h

for i = 1:n-1
    product = product*(u+1-1)
    fact = fact*(1/i)
    Y = Y + product * fact* D(n, i+1)
end

fprintf("The interpolated value is %2f", Y)


newtons backward
