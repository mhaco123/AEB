 clc; clear all;close all;
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ls01_60=[61.5	61.48	61.53	61.48	61.5	61.44	61.52	61.54	61.51	61.5	61.52	61.53	61.53	61.5	61	61.49	61.49	61.52	61.52	61.55	61.49	61.43	61.43	61.5	61.53	61.43	61.46	61.5	61.51	61.52	61.44	61.57	61.48	61.51	61.48];
srf_60=[57	57	57	57	57	57	57	57	57	57	57	57	57	57	56	58	56	56	56	56	58	58	58	60	58	58	58	57	58	58	57	57	57	57	57]+3;
var_l_60=var(ls01_60);
var_u_60=var(srf_60);

f_60_AA=((1/2)*ls01_60)+((1/2)*srf_60);
err_f_60_AA=60-f_60_AA;
MaPe_f_60_AA=mae((err_f_60_AA)/60)*100
VaPe_f_60_AA=var((err_f_60_AA)/60)*100

f_60_WEWA=(inv(var_l_60 + var_u_60))*[(var_l_60.*(srf_60))+(var_u_60.*(ls01_60))];
err_f_60_WEWA=60-f_60_WEWA;

MaPe_f_60_WEWA=mae((err_f_60_WEWA)/60)*100
VaPe_f_60_WEWA=var((err_f_60_WEWA)/60)*100

f_60_EWA=(inv(var_l_60 + var_u_60))*[(var_l_60.*(srf_60))+(var_u_60.*(ls01_60))];
err_f_60_EWA=60-f_60_EWA;
MaPe_f_60_EWA=mae((err_f_60_EWA)/60)*100
VaPe_f_60_EWA=var((err_f_60_EWA)/60)*100

f_60_CLT=(inv(var_l_60 + var_u_60))*[(var_l_60.*(ls01_60))+(var_u_60.*(srf_60))];
err_f_60_CLT=60-f_60_CLT;
MaPe_f_60_CLT=mae((err_f_60_CLT)/60)*100
VaPe_f_60_CLT=var((err_f_60_CLT)/60)*100

f_60_OWA=((200/211)*ls01_60)+((11/211)*srf_60);
err_f_60_OWA=60-f_60_OWA;
MaPe_f_60_OWA=mae((err_f_60_OWA)/60)*100
VaPe_f_60_OWA=var((err_f_60_OWA)/60)*100

err_srf_60=60-srf_60;err_ls01_60=60-ls01_60;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ir_100=[102.11	101.97	101.97	101.79	101.84	101.57	101.57	101.88	101.88	101.84	101.93	101.08	101.75	101.97	101.75	101.97	101.88	101.97	102.06	101.88	101.75	101.84	101.93	101.08	101.61	101.66	101.84	101.88	101.88	101.84	101.13	101.44	102.02	101.75	102.02];
ls01_100=[102.29	102.29	102	102.34	102.33	102.34	102.31	102.32	102.25	102.36	102.38	102.32	102.36	102.37	102.37	102.28	102.33	102	102.37	102.4	102.35	102.3	102.33	102.34	102.31	102.38	102.35	102.29	102.29	102.27	102.31	102.36	102.32	102.3	102.3];
srf_100=[95	96	95	94	93	95	96	94	93	93	95	95	95	95	97	95	94	93	95	95	95	94	94	95	99	93	95	95	95	94	95	94	95	97	97];
var_l_100=var(ls01_100);
var_u_100=var(srf_100);
var_i_100=var(ir_100);

f_100_AA=((1/3)*ls01_100)+((1/3)*srf_100)+ ((1/3)*ir_100);
err_f_100_AA=100-f_100_AA;
MaPe_f_100_AA=mae((err_f_100_AA)/100)*100
VaPe_f_100_AA=var((err_f_100_AA)/100)*100

f1_100_WEWA=(inv(var_i_100 + var_u_100))*[(var_i_100.*(srf_100))+(var_u_100.*(ir_100))]; var_f1_100=var(f1_100_WEWA);
f_100_WEWA=(inv(var_l_100 + var_f1_100))*[(var_f1_100.*(ls01_100))+(var_l_100.*(f1_100_WEWA))];
err_f_100_WEWA=100-f_100_WEWA;
MaPe_f_100_WEWA=mae((err_f_100_WEWA)/100)*100
VaPe_f_100_WEWA=var((err_f_100_WEWA)/100)*100

