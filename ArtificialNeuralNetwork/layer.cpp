//
// 
//

#include "layer.h"

layer::layer(size_t input_size, size_t output_size, const ptr_act_function &p_a_f): input_size(input_size),output_size(output_size) {
    neuron temp = neuron(get_input_size(),p_a_f);
    for(size_t i = 0; i < get_output_size() ; ++i)
        neurons.push_back(temp);
}

la::dense_matrix layer::eval(const la::dense_matrix & input_vector) const{
    la::dense_matrix output(output_size,1);

    for( size_t i = 0; i < output_size; ++i)
        output.data()[i] = neurons[i].eval(input_vector);

    return output;
}

size_t layer::get_input_size() const {
    return input_size;
}

size_t layer::get_output_size() const {
    return output_size;
}
