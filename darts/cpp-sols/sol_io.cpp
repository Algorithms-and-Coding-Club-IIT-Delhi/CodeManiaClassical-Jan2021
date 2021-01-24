#include <bits/stdc++.h>

#define DEBUG 0

using i32 = int_fast32_t;
using TT = i32;
using Coordinates = std::pair<TT, TT>;
using CoordinatesList = std::vector<Coordinates>;

const TT EMPTY_MAX = std::numeric_limits<TT>::min();

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    size_t input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0) input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len) _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    inline bool isspace(char c) {
        return (unsigned char)(c - '\t') < 5 || c == ' ';
    }

    inline void read_char(char &c) {
        while (isspace(next_char(false))) next_char();

        c = next_char();
    }

    template <typename T>
        inline void read_int(T &number) {
            bool negative = false;
            number = 0;

            while (!isdigit(next_char(false)))
                if (next_char() == '-') negative = true;

            do {
                number = 10 * number + (next_char() - '0');
            } while (isdigit(next_char(false)));

            if (negative) number = -number;
        }

    template <typename T, typename... Args>
        inline void read_int(T &number, Args &... args) {
            read_int(number);
            read_int(args...);
        }

    inline void read_str(std::string &str) {
        while (isspace(next_char(false))) next_char();

        str.clear();

        do {
            str += next_char();
        } while (!isspace(next_char(false)));
    }

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE) _flush_output();

        output_buffer[output_pos++] = c;
    }

    template <typename T>
        inline void write_int(T number, char after = '\0') {
            if (number < 0) {
                write_char('-');
                number = -number;
            }

            int length = 0;

            while (number >= 10) {
                uint8_t lookup_value = lookup[number % 100];
                number /= 100;
                number_buffer[length++] = char((lookup_value & 15) + '0');
                number_buffer[length++] = char((lookup_value >> 4) + '0');
            }

            if (number != 0 || length == 0) write_char(char(number + '0'));

            for (int i = length - 1; i >= 0; i--) write_char(number_buffer[i]);

            if (after) write_char(after);
        }

    inline void write_str(const std::string &str, char after = '\0') {
        for (char c : str) write_char(c);

        if (after) write_char(after);
    }

    void IOinit() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++) lookup[i] = uint8_t((i / 10 << 4) + i % 10);
    }
}  // namespace IO

int main() {

    IO::IOinit();

    i32 n, q;
    IO::read_int(n, q);
    
    CoordinatesList a(n);
    for (auto &&[x, y] : a)
        IO::read_int(x, y);

    std::sort(begin(a), end(a));

    std::function<CoordinatesList(const CoordinatesList&)> find_maximal =
        
        [&find_maximal] (const CoordinatesList& a) {
            
            size_t n = a.size();
            
            if (n <= 1)
                return a;
            
            auto l_maximal = find_maximal(CoordinatesList(begin(a), begin(a) + n / 2));
            auto r_maximal = find_maximal(CoordinatesList(begin(a) + n / 2, end(a)));
            
            TT max_second = EMPTY_MAX;
            
            for (const auto &[x, y] : r_maximal)
                max_second = std::max(max_second, y);
            
            for (const auto &[x, y] : l_maximal)
                if (y > max_second)
                    r_maximal.emplace_back(x, y);

            return r_maximal;
        };

    CoordinatesList maximal_vectors = find_maximal(a);

#if DEBUG
    
    std::cerr << "Maximal vectors" << std::endl;

    for (auto &&[x, y] : maximal_vectors)
        std::cerr << x << ' ' << y << '\n';
    
    for (size_t i = 0; i + 1 < maximal_vectors.size(); ++i) {
        assert(maximal_vectors[i].first > maximal_vectors[i + 1].first);
        assert(maximal_vectors[i].second < maximal_vectors[i + 1].second);
    }
    
    std::cerr << "Query answers" << std::endl;

#endif

    auto dominates = [] (const Coordinates& p, const Coordinates& q) {
        return p.first >= q.first && p.second >= q.second;
    };

    while (q--) {
        
        TT x, y;
        IO::read_int(x, y);
        
        i32 l = 0, r = (i32) maximal_vectors.size() - 1;
        i32 dominating_index = -1;
        
        while (l <= r) {
            i32 m = l + ((r - l) >> 1);
            if (x <= maximal_vectors[m].first) {
                dominating_index = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        if (dominating_index == -1) {
            IO::write_int(-1, '\n');
        } else {
            TT ans_x, ans_y;
            std::tie(ans_x, ans_y) = maximal_vectors[dominating_index];
            if (dominates(maximal_vectors[dominating_index], std::make_pair(x, y))) {
                IO::write_int(ans_x, ' ');
                IO::write_int(ans_y, '\n');
            } else {
                IO::write_int(-1, '\n');
            }
        }
    }

    return 0;
}
