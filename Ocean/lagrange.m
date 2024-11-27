%% langrange's interpolation question

% x : x1, x2, ..., xn
% X any value in (x1, xn) but ~= xi

% now
% L1 = (X-x2)(X-x3)...(X-xn) / (x1-x2)(x1-x3)...(x1-xn)
% L2 = (X-x1)(X-x3)...(X-xn) / (x2-x1)(x2-x3)...(x2-xn)
% .
% .
% Li = (X-x1)...(X-x(i-1))(X-x(i+1))...(X-xn) / (xi-x1)...(xi-x(i-1))(xi-x(i+1))...(xi-xn)
% or Li = product_of((X-xj)/(xi-xj)), condition - from j = 1 to n, i ~= j
% i = 1, 2, ..., n
% output in L = [L1 L2 ... Li ... Ln]

x = input("values of x in []- ");
X = input("value of X - ");
n = length(x);

L = zeros(1, n);

for i = 1:n
    Li = 1;
    for j = 1:n
        if i ~= j
            Li = Li * (X - x(j))/(x(i)-x(j));
        end
    end
    L(i) = Li;
end

fprintf("\nHere's the answer - ");
disp(L);


%% now find other half

% Y(X) = ?
% y : y1 y2 ... yn
% Y(X) = y1L1 + y2L2 + ... + ynLn


x = input("values of x in []- ");
y = input("values of y in []- ");
X = input("value of X - ");
n = length(x);

L = zeros(1, n);
Y = 0;

for i = 1:n
    Li = 1;
    for j = 1:n
        if i ~= j
            Li = Li * (X - x(j))/(x(i)-x(j));
        end
    end
    L(i) = Li;
    Y = Y + (L(i) * y(i));
end

fprintf("\nHere's the answer - %d", Y);

% ok so, yeah lagrange's interpolation method hai
