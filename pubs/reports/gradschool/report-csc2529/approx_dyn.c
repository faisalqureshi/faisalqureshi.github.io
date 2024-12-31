#include <stdio.h>
#include <math.h>
#include <string.h>
#include "defs.h"
#include "globals.h"


int get_acc(state, torq, fext, ac)
float *state;
float *torq;
float *fext;
float *ac;
{
    register int i;

    if (criterion(state,torq,fext,current_read)) {
	ac[0] = lut[current_read][23];
        ac[1] = lut[current_read][24];
        ac[2] = lut[current_read][25];
        ac[3] = lut[current_read][26];
        ac[4] = lut[current_read][27];
	
	return 1;
    }  

    for(i=0; i<lut_ent; i++) {
        if (i == current_read)
	    continue;

        if (criterion(state,torq,fext,i)) {
	    ac[0] = lut[i][23];
            ac[1] = lut[i][24];
            ac[2] = lut[i][25];
            ac[3] = lut[i][26];
            ac[4] = lut[i][27];
	    current_read = i;

            return 1;
	}
    }

   return 0;
}

int criterion(state, torq, fext, i)
float *state;
float *torq;
float *fext;
{
  if(fabs(lut[i][0] - state[4]) > tol[0] ||
     fabs(lut[i][1] - state[5]) > tol[1] ||
     fabs(lut[i][2] - state[6]) > tol[2] ||
     fabs(lut[i][3] - state[7]) > tol[3] ||
     fabs(lut[i][4] - state[8]) > tol[4] ||
     fabs(lut[i][5] - state[9]) > tol[5] ||
     fabs(lut[i][6] - torq[0]) > tol[6] ||
     fabs(lut[i][7] - torq[1]) > tol[7] ||
     fabs(lut[i][8] - torq[2]) > tol[8] ||
     fabs(lut[i][9] - fext[0]) > tol[9] ||
     fabs(lut[i][10] - fext[1]) > tol[10] ||
     fabs(lut[i][11] - fext[2]) > tol[11] ||
     fabs(lut[i][12] - fext[3]) > tol[12] ||
     fabs(lut[i][13] - fext[4]) > tol[13] ||
     fabs(lut[i][14] - fext[5]) > tol[14] ||
     fabs(lut[i][15] - fext[6]) > tol[15] ||
     fabs(lut[i][16] - fext[7]) > tol[16] ||
     fabs(lut[i][17] - fext[8]) > tol[17] ||
     fabs(lut[i][18] - fext[9]) > tol[18] ||
     fabs(lut[i][19] - fext[10]) > tol[19] ||
     fabs(lut[i][20] - fext[11]) > tol[20] ||
     fabs(lut[i][21] - fext[12]) > tol[21] ||
     fabs(lut[i][22] - fext[13]) > tol[22])
              return 0;
   return 1;
}

put_lut(state, torq, fext, ac)
float *state;
float *torq;
float *fext;
float *ac;
{
    register int i;

    if (lut_ent < 100) {
        lut_ent++;
    } 

    for (i=0; i<6; i++)
        lut[current_index][i] = state[i+4];
    for (i=0; i<3; i++)
        lut[current_index][i+6] = torq[i];
    for (i=0; i<14; i++)
        lut[current_index][i+9] = fext[i];
    for (i=0; i<5; i++)
        lut[current_index][i+23] = ac[i];

    if (current_index < 99)
        current_index++;
    else
        current_index = 0;
}    
    
approx_dyn(State, torq, fext, ac)
float *State;
float *torq;
float *fext;
float *ac;
{
  if(!get_acc(State,torq,fext,ac)) {
	 dyn_luxo(State,torq,fext,ac);
	 put_lut(State,torq,fext,ac);
    }
}    






















