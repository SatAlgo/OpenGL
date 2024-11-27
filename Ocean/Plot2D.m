x=-2:0.001:4;
y=3.*x.^3-26.*x+10;
subplot(2,3,1);
plot(x,y,"r")

xlabel("X axis")
ylabel("Y axis")
title("1st Graph")
grid on;
%% 

x=-2:0.001:4;
y=9.*x.^2-26;
subplot(2,3,2);
plot(x,y,"b")
xlabel("X axis")
ylabel("Y axis")
title("2nd Graph")

%% 

x=-2:0.001:4;
y=18.*x;
subplot(2,3,3);
plot(x,y,"b")
xlabel("X axis")
ylabel("Y axis")
title("3rd Graph")
%% 

x=-2:0.001:4;
y=18;
subplot(2,3,4);
plot(x,y,"b")
xlabel("X axis")
ylabel("Y axis")
title("4th Graph")
%% 

x=-2:0.001:4;
y=3.*x.^3-26.*x+10;
subplot(2,3,6);
hold on
plot(x,y,"r")

x=-2:0.001:4;
y=9.*x.^2-26;
plot(x,y,"b")

x=-2:0.001:4;
y=18.*x;
plot(x,y,"k")

x=-2:0.001:4;
y=18;
plot(x,y,"g")

xlabel("X");
ylabel("Y");
title("5th Graph");
legend("y = 3x^3 - 26x + 10", "y' = 9x^2 - 26", "y'' = 18x", "y''' = 18");
grid on;

hold off
