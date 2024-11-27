%find poly of degree 3 for the data points , also create graph that shows
%given data pts and poly function on same set of axes.
x = [-3,-2,-1,0,1,2,3];
y = [-28,-9,-2,-1,0,7,26];
P = polyfit(x,y,3)
plot(x,y,'*') 
title("Curve Fiting")
xlabel("x-axis")
ylabel("y-axis")
hold on
X=min(x):0.1:max(x);
Y=polyval(P,X);
plot(X,Y) 

%% 
x =[-6,-4,-2,0,2,4,6];
y = [-0.2,-0.8,-1.6,3.5,3.1,4.9,3.9];
P = polyfit(x,y,6)
plot(x,y,'o')
title("curve fitting")
xlabel("x-axis")
ylabel("y-axis")
hold on
X=min(x):0.1:max(x);
Y=polyval(P,X);
plot(X,Y)


%% 
x=[2,4,6,8,10,12,14,16]
y=[4.9,8.2,13.4,22.2,36.5,60.3,99.3,163.8];
P = polyfit(x,y,7)
plot(x,y,'r o')
title("curve fitting")
xlabel("x")
ylabel("y")
hold on
X = min(x):0.1:max(x);
Y = polyval(P,X);
plot(X,Y)
hold off