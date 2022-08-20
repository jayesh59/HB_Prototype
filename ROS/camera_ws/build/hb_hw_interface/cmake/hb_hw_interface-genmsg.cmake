# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "hb_hw_interface: 2 messages, 0 services")

set(MSG_I_FLAGS "-Ihb_hw_interface:/home/hb-jetson/camera_ws/src/hb_hw_interface/msg;-Istd_msgs:/home/hb-jetson/ros_noetic_source/install_isolated/share/std_msgs/cmake/../msg;-Isensor_msgs:/home/hb-jetson/ros_noetic_source/install_isolated/share/sensor_msgs/cmake/../msg;-Igeometry_msgs:/home/hb-jetson/ros_noetic_source/install_isolated/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(hb_hw_interface_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/position_cmd.msg" NAME_WE)
add_custom_target(_hb_hw_interface_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "hb_hw_interface" "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/position_cmd.msg" ""
)

get_filename_component(_filename "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/state_update.msg" NAME_WE)
add_custom_target(_hb_hw_interface_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "hb_hw_interface" "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/state_update.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(hb_hw_interface
  "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/position_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/hb_hw_interface
)
_generate_msg_cpp(hb_hw_interface
  "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/state_update.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/hb_hw_interface
)

### Generating Services

### Generating Module File
_generate_module_cpp(hb_hw_interface
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/hb_hw_interface
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(hb_hw_interface_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(hb_hw_interface_generate_messages hb_hw_interface_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/position_cmd.msg" NAME_WE)
add_dependencies(hb_hw_interface_generate_messages_cpp _hb_hw_interface_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/state_update.msg" NAME_WE)
add_dependencies(hb_hw_interface_generate_messages_cpp _hb_hw_interface_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(hb_hw_interface_gencpp)
add_dependencies(hb_hw_interface_gencpp hb_hw_interface_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS hb_hw_interface_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(hb_hw_interface
  "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/position_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/hb_hw_interface
)
_generate_msg_eus(hb_hw_interface
  "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/state_update.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/hb_hw_interface
)

### Generating Services

### Generating Module File
_generate_module_eus(hb_hw_interface
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/hb_hw_interface
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(hb_hw_interface_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(hb_hw_interface_generate_messages hb_hw_interface_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/position_cmd.msg" NAME_WE)
add_dependencies(hb_hw_interface_generate_messages_eus _hb_hw_interface_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/state_update.msg" NAME_WE)
add_dependencies(hb_hw_interface_generate_messages_eus _hb_hw_interface_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(hb_hw_interface_geneus)
add_dependencies(hb_hw_interface_geneus hb_hw_interface_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS hb_hw_interface_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(hb_hw_interface
  "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/position_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/hb_hw_interface
)
_generate_msg_lisp(hb_hw_interface
  "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/state_update.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/hb_hw_interface
)

### Generating Services

### Generating Module File
_generate_module_lisp(hb_hw_interface
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/hb_hw_interface
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(hb_hw_interface_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(hb_hw_interface_generate_messages hb_hw_interface_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/position_cmd.msg" NAME_WE)
add_dependencies(hb_hw_interface_generate_messages_lisp _hb_hw_interface_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/state_update.msg" NAME_WE)
add_dependencies(hb_hw_interface_generate_messages_lisp _hb_hw_interface_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(hb_hw_interface_genlisp)
add_dependencies(hb_hw_interface_genlisp hb_hw_interface_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS hb_hw_interface_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(hb_hw_interface
  "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/position_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/hb_hw_interface
)
_generate_msg_nodejs(hb_hw_interface
  "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/state_update.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/hb_hw_interface
)

### Generating Services

### Generating Module File
_generate_module_nodejs(hb_hw_interface
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/hb_hw_interface
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(hb_hw_interface_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(hb_hw_interface_generate_messages hb_hw_interface_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/position_cmd.msg" NAME_WE)
add_dependencies(hb_hw_interface_generate_messages_nodejs _hb_hw_interface_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/state_update.msg" NAME_WE)
add_dependencies(hb_hw_interface_generate_messages_nodejs _hb_hw_interface_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(hb_hw_interface_gennodejs)
add_dependencies(hb_hw_interface_gennodejs hb_hw_interface_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS hb_hw_interface_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(hb_hw_interface
  "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/position_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hb_hw_interface
)
_generate_msg_py(hb_hw_interface
  "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/state_update.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hb_hw_interface
)

### Generating Services

### Generating Module File
_generate_module_py(hb_hw_interface
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hb_hw_interface
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(hb_hw_interface_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(hb_hw_interface_generate_messages hb_hw_interface_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/position_cmd.msg" NAME_WE)
add_dependencies(hb_hw_interface_generate_messages_py _hb_hw_interface_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/hb-jetson/camera_ws/src/hb_hw_interface/msg/state_update.msg" NAME_WE)
add_dependencies(hb_hw_interface_generate_messages_py _hb_hw_interface_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(hb_hw_interface_genpy)
add_dependencies(hb_hw_interface_genpy hb_hw_interface_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS hb_hw_interface_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/hb_hw_interface)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/hb_hw_interface
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(hb_hw_interface_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(hb_hw_interface_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(hb_hw_interface_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/hb_hw_interface)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/hb_hw_interface
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(hb_hw_interface_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(hb_hw_interface_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(hb_hw_interface_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/hb_hw_interface)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/hb_hw_interface
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(hb_hw_interface_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(hb_hw_interface_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(hb_hw_interface_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/hb_hw_interface)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/hb_hw_interface
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(hb_hw_interface_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(hb_hw_interface_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(hb_hw_interface_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hb_hw_interface)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hb_hw_interface\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hb_hw_interface
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(hb_hw_interface_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(hb_hw_interface_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(hb_hw_interface_generate_messages_py geometry_msgs_generate_messages_py)
endif()
