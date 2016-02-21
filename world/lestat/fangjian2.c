// fangjian2.c
// by lestat

inherit ROOM;
#include <ansi.h>

string *strs = ({
        " 君不见黄河之水天上来，奔流到海不复回  \n",
        " 君不见高堂明镜悲白发，朝如清丝暮成雪   \n",
        " 人生得意须尽欢，莫使金樽空对月         \n",
        " 天生我材必有用。千金散失还复来         \n",
        " 烹羊宰牛且为乐，会须一饮三百杯      \n",
        " 岑夫子，丹丘生，将进酒，君莫停      \n",
        " 与君歌一曲，请君为我侧耳听        \n",
     });
     
void init();
void check_time(object where);
void play(object where);
void finish_play(object where);
void create()
{
        set("short", "桃花阁");
        set("long", @LONG
这是一间琴房，盘丝洞弟子可以在这里练琴(play).房内有张石
床，墙壁上悬着一个七弦琴，弦线都已经断了。
LONG );
       set("exits", ([
               "south" : __DIR__"shiji2",
       ]));

	    set("objects",([
		__DIR__"npc/niang" : 1,
		"/d/pansi/obj/qin.c":1, 
	]));
	
       set("no_clean_up", 0);
       setup();
}

void init()
{
	remove_call_out("check_time");
        check_time(this_object());
        add_action("do_play", "play");
        add_action("do_han", "han");
}
void check_time(object where)
{
   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];
   int phase=((int)(t/120));
   
   if(phase==5&&(!query("shuilian/start_play"))) play(where);
   if(phase==6&&query("shuilian/start_play")) finish_play(where);
   call_out("check_time",60,where);
}

void play(object where)
{
     message("channel:es",CYN+"◇"MAG"盘丝洞"CYN"◇"WHT"春三十娘[Chun sanshiniang]"CYN"：门人回桃花阁练琴！\n"+NOR,users());
     where->set("shuilian/start_play",1);
} 

int do_play()
{ 
     object who=this_player();
     
     if(who->is_busy())
        return notify_fail("你正忙着呢。\n");
     if(!this_object()->query("shuilian/start_play"))
        return notify_fail("还不到练琴的时候呢。\n");
     if((string)who->query("family/family_name")!="盘丝洞")
        return notify_fail("外派弟子不得来此练琴。\n");
//     tell_object( who,"你低眉垂目，口中微颂："+strs[random( sizeof(strs) )] );
     tell_object( who,"你双手手轻拨琴弦，发出如柳润风般的乐声。" );
     who->start_busy(5);
     if ( (int)who->query("faith")<40000)
     who->add("faith",1);
     who->ichatrove_skill("qin",random((int)(who->query("spi")+who->query("int"))/2),1);
     who->ichatrove_skill("pansi-dafa",random((int)(who->query("spi")+who->query("int"))/2),1);
     who->add("combat_exp",12);
     who->add("potential",3);
     who->receive_damage("kee",20);
     who->receive_damage("sen",20);
     tell_object(who,"你觉得琴艺进步了！\n");
     return 1;
}

void finish_play(object where)
{
     tell_object(where,"乐声猛地一停,春三十娘缓缓站起道:今天就练到这里。\n");
     where->delete("shuilian/start_play");
}

int do_han(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="芝麻开门") 
	{
		tell_object(me,"你气运丹田，对着墙壁大喝一声：“芝麻开门！”\n");
		message("vision", "过了一会儿，你只听到一阵轰隆隆的响声，出现了一道暗门。\n", me);
		set("exits/down", __DIR__"shishi4");
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
}

void close(object room)
{
	message("vision","一阵轰隆隆的响声过后，石门又缓缓地关上了。\n", room);
	room->delete("exits/down");
}
int valid_leave(object me,string dir)
{
        if(dir=="down" && (!me->query("family") || (me->query("family/family_name")!="仙界")) && present("niang",environment(me))) 
             return notify_fail("春十三娘一个闪身，挡住了你的去路！\n");
        return ::valid_leave(me,dir);
}
