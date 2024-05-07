#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PSIZE 20

int main()
{
	char *playlist[PSIZE] = {
		"Like a Rolling Stone", "Satisfaction", "Imagine",
		"What's Going On", "Respect", "Good Vibrations",
		"Johnny B. Goode", "Hey Jude", "What'd I Say",
		"Smells Like Teen Spirit", "My Generation",
		"Yesterday", "Blowin' in the Wind", "Purple Haze",
		"London Calling", "I Want to Hold Your Hand",
		"Maybellene", "Hound Dog", "Let It Be",
		"A Change Is Gonna Come"
	};
	int frequency[PSIZE];
	int recentSongs[PSIZE - 5];
	int x,r,count, index;
	int recentlyPlayed;

	/* initialize */
	srand( (unsigned)time(NULL) );
	for(x=0;x<PSIZE;x++)
		frequency[x] = 0;

  for(x=0;x < (PSIZE -5); x++)
	  recentSongs[x]=20;			  //initialize to invalid song

	/* run through the playlist randomly */
	puts("Playlist:");
	count = 0;
	index = 0;
	while(count<100)
	{
		recentlyPlayed = 1;

		while(recentlyPlayed)
		{
			/* does r appear in recent[]? */
			r = rand() % PSIZE; /* random value */
			recentlyPlayed = 0;

			for(x = 0; x < (PSIZE - 5); x++)
			{
				if (r == recentSongs[x])
				{
					recentlyPlayed = 1;
				}
			}
		}

		recentSongs[index++] = r;
		index %= (PSIZE - 5);

		printf("%3d: Now Playing '%s'\n",
				count+1,
				playlist[r]
			  );
		frequency[r]++;
		count++;
	}

	puts("Song frequency:");
	for(x=0;x<PSIZE;x++)
		printf("%s: %d\n",playlist[x],frequency[x]);

	puts("\nRecent Songs\n");
	for (x = 0; x < (PSIZE -5); x++)
		printf("%s \n", playlist[recentSongs[x]]);

	return(0);
}
