



#ifndef SEISMIC
#define SEISMIC 

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std; 
 #define SIZEOFARRAY 20

class seismic
{
public: 
	seismic();//constructor
	~seismic() { };//deconstructor
	seismic(int aST,  int aLT, float aTreshold);

	void askDataWindows();//ask how many measurements to use
	void askTresholdVlaue(); //ask treshold value

    void displayResults(float NumElements, float TimeInterval,float tempArrayST[], float tempArrayLT[] );


	float cal_ST_Power(float Array[], int num);
	float cal_LT_Power(float Array[], int num);

	int getDataWindowST();
	int getDataWindowLT();
	double getTresholdVlaue();

	void setDataWindowST(int aSTvalue);
	void setDataWindowLT(int aLTvalue);
	void setTresholdVlaue(double aTreshold);
private: 
	int DataWindowST;
	int DataWindowLT;
	double TresholdVlaue;




	
};






inline void seismic::displayResults(float NumElements, float TimeInterval,float tempArrayST[], float tempArrayLT[] )
{
				 int h;
				 h= (DataWindowLT +1)-2 ;//to store where the first valid time interval is.
			
	          for(int y=0 ; y<(NumElements+1)-DataWindowLT ; y++)//12-5 = 7
			 {

				 cout<<"\nThe point at "<<(  h * TimeInterval)<<endl;
				 cout<<"The Short Term power = "<<tempArrayST[y]<<endl;
				 cout<<"The Long Term power  = "<<tempArrayLT[y]<<endl;
				 cout<<"The Ratio            = "<<tempArrayST[y]<<"/"<<tempArrayLT[y]<<" = "<<(tempArrayST[y]/tempArrayLT[y])<<endl;
				 cout<<"The Threshold is      = "<<TresholdVlaue<<endl;
				 if(   tempArrayST[y]/tempArrayLT[y]   >TresholdVlaue )
				 {
					 cout<<"Result - Event at time "<<( h * TimeInterval)<<endl;

				 }
				 else  cout<<"Result - No Event at time "<<( h * TimeInterval)<<endl; 
				 h++;
				 
			}

}

inline float seismic::cal_LT_Power(float Array[], int num)
{

	float sum;
	sum = 0;
	
		 for(int i = num; i> num - DataWindowLT ; i=i -1)
	     {  
			 sum = (Array[i]*Array[i]) + sum;
		     cout<<"The LT array value = "<<Array[i]<<"| squared = "<<sum<<endl;    //--debug code
			 
		 }

   return (sum /DataWindowLT);
}





inline float seismic::cal_ST_Power(float Array[], int num)
{

	float sum;
	sum = 0;
	
	     for(int i = num; i > num - DataWindowST ; i--)
	     {  
			 sum = (Array[i]*Array[i]) + sum;
		     cout<<"The ST array value = "<<Array[i]<<"| squared = "<<sum<<endl; //--debug code
			 
		 }

   return (sum /DataWindowST);
}

inline void seismic::setDataWindowST(int aSTvalue)
{
	DataWindowST = aSTvalue;
	cout<<"Debug from setDataWindowST(), DataWindowST = "<<DataWindowST<<endl;
}

inline void seismic::setDataWindowLT(int aLTvalue)
{
	DataWindowLT = aLTvalue;
	cout<<"Debug from setDataWindowLT(), DataWindowLT = "<<DataWindowLT<<endl;
}

inline void seismic::setTresholdVlaue(double aTreshold)
{

	TresholdVlaue =aTreshold;
	cout<<"Debug from setThresholdVlaue(), TresholdVlaue = "<<TresholdVlaue<<endl;

}

inline int seismic::getDataWindowLT()
{	return DataWindowLT;
}

inline int seismic::getDataWindowST()
{	return DataWindowST;
}

inline double seismic::getTresholdVlaue()
{	return TresholdVlaue;
}


inline seismic ::seismic() // Default Constructor
{
	DataWindowST = 0;
	DataWindowLT = 0;
	TresholdVlaue = 0.0;
	cout << " Debug from default constructor" << endl;
	cout << "The Short Term Data Window = "  <<DataWindowST<< endl;
	cout << "The Long Term Data Window  = "  <<DataWindowLT<< endl;
	cout << "The Threshold value is      = "  <<TresholdVlaue<< endl;
}

inline seismic::seismic(int aST,  int aLT, float aTreshold)
{
	DataWindowST = aST;
	DataWindowLT = aLT;
	TresholdVlaue = aTreshold;

	cout << "\nDebug from Regular constructor" << endl;
	cout << "The Short Term Data Window = "  <<DataWindowST<< endl;
	cout << "The Long Term Data Window  = "  <<DataWindowLT<< endl;
	cout << "The Threshold value is      = "  <<TresholdVlaue<< endl;
}


inline void seismic::askDataWindows()
{
	cout<<"\n Enter the Data window value you would like to use for Short-Term power => ";
	cin>>DataWindowST;

	cout<<"\n Enter the Data window value you would like to use for Long-Term power => ";
	cin>>DataWindowLT;
}

inline void seismic ::askTresholdVlaue()
{
	cout<<"\n Enter The Treshold vlaue you would like to use => ";
	cin>>TresholdVlaue;
}



#endif