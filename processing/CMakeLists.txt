function(osqoop_processing_plugin _target)
    add_definitions(-DQT_PLUGIN)
    add_library(${_target} MODULE "${_target}/${_target}.cpp")
    add_definitions(-DQT_PLUGIN)
    target_link_libraries(${_target} processing Qt5::Widgets Qt5::Core)
    install(TARGETS ${_target} DESTINATION share/osqoop/processing)
endfunction()

add_subdirectory(lib)
include_directories (${CMAKE_SOURCE_DIR}/src)
include_directories (${CMAKE_SOURCE_DIR}/processing/lib)

osqoop_processing_plugin(Abs)
osqoop_processing_plugin(ProcessingBandPass2ndOrderFilter)
osqoop_processing_plugin(Const)
osqoop_processing_plugin(CropBelowLevel)
osqoop_processing_plugin(Delay)
osqoop_processing_plugin(Div)
osqoop_processing_plugin(EMGEnvelope)
osqoop_processing_plugin(EMGMouseBackpropNNClassifier)
osqoop_processing_plugin(Gain)
osqoop_processing_plugin(Greater)
osqoop_processing_plugin(IIR2ndOrderFilter)
osqoop_processing_plugin(Mult)
osqoop_processing_plugin(Negate)
osqoop_processing_plugin(Pow)
osqoop_processing_plugin(Sum)
osqoop_processing_plugin(XYMode)

find_path(XTEST_INCLUDE_DIR X11/extensions/XTest.h)
if (XTEST_INCLUDE_DIR)
    osqoop_processing_plugin(VirtualMouse)
endif()

if (FFTW_FOUND)
        include_directories (${FFTW_INCLUDE_DIR} ${CMAKE_BINARY_DIR}/processing/SpectroGraph)
        add_library(SpectroGraph MODULE SpectroGraph/SpectroGraph.cpp)
        target_link_libraries(SpectroGraph ${FFTW_LIBRARIES} Qt5::Core Qt5::Widgets)
        install(TARGETS SpectroGraph DESTINATION share/osqoop/processing)
endif (FFTW_FOUND)
