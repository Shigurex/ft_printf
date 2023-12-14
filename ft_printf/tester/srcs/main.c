#include "tester.h"

int	main(void)
{
	setvbuf(stdout, (char *)NULL, _IONBF, 0);

	printf("\n<-------------------------------------------------- [conversion %c] -------------------------------------------------->\n", 'c');
	F("%10c\n", 'a');
	F("%-10c\n", 'a');
	F("%-c\n", 'a');
	F("%1c\n", 'a');
	F("%-c\n", 'a');
	F("%c%c\n", 'a', 'd');
	F("%c \n", 0);

	printf("\n<-------------------------------------------------- [conversion %c] -------------------------------------------------->\n", 's');
	F("%-10.3sa\n", "hello");
	F("%-10.3sa\n", (char *)NULL);
	F("%10.3sa\n", "ewr");
	F("%10.5sa\n", "ewr");
	F("%5.3sa\n", "ewrerew");
	F("%5.0sa\n", "ewrerew");
	F("%0.1sa\n", "ewrerew");
	F("%0.0sa\n", "ewrerew");
	F("%4sa\n", "ewrerew");
	F("%-sa\n", "ewrerew");
	F("%-10sa\n", "ewrerew");
	F("%10.4sa\n", NULL);

	printf("\n<-------------------------------------------------- [conversion %c] -------------------------------------------------->\n", 'x');
	F("%x\n", 42);
	F("%#0x\n", 42);
	F("%#10x\n", 42);
	F("%#01x\n", 42);
	F("%#02x\n", 42);
	F("%x\n", 0);
	F("%#0x\n", 0);
	F("%#10x\n", 0);
	F("%#010x\n", 0);
	F("%#010x\n", 10);
	F("%-#010x\n", 10);
	F("%#10x\n", 10);
	F("%10x\n", 10);
	F("%#01x\n", 0);
	F("%#02x\n", 0);
	F("%#05.2x\n", 110);
	F("%#05.1x\n", 110);
	F("%#05.0x\n", 110);
	F("%#0.0x\n", 110);
	F("%#10.5x\n", 110);
	F("%#4.5x\n", 110);
	F("%#-10.5x\n", 110);
	F("%#02.4x\n", 110);
	F("%#05x\n", 110);
	F("%-4x\n", 16);

	//printf("\n<-------------------------------------------------- [conversion %c] -------------------------------------------------->\n", '%');
	//F("%0%\n");
	//F("%010%\n");
	//F("%04%\n");

	int a;
	int b = 0;
	printf("\n<-------------------------------------------------- [conversion %c] -------------------------------------------------->\n", 'p');
	F("%p\n", NULL);
	F("%p\n", &a);
	F("%p\n", &b);

	//printf("\n<-------------------------------------------------- [conversion %c] -------------------------------------------------->\n", 'u');
	//F("%010.6ua\n", 324);
	//F("%08.6ua\n", 324);
	//F("%8.6ua\n", 324);
	//F("%-8ua\n", 324);
	//F("%04.6ua\n", 324);
	//F("%06.4ua\n", 324);
	//F("%0.4ua\n", 324);
	//F("%06.2ua\n", 324);
	//F("%02.6ua\n", 324);
	//F("%0.6ua\n", 324);
	//F("%6.2ua\n", 324);
	//F("%6.6ua\n", 324);
	//F("%0u\n", 0);
	//F("%u\n", 0);
	//F("%5u\n", 0);
	//F("%.0u\n", 0);
	//F("%.0u\n", 1);
	//F("%-010.6ua\n", 324);
	//F("%-08.6ua\n", 324);
	//F("%-8.6ua\n", 324);
	//F("%-04.6ua\n", 324);
	//F("%-06.4ua\n", 324);
	//F("%-0.4ua\n", 324);
	//F("%010u\n", 1000);
	//F("%010.1u\n", 1000);
	//F("%010.0u\n", 1000);
	//F("%10u\n", 1000);
	//F("%010u\n", 1000);
	//F("%10.0u\n", 1000);
	//F("%+10.0u\n", 1000);
	
	//// F("aa%s%-10caa\n", "hello", 'f');
	//// F("aa%s%100caa\n", "hello", 'f');
	//// F("aa%s%caa\nd", "hello", 'f');
	//// F("aa%10.4s%caa\n", "hello", 'f');
	//// F("%c", '\n');

	//printf("\n<-------------------------------------------------- [conversion %c] -------------------------------------------------->\n", '%');
	//F("%4sa%10%\n", "Hello");
	//F("%4sa%-10%\n", "Hello");
	//F("%4sa%-010%\n", "Hello");
	//F("%4sa%05%\n", "Hello");

	//printf("\n<-------------------------------------------------- [conversion %c] -------------------------------------------------->\n", 'd');
	//F("%5.4d\n", -1000);
	//F("%5.5d\n", -1000);
	//F("%.5d\n", -1000);
	//F("%5.4d\n", 1000);
	//F("%5.5d\n", 1000);
	//F("%.5d\n", 1000);
	//F("%-8d\n", -1000);
	//F("%10.5d\n", 1000);
	//F("% 10.5d\n", 1000);
	//F("% 10d\n", 1000);
	//F("% d\n", 1000);
	//F("% d\n", -1000);
	//F("% +d\n", 1000);
	//F("%+10.5d\n", 1000);
	//F("%+10.7d\n", 1000);
	//F("%+d\n", 0);
	//F("%.0d\n", 0);
	//F("%0d\n", 0);
	//F("%d\n", 0);
	//F("%+d\n", 10);
	//F("%10.7d\n", 1000);

	//system("leaks -q a.out");
	return (0);
}
