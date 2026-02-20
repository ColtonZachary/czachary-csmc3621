#include <iostream>
#include <vector>

using namespace std;

// Helper function for backtracking
void backtrack(char* array, int size, int start,
               vector<char>& current,
               vector<vector<char>>& result)
{
    // Add current subset to result
    result.push_back(current);

    // Try adding each remaining element
    for (int i = start; i < size; i++)
    {
        // Choose/Try 
        current.push_back(array[i]);

        // Explore/Recurse 
        backtrack(array, size, i + 1, current, result);

        // Backtrack/Undo
        current.pop_back();
    }
}

// Function to generate all subsets of a given array
vector<vector<char>> subsets(char* array, int size) 
{
    vector<vector<char>> result; // To store all subsets
    vector<char> current; // To store the current subset being constructed

    backtrack(array, size, 0, current, result); // Start backtracking from the first element

    return result;
}

int main()
{
    // Initialize array
    char arr[] = { 'a', 'b', 'c' };
    int size = 3;

    // Get subsets
    vector<vector<char>> result = subsets(arr, size);

    // Output results
    cout << "All subsets:\n";

    for (auto& subset : result)
    {
        cout << "[";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i];
            if (i < subset.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}