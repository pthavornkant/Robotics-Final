function[] = imgtomap()

fprintf('Reading given map image...\n');
map = imread('givenmap.png');

map = rgb2gray(map);

bitmap = binarify(map);

fprintf('Done importing image\n');
dlmwrite('map.txt', bitmap);
