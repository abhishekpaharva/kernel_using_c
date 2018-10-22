#include "system.h"
#include "types.h"

void starting() {

	char *str1 = "\t\t\t\t\t                     ____   ____\n";
	char *str2 = "\t\t\t\t\t||      || | ||   | (    ) (    )\n";
	char *str3 = "\t\t\t\t\t| |    | | | | |  | (    ) (____\n";
  	char *str4 = "\t\t\t\t\t|  |  |  | | |  | | (    )      )\n";
	char *str5 = "\t\t\t\t\t|   ||   | | |   || (____) (____)\n";
	char *str6 = "\t\t\t\t\t---------------------------------\n";
	print(str1);
	print(str2);
	print(str3);
	print(str4);
	print(str5);
	print(str6);

}

void kmain(void) {

	init_VGA();
	idt_init();
	kb_init();
	starting();
	print(">>>");

	while(true);

}
