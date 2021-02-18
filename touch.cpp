#include <iostream>
#include <fstream>

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

inline void create_file(std::string);
std::string get_current_dir();

int main(int argc, char *argv[])
{
    if (argc < 2)
        std::cerr << "Not enough input" << std::endl;

    std::string base_path = get_current_dir();

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

std::string get_current_dir()
{
    char buff[FILENAME_MAX]; //create string buffer to hold path
    GetCurrentDir(buff, FILENAME_MAX);
    std::string current_working_dir(buff);
    return current_working_dir;
}