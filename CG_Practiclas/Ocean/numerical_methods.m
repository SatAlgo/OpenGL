%% very tof

% write matlab program to find I = int(ydx, x1, xn), if the curve
% y = f(x) passess through the following points
% x - x1 x2 x3 ... xn
% y - y1 y2 y3 ... yn
% such that values of x are equally spaced [h is the space]
% for n values, we will have [n-1] intervals

% as we don't know the integrand so we use numerical methods
% for integration there are 3 methods [preference 3 > 2 > 1]

%% first method

% I = (h/2) [y1 + yn + 2(summation of remaining y values)]
% e.g., I = (h/2) [y1 + yn + 2(y2 + y3 + ... + yn-1)]




%% second method
% only applicable when no of intervals are even

% I = (h/3) [y1 + yn + 4(even positions) + 2(odd positions)]
% e.g., I = (h/3) [y1 + yn + 4(y2 + y4 + ...) + 2(y3 + y5 + ...)]


%% third method
% only applicable when no of intervals are multiple of 3

% I = (3h/8) [y1 + yn + 3(set of twos) + 2(set of third) ]
% e.g., I = (3h/8) [y1 + yn + 2(y2 + y3 + y5 + y6 + ...) + 2(y4 + y7 + ...) ]
