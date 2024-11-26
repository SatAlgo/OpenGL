syms t s;
% Define a function f(t)
f = exp(-2*t) * sin(3*t); % Example: f(t) = e^(-2t) * sin(3t)

% Compute Laplace Transform
F = laplace(f, t, s);

% Display the result
disp('Laplace Transform of the function:');
disp(F);
%% 
syms t s Y;

% Define the differential equation: y''(t) - 3y'(t) + 2y(t) = 0
% Taking Laplace transform of each term
Y_s = (s^2 * 1 - s * 0) / (s^2 - 3*s + 2); % Laplace transform of the equation

% Solve for Y(s)
Y_s = simplify(Y_s);
disp('Laplace transform solution Y(s):');
disp(Y_s);

% Find the inverse Laplace transform to get y(t)
y_t = ilaplace(Y_s, s, t);
disp('Inverse Laplace transform (solution y(t)):');
disp(y_t);

%% 

% Define a matrix
A = [1 2 3; 4 5 6; 7 8 9]; 

% Perform row reduction to find the linearly independent rows
R = rref(A); % Reduced row echelon form of A

disp('Reduced Row Echelon Form (RREF) of A:');
disp(R);

% The non-zero rows of R correspond to the linearly independent rows of A
independent_rows = R(any(R, 2), :); % Rows with non-zero elements
disp('Linearly Independent Rows (Row Space):');
disp(independent_rows);
