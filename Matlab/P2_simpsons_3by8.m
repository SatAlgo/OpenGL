x=input("Enter the xi Vlaue");
y=input("Enter the yi values");

h=x(2)-x(1);
n=length(x);

Ieven=0;
Iodd=0;

for i=2:3:(n-1)
    Iodd=Iodd+y(i)+y(i+1);
end

for i=4:3:(n-2)
    Ieven=Ieven+y(i);
end

I=(3*h/8)*(y(1)+y(n)+3*Iodd+2*Ieven);
fprintf("The value is %d",I);

simpsons 3/8
