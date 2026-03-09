#include "matrix_split.hpp"

namespace la {

    dense_matrix split_cols(const dense_matrix& A)
    {
        int rank, size;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);

        unsigned m = A.columns();
        unsigned n = A.rows();

        MPI_Bcast(&m, 1, MPI_UNSIGNED, 0, MPI_COMM_WORLD);
        MPI_Bcast(&n, 1, MPI_UNSIGNED, 0, MPI_COMM_WORLD);

        const unsigned stripes = m / size;

        dense_matrix global_A;

        if(rank == 0)
            global_A = A.transposed();

        dense_matrix local_A(stripes, n, 0.0);

        MPI_Scatter(global_A.data(), stripes*n, MPI_DOUBLE, local_A.data(); stripes*n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        return local_A.transposed();
    }

}