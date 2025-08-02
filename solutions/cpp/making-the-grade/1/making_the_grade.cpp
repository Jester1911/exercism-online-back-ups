#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> rounded{};
    for (int score : student_scores) {
        rounded.push_back(static_cast<int>(score));
    }
    return rounded;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int numFailed{0};
    for (int score : student_scores) {
        if (score <= 40) {
            ++numFailed;
        }
    }
    
    return numFailed;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int gradeIncrement{0};
    std::array<int, 4> lowerGradeThreshold;
    gradeIncrement = (highest_score - 40) / 4;
    for (int i = 0; i < 4; ++i) {
        lowerGradeThreshold[i] = 41 + (i * gradeIncrement);
    }

    return lowerGradeThreshold;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {

    std::vector<std::string> results{};
    int rank{1};
    for (int i = 0; i < student_scores.size(); ++i) {
        results.push_back(std::to_string(rank) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));
    ++rank;
    }

    return results;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for (int i = 0; i < student_scores.size(); ++i) {
        if (student_scores[i] == 100) {
            return (student_names[i]);
        }
    }
    return "";
}