f_100_EWA=(inv(var_i_100 + var_u_100 + var_l_100))*((var_i_100.*(ls01_100))+(var_u_100.*(srf_100))+(var_l_100.*(ir_100))); 
err_f_100_EWA=100-f_100_EWA;
MaPe_f_100_EWA=mae((err_f_100_EWA)/100)*100
VaPe_f_100_EWA=var((err_f_100_EWA)/100)*100

f_100_CLT=(inv(var_i_100 + var_u_100 + var_l_100))*((var_i_100.*(ir_100))+(var_u_100.*(srf_100))+(var_l_100.*(ls01_100))); 
err_f_100_CLT=100-f_100_CLT;
MaPe_f_100_CLT=mae((err_f_100_CLT)/100)*100
VaPe_f_100_CLT=var((err_f_100_CLT)/100)*100

f_100_OWA=((200/211)*ls01_100)+((10/211)*srf_100)+ ((1/211)*ir_100);
err_f_100_OWA=100-f_100_OWA;
MaPe_f_100_OWA=mae((err_f_100_OWA)/100)*100
VaPe_f_100_OWA=var((err_f_100_OWA)/100)*100


err_srf_100=100-srf_100;err_ls01_100=100-ls01_100;err_ir_100=100-ir_100;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ir_300=[299.93	297.82	302.07	293.68	302.27	293.13	293.5	297.82	293.68	298.2	298.01	302.07	302.07	293.68	298.39	298.39	293.68	294.61	297.82	297.82	292.94	298.97	302.07	293.87	302.27	293.13	297.63	296.87	297.82	292.76	298.01	298.2	298.2	298.2	290.75];
ls01_300=[302.13	302.1	302.18	303.02	302.24	303	302.92	303.02	302	303.03	303.01	302.97	303.04	303.07	302.96	303.01	303.01	303.02	302.99	303.01	302.97	303.01	302.96	303.03	302.97	303.01	303.06	303.01	303	302.98	302.97	302.96	303.03	302.95	303.01];
srf_300=[287 287 286 288 285 285 286 285 285 286	285	285	285	285	287	286	287	286	286	285	287	286	286	288	285	286	287	287	287	285	285	285	287	287	285];
var_l_300=var(ls01_300);
var_u_300=var(srf_300);
var_i_300=var(ir_300);

f_300_AA=((1/3)*ls01_300)+((1/3)*srf_300)+ ((1/3)*ir_300);
err_f_300_AA=300-f_300_AA;
MaPe_f_300_AA=mae((err_f_300_AA)/300)*100
VaPe_f_300_AA=var((err_f_300_AA)/300)*100

f1_300_WEWA=(inv(var_i_300 + var_u_300))*[(var_i_300.*(srf_300))+(var_u_300.*(ir_300))]; var_f1_300=var(f1_300_WEWA);
f_300_WEWA=(inv(var_l_300 + var_f1_300))*[(var_f1_300.*(ls01_300))+(var_l_300.*(f1_300_WEWA))];
err_f_300_WEWA=300-f_300_WEWA;
MaPe_f_300_WEWA=mae((err_f_300_WEWA)/300)*100
VaPe_f_300_WEWA=var((err_f_300_WEWA)/300)*100

f_300_EWA=(inv(var_i_300 + var_u_300 + var_l_300))*[(var_i_300.*(ls01_300))+(var_u_300.*(srf_300))+(var_l_300.*(ir_300))];
err_f_300_EWA=300-f_300_EWA;
MaPe_f_300_EWA=mae((err_f_300_EWA)/300)*100
VaPe_f_300_EWA=var((err_f_300_EWA)/300)*100

f_300_CLT=(inv(var_i_300 + var_u_300 + var_l_300))*((var_i_300.*(ir_300))+(var_u_300.*(srf_300))+(var_l_300.*(ls01_300))); 
err_f_300_CLT=300-f_300_CLT;
MaPe_f_300_CLT=mae((err_f_300_CLT)/300)*100
VaPe_f_300_CLT=var((err_f_300_CLT)/300)*100

f_300_OWA=((200/211)*ls01_300)+((10/211)*srf_300)+ ((1/211)*ir_300);
err_f_300_OWA=300-f_300_OWA;
MaPe_f_300_OWA=mae((err_f_300_OWA)/300)*100
VaPe_f_300_OWA=var((err_f_300_OWA)/300)*100

