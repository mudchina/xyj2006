// Room: /d/nanhai/shuyuan
inherit ROOM;
#include <ansi.h>

string *strs = ({
        "须菩提！一合相者，则是不可说，但凡夫之人贪著其事。\n",
        "须菩提！菩萨所作福德，不应贪著，是故说不受福德。\n",
        "若以色见我，以音声求我，是人行邪道，不能见如来。\n",
        "须菩提！若福德有实，如来不说得福德多；以福德无故，如来说得福德多。\n",
        "须菩提！于意云何？如来有肉眼不？\n",
        "如是，世尊！如来有肉眼。\n",
        "须菩提！于意云何？如来有天眼不？\n",
        "如是，世尊！如来有天眼。\n",
        "须菩提！于意云何？如来有慧眼不？\n",
        "如是，世尊！如来有慧眼。\n",
        "须菩提！于意云何？如来有法眼不？\n",
        "如是，世尊！如来有法眼。\n",
        "须菩提！于意云何？如来有佛眼不？\n",
        "如是，世尊！如来有佛眼。\n",
        "须菩提！于意云何？恒河中所有沙，佛说是沙不？\n",
        "如是，世尊！如来说是沙。\n",
     });
     
void init();
void check_time(object where);
void nianjing(object where);
void finish_nianjing(object where);

void create ()
{
  set ("short", "书院");
  set ("long", @LONG

这里就是普陀山书院，书架上摆着无数书籍。普陀山门人弟子
中有来提高基本读书识字的，更多的是来钻研佛经修练佛法的，
以期早日修得正果。书院每天卯时至辰时念经礼佛，凡普陀弟子
可以来此念经（nianjing）。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zoulang",
]));
  set("objects", ([ /* sizeof() == 3 */
  "/d/obj/book/san.c" : 1,
  "/d/obj/book/jingang" : 1,
  __DIR__"npc/shami" : 1,
]));
  set("light_up", 1);

  setup();
}

void init()
{
  remove_call_out("check_time");
   check_time(this_object());
   add_action("do_nianjing", "nianjing");
}

void check_time(object where)
{
   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];
   int phase=((int)(t/120));
   
   if(phase==3&&(!query("nanhai/start_nianjing"))) nianjing(where);
if(phase==4&&query("nanhai/start_nianjing")) finish_nianjing(where);
   call_out("check_time",60,where);
}

void nianjing(object where)
{
     message("channel:es",HIG+"【南海普陀山】惠岸行者(Xing zhe)：门人该来念经了!\n"+NOR,users());
     where->set("nanhai/start_nianjing",1);
} 

int do_nianjing()
{ 
     object who=this_player();
     
     if(who->is_busy())
        return notify_fail("你正忙着呢。\n");
     if(!this_object()->query("nanhai/start_nianjing"))
        return notify_fail("还不到念经的时候呢。\n");
     if((string)who->query("family/family_name")!="南海普陀山")
        return notify_fail("外派弟子不得来此念经。\n");
     tell_object( who,"你低眉垂目，口中微颂："+strs[random( sizeof(strs) )] );
     who->start_busy(5);
     if ( (int)who->query("faith")<1000 )
        who->add("faith",1);
     who->improve_skill("buddhism",random((int)(who->query("spi")+who->query("int"))/2),1);
     who->add("combat_exp",30);
     who->add("potential",10);
     who->receive_damage("kee",20);
     who->receive_damage("sen",20);
     tell_object(who,"你觉得大乘佛法进步了！\n");
     return 1;
}

void finish_nianjing(object where)
{
     tell_object(where,"院外传来悠扬的钟声，却原来是经课结束了。\n");
     tell_object(where,"惠岸行者起身道：各位师兄弟请去吧，经课结束了!\n");
     where->delete("nanhai/start_nianjing");
}
