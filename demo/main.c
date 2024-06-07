

#include <katsu/kt.h>
#include <stdio.h>
#include "system.h"

/*Demo Palette*/
extern u8 _binary_res_palettes_bg_data_pal_start[];
extern u8 _binary_res_palettes_bg_data_pal_end[];
extern u8 _binary_res_palettes_spr_data_pal_start[];
extern u8 _binary_res_palettes_spr_data_pal_end[];

/*Demo Tiles*/
extern u8 _binary_res_tiles_norm_map_tiles_4bpp_start[];
extern u8 _binary_res_tiles_norm_map_tiles_4bpp_end[];
extern u8 _binary_res_tiles_affine_map_tiles_4bpp_start[];
extern u8 _binary_res_tiles_affine_map_tiles_4bpp_end[];


#define TMAP_PALETTE_OFS 0
#define SPR_PALETTE_OFS (4 * 16)



int main() {
	if (kt_Init()) {
		return 0;
	}
	u32 x = 40;
	u32 y = 20;
	u32 bg_pal_size =  (u32)((u32)&_binary_res_palettes_bg_data_pal_end - (u32)&_binary_res_palettes_bg_data_pal_start);
	u32 nmap_tile_size =  (u32)((u32)&_binary_res_tiles_norm_map_tiles_4bpp_end - (u32)&_binary_res_tiles_norm_map_tiles_4bpp_start) / 32;
	KTSpr spr[4] = {0};
	//kt_TilesetLoad(0, 12, bg_pal_size);
	kt_TilesetLoad(32*2, nmap_tile_size , &_binary_res_tiles_norm_map_tiles_4bpp_start);
	kt_VideoTitleSet("Test program");
	kt_PaletteLoad(0, bg_pal_size, &_binary_res_palettes_bg_data_pal_start);
	//kt_PaletteLoad(SPR_PALETTE_OFS, 16, test_pal_PAL);
	system_Init(15);

	spr[0].pos = KT_SPR_POS(20, 40);
	spr[0].chr = KT_SPR_CHR(0, 0, KT_SIZE_16, KT_SIZE_24, 0);
	spr[0].sfx = KT_SPR_HUE(0xFFFF, 0x00) | KT_SPR_BLEND(0x80);
	spr[0].mtx = 0;

	spr[1].pos = KT_SPR_POS(60, 120);
	spr[1].chr = KT_SPR_CHR(0, 0, KT_SIZE_32, KT_SIZE_16, 0);
	spr[1].sfx = 0;
	spr[1].mtx = 0;

	spr[2].pos = KT_SPR_POS(40, 20);
	spr[2].chr = KT_SPR_CHR(12, 0, KT_SIZE_64, KT_SIZE_48, 1);
	spr[2].sfx = KT_SPR_HUE(0x00FF, 0x80);
	spr[2].mtx = 0;


	kt_LayerInitSprite(1, 3, spr);
	kt_LayerInitMap(0, KT_LAYER_MAP_NORMAL, 0, KT_MAP_SIZE_64x64);
	kt_VideoFrameSet(KT_VIDEO_FRAME_2X);

	kt_TilemapSetChr(0, 4, 4, 1, KT_FLIP_NONE, 0);
	kt_TilemapSetChr(0, 5, 4, 1, KT_FLIP_X, 0);
	kt_TilemapSetChr(0, 4, 2, 1, KT_FLIP_XY, 0);
	kt_TilemapSetChr(0, 7, 6, 1, KT_FLIP_NONE, 0);
	for (int i = 0; i < 64;++i) {
		for (int j = 0; j < 64;++j) {
		kt_TilemapSetChr(1, i, j, 1, KT_FLIP_NONE, 0);
		kt_TilemapSetChr(2, i, j, 5, KT_FLIP_NONE, 0);
		kt_TilemapSetChr(3, i, j, 3, KT_FLIP_NONE, 0);
		}
	}


	system_WindowBegin(10, 4, 15);
	system_WindowLabel("HELLO THERE");
	system_WindowLabel("");
	system_WindowLabel("DEMO");
	system_WindowLabel("");
	system_WindowLabel("OPTION");
	system_WindowEnd();
	kt_LayerInitMap(15, KT_LAYER_MAP_NORMAL, 15, KT_MAP_SIZE_64x64);

	KTColor col_a = {0x50, 0x50, 0x50, 0x0};
	KTColor col_b = {0x50, 0x20, 0x20, 0x0};
	while (1) {
		kt_Poll();

		u32 btns = kt_JoyButtonHeld(0);
		x += ((btns >> JOY_BIT_RIGHT) & 0x1) - ((btns >> JOY_BIT_LEFT) & 0x1);
		y += ((btns >> JOY_BIT_DOWN) & 0x1) - ((btns >> JOY_BIT_UP) & 0x1);
		kt_OffsetColor(x - 50, x - 50, y - 50);

		//kt_LayerRect(0, 10, 15, x+30, y+40);
		kt_LayerSetMapOffset(0, x, y);

		spr[2].pos = KT_SPR_POS(x, y);

		if (kt_JoyButtonHeld(0) & JOY_A) {
			kt_BackColor(col_a);
		} else {
			kt_BackColor(col_b);
		}
		kt_Draw();
	}

	return 0;
}
