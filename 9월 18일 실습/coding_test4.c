#include <stdio.h>



int main(void)
{
	int room_width = 320; 
 	int room_height = 200; 
	int tile_size = 30; 
 
	
	int tiles_needed = (room_width / tile_size + (room_width % tile_size != 0)) * (room_height / tile_size + (room_height % tile_size != 0));
 	printf("필요한 타일 개수: %d개\n", tiles_needed);
	
       
	return 0;
}
