if(EXISTS "/Users/wu/miscellaneous/courses/miniob/test/case/miniob/build/unitest/persist_test[1]_tests.cmake")
  include("/Users/wu/miscellaneous/courses/miniob/test/case/miniob/build/unitest/persist_test[1]_tests.cmake")
else()
  add_test(persist_test_NOT_BUILT persist_test_NOT_BUILT)
endif()
