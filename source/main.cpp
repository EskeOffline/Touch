#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv) {
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	while (aptMainLoop())
	{
		hidScanInput();
		
		touchPosition touch;
		hidTouchRead(&touch);
		printf("\x1b[3;1HX coordinate: %i       ",touch.px);
		printf("\x1b[4;1HY coordinate: %i       ",touch.py);

		u32 kHeld = hidKeysHeld();
		if (kHeld & KEY_TOUCH)
			printf("\x1b[2;1HIs Active: TRUE ");
		else
			printf("\x1b[2;1HIs Active: FALSE");

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START) break;

		gfxFlushBuffers();
		gfxSwapBuffers();
		
		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
