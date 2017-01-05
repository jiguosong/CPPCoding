add_executable(para_accum para_accumulator.cpp)
set_target_properties(para_accum PROPERTIES COMPILE_FLAGS -pthread LINK_FLAGS -pthread)