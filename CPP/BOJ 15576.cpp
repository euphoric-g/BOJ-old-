#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <algorithm>

#define FASTIO
// #define DEBUG

const double PI = acos(-1);
typedef std::complex<double> cpx;

void FFT(std::vector<cpx> &vec, cpx w) {
    int n = vec.size();
    if(n == 1) return;
    // 크기가 1이면 통과
    // 그 이상이면 even, odd로 분리
    std::vector<cpx> even, odd;
    for(int i=0; i<n; i++) {
        (i%2 ? odd : even).push_back(vec[i]);
    }
    // even과 odd를 재귀적으로 FFT 처리
    FFT(even, w*w);
    FFT(odd, w*w);
    // FFT 처리 완료 후 계산
    cpx wp(1, 0);
    for(int i=0; i<n/2; i++) {
        vec[i] = even[i] + wp*odd[i];
        vec[i+n/2] = even[i] - wp*odd[i];
        wp *= w;
    }
}

std::vector<int> poly_mul(std::vector<cpx> &a, std::vector<cpx> &b) {
    std::vector<cpx> ret;
    int n = 1;
    int big = std::max(a.size(), b.size());
    while(n < big) n *= 2;
    n*= 2;
    a.resize(n), b.resize(n);
    // 두 다항식 a, b를 두 다항식의 크기보다 큰 최소의 2의 거듭제곱으로 늘려준 뒤 FFT를 통해 곱한다.
    cpx w(cos(2*PI/n), sin(2*PI/n));
    // 기본 각 w 설정 : 길이가 1이고 re축과 이루는 각이 360/n도
    FFT(a, w);
    FFT(b, w);
    for(int i=0; i<n; i++) {
        ret.push_back(a[i] * b[i]);
    }
    // a, b에 포함된 복소수를 곱한 값이 다항식의 DFT값이 된다. (복소수 형태)
    // 역변환을 통해 DFT로부터 다항식 형태로 복원한다.
    FFT(ret, cpx(1,0)/w);
    // 기본 각 설정 : 길이가 1이고 re축과 이루는 각이 -360/n도(w와 반대방향)
    std::vector<int> ans;
    for(int i=0; i<n; i++) {
        ret[i] /= cpx(n, 0);
        ret[i] = cpx(round(ret[i].real()), round(ret[i].imag()));
        ans.push_back(ret[i].real());
    }
    return ans;
}

int main() {
    #ifdef FASTIO
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    #endif
    std::string s1, s2;
    std::cin >> s1 >> s2;
    if(s1 == "0" || s2 == "0") {
        std::cout << 0 << '\n';
        return 0;
    }
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    std::vector<cpx> a, b;
    for(const auto &ch : s1) a.push_back(cpx(ch - '0', 0));
    for(const auto &ch : s2) b.push_back(cpx(ch - '0', 0));
    auto ret = poly_mul(a, b);
    #ifdef DEBUG
    std::cout << "A = ";
    for(const auto &item : a) {
        std::cout << item << ' ';
    }
    std::cout << "\nB = ";
    for(const auto &item : b) {
        std::cout << item << ' ';
    }
    std::cout << "\nANS = ";
    for(const auto &item : ret) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
    #endif
    for(int i=0; i<ret.size(); i++) {
        if(ret[i] >= 10) {
            ret[i+1] += ret[i] / 10;
            ret[i] %= 10;
        }
    }
    while(ret.back() == 0) ret.pop_back();
    std::reverse(ret.begin(), ret.end());
    for(const auto &item : ret) {
        std::cout << item;
    }
    std::cout << '\n';
}