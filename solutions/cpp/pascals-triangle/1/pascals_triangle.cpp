#include "pascals_triangle.h"

namespace pascals_triangle {

    /* 
        Observations:
            1. A row has even elements if its row number is even.
            2. A row has odd elements if its row number is odd.
            3. The sum of the elements in a row is 2^(row num - 1).
            4. A row has the same number of elements as its row number.
            5. Even rows are reflected at 0..(row num * 0.5 - 1)
            6. Odd rows are reflected at ceil(row num // 2) 

        Algorithm:
            - First element in any row is 1
            - Take the last number entered
            - Multiply number by what's left to count down from row number
            - Divide by the position of the row you are about to solve for
    */

    std::vector<int> generateRow(int rowNumber) {
        std::vector<int> row{1};
        int previous{1};
        
        if (rowNumber != 1) {
            for (int position = 1; position < rowNumber; ++position) {
                int next = (previous * (rowNumber - position)) / position;
                row.push_back(next);
                previous = next;
            }
        }
        return row;
    }
    
    std::vector<std::vector<int>> generate_rows(int numberOfRows) {
        std::vector<std::vector<int>> rows{};

        for (int i = 1; i <= numberOfRows; ++i) {
            rows.push_back(generateRow(i));
        }
        return rows;
    }
    

    
}  // namespace pascals_triangle
