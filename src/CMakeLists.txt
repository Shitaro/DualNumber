add_executable(${PROJECT_NAME}
  ${MY_SRCS}
  )

target_include_directories(${PROJECT_NAME} PUBLIC
  ${eigen_INCLUDE_PATH}
  ${MY_INCLUDE_PATH}
)
