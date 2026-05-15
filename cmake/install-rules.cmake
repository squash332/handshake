install(
    TARGETS handshake_exe
    RUNTIME COMPONENT handshake_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
