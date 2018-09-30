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

u8 bg_color(enum VGA_COLOR c1, enum VGA_COLOR c2)
{
	return c1|c2<<4;
}

void clear_src() {
	u32 j=0;
	while(j < src_width*src_height*2)
	{
		buffer[j] = ' ';
		buffer[j+1] = VGA_COLOR_WHITE;
		j = j + 2;
	}
	pos_x=0,pos_y=0;
}
void print(char *str, enum VGA_COLOR color)
{
	u32 j = 0;
	while(str[j] != '\0')
	{
		if(str[j] == '\n')
			pos_y++,pos_x=0;
		else{
			buffer[pos_y*(2*src_width) + pos_x] = str[j];
			buffer[pos_y*(2*src_width) + pos_x + 1] = color;
			pos_x += 2;
			if (pos_x >= 2*src_width)
			{
				++pos_y;
				pos_x %= (2*src_width);
			}
		}
		j++;
	}
}
void init_VGA(void) {
	buffer = (char*)VGA_ADDRESS;
	clear_src();
	print("\ninit VGA\n",bg_color(VGA_COLOR_BLUE,VGA_COLOR_WHITE));
}
