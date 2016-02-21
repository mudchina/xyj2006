// Room: come to baigudong.c or come to pingding  writted by smile 12/9/1998

inherit ROOM;

int do_sit(string arg);
int timer_sit(object ob);

void create ()
{
  set ("short", "三叉口");
  set ("long", @LONG
 
  这里是白骨山与平顶山分界的地方，以前经常有商人来
往，后来白骨山出了个白骨精，吃了无数过往行人，于是
再也没有行人敢往这条路走了。
  往西就是碗子山和平顶山，往北是白骨山，远远看去，
白骨山阴气重重，连耀人的炎阳也照不透。
  边上有一块平滑的山石(stone)，看来可以让过往行人
走累了坐下休息一阵。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wroad",
  "northup":__DIR__"baigushan",
  "eastup":__DIR__"xiapolu3",
]));
    set("item_desc",([
            "stone" : "这是一块长三尺，宽两尺的石头，朝天那面已经被过往行人磨坐得很平滑了\n",
                            ]));
  setup();
}

void init()
{
 add_action("do_sit","sit");
 add_action("do_sit","zuo");
}

int do_sit(string arg)
{
   object who=this_player();
     object where=this_object();
    if(!arg)   return notify_fail("你要坐什么石头？\n");
    if(arg!="stone"&&arg!="石头"&&arg!="山石"&&arg!="shitou")
        return notify_fail("你要坐什么？\n");
       if(who->query_temp("has_sitted"))
          return notify_fail("你不是已经坐着了吗？\n");
       if(where->query("has_sitted")) 
         return notify_fail("上面已经坐了人！\n");
  message_vision("\n$N往下一坐，坐到山石上。\n",who);
       where->set("has_sitted",1);
       who->set_temp("has_sitted",1);
    remove_call_out("timer_sit");
    call_out("timer_sit",180,who);
  return 1;
}

int timer_sit(object ob)
{
  object shanshen;
  object where=this_object();
    if(!ob->query_temp("has_sitted")) return 1;
  where->set("baigudong_has_sitted",1);
  where->set("baigudong_hero",ob);
  shanshen=new("/d/qujing/baigudong/npc/heimian");
  shanshen->move(where);
   where->delete("has_sitted");
   ob->delte_temp("has_sitted");
   return 1;
}

int valid_leave (object who, string dir)
{
   object lingfu;
     object where=this_object();
         who->delete_temp("has_sitted");
         where->delete("has_sitted");
         message_vision("$N站了起来！\n",who);
   if(dir!="northup")  return ::valid_leave(who,dir);
      lingfu=present("lingfu",who);
  if(!lingfu||!who->query_temp("obstacle/baigudong_lingfu_getted"))
       return notify_fail("突然一阵瘴雾扑来，你一个踉跄，摔到在地上！\n");
       destruct(lingfu);
    who->delete_temp("obstacle/baigudong_lingfu_getted");
   return ::valid_leave(who,dir);
}
