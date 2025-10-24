The src folder contains KGram.h/cpp which trains on data from the given text file. 
It contains TextGenerator.h/cpp which uses the training data to generate probability based output.

The main.cpp file tells us how to run the program. 
The folder also includes a Makefile with which a user can run "make" in the terminal, while in the folder, 
and an executable called "slm" will be created. This is the Small Languague Model (SLM), ready to be used. 

If a user then wants to run SLM, four arguments must be submitted along with ./slm: the length of the KGram k, 
the path to the textfile you want to train with, the length of the output text, (and a optionally a starting seed). 
The starting seed is a string which must have the same length as k. 
If a starting seed is not input, the first k characters will be the starting seed.

Example: You have a textfile called "mytextfile.txt" and you want KGram length of k = 3. You want the output to be 10 characters long. 
For completeness, we also want a starting seed, although not necessary. Let's use "the", since it is likely to appear in text.
In the terminal, this should look like:

./slm 3 ~/path_to/mytextfile.txt 10 the
