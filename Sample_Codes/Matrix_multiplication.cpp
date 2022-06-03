#include<iostream>
using namespace std;
class multiplymatrix
{
int a[10][10], b[10][10], result[10][10], r1, c1, r2, c2;
public:
void getdata()
{
   int i,j;
   cout<<"Enter rows and column for first matrix:"<<endl;
   cin>>r1>>c1;
   cout<<"Enter rows and column for second matrix:"<<endl;
   cin>>r2>>c2;
   // Column of first matrix should be equal to column of second matrix and
    while (c1 != r2)
    {
        cout<<"Error! No. of columns of first matrix not equal to no.of row of second."<<"\n\n";
        cout<<"Enter rows and column for first matrix:";
        cin>>r1>>c1;
        cout<<"Enter rows and column for second matrix:"<<endl;
        cin>>r2>>c2;
    }

    // Storing elements of first matrix.
    cout<<"\nEnter elements of matrix 1:\n";
    for(i=0; i<r1; ++i)
    {
        for(j=0; j<c1; ++j)
        {
            cin>>a[i][j];
        }
    }

    // Storing elements of second matrix.
    cout<<"\nEnter elements of matrix 2:\n";
    for(i=0; i<r2; ++i)
    {
        for(j=0; j<c2; ++j)
        {
            cin>>b[i][j];
        }
    }

}
void multiply_operation()
{
    int i,j,k;
// Initializing all elements of result matrix to 0
    for(i=0; i<r1; ++i)
    {
        for(j=0; j<c2; ++j)
        {
            result[i][j] = 0;
        }
    }
    // Multiplying matrices a and b and
    // storing result in result matrix
    for(i=0; i<r1; ++i)
    {
        for(j=0; j<c2; ++j)
        {
            for(k=0; k<c1; ++k)
            {
                result[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}
    void show()
    {
        int i,j;
    // Displaying the result
    cout<<"\nOutput Matrix:\n";
    for(i=0; i<r1; ++i)
    {
        for(j=0; j<c2; ++j)
        {
            cout<<result[i][j]<<" ";
        }
                cout<<"\n\n";
    }

}
};
int main()
{
    multiplymatrix obj1;
    obj1.getdata();
    obj1.multiply_operation();
    obj1.show();
}
