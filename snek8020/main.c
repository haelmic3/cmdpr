#include<unistd.h>
#include<curses.h>

// snek8020
int main()
{
	int i,j,k;
	char frame[1621];
	frame[1620]='\0';
	for(i = 0;i<1620;i++)
	{
		j = i%81;
		k = i/81;
		switch(j)
		{
		default:
			frame[i] = ' ';
			if(j==(k+2))frame[i] = 'A'+k;
		break;case 0:
			frame[i] = '[';
		break;case 79:
			frame[i] = ']';
		break;case 80:
			frame[i] = '\n';
		
		
		}
	}
	// TODO Enable free keyboard input
	for(;;)
	{
		int key = -1;
		switch(key)
		{
		//break;case ESC:goto exit;
		default:break;
		}
		printf("\f%s",frame);
		fflush(stdout);
		usleep(100);
		goto exit;
	}
	exit:
	return 0;
}
