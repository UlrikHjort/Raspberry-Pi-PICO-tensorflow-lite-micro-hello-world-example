cmake_minimum_required(VERSION 3.5)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
project(tfl_micro_pico C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

file(GLOB_RECURSE srcs
                  model/hello_world/*cc
                  tensorflow/lite/c/*.cc
                  tensorflow/lite/core/*.cc
                  tensorflow/lite/micro/*.cc
                  tensorflow/lite/schema/*.cc
                  tensorflow/lite/kernels/*.cc                  
                  )
                  
add_executable(${PROJECT_NAME} ${srcs})

target_include_directories(${PROJECT_NAME} PUBLIC
  tensorflow/lite/
  tensorflow/lite/core/
  tensorflow/lite/micro/                  
  tensorflow/lite/schema/
  tensorflow/lite/kernels/                  
  model/hello_world/
  third_party/flatbuffers/include/
  third_party/gemmlowp/
  third_party/ruy/
  ${CMAKE_CURRENT_SOURCE_DIR}
  )


pico_add_extra_outputs(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} pico_stdlib)


pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

