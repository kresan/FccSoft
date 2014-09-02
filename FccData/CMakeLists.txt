 # Create a library called "libFccData" 

set(INCLUDE_DIRECTORIES
${ROOT_INCLUDE_DIR} 
${BASE_INCLUDE_DIRECTORIES}
${CMAKE_SOURCE_DIR}/FccData
)

include_directories( ${INCLUDE_DIRECTORIES})

set(LINK_DIRECTORIES
${ROOT_LIBRARY_DIR}
${FAIRROOT_LIBRARY_DIR}
${CMAKE_SOURCE_DIR}/FccData

)
 
link_directories( ${LINK_DIRECTORIES})

set(SRCS
FccStack.cxx 
FccMCTrack.cxx
)

Set(HEADERS )
Set(LINKDEF MCStackLinkDef.h)
Set(LIBRARY_NAME FccData)
Set(DEPENDENCIES Base EG Physics Cint Core)

GENERATE_LIBRARY()

