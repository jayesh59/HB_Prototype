# CMake generated Testfile for 
# Source directory: /home/hb-jetson/camera_ws/src/image_geometry/test
# Build directory: /home/hb-jetson/camera_ws/build/image_geometry/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_image_geometry_nosetests_directed.py "/home/hb-jetson/camera_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python3" "/home/hb-jetson/ros_noetic_source/install_isolated/share/catkin/cmake/test/run_tests.py" "/home/hb-jetson/camera_ws/build/test_results/image_geometry/nosetests-directed.py.xml" "--return-code" "\"/usr/bin/cmake\" -E make_directory /home/hb-jetson/camera_ws/build/test_results/image_geometry" "/usr/bin/nosetests3 -P --process-timeout=60 /home/hb-jetson/camera_ws/src/image_geometry/test/directed.py --with-xunit --xunit-file=/home/hb-jetson/camera_ws/build/test_results/image_geometry/nosetests-directed.py.xml")
add_test(_ctest_image_geometry_gtest_image_geometry-utest "/home/hb-jetson/camera_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python3" "/home/hb-jetson/ros_noetic_source/install_isolated/share/catkin/cmake/test/run_tests.py" "/home/hb-jetson/camera_ws/build/test_results/image_geometry/gtest-image_geometry-utest.xml" "--return-code" "/home/hb-jetson/camera_ws/devel/lib/image_geometry/image_geometry-utest --gtest_output=xml:/home/hb-jetson/camera_ws/build/test_results/image_geometry/gtest-image_geometry-utest.xml")
add_test(_ctest_image_geometry_gtest_image_geometry-utest-equi "/home/hb-jetson/camera_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python3" "/home/hb-jetson/ros_noetic_source/install_isolated/share/catkin/cmake/test/run_tests.py" "/home/hb-jetson/camera_ws/build/test_results/image_geometry/gtest-image_geometry-utest-equi.xml" "--return-code" "/home/hb-jetson/camera_ws/devel/lib/image_geometry/image_geometry-utest-equi --gtest_output=xml:/home/hb-jetson/camera_ws/build/test_results/image_geometry/gtest-image_geometry-utest-equi.xml")