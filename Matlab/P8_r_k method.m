%Runge-Kutta 4th-order
syms x 
syms y
f(x, y) = input("Enter f(x,y): ");
y1 = input("Enter y1 value: ");
x1 = input("Enter x1 value: ");
h = input("Enter Step Size: ");
X = input("Enter X value: ");
n = (X - x1)/h; 
x = x1:h:X;

y = zeros(1, n+1); 
y(1) = y1;

for i = 2:(n+1)
    k1 = h * f(x(i-1), y(i-1));
    k2 = h * f(x(i-1) + h/2, y(i-1) + k1/2);
    k3 = h * f(x(i-1) + h/2, y(i-1) + k2/2);
    k4 = h * f(x(i-1) + h, y(i-1) + k3);
    y(i) = y(i-1) + (k1 + 2*k2 + 2*k3 + k4) / 6;
end

disp(y(n+1));


r_k method
