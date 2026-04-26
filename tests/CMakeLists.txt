find_package(GTest CONFIG REQUIRED)

add_executable(engine_unit_tests)

target_link_libraries(engine_unit_tests PRIVATE Engine GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(engine_unit_tests)
