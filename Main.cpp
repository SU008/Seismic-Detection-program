#include "seismic.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>


using namespace std;



float Array[SIZEOFARRAY];
float tempArrayST[SIZEOFARRAY];
float tempArrayLT[SIZEOFARRAY];

////--------------------------------------------------------------




void main() 
{
	

	
	float TotalValues,TimeInterval; //stores how many values there are in total
	

	

   fstream file; //object of fstream class
   fstream fileoutput; //object of fstream class
   seismic E1,Event(2,4,1.5);

      Event.setDataWindowLT(6);
      Event.setDataWindowST(3);
      Event.setTresholdVlaue(1.8);
	  cout<<"\nDebug from getDataWindowST(), ST data window = "<<Event.getDataWindowST()<<endl;
	  cout<<"Debug from getDataWindowLT(), LT data window = "<<Event.getDataWindowLT()<<endl;
	  cout<<"Debug from getTresholdVlaue(), Threshold = "<<Event.getTresholdVlaue()<<endl;
	  
   file.open("SEISMIC3.txt",ios::in); // open file in read mode
   
   int i =0;//reset i to 0, after we inatilise array values to = 0
   
   if(file.is_open())
   {

	   
             while(!file.eof()) //read values into array
             {

	           file>>Array[i];
	           cout<<"\nElement - Value "<<endl;
	           cout<<"      "<<i<<" = "<<Array[i];
	            i++;
              }
			  TotalValues = Array[0];
			  TimeInterval = Array[1];

			 
			 cout<<"\nThe Total data elements      = "<<TotalValues<<endl;
			 cout<<"\nThe Time interval in seconds = "<<TimeInterval<<"s"<<endl;

              Event.askDataWindows();
			  Event.askTresholdVlaue();
			 int ST;
			 if( Event.getDataWindowLT() > Event.getDataWindowST() )//if statement to determine the first valid point to start from
			 {
				 ST = Event.getDataWindowLT();
			 }
			 else
			 {
				 ST= Event.getDataWindowST();
			 }

			int g,f;//used for the tempArray of ST and LT in the for loops
			g=0;
			f=0;

			for( int GH =0 ; GH <20; GH++)
			{

				cout<<"\n------------- "<<GH<< " = "<<Array[GH]<<endl;

			}
			
			 for (int s = ST+1  ; s<= TotalValues+1; s++  )
			 {
				tempArrayST[f] =  Event.cal_ST_Power(Array, s   );//save calculations to an array

				//--Debug code to view the values being used--
				cout<<"the step value is = "<<s<<endl;
				cout<<"Temp array ST is => "<<f<<" - "<<tempArrayST[f]<<endl;
				f++;

				cout<<"\n"<<endl;
			 }
			 
			  
		
			  //------------------------calculating LT values---------------------
			 for (int s = Event.getDataWindowLT()+1 ; s<= TotalValues+1; s++  )
			 {
				tempArrayLT[g] =  Event.cal_LT_Power(Array, s   );  //save calculations to an array

				//--Debug code to view the values being used
				cout<<"-----the step value is => "<<s<<endl;
				cout<<"-----Temp array LT is => "<<g<<" - "<<tempArrayLT[g]<<endl;
				g++;
				cout<<"\n"<<endl;
			 }			
			
			  cout<<"\n----------------------------------------------"<<endl;
				 
		      Event.displayResults(TotalValues,TimeInterval,tempArrayST,tempArrayLT);





			 fileoutput.open("OutputResults.txt",ios::out); //create file to save data to.
    
             if(!fileoutput)
              { cout<<"Error in creating file!!!"<<endl; }


				 int h;//to store where the first valid time interval is.
				 h= (Event.getDataWindowLT() +1)-2 ;
				 fileoutput<<" Short Time window used "<<Event.getDataWindowST()<<endl;
				 fileoutput<<" Long Time window used  "<<Event.getDataWindowLT()<<endl;
				 fileoutput<<" Threshold used  "<<Event.getTresholdVlaue()<<endl;

			 for(int y=0; y<(TotalValues+1)-Event.getDataWindowLT() ; y++)
			 {

				 fileoutput<<"\nThe point at "<<( h * TimeInterval)<<" seconds"<<endl;
				 fileoutput<<"The Short Term power = "<<tempArrayST[y]<<endl;
				 fileoutput<<"The Long Term power  = "<<tempArrayLT[y]<<endl;
				 fileoutput<<"The Ratio            = "<<tempArrayST[y]<<"/"<<tempArrayLT[y]<<" = "<<tempArrayST[y]/tempArrayLT[y]<<endl;
				 fileoutput<<"The Threshold is      = "<<Event.getTresholdVlaue()<<endl;
				 if(   tempArrayST[y]/tempArrayLT[y]  > Event.getTresholdVlaue() )
				 {
					 fileoutput<<"Result - Event at time "<<( h * TimeInterval)<<endl;

				 }
				 else
				 {  fileoutput<<"Result - No Event at time "<<( h * TimeInterval)<<endl; }
				h++;
	
           
            }
			 fileoutput.close();
   }
  else
   {
    cout << "Unable to open file"; 
   }
     
	  file.close();
	  cout<<"\nMain is ending "<<endl;
	  
	

}


		
