% Clear previous data and close existing figures
clear; clc; close all;

% Create a figure window
figure;

% --- First 2D Plot: Sine and Cosine ---
subplot(2, 2, 1); % Divide the window into a 2x2 grid, 1st plot
x = 0:0.1:10; % Range of x values
y1 = sin(x); % y = sin(x)
y2 = cos(x); % y = cos(x)
plot(x, y1, '-r', 'LineWidth', 1.5); % Plot sin(x) with red line
hold on;
plot(x, y2, '--b', 'LineWidth', 1.5); % Plot cos(x) with blue dashed line
hold off;
title('Sine and Cosine Functions');
xlabel('x-axis');
ylabel('y-axis');
legend('sin(x)', 'cos(x)');
grid on;

% --- Second 2D Plot: Parabola ---
subplot(2, 2, 4); % 2nd plot
x = -10:0.1:10; % Range of x-values for the parabola
y_parabola = x.^2; % Parabolic function y = x^2

% Plot the parabola
plot(x, y_parabola, '-b', 'LineWidth', 1.5); % Plot parabola with blue line

% Add titles, labels, and legend
title('Parabola: y = x^2');
xlabel('x-axis');
ylabel('y-axis');
legend('y = x^2');
grid on;



% --- Third Plot: 3D Surface (Mesh) ---
subplot(2, 2, 3); % 3rd plot
[x3, y3] = meshgrid(-2:0.2:2, -2:0.2:2); % Create grid for 3D surface
z3 = x3.^2 - y3.^2; % Define a hyperbolic function
mesh(x3, y3, z3); % Wireframe surface plot
title('3D Mesh Plot');
xlabel('x-axis');
ylabel('y-axis');
zlabel('z-axis');
grid on;

% --- Fourth Plot: 3D Surface (Colorful Surface) ---
subplot(2, 2, 2); % 4th plot
z4 = sin(sqrt(x3.^2 + y3.^2)); % Define another 3D function
surf(x3, y3, z4); % Colored surface plot
colorbar; % Add a color scale
title('3D Surface Plot');
xlabel('x-axis');
ylabel('y-axis');
zlabel('z-axis');
grid on;

% Adjust layout for better spacing
sgtitle('Combined 2D and 3D Plots'); % Add a super title for all plots
