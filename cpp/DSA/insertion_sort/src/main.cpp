#include <iostream>
#include <vector>

// Insertion Sort
void
insertion_sort (std::vector<int> &A, int n)
{
    for (int i = 1; i < n; i++)
        {
            int key = A[i];

            // Insert A[i] into the sorted subarray A[1:i-1]
            int j = i - 1;

            while (j >= 0 and A[j] > key)
                {
                    A[j + 1] = A[j];
                    j = j - 1;
                }

            A[j + 1] = key;
        }
}

// Printing out array to console
void
printArrayToConsole (std::vector<int> A, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

int
main ()
{
    std::vector<int> A{ 5, 2, 4, 6, 1, 3 }; // The array that going to be sorted
    const int n = A.size ();                // Num of elements in the array

    std::cout << "Array before sort: " << std::endl;
    printArrayToConsole (A, n); // Print array to console before sorting

    insertion_sort (A, n); // Sorting

    std::cout << "Array after sort: " << std::endl;
    printArrayToConsole (A, n); // Print array to console after sorting
}
