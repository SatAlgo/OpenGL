%% differential equation methods

%% first - euler

% find Y at x = X
% for dy/dx = f(x, y), y(x0) = y0
% taking step size = h

% x = x0 x1=x0+h ... xn=X=x0+nh
% y = y0 y1=?    ... Y=yn=?

% either step size h or intervals n will be given
% their relation (X-x0)/n = h

% here y1 = y0 + h*f(x0, y0)
% .... yn = y(n-1) + h*f(x(n-1), y(n-1))

x0 = input("\nenter x0-");
y0 = input("enter y0-");
X = input("enter X-");
h = input("enter stepsize-");

% now to get this function f(x, y)

% example input
% dy/dx = 1/x^2 - y/x 
% h = 0.1 y(1) = 2
% y(2) = ?

f = @(x, y)(1/x^2 - y/x);

n = (X - x0) / h;

x = zeros(1, n+1);
y = zeros(1, n+1);

% firstly get all n x values

x(1) = x0;

for i = 2:n+1

    x(i) = x(i-1) + h;
end


% now get corresponding y values

y(1) = y0;

for i = 2:n+1

    y(i) = y(i-1) + h*f(x(i-1), y(i-1));
end

Y = y(n+1);

fprintf("\ny(%d) = %f", X, Y);

%% second method - runge kutta method of order 4

% yn = y(n-1) + (k1 + 2*k2 + 2*k3 + k4)*1/6
% k1 = h*f(x(n-1), y(n-1))
% k2 = h*f((x(n-1) + h/2), (y(n-1) + k1/2))
% k3 = h*f((x(n-1) + h/2), (y(n-1) + k2/2))
% k4 = h*f((x(n-1) + h), (y(n-1) + k3))

x0 = input("\nenter x0-");
y0 = input("enter y0-");
X = input("enter X-");
h = input("enter stepsize-");

f = @(x, y)(1/x^2 - y/x);

n = (X - x0) / h;

x = zeros(1, n+1);
y = zeros(1, n+1);


% firstly get all (n+1) x values

x(1) = x0;

for i = 2:n+1

    x(i) = x(i-1) + h;
end

% now get corresponding y values

y(1) = y0;

for i = 2:n+1

    k1 = h*f(x(i-1), y(i-1));
    k2 = h*f((x(i-1) + h/2), (y(i-1) + k1/2));
    k3 = h*f((x(i-1) + h/2), (y(i-1) + k2/2));
    k4 = h*f((x(i-1) + h), (y(i-1) + k3));

    y(i) = y(i-1) + (k1 + 2*k2 + 2*k3 + k4) / 6;
end

Y = y(n+1);

fprintf("\ny(%d) = %f", X, Y);
