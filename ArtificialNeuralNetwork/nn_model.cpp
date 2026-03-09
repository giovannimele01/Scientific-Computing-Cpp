//
// 
//

#include "nn_model.h"

la::dense_matrix nn_model::predict(const la::dense_matrix &input_vector) const {
    size_t i = 0;
    la::dense_matrix temp_in(input_vector);
    la::dense_matrix temp_out;
    for( i = 0; i < layers.size() - 1; ++i){
        temp_out = layers[i].eval(temp_in);
        temp_out.swap(temp_in);
    }
    return layers[i].eval(temp_in);
}

void nn_model::add_layer(const layer & l) {

    layers.push_back(l);

}
