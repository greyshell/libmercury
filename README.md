# libmercury
A library of common data structures written in C

## Development Notes
- Clone the Unity inside `tests/`
- Update the CMakeLists.txt when adding a data structure
  - creating binary
    - add_library section
    - add_executable section + target_include_directories + target_link_libraries section
  - unit testing
    - - add_library section
    - add_executable section + target_include_directories + target_link_libraries section
    - add_test section