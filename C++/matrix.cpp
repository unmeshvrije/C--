#include<iostream>
#include<iomanip>

using namespace std;

int main(void) {

  int m,n;
  cout << "Enter m : " << endl;
  cin >> m;
  cout << "Enter n : " << endl;
  cin >> n;

  // Pointer to something = Array of something
  int **mat = new int*[m];
  for (int i = 0; i < m; ++i) {
    mat[i] = new int[n];
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << "Enter mat[" << i << "][" << j << "]: " ; 
      cin >> mat[i][j];
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << setw(3) << mat[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < m; ++i) {
    delete [] mat[i];
  }
  delete[] mat;
  return 0;
}
