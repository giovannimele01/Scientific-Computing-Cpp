//
// 
//

#include "neuron.h"

neuron::neuron(size_t input_size, const ptr_act_function & p_a_f) {
    p_act_func = p_a_f;
    bias = 0;
    weights = la::dense_matrix(input_size,1, 1.0);
}

double neuron::eval(const la::dense_matrix & input_vect) const{
    double res = 0;
    la::dense_matrix res_mtx = (input_vect.transposed())*weights;
    res = res_mtx.data()[0];
    return p_act_func->eval(res + bias);

}