err_srf_300=300-srf_300;err_ir_300=300-ir_300;err_ls01_300=300-ls01_300;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ir_400=[408.06	406.64	414.98	398.62	407.35	407.35	399.31	398.28	406.99	407.35	398.96	400.34	393.23	391.25	405.93	398.96	398.96	397.94	408.06	398.96	391.58	399.65	390.26	406.99	398.28	391.25	398.62	391.25	406.99	398.28	391.25	398.62	391.25	406.99	397.94];
ls01_400=[402.44	402	402.42	402.41	402.45	402.37	402.36	402.37	402.4	402.29	402.45	402.37	402.45	402.35	402.34	402.39	402.35	405.35	402.34	402.4	402.39	402.37	402.31	402.43	402.34	402.33	402.35	402.33	402.34	402.35	402.38	402.39	402.35	402.4	402.33];
var_l_400=var(ls01_400);
var_i_400=var(ir_400);

f_400_AA=(((1/2)*ls01_400)+ ((1/2)*ir_400));
err_f_400_AA=400-f_400_AA;
MaPe_f_400_AA=mae((err_f_400_AA)/400)*100
VaPe_f_400_AA=var((err_f_400_AA)/400)*100

f_400_WEWA=(inv(var_i_400 + var_l_400))*[(var_i_400.*(ls01_400))+(var_l_400.*(ir_400))]; 
err_f_400_WEWA=400-f_400_WEWA;

MaPe_f_400_WEWA=mae((err_f_400_WEWA)/400)*100
VaPe_f_400_WEWA=var((err_f_400_WEWA)/400)*100

f_400_EWA=(inv(var_i_400 + var_l_400))*[(var_i_400.*(ls01_400))+(var_l_400.*(ir_400))]; 
err_f_400_EWA=400-f_400_EWA;

MaPe_f_400_EWA=mae((err_f_400_WEWA)/400)*100
VaPe_f_400_EWA=var((err_f_400_WEWA)/400)*100

f_400_CLT=(inv(var_i_400 + var_l_400))*[(var_l_400.*(ls01_400))+(var_i_400.*(ir_400))]; 
err_f_400_CLT=400-f_400_CLT;
MaPe_f_400_CLT=mae((err_f_400_CLT)/400)*100
VaPe_f_400_CLT=var((err_f_400_CLT)/400)*100

f_400_OWA=(((200/201)*ls01_400)+ ((1/201)*ir_400));
err_f_400_OWA=400-f_400_OWA;
MaPe_f_400_OWA=mae((err_f_400_OWA)/400)*100
VaPe_f_400_OWA=var((err_f_400_OWA)/400)*100

err_ir_400=400-ir_400;err_ls01_400=400-ls01_400;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% main plot 
figure(1)
Y1=[ mae(err_f_400_AA),mae(err_f_400_OWA),mae(err_f_400_EWA),mae(err_f_400_WEWA),mae(err_f_400_CLT);
    mae(err_f_300_AA),mae(err_f_300_OWA),mae(err_f_300_EWA),mae(err_f_300_WEWA),mae(err_f_300_CLT);
    mae(err_f_100_AA),mae(err_f_100_OWA),mae(err_f_100_EWA),mae(err_f_100_WEWA),mae(err_f_100_CLT);
    mae(err_f_60_AA),mae(err_f_60_OWA),mae(err_f_60_EWA) ,mae(err_f_60_WEWA) ,mae(err_f_60_CLT)];

subplot(3,2,1)
bar(Y1)
legend('AA','OWA','EWA','WEWA','CLT')
title('MAE')
Y2=[rms(err_f_400_AA),rms(err_f_400_OWA),rms(err_f_400_EWA),rms(err_f_400_WEWA),rms(err_f_400_CLT);
    rms(err_f_300_AA),rms(err_f_300_OWA),rms(err_f_300_EWA),rms(err_f_300_WEWA),rms(err_f_300_CLT);
    rms(err_f_100_AA),rms(err_f_100_OWA),rms(err_f_100_EWA),rms(err_f_100_WEWA),rms(err_f_100_CLT);
    rms(err_f_60_AA) ,rms(err_f_60_OWA) ,rms(err_f_60_EWA) ,rms(err_f_60_WEWA) ,rms(err_f_60_CLT)];
subplot(3,2,2)
bar(Y2)
legend('AA','OWA','EWA','WEWA','CLT')
title('RMS');
Y3=[MaPe_f_400_AA,MaPe_f_400_OWA,MaPe_f_400_EWA,MaPe_f_400_WEWA,MaPe_f_400_CLT;
    MaPe_f_300_AA,MaPe_f_300_OWA,MaPe_f_300_EWA,MaPe_f_300_WEWA,MaPe_f_300_CLT;
    MaPe_f_100_AA,MaPe_f_100_OWA,MaPe_f_100_EWA,MaPe_f_100_WEWA,MaPe_f_100_CLT;
    MaPe_f_60_AA ,MaPe_f_60_OWA ,MaPe_f_60_EWA ,MaPe_f_60_WEWA,MaPe_f_60_CLT ];
