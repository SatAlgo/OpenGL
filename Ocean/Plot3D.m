t = 0:0.001:6*pi;
x = sqrt(t).*sin(2.*t);
y = sqrt(t).*cos(2.*t);
z= t/2;
subplot(2,2,1)
plot3(x,y,z,"r")
xlabel("X axis")
ylabel("Y axis")
zlabel("Z axis")
title("3D line plot")

x = -4:0.1:4;
y = -4:0.1:4;
[x1,y1]=meshgrid(x,y)
z = (x1.^2 + (3.*y1.^2)).*exp(1-x1.^2-y1.^2);
subplot(2,2,2)
mesh(x1,y1,z)
xlabel("x-axis")
ylabel("y-axis")
zlabel("z-axis")
title("MESHPLOT")

x = -6:0.3:6;
y = -6:0.3:6;
[x1 y1] = meshgrid(x,y);
z = sin(sqrt(x1.^2 + y1.^2))./(sqrt(x1.^2 + y1.^2));
subplot(2,2,3)
surf(x1,y1,z)
xlabel("x-axis")
ylabel("y-axis")
zlabel("z-axis")
title("SURFPLOT")

t = 1:0.001:6*pi;
x =( 2./t).*sin(2.*t);
y = (2./t).*cos(2.*t);
z = t./2;
subplot(2,2,4)
plot3(x,y,z,"r")
xlabel("x-axis")
ylabel("y-axis")
zlabel("z-axis")
title("3DPLOT")