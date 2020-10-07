cmake_minimum_required(VERSION 3.10.2)

project("Thread Pool Manager")

enable_testing()

add_executable(
    thread_pool_manager
    Main.cc 
    ThreadPoolManager.cc
    )

add_test(TPM_TEST thread_pool_manager)

