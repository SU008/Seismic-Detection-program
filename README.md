# Seismic-Detection-program
To analyse a file of Seismic Data values and output useful info like, the Short Term power into a new file.

This is a Seismic Detection program where the a file is read in, whose first value is the number of data points, second value is the interval of the data points, and then data points are sequiecially listed.

Expantion of input file layout:

12 0.02 1 2 3 1 3 1 5 4 2 1 1 1
^1st value is the number of Seismic Data points in the file, here there are 12 data values used. 

12 0.02 1 2 3 1 3 1 5 4 2 1 1 1
   ^2nd value is the interval used during measuremnt of the Seismic Data points.  
   
12 0.02 1 2 3 1 3 1 5 4 2 1 1 1
        ^Data points (from 1 onwards is data points), the Seismic Data values listed in sequence. 
        
 
 The program will use then calcuate values for: 
    The Short Term power = X
    The Long Term power  = X
    The Ratio            = X
    The Threshold is      = X

And decide if there was an "Seismic Event" that occured depending on the threshold value that is set. For example if the threshold set is 4 and the calcuated threshold is greater than this, the program will diaplay an event occured at point X in the output file. 
