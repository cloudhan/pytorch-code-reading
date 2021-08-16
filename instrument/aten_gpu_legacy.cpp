#include "torch/torch.h"

#include <iostream>

int main()
{
    auto opt = at::TensorOptions().dtype(at::kFloat).device(at::kCUDA);
    auto a = at::ones({32, 32}, opt);
    auto b = at::glu(a);
    std::cout << b << std::endl;

    return 0;
}