subplot(3,2,5)
bar(Y3)
legend('AA','OWA','EWA','WEWA','CLT')
title('MAPE(%)');

Y4=[VaPe_f_400_AA,VaPe_f_400_OWA,VaPe_f_400_EWA,VaPe_f_400_WEWA,VaPe_f_400_CLT;
    VaPe_f_300_AA,VaPe_f_300_OWA,VaPe_f_300_EWA,VaPe_f_300_WEWA,VaPe_f_300_CLT;
    VaPe_f_100_AA,VaPe_f_100_OWA,VaPe_f_100_EWA,VaPe_f_100_WEWA,VaPe_f_100_CLT;
    VaPe_f_60_AA ,VaPe_f_60_OWA ,VaPe_f_60_EWA ,VaPe_f_60_WEWA,VaPe_f_60_CLT ];
subplot(3,2,6)
bar(Y4)
legend('AA','OWA','EWA','WEWA','CLT')
title('VAPE(%)');

Y5=[sse(err_f_400_AA),sse(err_f_400_OWA),sse(err_f_400_EWA),sse(err_f_400_WEWA),sse(err_f_400_CLT);
    sse(err_f_300_AA),sse(err_f_300_OWA),sse(err_f_300_EWA),sse(err_f_300_WEWA),sse(err_f_300_CLT);
    sse(err_f_100_AA),sse(err_f_100_OWA),sse(err_f_100_EWA),sse(err_f_100_WEWA),sse(err_f_100_CLT);
    sse(err_f_60_AA),sse(err_f_60_OWA),sse(err_f_60_EWA) ,sse(err_f_60_WEWA) ,sse(err_f_60_CLT)];

subplot(3,2,3)
bar(Y5)
legend('AA','OWA','EWA','WEWA','CLT')
title('SSE')
Y6=[mse(err_f_400_AA),mse(err_f_400_OWA),mse(err_f_400_EWA),mse(err_f_400_WEWA),mse(err_f_400_CLT);
    mse(err_f_300_AA),mse(err_f_300_OWA),mse(err_f_300_EWA),mse(err_f_300_WEWA),mse(err_f_300_CLT);
    mse(err_f_100_AA),mse(err_f_100_OWA),mse(err_f_100_EWA),mse(err_f_100_WEWA),mse(err_f_100_CLT);
    mse(err_f_60_AA) ,mse(err_f_60_OWA) ,mse(err_f_60_EWA) ,mse(err_f_60_WEWA) ,mse(err_f_60_CLT)];
subplot(3,2,4)
bar(Y6)
legend('AA','OWA','EWA','WEWA','CLT')
title('MSE');
%%
figure(2)
mmae=mean(Y1)
% mmaeowa=ave(Y1,:)
subplot(3,2,1)
bar(mmae)
title('mean mae');
legend('OWA','EWA','WEWA','CLT')
mrms=mean(Y2)
subplot(3,2,2)
bar(mrms)
title('mean RMS');

mmape=mean(Y3)
subplot(3,2,5)
bar(mmape)
title('mean mape');

mvape=mean(Y4)
subplot(3,2,6)
bar(mvape)
title('mean vape');


msse=mean(Y5)
subplot(3,2,3)
bar(msse)
title('mean sse');

mmse=mean(Y6)
subplot(3,2,4)
bar(mmse)
title('mean mse');

