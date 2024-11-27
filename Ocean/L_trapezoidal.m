function [I] = method1(X, Y)
    %METHOD1 trapezoidal, trapz is inbuilt function
    %   Detailed explanation goes here
    
    elementCount = length(X);
    intervals = elementCount - 1;
    interval = X(2) - X(1);

    A = 0; % stores others' sum

    for i = 2:intervals
        A = A + Y(i);
    end
    
    I = (interval/2) * (Y(1) + Y(elementCount) + 2*A);
end
