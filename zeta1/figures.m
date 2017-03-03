clear all;
close all;
clc;

load data.txt;
load dataz.txt;

n = data(:,1);
err = dataz(:,1);
tid = dataz(:,2);

figure
plot(n, err);
xlabel('n iterations');
ylabel('error of method');


figure
plot(n, tid);
xlabel('n iterations');
ylabel('time required');
