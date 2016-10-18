add_executable(MPPTNeuralNetworkEmbedded main.c)

add_subdirectory(lib)

target_link_libraries (MPPTNeuralNetworkEmbedded lib)