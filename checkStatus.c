#include <stdio.h>
// #include "returnHubs.h"

void checkStatus(struct hub *hubs){
	printf("inside checkStatus()\n");
	printf("file path: %s\n", hubs[1].hubPath);
	for (int i=0; i<4; i++){
		FILE *testFile = fopen(hubs[i].hubPath, "r");

		if (!testFile){
			printf("file not found."); break;
		}

		char val[256];
		if (fscanf(testFile, "%255s", val) == 1){
			printf("hub 1-%d", hubs[i].id); printf("status: ");
			if (val[0] == 's'){
				printf("char %x", val[0]);
				printf("usb 1-%d", hubs[i].id); printf(" not plugged in.\n");
			}
			else {printf(":)\n");}
		}
	}
}
