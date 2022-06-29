
#include<iostream>
using namespace std;
//define row and col with hardcored values
#define row 6
#define col 6

bool Find(int arr[][col],int m[],bool c[], int u) //Finds a vertice for set A to match with
{
  for(int i=0;i<col;i++)
  {
    if(arr[u][i] && !c[i])
    {
      c[i]=true;
      if(m[i]<0 || Find(arr,m,c,m[i])) //Recursively calls the function to backtrack and find for other combinations
      {
        m[i]=u;
        return true;
      }
    }
  }
  return false;
}

int Bipartial_Max_Cover(int arr[][col])
{
    int match[col];
    int result=0;
    bool check[col]; //Array to keep track whether the vertices in set B have been checked for respective set A vertice

    for(int i=0;i<col;i++)
    {
      match[i]=-1;
      check[i]=false;
    }

    for(int i=0;i<row;i++) //Tries to find a match for every vertice in set A
    {
      if(Find(arr,match,check,i))
        result++;
    }

    return result;
}

int main()
{
    int arr[row][col]; //row represents the number of vertices in set A and col in set B
    cout<<"Enter the adjacency matrix\n";
// To enter 6*6 values in matrix
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }
    //displays the maximum number covered through Bipartial_Max_Cover function..
    cout<<"Maximum number covered is: "<<Bipartial_Max_Cover(arr);
    return 0;
}
