#include "matrix_diff.hpp"
#include <iostream>
namespace la
{
    dense_matrix vertical_diff(const dense_matrix& A)
    {
        unsigned n = A.rows();
        unsigned m = A.columns();

        dense_matrix D(n-1, m, 0.0);

        if(n < 2)
        {
            std::cerr << "Impossibile eseguire la differenza, numero righe insufficiente!" << std::endl;
        }
        else
        {
            for(size_t i = 0; i < n - 1; ++i)
                for(size_t j = 0; j < m; j++)
                    D(i,j) = A(i+1, j) - A(i,j);
        }

        return D;
    }
}