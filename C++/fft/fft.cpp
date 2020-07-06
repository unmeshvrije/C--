#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include "myfft.h"
#include <complex.h>
#include <fftw3.h>
using namespace std;

void fft(std::vector<unmesh::Complex> &in, std::vector<unmesh::Complex> & out) {

    int n = in.size();
    for (int k = 0; k < n ; ++k){

        double realSum = 0.0;
        double imagSum = 0.0;
        for (int t = 0; t < n; ++t) {
            double angle = 2 * M_PI * t * k / n;
            double real = in[t].real * std::cos(angle) + in[t].imag * std::sin(angle);
            double imag = in[t].imag * std::cos(angle) - in[t].real * std::sin(angle);
            realSum += real;
            imagSum += imag;
        }
        out[k].real = realSum;
        out[k].imag = imagSum;
    }
}

void ifft(std::vector<unmesh::Complex> &in, std::vector<unmesh::Complex> & out) {

    /*
     * 1. Take Complex conjugate of the input array , call it x'
     * 2. Take fft(x') 
     * 3. Take Complext conjugate of fft(x')
     * 4. Divide it by N
     */
    for (int i = 0; i < in.size(); ++i) {
        in[i] = ~in[i];
    }

    fft(in, out);

    int n = out.size();
    for (int i = 0; i < out.size(); ++i) {
        out[i] = ~out[i];
        out[i] = out[i] / n;
    }
}

void ccorr(std::vector<unmesh::Complex>& a, std::vector<unmesh::Complex>& b, std::vector<double>& out) {
    /** Python code
    def ccorr(a,b):
        ifft(np.conj(fft(a)) * fft(b)).real
    */
    assert(a.size() == b.size());
    int n = a.size();

    // 1. Calculate FFT of vector a
    vector<unmesh::Complex> aOut(n);
    fft(a, aOut);

    // 2. Calculate FFT of vector b
    vector<unmesh::Complex> bOut(n);
    fft(b, bOut);

    // 3. Calculate complex conjugate of FFT(a)
    for (int i = 0; i < n; ++i) {
        aOut[i] = ~aOut[i];
    }

    // 4. Do complex multiplication of aOut and FFT(b)
    vector<unmesh::Complex> cOut(n);
    for (int i = 0; i < n; ++i) {
        cOut[i] = aOut[i] * bOut[i];
    }

    // 5. Take inverse FFT of the result
    vector<unmesh::Complex> inverseFFT(n);
    ifft(cOut, inverseFFT);

    // Copy the output in the output vector
    for (auto c : inverseFFT) {
        out.push_back(c.real);
    }
}

void ccorr(double* a, double* b, uint16_t size, vector<double>& out) {
    vector<unmesh::Complex> ac;
    for (int i = 0; i < size; ++i) {
        unmesh::Complex temp;
        temp.real = a[i];
        ac.push_back(temp);
    }

    vector<unmesh::Complex> bc;
    for (int i = 0; i < size; ++i) {
        unmesh::Complex temp;
        temp.real = b[i];
        bc.push_back(temp);
    }

    ccorr(ac, bc, out);
}

void cconv(std::vector<unmesh::Complex>& a, std::vector<unmesh::Complex>& b, std::vector<double>& out) {
    /** Python code
    def ccov(a,b):
        ifft(fft(a) * fft(b)).real
    */
    assert(a.size() == b.size());
    int n = a.size();

    // 1. Calculate FFT of vector a
    vector<unmesh::Complex> aOut(n);
    fft(a, aOut);

    // 2. Calculate FFT of vector b
    vector<unmesh::Complex> bOut(n);
    fft(b, bOut);

    // 3. Do complex multiplication of aOut and FFT(b)
    std::vector<unmesh::Complex> cOut(n);
    for (int i = 0; i < n; ++i) {
        cOut[i] = aOut[i] * bOut[i];
    }

    // 4. Take inverse FFT of the result
    vector<unmesh::Complex> inverseFFT(n);
    ifft(cOut, inverseFFT);

    // Copy the output in the output vector
    for (auto c : inverseFFT) {
        out.push_back(c.real);
    }
}

int main(int argc, char* argv[]) {
    
    /*unmesh::Complex c1(1, 1);
    unmesh::Complex c2(2, 2);
    unmesh::Complex c3(88, 6.5);
    unmesh::Complex c4(23, 45);

    std::vector<unmesh::Complex> test;
    test.push_back(c1);
    test.push_back(c2);
    test.push_back(c3);
    test.push_back(c4);

    vector<unmesh::Complex> out(test.size());

    fft(test, out);

    for (auto o : out) {
        std::cout << o.real << "." << o.imag << "j" << std::endl;
    }

    std::cout << "********************" << std::endl;
    vector<unmesh::Complex> rev(test.size());
    ifft(test, rev);
    for (auto o : rev) {
        std::cout << o.real << "(" << o.imag << "j)" << std::endl;
    }

    std::cout << "********************" << std::endl;
    unmesh::Complex a1(14, 0);
    unmesh::Complex a2(3.6, 0);
    unmesh::Complex a3(89.7, 0);
    unmesh::Complex a4(512, 0);
    vector<unmesh::Complex> a;
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3);
    a.push_back(a4);

    unmesh::Complex b1(78, 0);
    unmesh::Complex b2(798, 0);
    unmesh::Complex b3(7.12, 0);
    unmesh::Complex b4(56.3, 0);
    vector<unmesh::Complex> b;
    b.push_back(b1);
    b.push_back(b2);
    b.push_back(b3);
    b.push_back(b4);

    vector<double> out1;

    ccorr(a, b, out1);
    for (auto o : out1) {
        //std::cout << o.real << "(" << o.imag << "j)" << std::endl;
        std::cout << o << std::endl;
    }
    std::cout << "********************" << std::endl;

    vector<double> out2;
    cconv(a, b, out2);
    for (auto o : out2) {
        //std::cout << o.real << "(" << o.imag << "j)" << std::endl;
        std::cout << o << std::endl;
    }*/

    int N = 10;
    double in[] = {1,2,3,4,5,6,0,0,0,0};

    double in2[][2] = {{1,2}, {3,4}, {5,6}};
    /*double *mat [N];
    for (int i = 0; i < N; ++i) {
        mat[i] = new double[2];
        for (int j = 0; j < 2; ++j) {
            mat[i][j] = i+j+1; //complex<double>(i+1, j+1);
        }
    }*/
    fftw_complex *out3;
    fftw_complex *out4;
    fftw_plan p;

    //out3 = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * (N/2 + 1));
    out3 = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * (2)); // no * n1 = 6 = 10/2 + 1

    //p = fftw_plan_dft_r2c_2d(3, 2, in, out3, FFTW_ESTIMATE);
    for (int i = 0; i < 3; ++i){
        p = fftw_plan_dft_r2c_1d(2, in2[i], out3, FFTW_ESTIMATE);
        fftw_execute(p);

        for (int i = 0; i < 2 ; ++i) {
            cout << out3[i][0] << ", " << out3[i][1] << endl;
        }
        fftw_destroy_plan(p);
    }

    cout << endl;
    out4 = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * (N/2 + 1));
    p = fftw_plan_dft_r2c_1d(N/2+1 , in, out4, FFTW_ESTIMATE);
    fftw_execute(p);
    for (int i = 0; i < N/2+1 ; ++i) {
        cout << out4[i][0] << ", " << out4[i][1] << endl;;
    }
    fftw_destroy_plan(p);


    fftw_free(out3);
    fftw_free(out4);

    return 0;
}
