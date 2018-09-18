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

In the project dir, type
```sh
$ meson
$ mkdir build
$ cd build
$ ninja
```
### License
GPLv2
