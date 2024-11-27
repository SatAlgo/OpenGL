%% newton's interpolation

% condition - x values should be equally spaced

% to find y(X) if the curve y=f(x)
% passes through the points (xi, yi), i = 1,2,...,n

% two types
% 1. forward difference [when X is closer to x1]
% 2. backward difference [when X is closer to xn]
% any can be selected when X is midpoint of x1 to xn

% 1. Newton's forward interpolation formula
% y(X) = y1 + (X-x1)Δy1/h + (X-x1)(X-x2)(Δy1)^{2}/(2!)(h^2) + ...
% ... + (X-x1)...(X-x(n-1))(Δy1)^{n-1}/((n-1)!)(h^{n-1})
% Δy1 = first order forward diff. of y1 = y2-y1
% Δy2 = y3-y2
% .
% Δyr = y(r+1)-yr, r = 1,2,...,(n-1)
% (Δy1)^{2} = second order forward diff. of y1 = y3-2y2+y1
% these coefficients are decided using pascal's triangle, alternate signs

% so till where can we go
% i         Δ       ∇
% y1        n-1     0
% y2        n-2     1
% y3        n-3     2
% .         .       .
% y(n-1)    1       n-2
% yn        0       n-1

% we will be using a matrix for our coefficent
% difference table (D) will be its name
% its size will be n*n [n = number of elements]
% our first column is values of y
% eg. x : 0 1 2, y : 2 3 6
% D = [2 _ _]
%     [3 _ _]
%     [6 _ _]
% D(1,2) = D(2,1) - D(1,1)
% D(2,2) = D(3,1) - D(2,1)
% D = [2 1 _]
%     [3 3 _]
%     [6 _ _]
% D(1,3) = D(2,2) - D(2,1)
% D = [2 1 2]
%     [3 3 _]
%     [6 _ _]
% in general,
% j = 2, 3, ..., n
% j = 2 -> i = 1:n-1
% j = 3 -> i = 1:n-2
% .
% j = n-1 -> i = 1:2
% j = n -> i = 1
% D(i,j) = D(i+1, j-1) - D(i, j-1)
% in this D,
% the first row, will be used for forward interpolation
% the non-principal diagonal, will be used for backward interpolation


% 2. Netwon's Backward Interpolation Formula
% y(X) = yn + (X-xn)Δyn/h + (X-xn)(X-x(n-1))(Δyn)^{2}/(2!)(h^2) + ...
% ... + (X-xn)...(X-x2)(Δyn)^{n-1}/((n-1)!)(h^{n-1})
