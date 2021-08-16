#include "torch/torch.h"

#include <iostream>

int main()
{
    auto opt = at::TensorOptions().device(at::kCUDA);
    auto a = at::ones({32, 32}, opt);
    auto b = at::ones({32, 32}, opt);
    auto c = a + b;
    std::cout << c << std::endl;

    return 0;
}
