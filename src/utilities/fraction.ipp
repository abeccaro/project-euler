//
// Created by Alex Beccaro on 16/03/18.
//

#include <generics.hpp>

namespace fractions {

    template<class T, class V>
    bool fraction<T, V>::auto_red = false;

    /// region constructors

    template<class T, class V>
    fraction<T, V>::fraction() : num(0), den(1) {}

    template<class T, class V>
    fraction<T, V>::fraction(T n) : num(n), den(1) {}

    template<class T, class V>
    template<class U, class>
    fraction<T, V>::fraction(U n) : num(n), den(1) {}

    template<class T, class V>
    fraction<T, V>::fraction(T n, T d) : num(n), den(d) {
        assert(den != 0 && "Denominator can't be 0");

        if (auto_red)
            reduce();
    }

    template<class T, class V>
    template<class U, class>
    fraction<T, V>::fraction(const fraction<U>& f) : num(f.numerator()), den(f.denominator()) {}

    /// endregion

    template<class T, class V>
    void fraction<T, V>::reduce() {
        if (num < 0 && den < 0) {
            num = generics::abs(num);
            den = generics::abs(den);
        } else if (den < 0) {
            den = generics::abs(den);
            num *= -1;
        }

        T g = generics::gcd<T>(generics::abs(num), den);
        if (g != 1) {
            num /= g;
            den /= g;
        }
    }

    template<class T, class V>
    void fraction<T, V>::invert() {
        assert(num != 0 && "Can't invert 0");

        T temp = num;
        num = den;
        den = temp;
    }

    template<class T, class V>
    fraction<T, V> fraction<T, V>::inverse() const {
        assert(num != 0 && "Can't invert 0");

        return {den, num};
    }

    /// region getters and setters

    template<class T, class V>
    void fraction<T, V>::auto_reduce(bool b) {
        auto_red = b;
    }

    template<class T, class V>
    T fraction<T, V>::numerator() const {
        return num;
    }

    template<class T, class V>
    T fraction<T, V>::denominator() const {
        return den;
    }

    template<class T, class V>
    void fraction<T, V>::numerator(const T& n) {
        num = n;
        if (auto_red)
            reduce();
    }

    template<class T, class V>
    void fraction<T, V>::denominator(const T& d) {
        den = d;
        if (auto_red)
            reduce();
    }

    template<class T, class V>
    double fraction<T, V>::value() const {
        return (double) *this;
    }

    /// endregion

    /// region operators

    template<class T, class V>
    fraction<T>& fraction<T, V>::operator = (const fraction<T>& f) {
        num = f.num;
        den = f.den;
        return *this;
    }

    template<class T, class V>
    bool fraction<T, V>::operator == (fraction<T> f2) const {
        fraction f1 = *this;
        f1.reduce();
        f2.reduce();

        return f1.num == f2.num && f1.den == f2.den;
    }

    template<class T, class V>
    bool fraction<T, V>::operator != (fraction<T> f2) const {
        return !(*this == f2);
    }

    template<class T, class V>
    bool fraction<T, V>::operator < (const fraction<T>& f) const {
        return value() < f.value();
    }

    template<class T, class V>
    bool fraction<T, V>::operator <= (const fraction<T>& f) const {
        return *this == f || *this < f;
    }

    template<class T, class V>
    bool fraction<T, V>::operator > (const fraction<T>& f) const {
        return value() > f.value();
    }

    template<class T, class V>
    bool fraction<T, V>::operator >= (const fraction<T>& f) const {
        return *this == f || *this > f;
    }

    template<class T, class V>
    fraction<T> fraction<T, V>::operator + (const fraction<T>& other) const {
        T d = generics::lcm<T>(den, other.denominator());
        T n1 = d / den * num;
        T n2 = d / other.denominator() * other.numerator();
        fraction<T> res(n1 + n2, d);

        return res;
    }

    template<class T, class V>
    fraction<T>& fraction<T, V>::operator += (const fraction<T>& other) {
        T d = generics::lcm<T>(den, other.denominator());
        T n1 = d / den * num;
        T n2 = d / other.denominator() * other.numerator();

        num = n1 + n2;
        den = d;

        if (auto_red)
            reduce();

        return *this;
    }

