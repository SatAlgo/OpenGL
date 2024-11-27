function [I] = method2(X, Y)
    %METHOD2 Simpson's 1/3
    %   Detailed explanation goes here
    
    elementCount = length(X);
    intervals = elementCount - 1;
    interval = X(2) - X(1);

    E = 0; % even sum
    O = 0; % odd sum
    
    for i = 2:intervals
        if mod(i, 2) == 0
            E = E + Y(i);
        else
            O = O + Y(i);
        end
    
        I = (interval/3) * (Y(1) + Y(elementCount) + 4*E + 2*O);
    end
end
