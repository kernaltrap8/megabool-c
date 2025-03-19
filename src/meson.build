megabool_lib = library('megabool', 
    ['megabool.c'], 
    install: true,
    version: '1.0.0',
    soversion: '1'
)

install_headers('megabool.h')

megabool_dep = declare_dependency(
    include_directories: include_directories('.'),
    link_with: megabool_lib
)

meson.override_dependency('megabool', megabool_dep)
