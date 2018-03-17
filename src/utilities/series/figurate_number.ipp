//
// Created by Alex Beccaro on 17/03/18.
//

namespace series {

    template<class T, class U>
    figurate_number<T, U>::figurate_number(const T& sides) {
        this->numbers.emplace_back(1);

        next_increment = sides - 1;
        increment_step = sides - 2;
    }

    template<class T, class U>
    T figurate_number<T, U>::next_element() {
        T n = this->numbers.back() + next_increment;
        next_increment += increment_step;
        return n;
    }

}