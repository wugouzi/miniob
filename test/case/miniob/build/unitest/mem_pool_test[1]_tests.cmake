add_test([=[test_mem_pool_item.test_mem_pool_item_basic]=]  /Users/wu/miscellaneous/courses/miniob/test/case/miniob/build/bin/mem_pool_test [==[--gtest_filter=test_mem_pool_item.test_mem_pool_item_basic]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[test_mem_pool_item.test_mem_pool_item_basic]=]  PROPERTIES WORKING_DIRECTORY /Users/wu/miscellaneous/courses/miniob/test/case/miniob/build/unitest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  mem_pool_test_TESTS test_mem_pool_item.test_mem_pool_item_basic)
