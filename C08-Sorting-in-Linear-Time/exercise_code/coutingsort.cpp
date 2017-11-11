#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
std::vector<int> couting_sort(const std::vector<int>& input, int k)
{
    std::vector<int> counting_vector (k + 1, 0);
    std::vector<int> sorted (input.size());
    for(size_t i = 0; i < input.size(); ++i)
    {
        counting_vector[input[i]]++;
    }
    for(size_t i = 1; i < counting_vector.size(); ++i)
    {
        counting_vector[i] += counting_vector[i-1];
    }
    for(int j = input.size() - 1; j >= 0; --j)
    {
        sorted[counting_vector[input[j]] - 1] = input[j];
        counting_vector[input[j]]--;
    }
    return sorted;
}
int main(void)
{
    std::vector<int> A= {9, 4, 1, 7, 9, 1, 2, 0};
    auto sorted = couting_sort(A, 9);
    std::copy(sorted.begin(), sorted.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
