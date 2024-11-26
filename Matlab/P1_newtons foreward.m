x=input("Enter the xi values");
y=input("Enter the yi values");
X=input("Enter the value of X");

h=x(2)-x(1);
n=length(x);
d=zeros(n);

for i=1:n
    d(i,1)=y(i);
end

for j=2:n
    for i=1:n-j+1
        d(i,j)=d(i+1,j-1)-d(i,j-1);
    end
end

Y=y(1);
prod=1;
fac=1;

for i=1:n-1
    prod=prod*(X-x(i))/h;
    fac=fac*1/i;
    Y=Y+prod*fac*d(1,i+1);
end
fprintf("The interpolation value is %2f",Y);

newtons foreward
