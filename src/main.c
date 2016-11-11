#include "lib_easy.h"
#include <time.h>
int Menu_Main(void) {
	int isgamewon = 0;
	int time = 0;
	int timeup = 0;
	int timeneeded = 500;
	int cheater = 0;
	OSScreenPutFontEx(1, 0, 0, "Welcome to TimingU!");
	OSScreenPutFontEx(1, 0, 1,"(by Coolguy1260 :) )");
	flipBuffers();
	while(1) { 
		//<---put stuff that should run continuously before exiting here--->
		
		updatePressedButtons(); //Update buttons state
		if(isPressed(VPAD_BUTTON_A)) 
		{
			usleep(1000 * 1000);
			while(timeup == 0) {
				ucls();
				OSScreenPutFontEx(1, 0, 0,"Ready...");
				flipBuffers();
				while(timeup == 0) {
					updatePressedButtons();
					if(isPressed(VPAD_BUTTON_A)) {
						cheater = 1;
						ucls();
						OSScreenPutFontEx(1, 0, 0,"You pressed A too early! Auto-lose!");
						flipBuffers();
						usleep(3000 * 1000);
						break;
					}
					if(time == 3000) {
						timeup = 1;
					}
					usleep(1 * 1000);
					time = time + 1;
				}
				ucls();
				time = 0;
				OSScreenPutFontEx(1, 0, 0,"Press A!");
				flipBuffers();
				if(cheater == 0) {
					while(timeup == 0) {
					updatePressedButtons();
					if(isPressed(VPAD_BUTTON_A)) {
						isgamewon = 1;
						break;
					}
					if(time == timeneeded) {
						timeup = 1;
					}
					usleep(1 * 1000);
					time = time + 1;
					}
				}
				ucls();
				if(isgamewon == 1) {
					OSScreenPutFontEx(1, 0, 0,"You won! Time for the next level!");
					flipBuffers();
					timeneeded = timeneeded - 50;
				}
				else {
					OSScreenPutFontEx(1, 0, 0,"Times up!");
					flipBuffers();
				}
				usleep(3000 * 1000);
				isgamewon = 0;
				time = 0;
			}
			timeup = 0;
			timeneeded = 500;
			ucls();
			OSScreenPutFontEx(1, 0, 0, "Welcome to TimingU!");
			OSScreenPutFontEx(1, 0, 1,"(by Coolguy1260 :) )");
			flipBuffers();
		}
		if(isPressed(VPAD_BUTTON_HOME)) break; //Check if home is pressed
	}
	OSScreenPutFontEx(0, 0, 10, "Exiting...");
	flipBuffers();
	return 0;
}