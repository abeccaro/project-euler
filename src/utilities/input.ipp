//
// Created by Alex Beccaro on 16/03/18.
//

namespace input {

    template<class T, class>
    std::vector<T> read_vector(const std::string &filename) {
        std::vector<T> numbers;
        std::ifstream file(filename);
        assert(file && "Specified file does not exist");

        std::string line;
        while (file >> line) {
            std::stringstream line_stream(line);

            T n;
            while (line_stream >> n)
                numbers.push_back(n);
        }

        file.close();

        return numbers;
    }

    template<class T, class>
    std::vector<std::vector<T>> read_matrix(const std::string &filename) {
        std::vector<std::vector<T>> matrix;
        std::ifstream file(filename);
        assert(file && "Specified file does not exist");

        std::string line;
        while(getline(file, line)) {
            std::vector<T> row;
            std::stringstream line_stream(line);

            T n;
            while(line_stream >> n)
                row.push_back(n);

            matrix.push_back(row);
        }

        file.close();

        return matrix;
    }

}