# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(handshakeTests LANGUAGES CXX)

# ---- Tests ----

add_executable(handshake_test source/handshake_test.cpp)
target_link_libraries(handshake_test PRIVATE handshake_lib)
target_compile_features(handshake_test PRIVATE cxx_std_17)

add_test(NAME handshake_test COMMAND handshake_test)

# ---- End-of-file commands ----

add_folders(Test)
