#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

void replaceAllOccurrences(std::string& string, const std::string& searchStr, const std::string& replaceStr)
{
    // Find the first occurrance of substring
    std::size_t pos = string.find(searchStr);

    // Replace every occurance until find returns -1 or npos
    while (pos != std::string::npos)
    {
        string.replace(pos, searchStr.size(), replaceStr);

        // Find next occurrance from the end of the now replaced substring 
        pos = string.find(searchStr, pos + replaceStr.size());
    }
}

std::string uwufy(std::string& line)
{   
    /*
        The uwu Language
        th    -> d
        l,r   -> w
        ou    -> uw
        ohh   -> uh
    */
    replaceAllOccurrences(line, "th", "d");
	replaceAllOccurrences(line, "l", "w");
	replaceAllOccurrences(line, "r", "w");
	replaceAllOccurrences(line, "ou", "uw");
	replaceAllOccurrences(line, "ohh", "uh");

	replaceAllOccurrences(line, "Th", "D");
	replaceAllOccurrences(line, "TH", "D");

	replaceAllOccurrences(line, "L", "W");
	replaceAllOccurrences(line, "R", "W");
	replaceAllOccurrences(line, "Ohh", "Uhh");

    return line;
}

void fileMode(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::cout << uwufy(line) << std::endl;
        }

        file.close();
    }
    else std::cout << "Could not open file!" << std::endl;
}

void stringMode(std::string string)
{
    std::cout << uwufy(string);
}

void help()
{
    std::cout << "\tUsage\n";
    std::cout << "-f or --file\tEnable file input\n";
}

int main(int argc, char* argv[])
{
    if (argc < 2)
        std::cout << "No arguments given!" << std::endl;
    else if (argc == 2)
    {
        stringMode(argv[1]);
    }
    else if (argc == 3)
    {
        if (argv[1] == std::string("--file") || argv[1] == std::string("-f"))
            fileMode(argv[2]);
    }
    else help();

    return 0;
}