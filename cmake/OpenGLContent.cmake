function(find_and_link library)
  if (NOT TARGET ${library})
    find_package(${library} REQUIRED)
    if (NOT ${library}_FOUND)
      message(FATAL_ERROR "${library} not found")
    endif()
  endif()
endfunction()