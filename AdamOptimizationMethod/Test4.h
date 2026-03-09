unsigned int dim_samples = 50;

std::vector<double> noises = generate_noise(dim_samples, 21111998, 0.001);

std::default_random_engine generator(21111998);
std::uniform_real_distribution<double> distribution1(-5.0,5.0);
std::uniform_real_distribution<double> distribution2(-8.0,2.0);

std::vector<double> x_, y_, z_;
double x, y, z;

for (std::size_t i = 0; i < dim_samples; ++i){

    x = distribution1(generator);
    x_.push_back(x);

    y = distribution2(generator);
    y_.push_back(y);

    z = -4*x*x*y + 2*x*y*y*y + 5*x - y + 3 + noises[i];
    z_.push_back(z);

}

std::vector<Monomial> monomials; //
monomials.push_back (Monomial (1, {4, 2, 0}, {2, 0, 0, 0, 0}));
monomials.push_back (Monomial (1, {2, 6, 0}, {0, 2, 0, 0, 0}));
monomials.push_back (Monomial (1, {2, 0, 0}, {0, 0, 2, 0, 0}));
monomials.push_back (Monomial (1, {0, 2, 0}, {0, 0, 0, 2, 0}));
monomials.push_back (Monomial (1, {0, 0, 0}, {0, 0, 0, 0, 2}));
monomials.push_back (Monomial (1, {0, 0, 2}, {0, 0, 0, 0, 0}));
monomials.push_back (Monomial (2, {3, 4, 0}, {1, 1, 0, 0, 0}));
monomials.push_back (Monomial (2, {3, 1, 0}, {1, 0, 1, 0, 0}));
monomials.push_back (Monomial (2, {2, 2, 0}, {1, 0, 0, 1, 0}));
monomials.push_back (Monomial (2, {2, 1, 0}, {1, 0, 0, 0, 1}));
monomials.push_back (Monomial (-2, {2, 1, 1}, {1, 0, 0, 0, 0}));
monomials.push_back (Monomial (2, {2, 3, 0}, {0, 1, 1, 0, 0}));
monomials.push_back (Monomial (2, {1, 4, 0}, {0, 1, 0, 1, 0}));
monomials.push_back (Monomial (2, {1, 3, 0}, {0, 1, 0, 0, 1}));
monomials.push_back (Monomial (-2, {1, 3, 1}, {0, 1, 0, 0, 0}));
monomials.push_back (Monomial (2, {1, 1, 0}, {0, 0, 1, 1, 0}));
monomials.push_back (Monomial (2, {1, 0, 0}, {0, 0, 1, 0, 1}));
monomials.push_back (Monomial (-2, {1, 0, 1}, {0, 0, 1, 0, 0}));
monomials.push_back (Monomial (2, {0, 1, 0}, {0, 0, 0, 1, 1}));
monomials.push_back (Monomial (-2, {0, 1, 1}, {0, 0, 0, 1, 0}));
monomials.push_back (Monomial (-2, {0, 0, 1}, {0, 0, 0, 0, 1}));


FunctionRn f(monomials);

std::vector<Point> observations;

for (std::size_t i = 0; i < dim_samples; ++i)
    observations.push_back(Point({x_[i], y_[i], z_[i]}));

std::vector<double> inf_limits = {-5.0, 1.0, 4.0, -2.0, 2.0};
std::vector<double> sup_limits = {-3.0, 3.0, 6.0, 0.0, 4.0};
std::vector<double> initial_parameters_ = {-3.1, 2.4, 4.1, -1.7, 2.4};

Point exact_solution({-4, 2, 5, -1, 3});

const double tolerance = 1e-10;
const unsigned int max_iterations = 1e6;