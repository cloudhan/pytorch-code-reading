#include "torch/torch.h"

#include <iostream>

int main()
{
    auto a = at::ones({32, 32});
    auto b = at::ones({32, 32});
    auto c = a + b;
    std::cout << c << std::endl;

    return 0;
}
