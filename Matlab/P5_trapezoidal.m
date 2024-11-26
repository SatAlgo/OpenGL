x=input("Enter the xi Vlaue");
y=input("Enter the yi values");

h=x(2)-x(1);
n=length(x);

I=0;

for i=2:(n-1)
    I=I+y(i);
end
I=(h/2)*(y(1)+y(n)+2*I);
fprintf("The value is %d",I);


trapezoidal
