
#include<iostream>
#include<cstring>

int main(int argc, char* argv[])
{
    if(argc < 2)
        std::cerr << "Not enough input" << std::endl;

    
    std::string base_path(argv[0]);
    base_path = base_path.substr(0, base_path.length() - 9);

    for(int i = 1 ; i < argc ; i++)
    {
        std::string file_path = (base_path + "\\").append(argv[i]);

        std::cout << file_path << std::endl;
    }


    return 0;
}