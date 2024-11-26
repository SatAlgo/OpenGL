x=input("Enter the xi Vlaue");
y=input("Enter the yi values");

h=x(2)-x(1);
n=length(x);

Ieven=0;
Iodd=0;


for i=2:2:(n-1)
    Ieven=Ieven+y(i);
end

for i=3:2:(n-1)
    Iodd=Iodd+y(i);
end

I=(h/3)*(y(1)+y(2)+2*Iodd+4*Ieven);
fprintf("The value is %d",I);


simpsons 1/3
