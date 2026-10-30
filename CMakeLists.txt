cmake_minimum_required(VERSION 3.20)
project(cocomo_cli_estimator C)

set(CMAKE_C_STANDARD 99)

# Aponta para o arquivo dentro do subdiretório src
add_executable(cocomo_cli_estimator src/main.c)

# Vincula a biblioteca matemática para ambientes baseados em Linux/GCC
if(UNIX)
    target_link_libraries(cocomo_cli_estimator m)
endif()