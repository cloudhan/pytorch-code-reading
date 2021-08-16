#include "torch/torch.h"

#include <iostream>

int main()
{
    // lets do a dummy allocation and deallocation
    {
        auto _ = at::empty({1024, 1024});
    }
    return 0;
}
