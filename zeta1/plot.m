clear all;
close all;
clc;

n = fopen('data.txt');
n =n (2:length(n));

data = fopen('data.txt');
err = data(:,1);
tid = data(:,2);

figure
plot(n, err);
xlabel('n iterations');
ylabel('error of method');


figure
plot(n, tid);
xlabel('n iterations');
ylabel('time required');
