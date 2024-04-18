

#include <katsu/kt.h>
#include <stdio.h>
#include <GL/gl.h>


/*Test Sprite Palette*/
const u32 spr_palette[16] = {
	0x408080, 0x2F2F2F, 0x5F5F5F, 0x9F9F9F, 0xDFDFDF, 0xFFFFFF,
	0x085242, 0x188E10, 0x7BCE31, 0xC6E79C, 0x000060, 0x00399C,
	0x527BDE, 0xB5C6F7, 0xF1F0FF, 0x000000
};

/*Test Sprite Tiles*/
const u8 spr_tiles[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x32, 0x33, 0x00, 0x20, 0x43, 0x55, 0x03,
    0x21, 0x43, 0x55, 0x24, 0x21, 0x33, 0x44, 0x23,
    0x2f, 0x32, 0x33, 0x13, 0x1f, 0x22, 0x22, 0x12,
    0xf0, 0x21, 0x22, 0x01, 0x00, 0xff, 0xff, 0x00,
    0x00, 0x60, 0x77, 0x77, 0x00, 0x76, 0x88, 0x99,
    0x60, 0x86, 0x76, 0x77, 0x76, 0x78, 0x76, 0x77,
    0x86, 0x87, 0x66, 0x66, 0x86, 0x6f, 0x79, 0x66,
    0x86, 0xff, 0x98, 0x59, 0x76, 0x68, 0x88, 0x88,
    0x77, 0x77, 0x06, 0x00, 0x99, 0x88, 0x67, 0x00,
    0x77, 0x67, 0x68, 0x06, 0x77, 0x67, 0x87, 0x67,
    0x66, 0x66, 0x78, 0x68, 0x66, 0x97, 0xf6, 0x68,
    0x95, 0x89, 0xff, 0x68, 0x88, 0x88, 0x86, 0x67,
    0xf0, 0x68, 0x87, 0x88, 0xf0, 0x78, 0x77, 0x88,
    0x00, 0x8f, 0x77, 0x88, 0x00, 0xf0, 0x7f, 0x77,
    0x00, 0x00, 0x6f, 0x77, 0x00, 0x00, 0xf0, 0x77,
    0x00, 0x00, 0xff, 0x86, 0x00, 0x00, 0xf0, 0xff,
    0x88, 0x78, 0x86, 0x0f, 0x88, 0x77, 0x87, 0x0f,
    0x88, 0x77, 0xf8, 0x00, 0x77, 0xf7, 0x0f, 0x00,
    0x77, 0xf6, 0x00, 0x00, 0x77, 0x0f, 0x00, 0x00,
    0x68, 0xff, 0x00, 0x00, 0xff, 0x0f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcc,
    0x00, 0x00, 0xd0, 0xee, 0x00, 0x00, 0x5d, 0xee,
    0x00, 0xc0, 0xe5, 0xee, 0x00, 0xc0, 0xe5, 0xee,
    0x00, 0xc0, 0x55, 0xee, 0x00, 0xdb, 0x55, 0x55,
    0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0xce, 0x0c, 0x00, 0x00, 0xee, 0xbe, 0x00, 0x00,
    0xee, 0xee, 0x0a, 0x00, 0xe5, 0xee, 0xae, 0x00,
    0x55, 0xe5, 0xde, 0x0a, 0x55, 0xe5, 0xce, 0x0b,
    0x00, 0xeb, 0x55, 0x55, 0xb0, 0xec, 0x5e, 0x55,
    0xeb, 0xec, 0xee, 0x55, 0xeb, 0xed, 0xde, 0xee,
    0x5b, 0xed, 0xed, 0xee, 0xeb, 0xde, 0xed, 0x55,
    0x5b, 0xde, 0x5c, 0xde, 0x5a, 0xe5, 0xec, 0xdd,
    0xe5, 0x5e, 0xcd, 0xac, 0x55, 0xe5, 0xcc, 0xac,
    0xe5, 0xcd, 0xbc, 0xac, 0xdd, 0xcc, 0xbb, 0xfc,
    0xce, 0xcc, 0xbb, 0xfb, 0xde, 0xdc, 0xbd, 0xfb,
    0xdd, 0xee, 0xdd, 0xfb, 0xed, 0xee, 0xde, 0xfd,
    0xda, 0xd5, 0xee, 0xdd, 0xda, 0x5c, 0x55, 0xcc,
    0xda, 0xdc, 0xcc, 0xcc, 0xca, 0xcd, 0xcc, 0xbc,
    0xcf, 0xcd, 0xcc, 0xbc, 0xaf, 0xcd, 0xcc, 0xbc,
    0xf0, 0xcb, 0xcc, 0xab, 0x00, 0xff, 0xff, 0xff,
    0xec, 0xee, 0xcd, 0xfd, 0xdc, 0xce, 0xcc, 0xfb,
    0xdc, 0xcd, 0xcc, 0xfb, 0xcb, 0xcd, 0xcb, 0xfb,
    0xbb, 0xcc, 0xbb, 0xfa, 0xbb, 0xcb, 0xfc, 0x0f,
    0xfa, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
};

int main() {
	if (kt_Init()) {
		return 0;
	}

	kt_TileData(0, 12, (u32 *) spr_tiles);
	kt_PaletteData(0, 16, spr_palette);

	while (1) {
		kt_Poll();

		printf("%04x %04x %04x\n", kt_JoyButtonUp(0)
							, kt_JoyButtonDown(0)
							, kt_JoyButtonHeld(0));
		if (kt_JoyButtonHeld(0) & JOY_A) {
			kt_BackColorSet(0x505050);
		} else {
			kt_BackColorSet(0x202050);
		}

		kt_Draw();
	}

	return 0;
}
