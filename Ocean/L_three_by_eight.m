function [I] = method3(X, Y)
    %METHOD3 Simpson's 3/8
    %   Detailed explanation goes here
    
    elementCount = length(X);
    intervals = elementCount - 1;
    interval = X(2) - X(1);

    F = 0; % for sum of first two
    T = 0; % for sum of third
    
    for i = 2:intervals
    
        if mod(i-1, 3) == 0
            T = T + Y(i);
        else 
            F = F + Y(i);
        end
    end
    
    I = (3 * interval / 8) * (Y(1) + Y(elementCount) + 3*F + 2*T);
end
