#include <stdio.h>
// #include "returnHubs.h"

void checkStatus(struct hub *hubs){
	printf("\n\n-------inside checkStatus.c------\n");
	printf("hello?");
    printf("file path: %s\n", hubs[1].hubPath);
	for (int i=0; i<4; i++){
		printf("hi");
		FILE *testFile = fopen(hubs[i].hubPath, "r");
		if (!testFile){
			printf("file not found.");
		}
		// current issue, 3.1.25:
		// can only see directory 1-1.1, not any of the others. but gets to the others,
		// as the terminal visibly prints the filepath for 1-1.2

		char val[256];
		if (fscanf(testFile, "%255s", val) == 1){
			printf("the id: %d, ", hubs[i].id);
			printf("hub 1-1.%d", hubs[i].id); printf("status: ");
			
			if (val[0] == 's'){
				printf("char %x", val[0]);
				printf("usb 1-1.%d", hubs[i].id); printf(" not plugged in.\n");
			}
			else {printf(":)\n");}
		}
	}
}
