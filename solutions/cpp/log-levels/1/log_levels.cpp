#include <string>

namespace log_line {
std::string message(std::string line) {
    // Extract and return only the message portion of the log line
    auto colonIndex{line.find(":")};
    auto messageStartIndex{colonIndex + 2};
    std::string result{line.substr(messageStartIndex)};
    
    return result;
}

std::string log_level(std::string line) {
    // Extract and return the log level portion of the log line in upper case
    auto openBracketIndex{line.find("[")};
    auto closeBracketIndex{line.find("]")};
    auto logStartIndex{openBracketIndex + 1};
    std::string logLevel{line.substr(logStartIndex, closeBracketIndex - 1)};

    return logLevel;
}

std::string reformat(std::string line) {
    std::string logLevelPart{log_line::log_level(line)};
    std::string messagePart{log_line::message(line)};
    std::string formattedMessage{messagePart + " (" + logLevelPart + ")"};

    return formattedMessage;
}
}  // namespace log_line
