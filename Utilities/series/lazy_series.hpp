//
// Created by Alex Beccaro on 13/12/17.
//

#ifndef PROJECT_EULER_LAZY_SERIES_H
#define PROJECT_EULER_LAZY_SERIES_H

#include <vector>
#include <functional>
#include <climits>

using namespace std;

namespace series {
    template <class T>
    class lazy_series {
    public:
        /**
         * Lazy series iterator class. Referenced elements are constant
         */
        class iterator {
            // friend to gain access to private constructor
            friend class lazy_series<T>;

        private:
            /**
             * The index of current number
             */
            unsigned long index;

            /**
             * The lazy series
             */
            lazy_series<T>* series;

            /**
             * Constructor with series and index
             * @param pointer The pointer to the series
             * @param i The index. Defaults to 0 (first element)
             */
            explicit iterator(const lazy_series<T>* pointer, unsigned long i = 0) :
                    series(const_cast<lazy_series<T>*>(pointer)), index(i) {};

        public:

            //region Constructors

            /**
             * Default constructor, points to a null series
             */
            iterator() : series(nullptr), index(0) {};

            /**
             * Copy constructor
             * @param it The iterator to copy
             */
            iterator(const iterator& it) : series(it.series), index(it.index) {};

            /**
             * Default distructor
             */
            ~iterator() = default;

            //endregion

            /**
             * Assignment operator
             * @param it The value to assign
             * @return The reference to this object
             */
            iterator& operator = (const iterator& it) {
                series = it.series;
                index = it.index;
                return *this;
            }

            ///region Comparison operators

            /**
             * Equality check (not deep)
             * @param it The other iterator
             * @return True if they are equal, false otherwise
             */
            bool operator == (const iterator& it) const {
                return series == it.series && index == it.index;
            }

            /**
             * Inequality check
             * @param it The other iterator
             * @return True if they are different, false otherwise
             */
            bool operator != (const iterator& it) const {
                return index != it.index || series != it.series;
            }

            /**
             * Returns true if this references an element before the other, false otherwise
             * @param it The other iterator
             * @return True if this references an element before the other, false otherwise
             */
            bool operator < (const iterator& it) const {
                return index < it.index;
            }

            /**
            * Returns true if this references an element after the other, false otherwise
            * @param it The other iterator
            * @return True if this references an element after the other, false otherwise
            */
            bool operator > (const iterator& it) const {
                return index > it.index;
            }

            /**
            * Returns true if this references an element before or the same as the other, false otherwise
            * @param it The other iterator
            * @return True if this references an element before or the same as the other, false otherwise
            */
            bool operator <= (const iterator& it) const {
                return index <= it.index;
            }

            /**
            * Returns true if this references an element after or the same as the other, false otherwise
            * @param it The other iterator
            * @return True if this references an element after or the same as the other, false otherwise
            */
            bool operator >= (const iterator& it) const {
                return index >= it.index;
            }

            ///endregion

            ///region Navigation operators

            /**
             * Takes this Iterator to the next element before returning
             * @return The updated Iterator reference
             */
            iterator& operator ++ () {       // prefix ++
                index++;
                return *this;
            }

            /**
             * Takes this Iterator to the next element after returning
             * @return The Iterator
             */
            iterator operator ++ (int) {     // postfix ++
                lazy_series<T>::iterator it = *this;
                index++;
                return it;
            }

            /**
            * Takes this Iterator to the previous element before returning
            * @return The updated Iterator reference
            */
            iterator& operator -- () {       // prefix --
                index--;
                return *this;
            }

            /**
             * Takes this Iterator to the previous element after returning
             * @return The Iterator
             */
            iterator operator -- (int) {     // postfix --
                lazy_series<T>::iterator it = *this;
                index--;
                return it;
            }

            /**
             * Creates an Iterator that is n elements ahead of this
             * @param n The number of elements
             * @return The new Iterator
             */
            iterator operator + (int n) const {
                return {series, index + n};
            }

            /**
             * Creates an Iterator that is n elements behind of this
             * @param n The number of elements
             * @return The new Iterator
             */
            iterator operator - (int n) const {
                return {series, index - n};
            }

            /**
             * Shorthand for sum and auto assignment
             * @param n The number of elements
             * @return This iterator reference
             */
            iterator& operator += (int n) {
                index += n;
                return *this;
            }

            /**
             * Shorthand for difference and auto assignment
             * @param n The number of elements
             * @return This iterator reference
             */
            iterator& operator -= (int n) {
                index -= n;
                return *this;
            }

            ///endregion

            ///region Deferentiation operators

