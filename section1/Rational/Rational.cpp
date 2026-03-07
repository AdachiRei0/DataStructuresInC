#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>

class Rational {
    private:
        int Nume;   // Numerator
        int Deno;   // Denominator

        /// @brief 辗转相除法
        /// @param a 
        /// @param b 
        /// @return 整数a和b的最大公因数
        int gcd(int a, int b) {
            int r;
            while ((r = a % b) != 0) {
                a = b;
                b = r;
            }
            return b;
        }
        
    public:
        Rational(int Nume = 0, int Deno = 1): Nume(Nume), Deno(Deno) {
            int gcd_num = gcd(Nume, Deno);
            // 化简成最简分数，如果有负号，默认放在分子
            Nume /= gcd_num;
            Deno /= gcd_num;
            if (Deno < 0) {
                Deno *= -1;
                Nume *= -1;
            }
        }

        Rational operator+ (Rational other) {
            int new_Nume = Nume * other.Deno + Deno * other.Nume;
            int new_Deno = Deno * other.Deno;
            return Rational(new_Nume, new_Deno);
        }

        Rational operator- (Rational other) {
            int new_nume = Nume * other.Deno - Deno * other.Nume;
            int new_deno = Deno * other.Deno;
            return Rational(new_nume, new_deno);
        }

        Rational operator* (Rational other) {
            int new_nume = Nume * other.Nume;
            int new_deno = Deno * other.Deno;
            return Rational(new_nume, new_deno);
        }

        Rational operator/ (Rational other) {
            int new_nume = Nume * other.Deno;
            int new_deno = Deno * other.Nume;
            return Rational(new_nume, new_deno);
        }
         
        bool operator== (Rational other) {
            return (Nume == other.Nume) && (Deno == other.Deno);
        }

        bool operator!= (Rational other) {
            return (Nume != other.Nume) || (Deno != other.Deno);
        }

        bool operator> (Rational other) {
            Rational minus = Rational(Nume, Deno) - other;
            return minus > 0; 
        }

        bool operator>= (Rational other) {
            Rational minus = Rational(Nume, Deno) - other;
            return minus >= 0; 
        }

        bool operator< (Rational other) {
            Rational minus = Rational(Nume, Deno) - other;
            return minus < 0; 
        }

        bool operator<= (Rational other) {
            Rational minus = Rational(Nume, Deno) - other;
            return minus <= 0; 
        }
};

main() {
    // debug programs
    return 0;
}

#endif // RATIONAL_HPP