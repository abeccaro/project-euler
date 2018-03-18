//
// Created by Alex Beccaro on 17/03/18.
//

namespace series {

    template<class T, class U>
    fibonacci<T, U>::fibonacci() {
        this->numbers.emplace_back(1);
        this->numbers.emplace_back(1);
    }

    template<class T, class U>
    T fibonacci<T, U>::next_element() {
        uint64_t count = this->numbers.size();

        return this->numbers[count-2] + this->numbers[count-1];
    }

}