add_test([=[test_bitmap.test_bitmap]=]  /Users/wu/miscellaneous/courses/miniob/test/case/miniob/build/bin/bitmap_test [==[--gtest_filter=test_bitmap.test_bitmap]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[test_bitmap.test_bitmap]=]  PROPERTIES WORKING_DIRECTORY /Users/wu/miscellaneous/courses/miniob/test/case/miniob/build/unitest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  bitmap_test_TESTS test_bitmap.test_bitmap)
