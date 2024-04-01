# templatepp

My C++ project template

## Features

### CMake targets

- `thezhe::templatepp` - core library

### Artifacts

- `**/templatepp_<os>.zip` - test executable

## Usage

```CMake
# CMakeLists.txt

include(FetchContent)
FetchContent_Declare(
    templatepp
    GIT_REPOSITORY https://github.com/thezhe/templatepp.git
    GIT_TAG <tag>
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(templatepp)
```

## Versioning

- Tags - stable SemVer
- `main` branch - unstable
