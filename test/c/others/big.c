#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX_DIGIT 500

//大数运算：加法
int Multiply(int *a,int *b,int *&result);

//大数运算：乘法
int Add(int *a,int *b,int *&result);

//大数运算：减法
int Sub(int *a,int *b,int *&result);

//逐位调整大数，如result为11 9 22 -3 -2调整为:1 0 3 9 -3,然后再对符号提升到最高位: 9 9 6 0 2... ... -1
//表示大数的值为-20699
void AjustEncodeArray(int *&result,unsigned int iMaxNum);

//输出大数
void PrintBigNum(int *result);

//把个位在高位的字符数组转为个位在低位(下标0)的整型数组
void CArray2revDigitArray(char *cArray,int *DigitArray,unsigned int iNum);

//大数运算：加法
int Add(int *a,int *b,int *&result)
{
   if(a==NULL || b==NULL || result==NULL)
   {
      printf("multiply:input error/n");
      return -1;
   }
   int i=0,j=0;
   //初始化result数组
   for(i=0;i<MAX_DIGIT*2;++i)
   {
      result[i]=0;
   }
   for(i=0;i<MAX_DIGIT;++i)
   {
      result[i] += (a[i]+b[i]);
   }
   AjustEncodeArray(result,MAX_DIGIT*2);
   return 0;
}

//大数运算：减法
int Sub(int *a,int *b,int *&result)
{
   if(a==NULL || b==NULL || result==NULL)
   {
      printf("multiply:input error/n");
      return -1;
   }
   int i=0,j=0;
   //初始化result数组
   for(i=0;i<MAX_DIGIT*2;++i)
   {
      result[i]=0;
   }
   for(i=0;i<MAX_DIGIT;++i)
   {
      result[i] += (a[i]-b[i]);             //result里可以为负数
   }
   AjustEncodeArray(result,MAX_DIGIT*2);
   return 0;
}

//大数乘法
int Multiply(int *a,int *b,int *&result)
{
   if(a==NULL || b==NULL || result==NULL)
   {
      printf("multiply:input error/n");
      return -1;
   }
   int i=0,j=0;
   //初始化result数组
   for(i=0;i<MAX_DIGIT*2;++i)
   {
      result[i]=0;
   }
   //a[0]为个位起算,结果的偏移位为i+j,
   //如个位*十位，则运算结果的偏移为0+1即1
   //例子:a[0]为9，b[1]为7，则result[1]加63
   for(i=0;i<MAX_DIGIT;++i)
   {
      for(j=0;j<MAX_DIGIT;++j)
      {
         result[i+j] += a[i]*b[j];
      }
   }
   AjustEncodeArray(result,MAX_DIGIT*2);
   return 0;
}


//逐位调整大数，如result为11 9 22 -3 -2调整为:1 0 3 9 -3,然后再对符号提升到最高位: 9 9 6 0 2... ... -1
//表示大数的值为-20699
void AjustEncodeArray(int *&result,unsigned int iMaxNum)
{
   int i = 0;
   unsigned int iNumFlag = 0;
   unsigned int iWeight = 0;            //有效最高位的权值
   //遍历找出有效数据的最高位的下标(正负都有可能)
   for(i=iMaxNum-1;i>=0;--i)
   {
      if(result[i]!=0)
      {
         iNumFlag=i;
         break;
      }
   }
   //从低位开始往上调整，规则：大于10的正数要进位，负数要借位
   for(i=0;i<iNumFlag;++i)
   {
      //进位
      if(result[i]>0)
      {
         result[i+1] += result[i]/10;        //十位以上都要进位
         result[i] = result[i]%10;           //调整进位后的当前位
      }
      else if(result[i]<0)
      {
         result[i+1] -= 1;        //忽略高位是否可借位，强行借位
         result[i] = 10+result[i];
      }
   }
   //若有效最高位为负数，需要对负号进行提升,就是对高位与余下低位进行一次减法
   if(result[iNumFlag]<0)
   {
      iWeight = -result[iNumFlag];
      int iMinuend[2*MAX_DIGIT]={0};
      iMinuend[iNumFlag] = iWeight;          //被减数
      result[iNumFlag] = 0;               //构造减数
      for(i=0;i<iNumFlag+1;++i)
      {
         result[i] = (iMinuend[i]-result[i]);
      }
      //调整借位
      for(i=0;i<iNumFlag;++i)
      {
         if(result[i]<0)
         {
            result[i+1] -= 1;
            result[i] = 10+result[i];
         }
      }
      result[iMaxNum-1] = -1;
   }
}

void PrintBigNum(int *result)
{
   int index = MAX_DIGIT*2-1;
   bool bNegative = false;
   //从最高位找到第一个不为负的位，从此位开始为有效值
   while(result[index]<=0)
   {
      if(result[index]<0)
      {
         bNegative = true;
      }
      index--;
   }
   if(bNegative)
   {
      printf("-");
   }
   for(int i=index;i>=0;--i)
   {
      printf("%d",result[i]);
   }
   printf("\n");
}

void CArray2revDigitArray(char *cArray,int *DigitArray,unsigned int iNum)
{
   int i = 0;
   unsigned int iLen = strlen(cArray);
   //初始化DigitArray
   for(i=0; i<iNum; ++i)
   {
      DigitArray[i] = 0;
   }
   for(i=0; i<iLen; ++i)
   {
      DigitArray[iLen-1-i] = cArray[i]-'0';
   }
}

int main()
{
   int a[MAX_DIGIT], b[MAX_DIGIT], resultArray[2*MAX_DIGIT];
   char cArray1[MAX_DIGIT], cArray2[MAX_DIGIT];
   int ret = 0;
   int *result = (int *)resultArray;
   printf("Input multiplier:\n");
   scanf("%s",cArray1);
   printf("Input multiplicand:\n");
   scanf("%s",cArray2);
   CArray2revDigitArray(cArray1,a,MAX_DIGIT);
   CArray2revDigitArray(cArray2,b,MAX_DIGIT);
   ret=Multiply(a,b,result);
   if(ret!=0)
   {
      printf("Multiply error,ret:%d\n",ret);
      return -1;
   }
   PrintBigNum(result);

   ret=Add(a,b,result);
   if(ret!=0)
   {
      printf("Multiply error,ret:%d\n",ret);
      return -1;
   }
   PrintBigNum(result);

   ret=Sub(a,b,result);
   if(ret!=0)
   {
      printf("Multiply error,ret:%d\n",ret);
      return -1;
   }
   PrintBigNum(result);
   return 0;
}


