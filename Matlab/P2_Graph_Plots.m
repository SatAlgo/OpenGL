%Assignment 
%y=3x^3-26x+10 , -2<=x<=4 , Plot y , y’ , y’’ , y’’’ on separate set of axis
% and display in same fig window also one plot that contains all four 
% graphs on same set of axis. Divide fig window into 6 parts

x= -2:0.01:4;
y= 3.*x.^(3) - (26.*x) + 10;
y1 = 9.*x.^(2) - 26;
y2 = 18.*x ;
y3 = 18 * ones(size(x));

subplot(2,3,1)
plot(x,y,'r --')
xlabel("x value")
ylabel("y value")
title("1st graph")


subplot(2,3,2)
plot(x,y1,'b -.')
xlabel("x value")
ylabel("y1 value")
title("2nd graph")


subplot(2,3,3)
plot(x,y2,'m :')
xlabel("x value")
ylabel("y2 value")
title("3rd graph")


subplot(2,3,4)
plot(x,y3,'k -')
xlabel("x value")
ylabel("y3 value")
title("4th graph")


subplot(2,3,6)
plot(x,y,'r --')
xlabel("x value")
ylabel("y value")
title("1st graph")
hold on
plot(x,y1,'b -.')
xlabel("x value")
ylabel("y1 value")
title("2nd graph")
hold on
plot(x,y2,'m :')
xlabel("x value")
ylabel("y2 value")
title("3rd graph")
hold on
plot(x,y3,'k -')
xlabel("x value")
ylabel("y3 value")
title("Final graph")
hold off
clc
