#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <complex.h>
#include <fftw3.h>
using namespace std;


int main(int argc, char* argv[]) {
    
    // http://fftw.org/fftw3_doc/One_002dDimensional-DFTs-of-Real-Data.html#One_002dDimensional-DFTs-of-Real-Data
    int N = 50;
    // real array would actually have 2*(n/2+1) elements
    double in[] = {1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,1,2,0,0};

    //fftw_complex *in;
    fftw_complex *out, *test_complex;
    fftw_plan p, p2;

    //in = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * (N));
    //for (int i = 0; i < N; ++i) {
    //    in[i][0] = i+1;
    //}
    out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * (N/2 + 1));

    test_complex = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

    p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
    fftw_execute(p);
    int i,j;
    for (i = 0, j = 0; i < N/2 + 1 ; ++i, ++j) {
        cout << out[i][0] << ", " << out[i][1] << endl;
        test_complex[j][0] = out[i][0];
        test_complex[j][1] = out[i][1];
    }
    for (; i< N; ++i, ++j) {
        cout << i << ")" << out[N-i][0] << ", "<< out[N-i][1]*-1 << endl;
        test_complex[j][0] = out[N-i][0];
        test_complex[j][1] = out[N-i][1]*-1;
    }
    
    cout << "*****" << endl;
    double *inverse = new double[8];
    p2 = fftw_plan_dft_c2r_1d(N, test_complex, inverse, FFTW_ESTIMATE);

    fftw_execute(p2);
    //for (i = 0; i < 52; ++i) {
    //    cout << inverse[i]/N << endl;
    //}

    delete[] inverse;
    fftw_free(test_complex);
    //fftw_destroy_plan(p2);
    //fftw_destroy_plan(p);
    fftw_free(out);
    return 0;
}
