//
// Created by Alex Beccaro on 13/12/17.
//

#ifndef PROJECT_EULER_LAZY_SERIES_H
#define PROJECT_EULER_LAZY_SERIES_H

#include <vector>
#include <functional>

namespace series {
    template <class T>
    class lazy_series {
        using test = std::function<bool (T)>;

    protected:
        /**
         * The evaluated numbers
         */
        std::vector<T> numbers;

        /**
         * Function that calculates next element in the series
         * @return The next element
         */
        virtual T next_element() = 0;

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
            uint64_t index;

            /**
             * The lazy series
             */
            lazy_series<T>* series;

            /**
             * Constructor with series and index
             * @param pointer The pointer to the series
             * @param i The index. Defaults to 0 (first element)
             */
            explicit iterator(const lazy_series<T>* pointer, uint64_t i = 0);

        public:

            //region Constructors

            /**
             * Default constructor, points to a null series
             */
            iterator();

            /**
             * Copy constructor
             * @param it The iterator to copy
             */
            iterator(const iterator& it);

            /**
             * Default distructor
             */
            ~iterator();

            //endregion

            /**
             * Assignment operator
             * @param it The value to assign
             * @return The reference to this object
             */
            iterator& operator = (const iterator& it);

            /// region Comparison operators

            /**
             * Equality check (not deep)
             * @param it The other iterator
             * @return True if they are equal, false otherwise
             */
            bool operator == (const iterator& it) const;

            /**
             * Inequality check
             * @param it The other iterator
             * @return True if they are different, false otherwise
             */
            bool operator != (const iterator& it) const;

            /**
             * Returns true if this references an element before the other, false otherwise
             * @param it The other iterator
             * @return True if this references an element before the other, false otherwise
             */
            bool operator < (const iterator& it) const;

            /**
            * Returns true if this references an element after the other, false otherwise
            * @param it The other iterator
            * @return True if this references an element after the other, false otherwise
            */
            bool operator > (const iterator& it) const;

            /**
            * Returns true if this references an element before or the same as the other, false otherwise
            * @param it The other iterator
            * @return True if this references an element before or the same as the other, false otherwise
            */
            bool operator <= (const iterator& it) const;

            /**
            * Returns true if this references an element after or the same as the other, false otherwise
            * @param it The other iterator
            * @return True if this references an element after or the same as the other, false otherwise
            */
            bool operator >= (const iterator& it) const;

            ///endregion

            ///region Navigation operators

            /**
             * Takes this Iterator to the next element before returning
             * @return The updated Iterator reference
             */
            iterator& operator ++ (); // prefix

            /**
             * Takes this Iterator to the next element after returning
             * @return The Iterator
             */
            iterator operator ++ (int); // postfix

            /**
            * Takes this Iterator to the previous element before returning
            * @return The updated Iterator reference
            */
            iterator& operator -- (); // prefix

            /**
             * Takes this Iterator to the previous element after returning
             * @return The Iterator
             */
            iterator operator -- (int); // postfix

            /**
             * Creates an Iterator that is n elements ahead of this
             * @param n The number of elements
             * @return The new Iterator
             */
            iterator operator + (uint64_t n) const;

            /**
             * Creates an Iterator that is n elements behind of this
             * @param n The number of elements
             * @return The new Iterator
             */
            iterator operator - (uint64_t n) const;

            /**
             * Shorthand for sum and auto assignment
             * @param n The number of elements
             * @return This iterator reference
             */
            iterator& operator += (uint64_t n);

            /**
             * Shorthand for difference and auto assignment
             * @param n The number of elements
             * @return This iterator reference
             */
            iterator& operator -= (uint64_t n);

            ///endregion

            ///region Dereferencing operators

            /**
             * Dereferencing of iterator
             * @return The value referenced by this iterator
             */
            const T& operator * () const;

            /**
             * Member pointer access
             * @return The pointer to referenced element
             */
            const T* operator -> () const;

            /**
             * Dereferencing of iterator with offset
             * @param n The offset
             * @return The element n positions after the one referenced by this iterator
             */
            const T& operator [] (uint64_t n) const;

            ///endregion
        };


        /**
         * Virtual destructor for subclasses
         */
        virtual ~lazy_series<T>();


        /**
         * Gets the n-th element of the series. It needs to evaluate all the previous numbers if they aven't already
         * @param index The index of the requested element
         * @return The n-th element of the series
         */
        const T& operator[](uint64_t index);

        /**
         * Gets the iterator to the first element of the series
         * @return The iterator to the first element of the series
         */
        iterator begin() const;

        /**
         * Gets the iterator to the last possible element of the series.
         * As series are infinite the iterator to numeric limit of index is returned.
         * @return The iterator to the last possible element of the series
         */
        iterator end() const;

        /**
         * Returns the number of already evaluated elements
         * @return The number of already evaluated elements
         */
        uint64_t size() const;

        ///region Getters

        /**
         * Gets the first n elements of the series
         * @param n The number of elements
         * @return The vector of elements
         */
        std::vector<T> get(uint64_t n);

        /**
         * Gets the first n elements of the series filtered by given function
         * @param n The number of elements to check
         * @param filter The filter function
         * @return The vector of the elements
         */
        std::vector<T> get(uint64_t n, const test& filter);

        /**
         * Gets all the elements before the first one to fail given test
         * @param check The test function
         * @return The vector of elements
         */
        std::vector<T> get_while(const test& check);

        /**
         * Gets all the elements before the first one to fail given test
         * @param check The test function
         * @param filter The filter function
         * @return The vector of elements
         */
        std::vector<T> get_while(const test& check, const test& filter);

        /**
         * Gets all the elements before the first one to pass given test
         * @param check The test function
         * @return The vector of elements
         */
        std::vector<T> get_until(const test& check);

        /**
         * Gets all the elements before the first one to pass given test
         * @param check The check function
         * @param filter The filter function
         * @return The vector of elements
         */
        std::vector<T> get_until(const test& check, const test& filter);

        /**
         * Gets the first element that pass given test
         * @param check The test function
         * @return The first element that pass given test
         */
        T get_first(const test& check);

        /**
         * Gets the first n elements that pass given test
         * @param check The test function
         * @param n The number of elements to return
         * @return The first n elements that pass given test
         */
        std::vector<T> get_first(const test& check, uint64_t n);

        ///endregion


    };
}

#include "lazy_series.ipp"

#endif //PROJECT_EULER_LAZY_SERIES_H
