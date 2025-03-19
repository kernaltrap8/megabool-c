megabool_dep = dependency('megabool', required: true)

test_exec = executable('test_program', 
    ['main.c'], 
    dependencies: [megabool_dep]
)

test('megabool_test', test_exec)
