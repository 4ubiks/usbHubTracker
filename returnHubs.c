#include <stdio.h>
#include "initHub.c"
#include "constants.h"
#include "checkStatus.c"

int main(){
	struct hub hubs[4];
	FILE *testFile = fopen("/sys/bus/usb/devices/1-1/power/runtime_status", "r");
	//printf("test: %d\n", hub1.id);

	if (!testFile){
		printf("file not found.");
		return 0;
	}

	char val[256];
	if (fscanf(testFile, "%255s", val) == 1){
		printf("hub 1-1 status: %s\n", val);
		if (val[0] == 's') {
			printf("char %x\n", val[0]);
			printf("usb 1-1 not plugged in.\n");
		}
		else {printf("yay\n");}
	}	

	initializeHubs(hubs);
	for (int i=0; i<4; i++){
		printf("print from main: %s\n", hubs[i].hubPath);
	}
	checkStatus(hubs);
	
}
