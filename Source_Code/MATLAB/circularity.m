%circularity:

rmax = zeros(12,2);
theta1 = (0:11)*pi/6;
theta2 = (1:12)*pi/6;


for i=1:n
    
    region = 0;
    
    for j =  1:12
        if theta1(j) <= pos(i,5) && pos(i,5) <= theta2(j)
            region = j;
        end
    end
    
    if region > 0
        if pos(i,4) > rmax(region,1)
            rmax(region,1) = pos(i,4);
            rmax(region,2) = i;
        end
    end
end

dist = 0;

for i = 1:11
    ind1 = rmax(i,2);
    ind2 = rmax(i+1,2);
    dist = dist + sqrt( (pos(ind2,1) - pos(ind1,1))^2 + (pos(ind2,2) -pos(ind1,2))^2 );
end

ind1 = rmax(12,2);
ind2 = rmax(1,2);
dist = dist + sqrt( (pos(ind2,1) - pos(ind1,1))^2 + (pos(ind2,2) -pos(ind1,2))^2 );
    
ind = rmax(:,2);

area = polyarea(pos(ind,1),pos(ind,2));

circle = 0.977046801922590; 
c_larity = 4*pi*area/dist^2/circle;

fprintf('\nCircularity is: %f\n\n', c_larity);