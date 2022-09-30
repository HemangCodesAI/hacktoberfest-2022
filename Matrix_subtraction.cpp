#include<iostream>
#include<vector>
using namespace std;
class matrixSubtraction{
  int m,n;
  vector<vector<long long >> matrix1,matrix2;
  public:
    matrixSubtraction(int m,int n){
        this->m=m;
        this->n=n;
        matrix1.resize(m,vector<long long>(n));
        matrix2.resize(m,vector<long long>(n));
        inputMatrix(matrix1);
        inputMatrix(matrix2);
    }
   void inputMatrix(vector<vector<long long>> &matrix){
    cout<<"Input the matrix elements \n";
    for(int i=0;i<m;i++){
      cout<<"Input "<<n<<" elements of row "<<i+1<<" :";
      for(int j=0;j<n;j++){
        cin>>matrix[i][j];
      }
    }
  }
   void subtractMatrixAndDisplay(){
      cout<<"\nFirst Matrix :\n\n";
      displayMatrix(matrix1);
      cout<<"Second Matrix  :\n\n";
      displayMatrix(matrix2);
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           matrix1[i][j]-=matrix2[i][j];
        }
      }
      cout<<"First Matrix - Second Matrix :"<<endl;
      displayMatrix(matrix1);
   }
   void displayMatrix(vector<vector<long long>> &matrix){
        for(auto & row:matrix){
          for(auto &element:row){
            cout<<element<<" ";
          }
          cout<<endl;
        }
   }
};
int main(){
  int m,n;
  cout<<"Input number of rows of the matrix : ";
  cin>>m;
  cout<<"Input number of columns of the matrix: ";
  cin>>n;
  matrixSubtraction solution(m,n);
  solution.subtractMatrixAndDisplay();
  return 0;
}