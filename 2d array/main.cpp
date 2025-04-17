#include <iostream>
using namespace std;

void multipyMatrix();
int main() {

    int arr[3][4] = {0};

    int arr2[3][4] = { {12, 23, 34, 45}, {56, 67, 78, 89}, {90, 91, 92, 93} };
    int arr2b[3][4] = { {12, 33, 34, 44}, {56, 55, 78, 89}, {55, 91, 22, 93} };
    int arrSum[3][4] = {0};

    int arr3[3][4]={0};

    cout<<"Enter 12 elements for the 2D array (3x4): "<<endl;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {

            cin>> arr [i][j];

        }

    }

    cout<<"Addition of matrices "<<endl;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout<< arr[i][j] + arr2[i][j] <<" ";
            arr3[i][j] = arr[i][j] + arr2[i][j];
        }

        cout<<endl;
    }


    for(int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            arrSum[i][j] = arr2[i][j] + arr2b[i][j];
        }
    }



    return 0;
}

void multipyMatrix(){


        int arr1[2][2] = {{1, 2}, {3, 4}};
        int arr2[2][2] = {{5, 6}, {7, 8}};

        int ansMulti[2][2] = {0};

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    ansMulti[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }

}
void multiply(){

  int mat1 [2][2] = {{1, 2}, {3, 4}};
  int mat2 [3][2] = {{5, 6}, {7, 8}, {9, 10}};
    int mat3 [2][3] = {0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

  }


// i=0, j=1, k=1