
project('ncman', 'c',
  version: '0.0.1',
  meson_version: '>=0.43',
  default_options: 'c_std=c99'
)

version_array = meson.project_version().split('.')

cc = meson.get_compiler('c')

## libs
dbus =		  dependency('dbus-1')
json =		  dependency('json-c')
ncurses =	  dependency('ncurses')
formw =		  dependency('formw')
menuw =		  dependency('menuw')
build_dependencies = [dbus, ncurses, json, formw, menuw]

## flags
flags = [
 '-Wall',
 '-Wextra'
]

## defines
defines = [
  '-DVERSION_MAJOR=@0@'.format(version_array[0]),
  '-DVERSION_MINOR=@0@'.format(version_array[1]),
  '-DVERSION_PATCH=@0@'.format(version_array[2])
]

flags = cc.get_supported_arguments(flags)

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

executable('ncman', 
  sources,
  dependencies: build_dependencies,
  c_args: defines + flags,
  include_directories: inc)

