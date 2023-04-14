filename = 'results1.xlsx';
sheet = 1;
xlRange = 'A36:I81';

RESULT = xlsread(filename,sheet,xlRange);
MotorSpeed=RESULT(:,1);
MotorOrder=RESULT(:,2);
X_fus=RESULT(:,3);
V_rel=RESULT(:,5);
A=RESULT(:,6);
TTC=RESULT(:,7);
t=RESULT(:,8);
ETTC=RESULT(:,9);
%%
figure(1)
subplot(4,2,1)
plot(t,MotorSpeed,'LineWidth',2)
grid on;grid on;
title('MotorSpeed')
xlabel('Time (s)');
ylabel('degree');
grid on;grid on;
subplot(4,2,2)
plot(t,MotorOrder,'LineWidth',2)
title('MotorOrder')
xlabel('Time (s)');
ylabel('degree');
grid on;grid on;
subplot(4,2,3)
plot(t,X_fus,'LineWidth',2)
title('X-fus')
xlabel('Time (s)');
ylabel('X-fus(cm)');
grid on;
subplot(4,2,4)
plot(t,V_rel,'LineWidth',2)
title('V-rel')
xlabel('Time (s)');
ylabel('V_rel (m/s)');
grid on;
subplot(4,2,5)
plot(t,A,'LineWidth',2)
title('Acceleration')
xlabel('Time (s)');
ylabel('a(m/s^2)');
grid on;
subplot(4,2,6)
plot(t,TTC,'LineWidth',2)
title('Thw')
xlabel('Time (s)');
grid on;
ylabel('THW(s)');
grid on;
subplot(4,2,7)
plot(t,TTC,'LineWidth',2)
title('TTC')
xlabel('Time (s)');
grid on;
ylabel('TTC(s)');
subplot(4,2,8)
grid on;
plot(t,ETTC,'LineWidth',2)
title('ETTC')
xlabel('Time (s)');
grid on;
ylabel('ETTC(s)');
grid on;
%%
filename = 'results1.xlsx';
sheet2 = 2;
xlRange = 'A26:I35';

RESULT2 = xlsread(filename,sheet2,xlRange);
MotorSpeed2=RESULT2(:,1);
MotorOrder2=RESULT2(:,2);
X_fus2=RESULT2(:,3);
V_rel2=RESULT2(:,5);
A2=RESULT2(:,6);
TTC2=RESULT2(:,7);
t2=RESULT2(:,8);
ETTC2=RESULT2(:,9);
%%
figure(2)
subplot(4,2,1)
plot(t2,MotorSpeed2,'LineWidth',2)
grid on;grid on;
title('MotorSpeed')
xlabel('Time (s)');
ylabel('degree');
grid on;grid on;
subplot(4,2,2)
plot(t2,MotorOrder2,'LineWidth',2)
title('MotorOrder')
xlabel('Time (s)');
ylabel('degree');
grid on;grid on;
subplot(4,2,3)
plot(t2,X_fus2,'LineWidth',2)
title('X-fus')
xlabel('Time (s)');
ylabel('X-fus(cm)');
grid on;
subplot(4,2,4)
plot(t2,V_rel2,'LineWidth',2)
title('V-rel')
xlabel('Time (s)');
ylabel('V_rel (m/s)');
grid on;
subplot(4,2,5)
plot(t2,A2,'LineWidth',2)
title('Acceleration')
xlabel('Time (s)');
ylabel('a(m/s^2)');
grid on;
subplot(4,2,6)
plot(t2,TTC2,'LineWidth',2)
title('Thw')
xlabel('Time (s)');
grid on;
ylabel('THW(s)');
grid on;
subplot(4,2,7)
plot(t2,TTC2,'LineWidth',2)
title('TTC')
xlabel('Time (s)');
grid on;
ylabel('TTC(s)');
subplot(4,2,8)
grid on;
plot(t2,ETTC2,'LineWidth',2)
title('ETTC')
xlabel('Time (s)');
grid on;
ylabel('ETTC(s)');
grid on;
%%
filename = 'results1.xlsx';
sheet3 = 3;
xlRange = 'A4:I30';

RESULT3 = xlsread(filename,sheet3,xlRange);
MotorSpeed3=RESULT3(:,1);
MotorOrder3=RESULT3(:,2);
X_fus3=RESULT3(:,3);
V_rel3=RESULT3(:,5);
A3=RESULT3(:,6);
TTC3=RESULT3(:,7);
t3=RESULT3(:,8);
ETTC3=RESULT3(:,9);
%%
figure(3)
subplot(4,2,1)
plot(t3,MotorSpeed3,'LineWidth',2)
grid on;grid on;
title('MotorSpeed')
xlabel('Time (s)');
ylabel('degree');
grid on;grid on;
subplot(4,2,2)
plot(t3,MotorOrder3,'LineWidth',2)
title('MotorOrder')
xlabel('Time (s)');
ylabel('degree');
grid on;grid on;
subplot(4,2,3)
plot(t3,X_fus3,'LineWidth',2)
title('X')
xlabel('Time (s)');
ylabel('X(cm)');
grid on;
subplot(4,2,4)
plot(t3,V_rel3,'LineWidth',2)
title('V-rel')
xlabel('Time (s)');
ylabel('V_rel (m/s)');
grid on;
subplot(4,2,5)
plot(t3,A3,'LineWidth',2)
title('Acceleration')
xlabel('Time (s)');
ylabel('a(m/s^2)');
grid on;
subplot(4,2,6)
plot(t3,TTC3,'LineWidth',2)
title('Thw')
xlabel('Time (s)');
grid on;
ylabel('THW(s)');
grid on;
subplot(4,2,7)
plot(t3,TTC3,'LineWidth',2)
title('TTC')
xlabel('Time (s)');
grid on;
ylabel('TTC(s)');
subplot(4,2,8)
grid on;
plot(t3,ETTC3,'LineWidth',2)
title('ETTC')
xlabel('Time (s)');
grid on;
ylabel('ETTC(s)');
grid on;

