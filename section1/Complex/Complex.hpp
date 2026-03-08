#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cassert>
#include <float.h>
using namespace std;

class Complex {
private:
    double r;   // 实部
    double i;   // 虚部
    double mod; // 模长
    double arg; // 辐角
public:
    constexpr Complex(double real = 0, double imag = 0) noexcept: r(real), i(imag), mod(DBL_MAX), arg(DBL_MAX) {} // 先用DBL_MAX占mod和arg的位置，等到第一次要用到时再计算替换掉

    constexpr Complex operator+ (const Complex other) const noexcept{
        Complex res;
        res.r = r + other.r;
        res.i = i + other.i;
        return res;
    }

    constexpr Complex operator- (const Complex other) const noexcept{
        Complex res;
        res.r = r - other.r;
        res.i = i - other.i;
        return res;
    }

    constexpr bool operator== (const Complex other) const noexcept{
        return (r == other.r) && (i == other.i);
    } 

    constexpr bool operator!= (const Complex other) const noexcept{
        return (r != other.r) || (i != other.i);
    }

    // conjugate of a Complex number 求共轭复数
    constexpr Complex cg() const noexcept{               
        Complex res(r, -i);
        return res;
    }

    constexpr Complex operator* (const Complex other) const noexcept{
        Complex res;
        res.r = r * other.r - i * other.i;
        res.i = r * other.i + i * other.r;
        return res;
    }

    // 输出实部
    constexpr double get_real () const noexcept{
        return r;
    }

    // 输出虚部
    constexpr double get_imag () const noexcept{
        return i;
    }

    // 输出模长
    constexpr double get_mod () noexcept{
        if (mod == DBL_MAX) {
            mod = sqrt(r * r + i * i);
        }
        return mod;
    }

    // 输出辐角，采用弧度制
    constexpr double get_arg () noexcept{
        if (arg == DBL_MAX) {
            arg = atan2(r, i);
        }
        return arg;
    }

    constexpr Complex operator/ (const Complex other) const noexcept{ 
        assert(other.get_real() != 0 || other.get_imag() != 0);
        Complex res;
        double res_r = r * other.r + i * other.i;
        double res_i = i * other.r - r * other.i;
        double other_mod_2 = other.r * other.r + other.i * other.i;
        return Complex(res_r/other_mod_2, res_i/other_mod_2);
    }

    // print 复数到屏幕上 
    void show () const {
        if (r == 0 || i == 0) {
            if (i == 0) {
                cout << r << endl;
            } else {
                ostringstream i_str_stream;
                i_str_stream << i;
                cout << (i == 1? "\0" : i == -1? "-" : i_str_stream.str()) << 'j' << endl;
            }
            return;
        }
        ostringstream i_str_stream;
        i_str_stream << i;
        cout << r << ((i > 0) ? "+" : "\0") << (i == 1? "\0" : i == -1? "-" : i_str_stream.str()) << 'j' << endl;
    }

    // 将复数表示为字符串输出
    string get_str () const {
        ostringstream Complex_stream;
        if (r == 0 || i == 0) {
            if (i == 0) {
                Complex_stream << r;
            } else {
                ostringstream i_str_stream;
                i_str_stream << i;
                Complex_stream << (i == 1? "\0" : i == -1? "-": i_str_stream.str()) << 'j';
            }
            return Complex_stream.str();
        }
        ostringstream i_str_stream;
        i_str_stream << i;
        Complex_stream << r << ((i > 0) ? "+" : "\0") << (i == 1? "\0" : i == -1? "-": i_str_stream.str()) << 'j';
        //return to_string(r) + ((i > 0) ? "+" : "\0") + to_string(i) + "j";
        return Complex_stream.str();
    }
};

#endif // COMPLEX_HPP