close all; clear;

V_rel=linspace(0,5,12);

% legend(strcat('VH=',num2str(V_h(1))),strcat('VH=',num2str(V_h(2))),strcat('VH=',num2str(V_h(3))),strcat('VH=',num2str(V_h(4))),strcat('VH=',num2str(V_h(5))))

a_f=linspace(1,5,12);
% a=linspace(0,6.5,12);

ttc=linspace(3,0,11);
for i = 1:length(V_rel)
    figure(3)
a1=3+(V_rel(i))./((2*ttc));
a2=(V_rel(i))./((2*ttc));
end 
% plot(ttc,a,'-k')
% hold on
grid on;
hold on
b1=[1.7 2.5  4  4.2  4.2  4.3  5.1    6.1    6.6  6.8 6.8];
b2=[4    4.5 6.5  6.7  6.75  6.85 7.5  7.9 8.5 9.3 9.5];
c1=[1.5 1.7  2.7  3.3   3.8  4.2  4.52 4.75 4.8  4.8 4.9];
c2=[1.5 2.1 4.3   5.5   6.7  7.5    8    8.5  9.1 9.4  9.5];
hold on
a=5+(V_rel(i))./((2*ttc));
plot(ttc,b1,':cs','LineWidth',2)
hold on
plot(ttc,a1,'.--r','LineWidth',1)
hold on
plot(ttc,a2,'.--k','LineWidth',1)
hold on
plot(ttc,b2,':gs','LineWidth',2)
hold on
% plot(ttc,c1,'--r','LineWidth',1.25)
% hold on
% plot(ttc,c2,'--b','LineWidth',2)
legend('Dec-(MinRisk)','Dec-req-Max','Dec-req-Min','Dec-(MaxRisk)')
title('Compare fuzzy method with the formula')
xlabel('Time To Collision (s)');
ylabel('Deceleration(m/s^2)');
