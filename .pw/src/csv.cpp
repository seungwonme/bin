#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iostream>

static std::string GetTimestamp();
static bool IsFileEmpty(std::ifstream &file);
static int GetLastId(std::ifstream &inFile);

void LogPasswordToCSV(const std::string &password)
{
    const std::string filename = "passwords.csv";
    std::ofstream outFile(filename, std::ios::app);
    std::ifstream inFile(filename, std::ios::in);
    int id = GetLastId(inFile) + 1;
    /*
    In C++, std::ios::app is an open mode flag used with file streams to specify that data should be appended to the end of the file instead of overwriting its contents.
    When you open a file with std::ios::app, any data you write to the file will be added at the end, preserving the existing content.
    This is useful when you want to add new data to an existing file without deleting its previous contents.
    In the code snippet you provided, std::ofstream outFile("passwords.csv", std::ios::app); opens the file "passwords.csv" in append mode.
    This means that if the file already exists, the new password will be added to the end of the file. If the file doesn't exist, it will be created.
    Appending data to a file is a common operation when you want to store a log of events, update a record, or add new entries to a data file without losing the existing data.
    */

    if (!inFile.is_open() || !outFile.is_open())
    {
        std::cerr << "\e[0;31m"
                  << "Error\n"
                  << "Failed to open " << filename << ".\e[0m" << std::endl;
        return;
    }

    if (IsFileEmpty(inFile))
    {
        outFile << "id, timestamp, password" << std::endl;
    }
    outFile << id << ", " << GetTimestamp() << ", " << password << std::endl;
    inFile.close();
    outFile.close();
}

static std::string GetTimestamp()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    std::tm *now_tm = std::localtime(&now_time);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now_tm);

    return std::string(buffer);
}

static bool IsFileEmpty(std::ifstream &file)
{
    /*
    The peek function is a member function of std::ifstream (input file stream) in C++.
    It returns the next character in the input sequence, without extracting it.
    This means that the next read operation will still see this character.
    traits_type::eof() is a static member function of std::char_traits<char>, which is the default character traits class used by std::ifstream.
    This function returns a special value that represents the end-of-file (EOF). In other words, it's a value that peek would return if there were no more characters to read from the file.
    */
    file.clear();
    file.seekg(0, std::ios::beg);
    return file.peek() == std::ifstream::traits_type::eof();
}

static int GetLastId(std::ifstream &inFile)
{
    inFile.clear();
    inFile.seekg(0, std::ios::beg);
    /*
    clear(): This function is used to reset the error state flags (eofbit, failbit, badbit) of the stream.
    For example, if you've read past the end of the file, the eofbit (end-of-file) flag will be set and further read operations will fail.
    By calling clear(), you can reset these flags and make the stream usable again.

    seekg(): This function changes the location of the "get" pointer, which determines the next location to be read in the input stream.
    The seekg() function takes two arguments: the first is the number of bytes to move the get pointer, and the second is the position to move from.
    In your code, seekg(0, std::ios::beg) is moving the get pointer to the beginning of the file.
     */

    std::string line;
    int lastId = 0; // Default to 0 if file is empty or doesn't exist

    if (std::getline(inFile, line).eof())
    {
        return lastId;
    }

    while (getline(inFile, line))
    {
        std::istringstream iss(line);
        std::string idStr;
        getline(iss, idStr, ','); // Get the first token (ID) from the line
        try
        {
            // 마지막으로 성공적으로 읽힌 ID를 저장
            lastId = std::stoi(idStr);
        }
        catch (const std::invalid_argument &e)
        {
            // stoi 변환 실패 시 무시하고 계속 진행
            continue;
        }
        catch (const std::out_of_range &e)
        {
            // stoi 변환 범위 초과 시 무시하고 계속 진행
            continue;
        }
    }

    return lastId;
}
