#!/bin/bash
#IFS=\&

#input=\""map=imread('\"$1\"');,map=rgb2gray(map);,bitmap=binarify(map);,dlmwrite('map.txt',bitmap),quit;"\"

#echo $input
#matlab -nosplash -nodisplay -nojvm -r $input

matlab -nosplash -nodisplay -nojvm -r "imgtomap();, quit;" #> /dev/null 2>&1

./laser_reader