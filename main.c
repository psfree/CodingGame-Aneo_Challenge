#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int speed;
    scanf("%d", &speed);
    int lightCount;
    scanf("%d", &lightCount);
    int dist[lightCount];
    int dur[lightCount];
    for (int i = 0; i < lightCount; i++) {
        int distance;
        int duration;
        scanf("%d%d", &distance, &duration);
        dist[i] = distance;
        dur[i] = duration;
    }
    
    for(int i =speed; i>0; i--) {
        int j;
        double mps = i*1000.0f/3600.0f;
        int state = 1;
        for(j=0; j<lightCount; j++) {
               double time  = dist[j]/mps;
               double period = 1.0f/(2*dur[j]);
               double status = sin(2*M_PI*period*time);
               if(status<0 ) {
               		state = 0;
                   break;
               }
        }
        if(state==1) {
            printf("%d\n", i);
            break;
        }
        
    }

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");


    return 0;
}
