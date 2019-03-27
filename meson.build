project('ncman', 'c',
  version: '0.0.1',
  meson_version: '>=0.43',
  default_options: 'c_std=c99'
)

cc = meson.get_compiler('c')

## flags
cflags = [
 '-Wall'
]

version_array = meson.project_version().split('.')

## libs
dbus =       dependency('dbus-1')
json =       dependency('json-c')

# prefer wide ncurses library
ncurses =    cc.find_library('ncursesw', required: false)
if ncurses.found()
  cflags += ['-DENABLE_UNICODE']
else
  ncurses =  cc.find_library('ncurses') # failed if not exist
endif

formw =      dependency('formw')
menuw =      dependency('menuw')
build_dependencies = [dbus, ncurses, json, formw, menuw]

## defines
defines = [
  '-DVERSION_MAJOR=@0@'.format(version_array[0]),
  '-DVERSION_MINOR=@0@'.format(version_array[1]),
  '-DVERSION_PATCH=@0@'.format(version_array[2])
]

cflags = cc.get_supported_arguments(cflags)

sources = files(
  'src/agent.c',
  'src/commands.c',
  'src/dbus_helpers.c',
  'src/dbus_json.c',
  'src/engine.c',
  'src/json_regex.c',
  'src/json_utils.c',
  'src/keys.c',
  'src/loop.c',
  'src/main.c',
  #  'src/main_simple_commands.c',
  'src/ncurses_utils.c',
  'src/popup.c',
  'src/renderers.c',
  'src/special_win.c',
  'src/string_utils.c'
)

inc = include_directories('inc')

executable(
  'ncman', 
  sources,
  install: true,
  dependencies: build_dependencies,
  c_args: defines + cflags,
  include_directories: inc
)

#t1 = executable(
#  'test_json_utils',
#  files('test/test_json_utils.c', 'src/json_utils.c', 'src/keys.c'),
#  dependencies: build_dependencies,
#  include_directories: inc
#)

t2 = executable(
  'test_regexp',
  files('test/test_regexp.c', 'src/json_utils.c', 'src/keys.c'),
  dependencies: build_dependencies,
  include_directories: inc
)

#test('Json utilities', t1)
test('Json regexp', t2)
