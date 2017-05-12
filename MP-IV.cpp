#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

int main(int argc,char *argv[])
{
    ifstream fin;
    char n='\0',m='\0',in;
    int i,j,k,flag1,flag2,ra,rab;

    fin.open(argv[1]);
    fin>>n>>m;

    float a[m][n+1]={0},c[m]={0},res[n]={0};
    float temp,t,sum=0;

    if(m>=n)
    {
        for(i=1;i<=m;i++)  //Taking Input in 2-D Array(Matrix) & 1-D Array
        {
            for(j=1;j<=n;j++)
            {
                fin>>a[i][j];
            }
            fin>>c[i];
        }
        fin.close();

        for(i=1;i<=m;i++)  //Creating Augmented Matrix(2-D Array)
        {
            a[i][n+1]=c[i];
        }

        for(i=1;i<=(m-1);i++)  //Creating Upper Triangular Matrix
        {
            for(j=(i+1);j<=n;j++)
            {
                temp=a[j][i]/a[i][i];

                for(k=1;k<=(n+1);k++)
                {
                    t=temp*a[i][k];
                    a[j][k]=a[j][k]-t;
                }
            }
        }

        ra=0;
        rab=0;
        for(i=1;i<=m;i++)  //Calculating rank of coefficient matrix and augmented matrix
        {
            flag1=0;
            for(j=1;j<=n;j++)
            {
                if(a[i][j]!=0)
                {
                    flag1=1;
                    break;
                }
            }
            if(flag1==1)
            {
                ra++;
            }

            flag2=0;
            for(j=1;j<=(n+1);j++)
            {
                if(a[i][j]!=0)
                {
                    flag2=1;
                    break;
                }
            }
            if(flag2==1)
            {
                rab++;
            }
        }

        if(ra==rab)  //Calculation of unknowns
        {
            //cout<<"System of Linear Equations is Consistent"<<endl;

            if(ra<n)
            {
                cout<<"Multiple Solutions";
            }
            else
            {
                //cout<<"Unique Solution:-"<<endl;
                res[n]=a[m][n+1]/a[m][n];
                in=n;
                for(i=(m-1);i>=1;i--)
                {
                    t=n;
                    sum = a[i][n+1];
                    for(j=n;j>i;j--)
                    {
                        temp=a[i][j]*res[n];
                        n--;
                        sum-=temp;
                    }
                    in--;
                    res[in]=sum/a[i][i];
                    n=t;
                }
            }
        }
        else
        {
            //cout<<"System of Linear Equations is Inconsistent"<<endl;
            cout<<"No Solution";
        }

        /*cout<<endl;
        for(i=1;i<=m;i++)  //Displaying Upper Triangular Matrix
        {
            for(j=1;j<=(n+1);j++)
            {
                cout<<a[i][j]<<"\t\t";
            }
            cout<<endl;
        }*/

        for(i=1;i<=n;i++)  //Displaying Roots of the Equations
        {
            cout<<res[i]<<" ";
        }
    }
    else
    {
        cout<<"No solution";
    }

    return (0);
}