            /**
             * Dereferentiation of iterator
             * @return The value referenced by this iterator
             */
            const T& operator * () const {
                return (*series)[index];
            }

            /**
             * Member pointer access
             * @return The pointer to referenced element
             */
            const T* operator -> () const {
                return (*series)[index];
            };

            /**
             * Dereferentiation of iterator with offset
             * @param n The offset
             * @return The element n positions after the one referenced by this iterator
             */
            const T& operator [] (unsigned long n) const {
                return (*series)[index + n];
            }

            ///endregion
        };


        /**
         * Virtual destructor for subclasses
         */
        virtual ~lazy_series<T>() = default;


        /**
         * Gets the n-th element of the series. It needs to evaluate all the previous numbers if they aven't already
         * @param index The index of the requested element
         * @return The n-th element of the series
         */
        const T& operator[](unsigned long index) {
            for (unsigned long i = numbers.size(); i <= index; i++)
                numbers.push_back(next_element());

            return numbers[index];
        }

        /**
         * Gets the iterator to the first element of the series
         * @return The iterator to the first element of the series
         */
        iterator begin() const {
            return iterator(this);
        }

        /**
         * Gets the iterator to the last possible element of the series.
         * As series are infinite the iterator to numeric limit of index is returned.
         * @return The iterator to the last possible element of the series
         */
        iterator end() const {
            return iterator(this, ULONG_MAX);
        }

        /**
         * Returns the number of already evaluated elements
         * @return The number of already evaluated elements
         */
        unsigned long size() {
            return numbers.size();
        }

        ///region Getters


        /**
         * Gets the first n elements of the series
         * @param n The number of elements
         * @return The vector of elements
         */
        vector<T> get(unsigned long n) {
            if (numbers.size() < n)
                numbers.reserve(n);

            vector<T> result;
            for (iterator it = begin(); result.size() < n; it++)
                result.push_back(*it);

            return result;
        }

        /**
         * Gets the first n elements of the series filtered by given function
         * @param n The number of elements to check
         * @param filter The filter function
         * @return The vector of the elements
         */
        vector<T> get(unsigned long n, const function<bool (T)>& filter) {
            if (numbers.size() < n)
                numbers.reserve(n);

            vector<T> result;
            for (iterator it = begin(); result.size() < n; it++)
                if (filter(*it))
                    result.push_back(*it);

            return result;
        }

        /**
         * Gets all the elements before the first one to fail given test
         * @param test The test function
         * @return The vector of elements
         */
        vector<T> get_while(const function<bool(T)> &test) {
            vector<T> result;
            for (iterator it = begin(); test(*it); it++)
                result.push_back(*it);
            return result;
        }

        /**
         * Gets all the elements before the first one to fail given test
         * @param test The test function
         * @param test The filter function
         * @return The vector of elements
         */
        vector<T> get_while(const function<bool(T)> &test, const function<bool(T)> &filter) {
            vector<T> result;
            for (iterator it = begin(); test(*it); it++)
                if (filter(*it))
                    result.push_back(*it);
            return result;
        }

        /**
         * Gets all the elements before the first one to pass given test
         * @param test The test function
         * @return The vector of elements
         */
        vector<T> get_until(const function<bool(T)> &test) {
            vector<T> result;
            for (iterator it = begin(); !test(*it); it++)
                result.push_back(*it);
            return result;
        }

        /**
         * Gets all the elements before the first one to pass given test
         * @param test The test function
         * @param test The filter function
         * @return The vector of elements
         */
        vector<T> get_until(const function<bool(T)> &test, const function<bool(T)> &filter) {
            vector<T> result;
            for (iterator it = begin(); !test(*it); it++)
                if (filter(*it))
                    result.push_back(*it);
            return result;
        }

        /**
         * Gets the first element that pass given test
         * @param test The test function
         * @return The first element that pass given test
         */
        T get_first(const function<bool(T)> &test) {
            for (iterator it = begin(); ; it++)
                if (test(*it))
                    return *it;
        }

        /**
         * Gets the first n elements that pass given test
         * @param test The test function
         * @param n The number of elements to return
         * @return The first n elements that pass given test
         */
        vector<T> get_first(const function<bool(T)> &test, unsigned long n) {
            unsigned long count = 0;
            vector<T> elements(n);

            for (iterator it = begin(); count < n; it++)
                if (test(*it)) {
                    elements.push_back(*it);
                    count++;
                }

            return elements;
        }

        ///endregion


    protected:
        /**
         * The evaluated numbers
         */
        vector<T> numbers;

        /**
         * Function that calculates next element in the series
         * @return The next element
         */
        virtual T next_element() = 0;
    };
}


#endif //PROJECT_EULER_LAZY_SERIES_H
