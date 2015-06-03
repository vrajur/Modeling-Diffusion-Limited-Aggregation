%walktest

load walks.dat;

fprintf('\n');
fprintf('Average r^2: %f\n', mean(walks));
fprintf('Characteristic Length: %f\n', sqrt(mean(walks)));
fprintf('\n');