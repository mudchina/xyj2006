// mon 9/26/98

inherit ROOM;
#include <ansi.h>

int max_i, max_j, max_k;

mixed inc=({ ({-1,0,0}),
	     ({1,0,0}),
	     ({0,-1,0}),
	     ({0,1,0}),
	     ({0,0,-1}),
	     ({0,0,1}),
	     });
int *opposite=({1,0,3,2,5,4});
int *index=({1,2,4,8,16,32});
// down, up, west, east, south, north
//  1  , 2,  4,    8,     16,   32
mixed maze;

void search_path(int i, int j, int k);

void create ()
{
    set ("short", "maze");
    setup();
}

void init()
{
    add_action("do_setup", "setup");
    add_action("do_show", "show");
}

int do_setup(string arg)
{
    int i,j,k,i1,j1,k1,out,m,n;
    if(!arg) return 0;
    if(sscanf(arg, "%d %d %d", i,j,k)!=3)
	return 0;
    if(i<1 || i>20) return 0;
    if(j<1 || j>20) return 0;
    if(k<1 || k>20) return 0;
    
    max_i=i;
    max_j=j;
    max_k=k;
    maze=0;
    
    maze=allocate(max_i+2);
    for(i=0;i<=max_i+1;i++) {
	maze[i]=allocate(max_j+2);
	for(j=0;j<=max_j+1;j++) {
	    maze[i][j]=allocate(max_k+2);
	}
    }

    for(i=1;i<=max_i;i++)
	for(j=1;j<=max_j;j++)
	    for(k=1;k<=max_k;k++)
		maze[i][j][k]=0;
    for(i=0;i<=max_i+1;i++)
	for(j=0;j<=max_j+1;j++) {
	    maze[i][j][0]=-1;
	    maze[i][j][max_k+1]=-1;
	}
    for(i=0;i<=max_i+1;i++)
	for(j=0;j<=max_k+1;j++) {
	    maze[i][0][j]=-1;
	    maze[i][max_j+1][j]=-1;
	}
    for(i=0;i<=max_j+1;i++)
	for(j=0;j<=max_k+1;j++) {
	    maze[0][i][j]=-1;
	    maze[max_i+1][i][j]=-1;
	}
    
    // starting position
    search_path(1,1,1);

    // loop over maze
    for(i=1;i<=max_i;i++) 
	for(j=1;j<=max_j;j++)
	    for(k=1;k<=max_k;k++) {
		if(maze[i][j][k]==0) { // not connected yet.
		    out=-1;
		    for(m=0;m<6;m++) {
			i1=i+inc[m][0];
			j1=j+inc[m][1];
			k1=k+inc[m][2];
			if(maze[i1][j1][k1]<=0) continue;
			out=m;
			if(random(2)==0) break;
		    }
		    if(out==-1) {
			write("sth wrong in loop over maze.\n");
			return 0;
		    }
		    m=out;
		    n=opposite[m];
		    i1=i+inc[m][0];
		    j1=j+inc[m][1];
		    k1=k+inc[m][2];
		    maze[i1][j1][k1]+=index[n];
		    maze[i][j][k]=index[m];
		    
		    search_path(i,j,k);
		}
	    }
    write("ok.\n");
    return 1;
}

void search_path(int i, int j, int k)
{
    int i1,j1,k1,out,cont,m,n;

    cont=1;
    while(cont) {
	out=-1;
	for(m=5;m>=0;m--) {
	    if(m==2) { // reduce the possibility of going up and down.
		if(out!=-1 && random(10)>0) break;
	    }
	    i1=i+inc[m][0];
	    j1=j+inc[m][1];
	    k1=k+inc[m][2];
	    if(maze[i1][j1][k1]!=0) continue;
	    out=m;
	    if(random(2)==0) break;
	}
	if(out==-1) return;
	m=out;
	n=opposite[m];
	i1=i+inc[m][0];
	j1=j+inc[m][1];
	k1=k+inc[m][2];
	maze[i][j][k]+=index[m];
	maze[i1][j1][k1]=index[n];
	i=i1;
	j=j1;
	k=k1;
    }
}

int do_show(string arg)
{
    int i,j,k,m;
    string str;

    if(!arg) return 0;
    if(sscanf(arg, "%d", i)!=1) return 0;
    if(i<0 || i>max_i) return notify_fail("show i (0<i<"+
	    (max_i+1)+")\n");
    str="\n\n.";
    for(j=1;j<=max_j;j++)
	str+="_.";
    str+="\n";
    for(k=max_k;k>0;k--) {
	str+="|";
	for(j=1;j<=max_j;j++) {
	    m=maze[i][j][k];
	    if((m&16)>0) str+=" ";
	    else str+="_";
	    if((m&8)>0) str+=".";
	    else str+="|";
	}
	str+="\n";
    }
    str+="\n";
    write(str);
    return 1;
}





