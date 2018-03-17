//
// Created by Alex Beccaro on 17/03/18.
//

namespace series {

    /// region iterator

    /// region constructors and destructors

    template<class T>
    lazy_series<T>::iterator::iterator(const lazy_series<T>* pointer, ulong i) :
            series(const_cast<lazy_series<T>*>(pointer)), index(i) {}

    template<class T>
    lazy_series<T>::iterator::iterator() : series(nullptr), index(0) {}

    template<class T>
    lazy_series<T>::iterator::iterator(const iterator& it) : series(it.series), index(it.index) {}

    template<class T>
    lazy_series<T>::iterator::~iterator() = default;

    /// endregion

    template<class T>
    typename lazy_series<T>::iterator& lazy_series<T>::iterator::operator = (const iterator& it) {
        series = it.series;
        index = it.index;
        return *this;
    }

    /// region comparison operators

    template<class T>
    bool lazy_series<T>::iterator::operator == (const iterator& it) const {
        return series == it.series && index == it.index;
    }

    template<class T>
    bool lazy_series<T>::iterator::operator != (const iterator& it) const {
        return index != it.index || series != it.series;
    }

    template<class T>
    bool lazy_series<T>::iterator::operator < (const iterator& it) const {
        return index < it.index;
    }

    template<class T>
    bool lazy_series<T>::iterator::operator > (const iterator& it) const {
        return index > it.index;
    }

    template<class T>
    bool lazy_series<T>::iterator::operator <= (const iterator& it) const {
        return index <= it.index;
    }

    template<class T>
    bool lazy_series<T>::iterator::operator >= (const iterator& it) const {
        return index >= it.index;
    }

    /// endregion

    /// region navigation operators

    template<class T>
    typename lazy_series<T>::iterator& lazy_series<T>::iterator::operator ++ () { // prefix ++
        index++;
        return *this;
    }

    template<class T>
    typename lazy_series<T>::iterator lazy_series<T>::iterator::operator ++ (int) { // postfix ++
        lazy_series<T>::iterator it = *this;
        index++;
        return it;
    }

    template<class T>
    typename lazy_series<T>::iterator& lazy_series<T>::iterator::operator -- () { // prefix --
        index--;
        return *this;
    }

    template<class T>
    typename lazy_series<T>::iterator lazy_series<T>::iterator::operator -- (int) { // postfix --
        lazy_series<T>::iterator it = *this;
        index--;
        return it;
    }

    template<class T>
    typename lazy_series<T>::iterator lazy_series<T>::iterator::operator + (ulong n) const {
        return iterator(series, index + n);
    }

    template<class T>
    typename lazy_series<T>::iterator lazy_series<T>::iterator::operator - (ulong n) const {
        return iterator(series, index - n);
    }

    template<class T>
    typename lazy_series<T>::iterator& lazy_series<T>::iterator::operator += (ulong n) {
        index += n;
        return *this;
    }

    template<class T>
    typename lazy_series<T>::iterator& lazy_series<T>::iterator::operator -= (ulong n) {
        index -= n;
        return *this;
    }

    /// endregion

    /// region dereferencing operators

    template<class T>
    const T& lazy_series<T>::iterator::operator * () const {
        return (*series)[index];
    }

    template<class T>
    const T* lazy_series<T>::iterator::operator -> () const {
        return &(*series)[index];
    }

    template<class T>
    const T& lazy_series<T>::iterator::operator [] (ulong n) const {
        return (*series)[index + n];
    }

    /// endregion

    /// endregion

    template<class T>
    lazy_series<T>::~lazy_series<T>() = default;

    template<class T>
    const T& lazy_series<T>::operator[](ulong index) {
        for (ulong i = numbers.size(); i <= index; i++)
            numbers.push_back(next_element());

        return numbers[index];
    }

    template<class T>
    typename lazy_series<T>::iterator lazy_series<T>::begin() const {
        return iterator(this);
    }

    template<class T>
    typename lazy_series<T>::iterator lazy_series<T>::end() const {
        return iterator(this, ULONG_MAX);
    }

    template<class T>
    ulong lazy_series<T>::size() const {
        return numbers.size();
    }

    /// region getters

    template<class T>
    std::vector<T> lazy_series<T>::get(ulong n) {
        if (numbers.size() < n)
            numbers.reserve(n);

        std::vector<T> result;
        for (iterator it = begin(); result.size() < n; it++)
            result.push_back(*it);

        return result;
    }

    template<class T>
    std::vector<T> lazy_series<T>::get(ulong n, const test& filter) {
        if (numbers.size() < n)
            numbers.reserve(n);

        std::vector<T> result;
        for (iterator it = begin(); result.size() < n; it++)
            if (filter(*it))
                result.push_back(*it);

        return result;
    }

    template<class T>
    std::vector<T> lazy_series<T>::get_while(const test& check) {
        std::vector<T> result;
        for (iterator it = begin(); check(*it); it++)
            result.push_back(*it);
        return result;
    }

    template<class T>
    std::vector<T> lazy_series<T>::get_while(const test& check, const test& filter) {
        std::vector<T> result;
        for (iterator it = begin(); check(*it); it++)
            if (filter(*it))
                result.push_back(*it);
        return result;
    }

    template<class T>
    std::vector<T> lazy_series<T>::get_until(const test& check) {
        std::vector<T> result;
        for (iterator it = begin(); !check(*it); it++)
            result.push_back(*it);
        return result;
    }

    template<class T>
    std::vector<T> lazy_series<T>::get_until(const test& check, const test& filter) {
        std::vector<T> result;
        for (iterator it = begin(); !check(*it); it++)
            if (filter(*it))
                result.push_back(*it);
        return result;
    }

    template<class T>
    T lazy_series<T>::get_first(const test& check) {
        for (iterator it = begin(); ; it++)
            if (check(*it))
                return *it;
    }

    template<class T>
    std::vector<T> lazy_series<T>::get_first(const test& check, ulong n) {
        ulong count = 0;
        std::vector<T> elements(n);

        for (iterator it = begin(); count < n; it++)
            if (check(*it)) {
                elements.push_back(*it);
                count++;
            }

        return elements;
    }

    /// endregion

}