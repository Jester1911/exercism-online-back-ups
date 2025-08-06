#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

int vote_count(ElectionResult& electionResult) {
    return electionResult.votes;
}

void increment_vote_count(ElectionResult& electionResult, int votesToAdd) {
    electionResult.votes += votesToAdd;
}

// TODO: Task 3
// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.
ElectionResult& determine_result(std::vector<ElectionResult>& results) {
    size_t winnerIdx{0};
    int highestVoteCount{0};

    for (size_t i = 0; i < results.size(); ++i) {
        if (results[i].votes > highestVoteCount) {
            winnerIdx = i;
            highestVoteCount = results[i].votes;
        }
    }

    // Change "name" field of winner
    results[winnerIdx].name = "President " + results[winnerIdx].name;

    ElectionResult& winner{results[winnerIdx]};
    return winner;
}





}  // namespace election