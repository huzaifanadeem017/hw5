#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<ncurses.h>
#include"dsh.h"
int main(int argc, char** argv) {
    char *line=0;
    size_t size=0;
    int height,width,startY,startX;

    height=30;
    width=50;
    startY=5;
    startX=5;

    


   dsh_init(); 

    printf("dsh> ");
	
    
    while(getline(&line,&size,stdin) > 0) {

       // dsh_run(line);
	printf("dsh>c");



	initscr();
	noecho();
	cbreak();

	WINDOW *inpWindow=newwin(height,width,startY,startX);
	box(inpWindow,0,0);
	mvwprintw(inpWindow,1,1,"Enter Input");
	dsh_run(line);
	mvwprintw(inpWindow,3,3,line);

	refresh();
	wrefresh(inpWindow);
	int inp=wgetch(inpWindow);


	initscr();	
	WINDOW *myWindow=newwin(height,width,startY,startX);
	refresh();
	box(myWindow,'*','*');
	mvwprintw(myWindow,1,1,"History");
	mvwprintw(myWindow,3,3,line);
	wrefresh(myWindow);
	
        int c=getch();

        
  
   
        endwin();	   
   }
	
   
    return 0;
}
