cmake_minimum_required(VERSION 3.18)
project(pytorch_cpp_demo LANGUAGES CXX)

if(NOT Torch_DIR)
    find_package(Python COMPONENTS Interpreter)
    execute_process(COMMAND ${Python_EXECUTABLE} -c "import torch.utils; print(torch.utils.cmake_prefix_path)"
                    OUTPUT_VARIABLE TORCH_CMAKE_PREFIX_PATH
                    OUTPUT_STRIP_TRAILING_WHITESPACE)
    set(Torch_DIR ${TORCH_CMAKE_PREFIX_PATH}/Torch)
endif()


add_compile_options(-finstrument-functions -finstrument-functions-exclude-file-list=/usr/include,/usr/local)

find_package(Torch REQUIRED)
link_libraries(${TORCH_LIBRARIES})
add_executable(aten_cpu_empty "aten_cpu_empty.cpp")
add_executable(aten_cpu_simple "aten_cpu_simple.cpp")
add_executable(aten_gpu_empty "aten_gpu_empty.cpp")
add_executable(aten_gpu_simple "aten_gpu_simple.cpp")
add_executable(aten_gpu_legacy "aten_gpu_legacy.cpp")
