if(EXISTS "/Users/wu/miscellaneous/courses/miniob/test/case/miniob/build/unitest/pidfile_test[1]_tests.cmake")
  include("/Users/wu/miscellaneous/courses/miniob/test/case/miniob/build/unitest/pidfile_test[1]_tests.cmake")
else()
  add_test(pidfile_test_NOT_BUILT pidfile_test_NOT_BUILT)
endif()
