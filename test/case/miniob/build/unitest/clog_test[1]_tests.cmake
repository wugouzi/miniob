add_test([=[test_clog.test_clog]=]  /Users/wu/miscellaneous/courses/miniob/test/case/miniob/build/bin/clog_test [==[--gtest_filter=test_clog.test_clog]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[test_clog.test_clog]=]  PROPERTIES WORKING_DIRECTORY /Users/wu/miscellaneous/courses/miniob/test/case/miniob/build/unitest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  clog_test_TESTS test_clog.test_clog)