    template<class T, class V>
    fraction<T> fraction<T, V>::operator - (const fraction<T>& other) const {
        T d = generics::lcm<T>(den, other.denominator());
        T n1 = d / den * num;
        T n2 = d / other.denominator() * other.numerator();
        fraction<T> res(n1 - n2, d);

        return res;
    }

    template<class T, class V>
    fraction<T>& fraction<T, V>::operator -= (const fraction<T>& other) {
        T d = generics::lcm<T>(den, other.denominator());
        T n1 = d / den * num;
        T n2 = d / other.denominator() * other.numerator();

        num = n1 - n2;
        den = d;

        if (auto_red)
            reduce();

        return *this;
    }

    template<class T, class V>
    fraction<T> fraction<T, V>::operator *(const fraction<T>& other) const {
        T n = num * other.numerator();
        T d = den * other.denominator();
        fraction<T> res(n, d);

        return res;
    }

    template<class T, class V>
    fraction<T>& fraction<T, V>::operator *=(const fraction<T>& other) {
        num *= other.numerator();
        den *= other.denominator();

        if (auto_red)
            reduce();

        return *this;
    }

    template<class T, class V>
    fraction<T> fraction<T, V>::operator /(fraction<T> other) const {
        assert(other != 0 && "Can't divide by 0");

        other.invert();
        return *this * other;
    }

    template<class T, class V>
    fraction<T>& fraction<T, V>::operator /=(fraction<T> other) {
        assert(other != 0 && "Can't divide by 0");

        other.invert();
        return *this *= other;
    }

    template<class T, class V>
    fraction<T> fraction<T, V>::operator -() const {
        return fraction<T>(-num, den);
    }

    /// endregion

    template<class T, class V>
    template<class U, class>
    fraction<T, V>::operator U () const {
        return (U) num / den;
    }



    template<class T>
    std::ostream& operator<<(std::ostream& os, const fraction<T>& f) {
        os << f.numerator();
        T den = f.denominator();
        if (den != 1)
            os << "/" << den;
        return os;
    }

    template<class T>
    void pow(fraction<T>& f, const T& exp) {
        f.numerator(generics::int_pow(f.numerator(), exp));
        f.denominator(generics::int_pow(f.denominator(), exp));
    }

    template<class T>
    fraction<T> max(const fraction<T>& f1, const fraction<T>& f2) {
        return f1 < f2 ? f2 : f1;
    }

    template<class T>
    fraction<T> min(const fraction<T>& f1, const fraction<T>& f2) {
        return f1 < f2 ? f1 : f2;
    }

    template<class T>
    fraction<T> abs(const fraction<T>& f) {
        return f < 0 ? -f : f;
    }

    template<class T>
    fraction<T> floor(const fraction<T>& f) {
        T x = (T) f;
        if (f == x)
            return f;
        return fraction<T>(f < 0 ? x - 1 : x);
    }

    template<class T>
    fraction<T> ceil(const fraction<T>& f) {
        T x = (T) f;
        if (f == x)
            return f;
        return fraction<T>(f < 0 ? x : x + 1);
    }

    template<class T>
    fraction<T> round(const fraction<T>& f) {
        double v = f.value();
        if (v >= 0)
            return v - (T) v < 0.5 ? floor(f) : ceil(f);
        return v - (T) v <= -0.5 ? floor(f) : ceil(f);
    }

}

namespace std {
    template <class T>
    struct hash<fractions::fraction<T>> {
        // see https://stackoverflow.com/a/34799763/5337213
        auto operator()(const fractions::fraction<T>& f) const -> size_t {
            size_t n = f.numerator();
            size_t d = f.denominator();
            auto elegant = [](size_t n, size_t d) { return n < d ? d * d + n : n * n + n + d; }; // elegant pairing function

            if (n < 0) {
                if (d < 0)
                    return 3 + 4 * elegant(-n - 1, -d - 1);
                return 2 + 4 * elegant(-n - 1, d);
            }
            if (d < 0)
                return 1 + 4 * elegant(n, -d - 1);
            return 4 * elegant(n, d);
        }
    };
}