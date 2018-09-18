# ncman

This project aim to provide a simple ncurses interface to control ConnMan through
dbus.

Rewritten from https://github.com/eurogiciel-oss/connman-json-client, which was unmaintained for years. This fork aims for some good batteries, including:
- [ ] Color support
- [x] Better build-system
- [ ] Better code-readability

## Build
### Dependencies
* meson
* gcc
* ncurses
* json-c
* dbus

### Build steps

To build ncman, in the project dir, type
```sh
$ mkdir build
$ cd build
$ meson
$ ninja
```

To run test, simply run this command after running above
```sh
$ ninja test
```

### License
GPLv2
