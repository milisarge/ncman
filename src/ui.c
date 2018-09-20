/*
 *  connman-ncurses
 *
 *  Copyright (C) 2014 Eurogiciel. All rights reserved.
 *  Copyright (C) 2018 l4rzy
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */
#include "ui.h"

#define UI_MINIMUM_LINES 24
#define UI_MINIMUM_COLS  80

/*
 * static variables
 */

static WINDOW *win_body;
static WINDOW *win_footer;

/*
 * save all ui flags in this struct
 */
static struct {
	int mode;
	int dialog;
} flag;

/*
 * initialize all the ui components
 */
int ui_initialize() {
	if (LINES < UI_MINIMUM_LINES || COLS < UI_MINIMUM_COLS) {
		return;
	}

	win_body = newwin(LINES-1, COLS, 0, 0);
	win_footer = newwin(1, COLS, LINES-1, 0);

	if (!win_body && !win_footer) {
		return;
	}


}

static void ui_get_size(int *l, int *c) {
	getmaxyx(stdscr, *l, *c);
}

bool ui_size_ok(void) {
	int l, c;

	ui_get_size(&l, &c);
	if (h < UI_MINIMUM_ ||
			w < UI_MINIMUM_SIZE_W) {
		return false;
	}
	return true;
}
