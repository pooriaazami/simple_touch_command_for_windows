
#include <iostream>
#include <fstream>
#include <cstring>

inline void create_file(std::string);

int main(int argc, char *argv[])
{
    if (argc < 2)
        std::cerr << "Not enough input" << std::endl;

    std::string base_path(argv[0]);
    base_path = base_path.substr(0, base_path.length() - 9);

    for (int i = 1; i < argc; i++)
    {
        std::string file_path = (base_path + "\\").append(argv[i]);

        create_file(file_path);
    }

    return 0;
}

inline void create_file(std::string input)
{
    std::fstream file_stream;
    file_stream.open(input.data(), std::ios::out);
    file_stream.close();
}