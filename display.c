#include "system.h"
#include "types.h"
#define VGA_ADDRESS 0xB8000
#define src_width 80
#define src_height 25

char *buffer;
u32 pos_x,pos_y;

enum VGA_COLOR {

	VGA_COLOR_BLACK = 0x00,
	VGA_COLOR_BLUE = 0x01,
	VGA_COLOR_GREEN  = 0x02,
	VGA_COLOR_CYAN = 0x03,
	VGA_COLOR_RED = 0x04,
	VGA_COLOR_MAGENTA = 0x05,
	VGA_COLOR_BROWN = 0x06,
	VGA_COLOR_LIGHT_GREY = 0x7,
	VGA_COLOR_DARK_GREY = 0x08,
	VGA_COLOR_LIGHT_BLUE = 0x09,
	VGA_COLOR_LIGHT_GREEN = 0x0A,
	VGA_COLOR_LIGHT_CYAN = 0x0B,
	VGA_COLOR_LIGHT_RED = 0x0C,
	VGA_COLOR_LIGHT_MAGENTA = 0x0D,
	VGA_COLOR_LIGHT_BROWN = 0x0E,
	VGA_COLOR_WHITE = 0x0F

};

enum VGA_COLOR color;

void set_color(enum VGA_COLOR c) {

	color = c;

}

void set_bg_color(enum VGA_COLOR c) {

	color = color|c<<4;

}

void printch(char ch) {

	int idx = pos_y*(2*src_width) + pos_x;

	if(ch == '\n') {

		pos_x = 0;
		pos_y++;

	}

	else if(ch == '\b')	{

		if(pos_x != 0) {

			buffer[idx - 2] = VGA_COLOR_BLACK;
			pos_x -= 2;

		}

	}

	else if(ch == '\t')	{

		pos_x = (pos_x + 8);

		if(pos_x >= 2*src_width) {

			pos_x %= 2*src_width;
			pos_y++;

		}

	}

	else if(ch == '\r') {

		pos_x = 0;

	}

	else {

		buffer[idx] = ch;
		buffer[idx + 1] = color;

		pos_x += 2;

		if (pos_x >= 2*src_width) {

			++pos_y;
			pos_x %= (2*src_width);

		}

	}

	if(pos_y > 24)
		pos_y = 0;

}

void print(char *str) {

	for(u32 i = 0; str[i] != '\0'; i++) {

		printch(str[i]);

	}

}

void clear_src() {

	for(u32 i = 0; i < src_width*src_height*2; i += 2) {

		buffer[i] = ' ';
		buffer[i+1] = VGA_COLOR_BLACK;

	}

	pos_x = 0;
	pos_y = 0;

}

void init_VGA() {

	buffer = (char*)VGA_ADDRESS;
	clear_src();
	set_color(VGA_COLOR_LIGHT_GREY);
	set_bg_color(VGA_COLOR_BLACK);

}
