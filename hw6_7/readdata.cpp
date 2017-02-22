#include <iostream>
#include <stdio.h>
#include <fstream>
#include <rarray>
#include <rarrayio>
#include <cstring>
#include <sstream>
#include <complex>
#include <fftw3.h>
#include "filename.h"
#include <cmath>
#include <cblas.h>
#include <typeinfo>

//using  namespace std;

int main()
{
  string *name;
	name = create_filename(); 
  double *CCarray;
  CCarray = new double[32];
  
  for (int i = 1;i<=32;i++) // calculate CC for each detection file with GWprediction
  {
    char *filename;
    filename = new char[name[i].length()];
    sprintf(filename,"%s",name[i].c_str());
  
    //std::cout<<"name[1] is: "<<name[i]<<" tpye is:"<<typeid( name[1] ).name()<<std::endl;
    //std::cout<<"filename is: "<<filename<<" tpye is:"<<typeid( filename ).name()<<std::endl;
  
    //char *filename = name[1].c_str();
    std::ifstream g("GWprediction.rat",std::ifstream::in);//open GWprediction
    std::ifstream f(filename,std::ifstream::in);//open detection
    //create empty arrays
    rarray<double,1> Gtimes;
    rarray<double,1> ftimes;
    rarray<std::complex<double>,1> Gsignal;
    rarray<std::complex<double>,1> detection;
    // read in the signal;
    g >> Gtimes;
    g >> Gsignal;
    f >> ftimes;
    f >> detection;
    // signal size
    const int nG = Gsignal.size();
    const int nf = detection.size();
    // initial F-transform array
    rarray<std::complex<double>,1> Gsignalhat(nG);
    rarray<std::complex<double>,1> detectionhat(nf);
    
    // Fourier transform for signal of Gwprediction and detection
    fftw_plan G = fftw_plan_dft_1d(nG,(fftw_complex*)Gsignal.data(),(fftw_complex*)Gsignalhat.data(),FFTW_FORWARD,FFTW_ESTIMATE);
    fftw_execute(G);
    fftw_destroy_plan(G);
    
    fftw_plan F = fftw_plan_dft_1d(nf,(fftw_complex*)detection.data(),(fftw_complex*)detectionhat.data(),FFTW_FORWARD,FFTW_ESTIMATE);
    fftw_execute(F);
    fftw_destroy_plan(F);
    //std::cout<<detectionhat[1]<<"  real: "<<detectionhat[1].real()<<"  imag: "<<detectionhat[1].imag()<<std::endl;
    //std::cout<<detectionhat.size()<<"  "<<Gsignalhat.size()<<"  "<<nf<<"  "<<nG<<std::endl;
        
    double *Fd;
    Fd = new double[nf];
    double *Gw;
    Gw = new double[nG];
    
    // Calculate F and G
    for (int i=0; i<nf;i++)
      {Fd[i] = pow(detectionhat[i].real(),2.0)+pow(detectionhat[i].imag(),2.0);}
    for (int i=0;i<nG;i++)
      {Gw[i] = pow(Gsignalhat[i].real(),2.0)+pow(Gsignalhat[i].imag(),2.0);}
    
    // Calculate CC
    double FF = cblas_ddot(nG,Fd,1,Fd,1);
    double FG = cblas_ddot(nG,Fd,1,Gw,1);
    double GG = cblas_ddot(nG,Gw,1,Gw,1);
    double CC = FG/sqrt(FF*GG);
    //std::cout<<"FF: "<<FF<<" GG: "<<GG<<" FG: "<<FG<<std::endl;
    //std::cout<<"Corelation is: "<<CC<<std::endl;
    CCarray[i-1] = CC;
    
    delete[] Fd;
    delete[] Gw;
    }
    
    // output CC for 32 cases
    std::cout<<"Datasets  "<<"CC      "<<"Datasets  "<<"CC     "<<"Datasets  "<<"CC     "<<"Datasets  "<<"CC"<<std::endl;
    for (int i=0;i<32;i++){
      if (i%4==0)
      std::cout<<"   ";
      if(i+1<10)
      std::cout<<0;
      if(i!=17)
      std::cout<<i+1<<"  "<<CCarray[i]<<"     ";
      if(i==17)
      std::cout<<i+1<<"  "<<CCarray[i]<<"      ";
      if ((i+1)%4==0)
      std::cout<<" "<<std::endl;}

    std::cout<<" "<<std::endl;
   
    double **NewCCarray;
    NewCCarray = insertsort(CCarray, 32);

    //output the largest five
    std::cout<<"Finding the largest five:"<<std::endl;   
    std::cout<<"Datasets    "<<"Correlation  coefficient"<<std::endl;
    for (int i=0;i<5;i++)
    {  
      if(NewCCarray[i][1]<10)
      std::cout<<0;
      std::cout<<NewCCarray[i][1]<<"          "<<NewCCarray[i][0]<<std::endl;
    }
  return 0;
}