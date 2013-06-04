#!/usr/bin/env octave
a = double(imread(argv(){1}));
b = double(imread(argv(){2}));
imwrite(abs(a-b), 'out.png')
