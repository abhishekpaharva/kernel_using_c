#include "display.h"
void kmain(void)
{
	init_VGA();
	char *str = ">>";
	print(str,VGA_COLOR_WHITE);
}
