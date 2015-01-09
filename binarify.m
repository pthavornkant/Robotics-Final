function res = binarify( image )

[rows, columns] = size(image);

for i = 1:rows
        for j = 1:columns
            if (image(i, j) > 230)
                image(i, j) = 1;
            else
                image(i, j) = 0;
            end
        end
end

res = image;