#include "torch/torch.h"

#include <iostream>

int main()
{
    auto opt = at::TensorOptions().device(at::kCUDA);
    // lets do a dummy allocation and deallocation
    {
        auto _ = at::empty({1024, 1024}, opt);
    }

    return 0;
}
