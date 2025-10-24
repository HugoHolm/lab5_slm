# Small Languague Model
The src folder contains the following files. 

* KGram.h
* KGram.cpp // Class for reading and training on input text.
* TextGenerator.h
* TextGenerator.cpp // Class for generating probability-based output based on the training data. 
* main.cpp // Handles the command line arguments, using the classes above to generate output. 
* Makefile // User friendly file for compiling all the files in to an executable. 

## Building the model
While in the folder, run "make" in the terminal to compile main.cpp and create the executable "slm", which is the small languague model.

## Using the model
If a user then wants to run SLM, three (optionally four) arguments must be submitted along with ./slm: 

* The length of the KGram k. 
* The path to the textfile you want to train with.
* The length of the output text.
* (Optionally a starting seed. The starting seed is a string which must have the same length as k. 
If a starting seed is not input, the first k characters will act as the starting seed.)

Example: You have a textfile called "mytextfile.txt" and you want KGram length of k = 3. You want the output to be 10 characters long. 
For completeness, we also want a starting seed, although not necessary. Let's use "the", since it is likely to appear in text.
In the terminal, this should look like:

./slm 3 ~/path_to/mytextfile.txt 10 the


