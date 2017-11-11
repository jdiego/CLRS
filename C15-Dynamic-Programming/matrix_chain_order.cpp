#include <iostream>
#include <climits>
int matrix_chain_order_rec(int p[], int i, int j)
{
    if ( i == j ) return 0;
    int min_cost = INT_MAX;
    for(int k = i; k < j; ++k)
    {
        min_cost = std::min(min_cost, matrix_chain_order_rec(p, i, k) + matrix_chain_order_rec(p, k+1, j) + (p[i-1]*p[k]*p[j]));
    }
    return min_cost;
}

int matrix_chain_order(int p[], int n)
{
    int m[n][n];
    // if i == j, then min[i][j] = 0
    for (int i = 0; i < n; ++i)
        m[i][i] = 0;

    //int s[n][n] = {0};

    // l is chain length.
    for(int l = 2; l < n; ++l)
    {
        for(int i = 1; i < n-l+1; ++i)
        {
            int j =  i + l - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k < j; ++k)
            {
                m[i][j] = std::min(m[i][j], m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]));
            }
        }
    }

    return m[1][n-1];

}
int main(void)
{
    int p [] = {40, 20, 30, 10, 30};
    int n = sizeof(p)/sizeof(p[0]);
/*    std::cout   << "Minimum number of multiplications is "*/
                //<< matrix_chain_order_rec(p, 1, n-1)
                /*<< std::endl;*/
    std::cout   << "Minimum number of multiplications is "
                << matrix_chain_order(p, n)
                << std::endl;

    return 0;
}
