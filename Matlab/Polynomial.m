% Define the polynomial P(x) = x³ - 6x² + 11x - 6

P = [1, -6, 11, -6]; % Coefficients of the polynomial

% Evaluate P(2)
x = 2;
P_value = polyval(P, x);
disp(['P(2) = ', num2str(P_value)]);

% Find the roots of the polynomial
roots_P = roots(P);
disp('Roots of the polynomial P(x):');
disp(roots_P);
