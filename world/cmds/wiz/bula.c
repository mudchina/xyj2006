// random load

inherit F_CLEAN_UP;

int random_go(object me, string* dirs)
{
	int		i, j, k;
	object	newob;
	mixed*	file;

	if( !sizeof(dirs) )  return 1;

    i = random(sizeof(dirs));    // pick up one directory

	file = get_dir( dirs[i]+"*.c", -1 );
	if( !sizeof(file) )		return 1;

	k = sizeof(file);
	while(1)  {
	   j = random(k);
	   if( file[j][1] > 0 )		break; 		// pick up a file with size > 0
	}

    if( (newob=find_object(dirs[i]+file[j][0])) )   {
		me->move( newob ); 
	}
	else  {
		seteuid(getuid(me));
		newob = load_object(dirs[i]+file[j][0]);
		if (newob)   // now this is not necessary, only for debug use
			me->move(newob);
        else  {
			tell_object(me, "Error.\n");
		}
	}

	return 1;
}


int main(object me, string arg)
{
	string* dirs;

	dirs = ({"/d/4world/","/d/city/","/d/gao/", "/d/jjf/",
"/d/lingtai/", "/d/meishan/","/d/moon/", "/d/nanhai/", "/d/penglai/",
"/d/sea/","/d/sky/", "/d/xueshan/", "/d/qujing/nuerguo/", 
"/d/qujing/wudidong/", "/d/qujing/firemount/"});
    	random_go(me, dirs);

	return 1;
}
