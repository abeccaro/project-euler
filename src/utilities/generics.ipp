//
// Created by Alex Beccaro on 16/03/18.
//

#include <primes.hpp>

namespace generics {

    template<class T, class>
    std::vector<uint> digits(const T& n) {
        std::vector<uint> digits;
        T copy = n;

        if (copy < 0)
            copy *= -1;

        while (copy > 9) {
            auto d = (uint) (copy % 10);
            digits.push_back(d);
            copy /= 10;
        }
        digits.push_back((uint) copy);

        reverse(digits.begin(), digits.end());
        return digits;
    }

    template<class T, class>
    T from_digits(const std::vector<uint>& digits) {
        assert(all_of(digits.begin(), digits.end(), [](uint n){return n < 10;}) &&
               "At least a non digit number (> 10)");

        T result = 0;
        ulong length = digits.size();

        for (ulong i = 0; i < length; i++)
            result += digits[length - i - 1] * pow(10, i);

        return result;
    }

    template<class T, class>
    bool is_palindrome(const T& n) {
        std::vector<uint> dig = digits(n);
        std::vector<uint> reversed_dig(dig.size());

        reverse_copy(dig.begin(), dig.end(), reversed_dig.begin());

        return dig == reversed_dig;
    }

    template<class T, class>
    T gcd(const T& a, const T& b) {
        assert (a >= 0 && b >= 0 && "Numbers can't be negative");

        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

    template<class T, class>
    T gcd(const std::vector<T>& numbers) {
        assert (numbers.size() > 0 && "At least one number is required");

        T partial_gcd = numbers[0];

        for (auto i = numbers.begin() + 1; i < numbers.end(); i++)
            partial_gcd = gcd(partial_gcd, *i);

        return partial_gcd;
    }

    template<class T, class>
    T lcm(const T& a, const T& b) {
        return (a * b) / gcd(a, b);
    }

    template<class T, class>
    T lcm(const std::vector<T>& numbers) {
        assert (numbers.size() > 0 && "At least one number is required");

        T partial_lcm = numbers[0];

        for (auto i = numbers.begin() + 1; i < numbers.end(); i++)
            partial_lcm = lcm(partial_lcm, *i);

        return partial_lcm;
    }

    template<class T, class>
    std::vector<T> divisors(const T& n) {
        assert (n > 0 && "Numbers must be positive");

        std::vector<T> divisors;
        auto root = sqrt(n);

        for (T i = 1; i < root; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                divisors.push_back(n / i);
            }
        }

        if (root == (T) root)
            divisors.push_back((T) root);

        return divisors;
    }

    template<class T, class>
    T factorial(const T& n) {
        assert(n >= 0 && "Number can't be negative");

        T result = 1;
        for (T i = 2; i <= n; i++)
            result *= i;
        return result;
    }

    template<class T, class>
    T binomial_coefficient(const T& n, const T& k) {
        assert(n >= 0 && k >= 0 && "Numbers must be positive");
        assert(n >= k && "Invalid arguments values");

        T num = 1;

        for (T i = n; i > n - k; i--)
            num *= i;

        T den = factorial(k);

        return num / den; // safe integer division, result is always integer
    }

    template<class T, class>
    bool are_coprime(const T& a, const T& b) {
        return gcd(a,b) == 1;
    }

    template<class T, class>
    T multiplicative_order(const T& base, const T& mod) {
        assert(mod > 1 && "Modulo must be greater than 1");
        assert(are_coprime(base, mod) && "Multiplicative order is not defined for given values");

        ulong exp = 1;
        while ((T) pow(base, exp) % mod != 1)
            exp++;

        return exp;
    }

    template<class T, class>
    std::vector<T> rotations(const T& n) {
        std::vector<uint> digs = digits(n);
        ulong length = digs.size();

        std::vector<T> result(length);
        result[0] = n;

        for (ulong i = 1; i < length; i++) {
            std::vector<uint> ds(length);

            copy(digs.begin() + i, digs.end(), ds.begin());
            ulong copied = length - i;
            copy(digs.begin(), digs.begin() + i, ds.begin() + copied);

            result[i] = from_digits<T>(ds);
        }

        return result;
    }

    template<class T, class>
    std::vector<uint> to_base(const T& n, uint base) {
        assert (base > 0 && "Base must be positive");

        std::vector<uint> digits;
        T copy = n;

        while (copy > 0) {
            digits.push_back(copy % base);
            copy = copy / base;
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }

    template<class T, class>
    T from_base(const T& n, uint base) {
        assert (base > 0 && "Base must be positive");

        T result = 0;
        std::vector<uint> digs = digits(n);
        ulong size = digs.size();

        for (ulong i = 0; i < size; i++)
            result += digs[size-i-1] * pow(base, i);

        return result;
    }

    template<class T, class>
    std::vector<uint> to_base(const T& n, uint from, uint to) {
        // FIXME: not correct? Test!
        from_base(from_digits<T>(to_base(n, 2)), 2);
    }

    template<class T, class>
    T abs(const T& n) {
        return n < 0 ? 0 - n : n;
    }

    template<class T, class>
    T totient(const T& n) {
        std::vector<T> p = primes::prime_factors<T>(n);

        T num = 1;
        T den = 1;
        for (const auto& prime : p) {
            num *= prime - 1;
            den *= prime;
        }

        return n * num / den;
    }

    template<class T>
    std::vector<std::vector<T>> combinations(const std::vector<T>& elements, ulong k) {
        std::vector<std::vector<T>> combs;
        ulong n = elements.size();

        std::string bitmask(k, 1); // k leading 1s
        bitmask.resize(n, 0); // n-k trailing 0s

        // for each bitmask obtained through permutations of k 1s and n-k 0s choose the elements where there's a 1 in
        // the bitmask and skip the others
        do {
            std::vector<T> comb(k);
            uint j = 0;

            for (uint i = 0; i < n; ++i)
                if (bitmask[i])
                    comb[j++] = elements[i];

            combs.push_back(comb);
        } while (std::prev_permutation(bitmask.begin(), bitmask.end()));

        return combs;
    }

    template<class T, class>
    T mod_pow(T base, T exponent, const T& modulo) {
        base %= modulo;
        T result = 1;

        while (exponent > 0) {
            if (exponent % 2 == 1)
                result = (result * base) % modulo;
            base = (base * base) % modulo;
            exponent /= 2;
        }

        return result;
    }

}