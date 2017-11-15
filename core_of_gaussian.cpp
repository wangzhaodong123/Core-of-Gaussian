#include "iostream"  
#include "math.h"  

using namespace std;    
      
//******************高斯卷积核生成函数*************************  
//第一个参数gaus是一个指向含有3个double类型数组的指针；  
//第二个参数size是高斯卷积核的尺寸大小；  
//第三个参数sigma是卷积核的标准差  
//*************************************************************  
void GetGaussianKernel(double **gaus, const int size,const double sigma);  
      
int main(int argc,char *argv[])    
{
  //定义卷积核大小和标准差
  int size=0; 
  double sigma=0.0;
  
  //用户输入值
  cout<<"请输入高斯卷积核的尺寸（奇数）："<<endl;
  cin>>size;  
  cout<<"请输入高斯卷积核的sigma："<<endl;
  cin>>sigma;
  
  //定义高斯卷积核
  double **gaus=new double *[size];  
  for(int i=0;i<size;i++)  
  {
    gaus[i]=new double[size];  //动态生成矩阵  
  }
  cout<<"尺寸 = "<<size<<"*"<<size<<"，Sigma = "<<sigma<<"，高斯卷积核参数为："<<endl;
  GetGaussianKernel(gaus,size,sigma);
  return 0;  
  }  

//******************高斯卷积核生成函数*************************  
void GetGaussianKernel(double **gaus, const int size,const double sigma)  
{
  const double PI=4.0*atan(1.0); //圆周率π赋值  
  int center=size/2;  
  double sum=0;  
  for(int i=0;i<size;i++)  
  {
    for(int j=0;j<size;j++)  
    {
      gaus[i][j]=(1/(2*PI*sigma*sigma))*exp(-((i-center)*(i-center)+(j-center)*(j-center))/(2*sigma*sigma));  
      sum+=gaus[i][j];  
    }  
  }  
      
  for(int i=0;i<size;i++)  
  {  
    for(int j=0;j<size;j++)  
    {  
      gaus[i][j]/=sum;  
      cout<<gaus[i][j]<<"  ";  
    }  
    cout<<endl<<endl;  
   }
   
   return ;  
}  