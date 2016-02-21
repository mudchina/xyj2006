// mon@xyj 10/10/98

inherit ROOM;

int max_i = 2;
int max_j = 5;
int max_k = 5;

object maze_g=0;
mixed rooms;

void dest();

void create()
{
  set ("short", "白虎岭");
  set ("long", @LONG

峰岩重叠，涧壑湾环。虎狼成阵走，麂鹿作群行。千尺大蟒，万丈
长蛇。大蟒喷愁雾，长蛇吐怪风。道旁荆棘浅漫，岭上松楠秀丽。
薜萝满目，芳草连天。

草丛中似乎隐隐现出一个洞口(enter)。

LONG);

  set("objects", ([
	__DIR__"maze_generator":1,
      ]));

  set("no_fight",1);
  set("no_magic",1);
//  set("valid_startroom",1);

  setup();
}

void init ()
{
    add_action ("do_test","enter");
    if (! maze_g)
      maze_g = present ("maze generator", this_object());
}
void setup_rooms()
{
    dest();
    maze_g->do_setup(""+max_i+" "+max_j+" "+max_k);
    rooms=maze_g->generate_room(__DIR__"cave");
}

int do_test (string arg)
{
    object room;
    int i,j,k;
    
    if(!rooms)
	setup_rooms();
    else {
        for(i=0;i<max_i;i++)
	  for(j=0;j<max_j;j++)
	    for(k=0;k<max_k;k++) {
		if(!rooms[i][j][k]) {
		    setup_rooms();
		    break;
		}
	    }
    }

    message_vision("$N小心翼翼地走近洞口，探身向里张望。\n",this_player());
    message_vision("忽然$N脚下一滑，扑通跌了进去！\n",this_player());
    this_player()->move(rooms[0][0][0],1);
    message_vision("$N大叫一声，从天而降！\n",this_player());
    maze_g->do_show("1");
    maze_g->do_show("2");
    rooms[random(max_i)][1+random(max_j-1)][random(max_k)]
	->set("exits/out",__DIR__"cave_exit");
    return 1;
}

// mon
void dest()
{
    object* child=children(__DIR__"cave");
    int i=sizeof(child);
    
    while(i--) 
	if(clonep(child[i]))
	    destruct(child[i]);
}

int clean_up ()
{
      return 0;
}

