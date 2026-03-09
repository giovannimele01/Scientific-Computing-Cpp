#include "matrix_assemble.hpp"

namespace la
{
    dense_matrix assemble_cols(const dense_matrix& local_A)
    {
        int rank, size;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);

        unsigned n = local_A.rows();
        unsigned m = local_A.columns();

        dense_matrix A_fin(m*size, n, 0.0);
        dense_matrix A = local_A.transposed();

        MPI_Allgather(A.data(), m*n, MPI_DOUBLE, A_fin.data(), m*n, MPI_DOUBLE, MPI_COMM_WORLD);

        return A_fin.transposed();
    }
}