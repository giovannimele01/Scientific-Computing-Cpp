//
// 
//

#include "Adam.h"
#include <cmath>


std::vector<int> Adam::create_batch() {

    std::vector<int> indices;

    for (std::size_t i = 0; i < dim_batch; ++i)
        indices.push_back(distribution(generator));

    return indices;

}


double Adam::evaluate_batch(const Point &parameters, const std::vector<int> & batch) const {

    double value = 0.0;

    for (const auto i : batch)
        value += f.evaluate(observations[i], parameters);

    return value / batch.size();

}


double Adam::evaluate_partial_derivative_batch(std::size_t j, const Point &parameters, const std::vector<int> & batch) const {

    double value = 0.0;

    for(const auto i : batch) {
        value += f.evaluate_partial_derivative(j, observations[i], parameters);
    }

    return value / batch.size();

}


void Adam::set_f(const FunctionRn &f_) {

    f = f_;

}


void Adam::set_observations(const std::vector<Point> &observations_) {

    observations = observations_;

}


void Adam::set_dim_batch(unsigned int dim_batch_) {

    dim_batch = dim_batch_;

}


void Adam::set_tolerance(double tolerance_) {

    tolerance = tolerance_;

}


void Adam::set_max_iterations(unsigned int max_iterations_) {

    max_iterations = max_iterations_;

}


void Adam::set_inf_limits(const std::vector<double> &inf_limits_) {

    inf_limits = inf_limits_;

}


void Adam::set_sup_limits(const std::vector<double> &sup_limits_) {

    sup_limits = sup_limits_;

}


const FunctionRn & Adam::get_f() const {

    return f;

}


const std::vector<Point> & Adam::get_observations() const {

    return observations;

}


unsigned int Adam::get_dim_batch() const {

    return dim_batch;

}


double Adam::get_tolerance() const {

    return tolerance;

}


unsigned int Adam::get_max_iterations() const {

    return max_iterations;

}


const std::vector<double> & Adam::get_inf_limits() const {

    return inf_limits;

}


const std::vector<double> & Adam::get_sup_limits() const {

    return sup_limits;

}


Point Adam::solve(const Point &initial_parameters) {

    Point theta0 (initial_parameters.get_coordinates());
    Point theta1 (initial_parameters.get_coordinates());

    bool converged = false;
    double distance = 1.0;
    double value_f = 1.0;

    unsigned int t = 0; // step number

    std::vector<double> m0(initial_parameters.get_dimension(), 0.0);
    std::vector<double> mt(initial_parameters.get_dimension(), 0.0);
    std::vector<double> v0(initial_parameters.get_dimension(), 0.0);
    std::vector<double> vt(initial_parameters.get_dimension(), 0.0);

    while (t < max_iterations and !converged){
        t += 1;
        std::vector<int> batch = create_batch();

        for (std::size_t j = 0; j < initial_parameters.get_dimension(); ++j){

            double gt = evaluate_partial_derivative_batch(j, theta0, batch);

            mt[j] = gamma1*m0[j] + (1-gamma1)*gt;
            vt[j] = gamma2*v0[j] + (1-gamma2)*gt*gt;

            double mt_hat = mt[j] / (1-pow(gamma1,t));
            double vt_hat = vt[j] / (1-pow(gamma2, t));

            double thetat = theta0.get_coordinate(j)-alpha*mt_hat/(sqrt(vt_hat)+epsilon);

            if (gt > 0)
                theta1.set_coordinate(j, std::max(inf_limits[j], thetat));
            else
                theta1.set_coordinate(j, std::min(sup_limits[j], thetat));
        }

        m0 = mt;
        v0 = vt;

        // Check convergence
        distance = theta1.distance(theta0);
        value_f = evaluate_batch(theta0, batch) - evaluate_batch(theta1, batch);
        if (distance < tolerance or std::abs(value_f) < tolerance)
            converged = true;

        theta0.set_coordinates(theta1.get_coordinates());

    }

    std::cout << "Iterations: " << t << ", distance = " << distance << ", value_f = " << value_f << std::endl;

    return theta0;

}
