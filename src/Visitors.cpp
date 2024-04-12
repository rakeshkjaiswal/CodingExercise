/**
* @file Visitor.cpp
* @brief Concise implementation of Museum Visitors program
*
* @author Rakesh Jaiswal
*
* @date 12/04/2024
*/

/* -- Includes -- */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>

/// <summary>
/// This will return a vector of tokens (i.e. strings) using a string based on a delimiter
/// </summary>
/// <param name="s is the source string which needs to be extracted"></param>
/// <param name="delimiter is used to find tokens based on this"></param>
/// <returns>
/// A vector of strings
/// </returns>
std::vector<std::string> tokenize(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

/// <summary>
/// This program will return maximum number of visitors along with the corresponding time range based on the
/// visitors' in-out time provided in an input text file.
/// </summary>
/// <param name="argc represents program argument count"></param>
/// <param name="argv represnts program arguments along with program name"></param>
/// <returns> program exit code</returns>
int main(int argc, char* argv[]) {
    // return with message if file path of input file in not provided
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " followed by" << " <input_file_path>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);

    // return with message if unable to open input file
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << argv[1] << std::endl;
        return 1;
    }

    std::string line; // a single line from the input file
    std::unordered_map<int, int> visitorCount; // represents a particular time mapped with the number of visitors at that time
    int maxVisitors = 0; //maximum number of visitors so far while parsing the file line by line
    int startTime = 0;
    int endTime = 0;

    // Read the input file line by line
    while (std::getline(file, line)) {
        std::vector<std::string> times = tokenize(line, ',');
        int start = std::stoi(times[0].substr(0, 2)) * 60 + std::stoi(times[0].substr(3, 2));
        int end = std::stoi(times[1].substr(0, 2)) * 60 + std::stoi(times[1].substr(3, 2));

        // Increment count of visitor for each minute they were in the museum and update maxVisitors accordingly
        for (int i = start; i <= end; ++i) {
            visitorCount[i]++;
            if (visitorCount[i] > maxVisitors) {
                maxVisitors = visitorCount[i];
                startTime = i;
            }
        }
    }

    // Find the end time of the period with the most visitors
    for (int i = startTime; i < 24 * 60 && visitorCount[i] == maxVisitors; ++i) {
        endTime = i;
    }

    // Convert minutes back to HH:MM format
    std::string startPeriod = std::to_string(startTime / 60) + ":" + (startTime % 60 < 10 ? "0" : "") + std::to_string(startTime % 60);
    std::string endPeriod = std::to_string(endTime / 60) + ":" + (endTime % 60 < 10 ? "0" : "") + std::to_string(endTime % 60);

    // Display the details as per requirement
    std::cout << startPeriod << "-" << endPeriod << ";" << maxVisitors << std::endl;

    return 0;
}