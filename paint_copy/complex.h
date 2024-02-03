#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
#include <windows.h>
#include <fstream>
#include <cmath>


class Complex
{
 public :
	int num;
	float *newreal;
	float *newimag;
	float *preal;
	float *pimag;
	float **phase;
	float **norm;
	 Complex(int l)
	{
		num = sqrt(l/8);
		newreal=new float[(num+1)*(num+1)];
		newimag=new float[(num+1)*(num+1)];
		preal=newreal;
		pimag=newimag;
		
		phase= new float* [num];		
		for (int i = 0; i < num; i++)
		{phase[i] = new float[num];}
		
		norm= new float* [num];		
		for (int i = 0; i < num; i++)
		{norm[i] = new float[num];}
		
	}
	
	void getPhase()
	{
		int a,b;
		for( a=0 ; a < num; a++ )
		{
			for( b = 0 ; b < num ; b++)
			phase[a][b]= atan2( newimag[a*1250+b] , newreal[a*1250+b] );
		}
	}
	
	void outputPhase()
	{
		for (int i = 0;i<1250;i++)
		{
			for (int j = 0;j<1250;j++)
			{
				//std::cout<<phase[i][j]<<" ";
			}
	  	//std::cout<<std::endl;
		}
	}
	void toNormalize()
	{
        float pai = 3.1415926;
        int a,b;
		for( a=0 ; a < num; a++ )
		{
			for( b = 0 ; b < num ; b++)
			norm[a][b]= ( phase[a][b] + pai )/( 2*pai );
		}
	}
    
	
	
	~Complex()
	{
		delete[] newreal;
		delete[] newimag;
		
		for (int i = 0; i < num; i++)
		{delete[] phase[i]; }
		 delete[] phase;
		 
		 for (int i = 0; i < num; i++)
		{delete[] norm[i]; }
		 delete[] norm;
		 //std::cout<<"delete!"<<std::endl;
	}
};




#endif



