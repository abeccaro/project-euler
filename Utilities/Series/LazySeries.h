//
// Created by Alex Beccaro on 13/12/17.
//

#ifndef PROJECT_EULER_LAZYSERIES_H
#define PROJECT_EULER_LAZYSERIES_H

#include <vector>
#include <functional>

using namespace std;

namespace series {
    template <class T>
    class LazySeries {
    public:
        /**
         * Virtual destructor for subclasses
         */
        virtual ~LazySeries<T>() = default;


        /**
         * Lazy series iterator class
         */
        class Iterator {
            // friend to gain access to private members
            friend class LazySeries<T>;

        private:
            /**
             * The index of current number
             */
            unsigned long index;

            /**
             * The lazy series
             */
            LazySeries<T>* series;

            /**
             * Constructor with series and index
             * @param pointer The pointer to the series
             * @param i The index. Defaults to 0 (first element)
             */
            explicit Iterator(LazySeries<T>* pointer, unsigned long i = 0) : series(pointer), index(i) {};

        public:
            /**
             * Equality check (not deep)
             * @param it The other iterator
             * @return True if they are equal, false otherwise
             */
            bool operator == (const Iterator& it) const {
                return series == it.series && index == it.index;
            }

            /**
             * Inequality check
             * @param it The other iterator
             * @return True if they are different, false otherwise
             */
            bool operator != (const Iterator& it) const {
                return index != it.index || series != it.series;
            }

            /**
             * Returns true if this references an element before the other, false otherwise
             * @param it The other iterator
             * @return True if this references an element before the other, false otherwise
             */
            bool operator < (const Iterator& it) const {
                return index < it.index;
            }

            /**
            * Returns true if this references an element after the other, false otherwise
            * @param it The other iterator
            * @return True if this references an element after the other, false otherwise
            */
            bool operator > (const Iterator& it) const {
                return index > it.index;
            }

            /**
            * Returns true if this references an element before or the same as the other, false otherwise
            * @param it The other iterator
            * @return True if this references an element before or the same as the other, false otherwise
            */
            bool operator <= (const Iterator& it) const {
                return index <= it.index;
            }

            /**
            * Returns true if this references an element after or the same as the other, false otherwise
            * @param it The other iterator
            * @return True if this references an element after or the same as the other, false otherwise
            */
            bool operator >= (const Iterator& it) const {
                return index >= it.index;
            }

            /**
             * Takes this Iterator to the next element before returning
             * @return The updated Iterator reference
             */
            Iterator& operator ++ () {       // prefix ++
                index++;
                return *this;
            }

            /**
             * Takes this Iterator to the next element after returning
             * @return The Iterator
             */
            Iterator operator ++ (int) {     // postfix ++
                LazySeries<T>::Iterator it = *this;
                index++;
                return it;
            }

            /**
            * Takes this Iterator to the previous element before returning
            * @return The updated Iterator reference
            */
            Iterator& operator -- () {       // prefix --
                index--;
                return *this;
            }

            /**
             * Takes this Iterator to the previous element after returning
             * @return The Iterator
             */
            Iterator operator -- (int) {     // postfix --
                LazySeries<T>::Iterator it = *this;
                index--;
                return it;
            }

            /**
             * Creates an Iterator that is n elements ahead of this
             * @param n The number of elements
             * @return The new Iterator
             */
            Iterator operator + (int n) {
                return {series, index + n};
            }

            /**
             * Creates an Iterator that is n elements behind of this
             * @param n The number of elements
             * @return The new Iterator
             */
            Iterator operator - (int n) {
                return {series, index - n};
            }

            /**
             * Shorthand for sum and auto assignment
             * @param n The number of elements
             * @return This iterator reference
             */
            Iterator& operator += (int n) {
                index += n;
                return *this;
            }

            /**
             * Shorthand for difference and auto assignment
             * @param n The number of elements
             * @return This iterator reference
             */
            Iterator& operator -= (int n) {
                index -= n;
                return *this;
            }

            /**
             * Dereferentiation of iterator
             * @return The value referenced by this iterator
             */
            T operator * () const {
                return (*series)[index];
            }
        };


        /**
         * Gets the n-th element of the series. It needs to evaluate all the previous numbers if they aven't already
         * @param index The index of the requested element
         * @return The n-th element of the series
         */
        T operator[](unsigned long index) {
            for (unsigned long i = numbers.size(); i <= index; i++)
                numbers.push_back(nextElement());

            return numbers[index];
        }

        /**
         * Gets the iterator to the first element of the series
         * @return The iterator to the first element of the series
         */
        Iterator begin() {
            return Iterator(this);
        }

        /**
         * Gets the iterator to the last possible element of the series.
         * As series are infinite the iterator to numeric limit of index is returned.
         * @return The iterator to the last possible element of the series
         */
        virtual Iterator end() {
            return Iterator(this, numeric_limits<unsigned long>::max());
        }


        /**
         * Gets the first n elements of the series
         * @param n The number of elements
         * @return The vector of elements
         */
        vector<T> get(unsigned long n) {
            if (numbers.size() < n)
                numbers.reserve(n);

            vector<T> result;
            for (Iterator it = begin(); result.size() < n; it++)
                result.push_back(*it);

            return result;
        }

        /**
         * Gets the first n elements of the series filtered by given test
         * @param n The number of elements to check
         * @param test The test function
         * @return The vector of the elements
         */
        vector<T> get(unsigned long n, const function<bool (T)>& test) {
            if (numbers.size() < n)
                numbers.reserve(n);

            vector<T> result;
            for (Iterator it = begin(); result.size() < n; it++)
                if (test(*it))
                    result.push_back(*it);

            return result;
        }

        /**
         * Gets all the elements before the first one greater than given upper bound
         * @param upperBound The upper bound
         * @return The vector of elements
         */
        vector<T> getUpTo(unsigned long upperBound) {
            vector<T> result;
            for (Iterator it = begin(); *it <= upperBound; it++)
                result.push_back(*it);
            return result;
        }

        /**
         * Gets all the elements before the first one greater than given upper bound filtered by given test
         * @param upperBound The upper bound
         * @param test The test function
         * @return The vector of elements
         */
        vector<T> getUpTo(unsigned long upperBound, const function<bool (T)>& test) {
            vector<T> result;
            for (Iterator it = begin(); *it <= upperBound; it++)
                if (test(*it))
                    result.push_back(*it);
            return result;
        }

        /**
         * Gets the first element that pass given test
         * @param test The test function
         * @return The first element that pass given test
         */
        T getFirst(const function<bool (T)>& test) {
            for (Iterator it = begin(); ; it++)
                if (test(*it))
                    return *it;
        }

        /**
         * Gets the first n elements that pass given test
         * @param test The test function
         * @param n The number of elements to return
         * @return The first n elements that pass given test
         */
        vector<T> getFirst(const function<bool (T)>& test, unsigned long n) {
            unsigned long count = 0;
            vector<T> elements(n);

            for (Iterator it = begin(); count < n; it++)
                if (test(*it)) {
                    elements.push_back(*it);
                    count++;
                }

            return elements;
        }


    protected:
        /**
         * The evaluated numbers
         */
        vector<T> numbers;

        /**
         * Function that calculates next element in the series
         * @return The next element
         */
        virtual T nextElement() = 0;
    };
}


#endif //PROJECT_EULER_LAZYSERIES_H
