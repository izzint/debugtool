#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>

int main(void)
{

      /* Initialize peripherals */
    display_init( RESOLUTION_320x240, DEPTH_16_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE );
    dfs_init( DFS_DEFAULT_LOCATION );
    rdp_init();
    controller_init();
    timer_init();

    /* init sprites */
    int fp = dfs_open("/bliss.sprite");
    sprite_t *bliss = malloc( dfs_size( fp ) );
    dfs_read( bliss, 1, dfs_size( fp ), fp );
    dfs_close( fp );
  
while(1)
{
        static display_context_t disp = 0;

        /* Grab a render buffer */
        while( !(disp = display_lock()) );
       
        /*Fill the screen */
        graphics_fill_screen( disp, 0x0 );

        /* Set the text output color */
        graphics_set_color( 0xffffff, 0x000000 );

        graphics_draw_sprite_trans( disp, 0, 0, bliss );
        

        /* rendering stuff and stuff */
        graphics_draw_box(disp,30,55,267,120,245401450);
        graphics_draw_box(disp,25,50,267,120,255000);
        

        graphics_draw_text(disp, 40, 57, "Mandarin Testing Software v0.4");
        

        


        graphics_draw_text(disp, 40, 150, "Hello from the Nintendo 64! :)");

        printf("Loaded!");

      display_show(disp);
}           
    
}