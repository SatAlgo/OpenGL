%Euler's Method
syms x 
syms y
f(x,y) = input("Enter f(x,y)")
y1 = input("Enter y1 value")
x1 = input("Enter x1 value")
h = input("Enter Step Size")
X = input("Enter X value")
n = (X - x1)/h
x = x1:h:X

y = zeros(1, n+1)
y(1) = y1

for i = 2 : (n+1)
    y(i) = y(i-1) + h * f(x(i-1),y(i-1))
end
disp(y(n+1))


eulers method