%%
figure(3)
subplot(2,2,1)
plot(f_60_AA,'-k');
hold on;
plot(f_60_CLT,'-b');
hold on;
plot(f_60_OWA,'-g');
hold on;
plot(f_60_EWA,'-r');
hold on;
plot(f_60_WEWA,'-c');
hold off;
grid on
% legend('AA Fusion of Sensors(60cm)','CLT Fusion of Sensors(60cm)','OWA Fusion of Sensors(60cm)','EWA Fusion of Sensors (60cm)','WEWA Fusion of Sensors (60cm) ')
title('(position-60cm)')
xlabel('epoch');
ylabel('position (cm)');
% plot
subplot(2,2,2)
plot(f_100_AA,'-k');
hold on;
plot(f_100_CLT,'-b');
hold on;
plot(f_100_OWA,'-g');
hold on;
plot(f_100_EWA,'-r');
hold on;
plot(f_100_WEWA,'-c');
hold off;
grid on
% legend('AA Fusion of Sensors(100cm)','CLT Fusion of Sensors(100cm)','OWA Fusion of Sensors(100cm)','EWA Fusion of Sensors (100cm)','WEWA Fusion of Sensors (100cm) ')
title('(position-100cm)')
xlabel('epoch');
ylabel('position (cm)');
% plot
subplot(2,2,3)
plot(f_300_AA,'-k');
hold on;
plot(f_300_CLT,'-b');
hold on;
plot(f_300_OWA,'-g');
hold on;
plot(f_300_EWA,'-r');
hold on;
plot(f_300_WEWA,'-c');
hold off;
grid on
% legend('AA Fusion of Sensors(300cm)','CLT Fusion of Sensors(300cm)','OWA Fusion of Sensors(300cm)','EWA Fusion of Sensors (300cm)','WEWA Fusion of Sensors (300cm) ')
title('(position-300cm)')
xlabel('epoch');
ylabel('position (cm)');
% plot
subplot(2,2,4)
plot(f_400_AA,'-k');
hold on;
plot(f_400_CLT,'-b');
hold on;
plot(f_400_OWA,'-g');
hold on;
plot(f_400_EWA,'-r');
hold on;
plot(f_400_WEWA,'-c');
hold off;
grid on
legend('AA Fusion of Sensors','CLT Fusion of Sensors','OWA Fusion of Sensors','EWA Fusion of Sensors','WEWA Fusion of Sensors')
title('(position-400cm)')
xlabel('epoch');
ylabel('position (cm)');
%%
% plot err
figure(4)
subplot(2,2,1)
plot(abs(err_f_60_AA),'-k');
hold on;
plot(abs(err_f_60_CLT),'-r');
hold on;
plot(abs(err_f_60_OWA),'-g');
hold on;
plot(abs(err_f_60_EWA),'-b');
hold on;
plot(abs(err_f_60_WEWA),'-c');
hold off;
grid on
% legend('error of AA Fusion of Sensors(60cm)','error of CLT Fusion of Sensors(60cm)','error of OWA Fusion of Sensors(60cm)','error of EWA Fusion of Sensors (60cm)','error of WEWA Fusion of Sensors (60cm) ')
title('(error-60cm)')
xlabel('epoch');
ylabel('positioning error for 60cm (cm)');
% plot
subplot(2,2,2)
plot(abs(err_f_100_AA),'-k');
hold on;
plot(abs(err_f_100_CLT),'-r');
hold on;
plot(abs(err_f_100_OWA),'-g');
hold on;
plot(abs(err_f_100_EWA),'-b');
hold on;
plot(abs(err_f_100_WEWA),'-c');
hold off;
grid on
% legend('error of AA Fusion of Sensors(100cm)','error of CLT Fusion of Sensors(100cm)','error of OWA Fusion of Sensors(100cm)','error of EWA Fusion of Sensors (100cm)','error of WEWA Fusion of Sensors (100cm) ')
title('(error-100cm)')
xlabel('epoch');
ylabel('positioning error for 100cm (cm)');
% plot
subplot(2,2,3)
plot(abs(err_f_300_AA),'-k');
hold on;
plot(abs(err_f_300_CLT),'-r');
hold on;
plot(abs(err_f_300_OWA),'-g');
hold on;
plot(abs(err_f_300_EWA),'-b');
hold on;
plot(abs(err_f_300_WEWA),'-c');
hold off;
grid on
% legend('error of AA Fusion of Sensors(300cm)','error of CLT Fusion of Sensors(300cm)','error of OWA Fusion of Sensors(300cm)','error of EWA Fusion of Sensors (300cm)','error of WEWA Fusion of Sensors (300cm) ')
title('(error-300cm)')
xlabel('epoch');

ylabel('positioning error for 300cm (cm)');
% plot
subplot(2,2,4)
plot(abs(err_f_400_AA),'-k');
hold on;
plot(abs(err_f_400_CLT),'-r');
hold on;
plot(abs(err_f_400_OWA),'-g');
hold on;
plot(abs(err_f_400_EWA),'-b');
hold on;
plot(abs(err_f_400_WEWA),'-c');
hold off;
grid on
legend('error of AA Fusion of Sensors','error of CLT Fusion of Sensors','error of OWA Fusion of Sensors','error of EWA Fusion of Sensors ','error of WEWA Fusion of Sensors  ')
title('(error-400cm)')
xlabel('epoch');
ylabel('positioning error for 400cm (cm)');
