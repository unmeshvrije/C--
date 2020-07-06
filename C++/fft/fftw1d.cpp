#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <complex.h>
#include <fftw3.h>
using namespace std;


int main(int argc, char* argv[]) {
    
    // http://fftw.org/fftw3_doc/One_002dDimensional-DFTs-of-Real-Data.html#One_002dDimensional-DFTs-of-Real-Data
    int N = 6;
    // real array would actually have 2*(n/2+1) elements
    double in[] = {1,2,3,4,5,6,0,0};

    fftw_complex *out;
    fftw_plan p;

    out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * (N/2 + 1));
    p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
    fftw_execute(p);
    int i;
    for (i = 0; i < N/2+1 ; ++i) {
        cout << out[i][0] << ", " << out[i][1] << endl;;
    }
    for (; i< N; ++i) {
        cout << out[N-i][0] << ", "<< out[N-i][1]*-1 << endl;
    }

    fftw_destroy_plan(p);
    fftw_free(out);
    return 0;
}
