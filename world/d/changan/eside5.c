inherit ROOM;
void create ()
{
  set ("short", "泾水之滨");
  set ("long", @LONG

　　泾水东去，绿杨城郭。漫步于此，不由得心旷神怡。只见
这泾水清澈见底，不时有鱼儿越出水面，旁边一群孩子们正在
挖(wa)蚯蚓(qiuyin)，几位老人正在垂钓(diao)。
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"eside4",
 "south":"/d/shulin/lin1",
 "north":"/d/zhaoze/zhaoze1",
]));
  set("objects", ([ /* sizeof() == 2 */
 "/d/city/npc/leigong":1,
]));
  set("outdoors", 1);
  set("have_qiuyin", 10);
  set("can_fish", 1);
  setup();
}

void init()
{
   add_action("do_dig", "dig");
   add_action("do_dig", "wa");
}

int do_dig(string arg)
{
   object ob,qiuyin;
   object who=this_player();
   object where=this_object();
   if( (!arg) || (arg != "qiu yin" && arg != "qiuyin" && arg !="蚯蚓") )
      return notify_fail("想挖什么？\n");
   if( !(ob = who->query_temp("weapon")) || ( (string)ob->query("skill_type")!="axe" && 
(string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword" ) )
      return notify_fail("找个好锋利的家伙来挖吧。\n");
   if( who->query("kee")<50 )
      return notify_fail("你太累了，先歇会儿再挖吧。\n");
   who->add("kee",-50);
   if (random(10) > where->query("have_qiuyin"))
      message_vision("$N在泥巴中翻来翻去，结果什么也没找到。\n", who);
   else  
     {
     qiuyin=new("/d/southern/jinghe/obj/qiuyin");
     qiuyin->move(who);
        message_vision("$N从泥巴里找到一只蚯蚓，把它抓了出来。\n", who);
     where->add("have_qiuyin",-1);
     call_out("regenerate", 300);
     }
     return 1;
}

int regenerate()
{
   object where=this_object();
   if (where->query("have_qiuyin") < 10)  
        where->add("have_qiuyin",1);
   return 1;
}
