%plott2
clear all

load 'pos.dat'

%hold on
close all

rad = .25;

n = size(pos(:,1));
n = n(1);
cmax = pos(n,3);
mean_rad = 0;
max_rad = 0;
last = 0;
for i = 1:n;
%     c = round(pos(i,3)/cmax*1000);
%     r = (mod(c,1000) - mod(c,100))/100;
%     g = (mod(c,100) - mod(c,10))/10;
%     b = mod(c,10);
%    [b(1) g(1) r(1)]/10
    
    c = pos(i,3)/cmax;
    
    r = 1-c;
    b = c;
    color = [r b b];
    
    rectangle('Position',[pos(i,1), pos(i,2), rad, rad], 'Curvature',[1,1],...
        'FaceColor', color  ) %, 'EdgeColor', color
    radius(i) = sqrt(pos(i,1)^2 + pos(i,2)^2);
    
    coll(i) = pos(i,3) - last;
    last = coll(i);
    
end

mean_rad = mean(radius);
max_rad = max(radius);
mean_coll = mean(coll);

fprintf('\n');

fprintf('%d Particles\n', n);
fprintf('Average Distance is: %f\n',mean_rad);
fprintf('Average Time Between Collisions: %f\n', mean_coll);
fprintf('Particle Denisty: %f\n', n/mean_rad^2);
fprintf('Max Distance: %f\n', max_rad);

circularity;



hold on
plot([pos(ind,1); pos(rmax(1,2),1)], [pos(ind,2); pos(rmax(1,2),2)], '--r')

plot(mean(rmax(:,1))*cos((1:1000)*pi/500),mean(rmax(:,1))*sin((1:1000)*pi/500), '--k')
hold off


