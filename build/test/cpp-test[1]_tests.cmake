add_test( OpenCVTest.LoadImage /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test/cpp-test [==[--gtest_filter=OpenCVTest.LoadImage]==] --gtest_also_run_disabled_tests)
set_tests_properties( OpenCVTest.LoadImage PROPERTIES WORKING_DIRECTORY /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test)
add_test( DetectorTest.LoadModelTest /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test/cpp-test [==[--gtest_filter=DetectorTest.LoadModelTest]==] --gtest_also_run_disabled_tests)
set_tests_properties( DetectorTest.LoadModelTest PROPERTIES WORKING_DIRECTORY /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test)
add_test( DetectorTest.CalculateDistanceTest /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test/cpp-test [==[--gtest_filter=DetectorTest.CalculateDistanceTest]==] --gtest_also_run_disabled_tests)
set_tests_properties( DetectorTest.CalculateDistanceTest PROPERTIES WORKING_DIRECTORY /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test)
add_test( DetectorTest.ProcessingTest /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test/cpp-test [==[--gtest_filter=DetectorTest.ProcessingTest]==] --gtest_also_run_disabled_tests)
set_tests_properties( DetectorTest.ProcessingTest PROPERTIES WORKING_DIRECTORY /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test)
add_test( DetectorTest.ImageProcessing /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test/cpp-test [==[--gtest_filter=DetectorTest.ImageProcessing]==] --gtest_also_run_disabled_tests)
set_tests_properties( DetectorTest.ImageProcessing PROPERTIES WORKING_DIRECTORY /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test)
add_test( TrackerTest.TestGetPredictions /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test/cpp-test [==[--gtest_filter=TrackerTest.TestGetPredictions]==] --gtest_also_run_disabled_tests)
set_tests_properties( TrackerTest.TestGetPredictions PROPERTIES WORKING_DIRECTORY /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test)
add_test( TrackerTest.TestGetCoordinates /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test/cpp-test [==[--gtest_filter=TrackerTest.TestGetCoordinates]==] --gtest_also_run_disabled_tests)
set_tests_properties( TrackerTest.TestGetCoordinates PROPERTIES WORKING_DIRECTORY /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test)
add_test( TrackerTest.TestHumanTrack /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test/cpp-test [==[--gtest_filter=TrackerTest.TestHumanTrack]==] --gtest_also_run_disabled_tests)
set_tests_properties( TrackerTest.TestHumanTrack PROPERTIES WORKING_DIRECTORY /home/interns/prim/ENPM808X-Human-Detection-and-Tracking/build/test)
set( cpp-test_TESTS OpenCVTest.LoadImage DetectorTest.LoadModelTest DetectorTest.CalculateDistanceTest DetectorTest.ProcessingTest DetectorTest.ImageProcessing TrackerTest.TestGetPredictions TrackerTest.TestGetCoordinates TrackerTest.TestHumanTrack)