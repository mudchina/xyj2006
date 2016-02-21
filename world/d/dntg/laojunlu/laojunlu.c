#include <ansi.h>
#include <room.h>
inherit ROOM;


void create()
{
set("short", "丹房");
set("long", @LONG
    
这八卦炉中四处都是文武之火，坐在其中，只感到浑身燥热难当。
LONG );

     set("exits/east", __DIR__"laojunlu"+(string)random(8));
     set("exits/west", __DIR__"laojunlu"+(string)random(8));
     set("exits/south", __DIR__"laojunlu"+(string)random(8));
     set("exits/north", __DIR__"laojunlu"+(string)random(8));

     set("objects", ([ /* sizeof() == 4 */
       __DIR__"npc/huoshen" : 1,

]));

     set("has_ppl","no");
setup();
}

void init() 
{
  delete("exits/out");
  if( userp(this_player()) )  this_object()->set("has_ppl","yes");
  if(this_player()->query_temp("dntg/laojunlu_day") >= 49)
    {
     if (this_player()->query("dntg/laojunlu") != "allow")
       {
        message_vision(HIY"只听外面隐隐传来太上老君的声音：时辰已到，童儿开炉吧。\n"NOR,this_player());
        this_player()->set("dntg/laojunlu","allow");
       } 
     set("exits/out", __DIR__"luwai");
    } 


  if (this_player()->query("dntg/laojunlu") == "begin")
    {
    remove_call_out ("check_hp");
    call_out ("check_hp", 3,this_player());
    }


  add_action("do_quit", "quit");
   add_action ("do_cast","cast");
}

int check_hp(object who)
  {
  object where = this_object();


  if ( (! who)  ||    (! present(who, where)) )  return 1;

  if (random(4)==1 && who->query("kee") > 20  )
    {
    who->add("kee",-20);
    message_vision(HIY"四壁卷起一团火焰，烧得$N焦头烂额！\n"NOR,who);
    }
  if ( (100*(who->query("kee")))/(who->query("max_kee")) <= 10)
    {
     message_vision(HIY"$N被烧得头晕眼花，再也支撑不住了。\n"NOR,who);
     who->delete_temp("last_damage_from");
     who->set_temp("death_msg", "在八卦炉中被熊熊烈火烧成了灰烬。\n");
     who->die();
     who->save();
     return 1;
    }


  remove_call_out ("check_hp");
  call_out ("check_hp", 3,who);

  return 1;
  }


int do_quit ()
{
  object me;
  object tiangong=load_object("/d/dntg/sky/lingxiao.c");
  object yuhuang;

  me = this_player();
  me->set("startroom",base_name(environment(me)));

  if ( present ("yuhuang dadi", tiangong))
    {
    yuhuang=( present ("yuhuang dadi", tiangong));
    yuhuang->delete("laojunlu");
    }

  this_object()->set("has_ppl","no");
  tell_object(me,"暂时离开老君炉……\n");
  return 0; 
}


int valid_leave(object me, string dir)
{
/*
    object tiangong=load_object("/d/dntg/sky/lingxiao.c");
    object yuhuang;

    if ( present ("yuhuang dadi", tiangong) && dir=="out")
      {
      yuhuang=( present ("yuhuang dadi", tiangong));
      yuhuang->delete("laojunlu");
      }
*/
    this_object()->set("has_ppl","no");
    remove_call_out ("check_hp");
    return ::valid_leave(me, dir);
}

int do_cast (string arg)
{
  object who = this_player();

  if (who->query("dntg/laojunlu")=="allow" && 
             (arg=="escape" || arg=="shuidun" || arg=="tudun"))
     {
      tell_object(who,"哪里跑！\n");
      return 1;
     }
  else return 0;
}
