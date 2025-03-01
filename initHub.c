 	#include <stdio.h>
 	#include <string.h>
 	#include <stdlib.h>
 	#include "returnHubs.h"
 	
 	char lastPath[21] = "/power/runtime_status"; 
 	char *hubNums[4];
 	char *path[4];
 	
 	void initializeHubs(struct hub *hubby) {
 		for (int i=0; i<4; i++){
 			char firstPath[30] = "/sys/bus/usb/devices/1-1.";
 			hubby[i].id = i+1;
 			
 			sprintf(firstPath + strlen(firstPath), "%d", (i+1));
 			
 			hubNums[i] = malloc(50); // allocates 50 byte block for each array
 			
 			strcpy(hubNums[i], firstPath);
 			strcat(hubNums[i], lastPath);
 		}
 		
 		for (int j=0; j<4; j++) {
 			memcpy(hubby[j].hubPath, hubNums[j], 50);
 		}
 	}
 	
