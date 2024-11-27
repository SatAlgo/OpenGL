X = input('Enter list of abscissas: ');  % Example: [2, 3, 4, 5]
Y = input('Enter list of ordinates: ');  % Example: [4, 9, 16, 25]
point = input('Enter point of approximation: ');  % Example: 2.5

n = length(X);  % Number of data points
h = X(2) - X(1);  % Step size (assuming uniform spacing)

F = zeros(n, n);  % Initialize the forward difference table
F(:, 1) = Y;  % The first column is the Y-values

% Compute the forward differences
for j = 2:n
    for i = j:n
        F(i, j) = F(i, j-1) - F(i-1, j-1);  % Forward difference formula
    end
end

% Output the forward difference table
disp('Forward Difference Table:');
disp(F);

% Calculate the interpolated value using the forward difference table
prod = 1;  % Initialize product for Newton's Forward Formula
result = F(1, 1);  % Start with the first Y-value

u = (point - X(1)) / h;  % Calculate u

% Use the forward difference table to compute the interpolated value
for i = 1:n-1
    prod = prod * (u - (i-1));  % Update product
    result = result + (prod / factorial(i)) * F(1, i+1);  % Add to the result
end

fprintf('The interpolated value at x = %.2f is: %.4f\n', point, result);
