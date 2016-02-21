#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short", HIC"石林"NOR);
set("long", @LONG
    
这里到处是奇形怪状的石柱子。
  
LONG );
     set("exits/east", __DIR__"tumigong"+(string)random(8));
     set("exits/west", __DIR__"tumigong"+(string)random(8));
     set("exits/south", __DIR__"tumigong"+(string)random(8));
     set("exits/north", __DIR__"tumigong"+(string)random(8));
     set("objects", ([ /* sizeof() == 4 */
       __DIR__"npc/shenjiang" : 1,
        __DIR__"obj/shitou" : 1,
]));
setup();
}
void init() 
{
  delete("exits/out");
  if(this_player()->query_temp("shendian/tumigong_kill") >= 2)
    {
        message_vision(HIC"\n刹那间你眼前的石头中间裂开了。\n\n"NOR,this_player());
     set("exits/out", __DIR__"linwai");
    } 
if (!((this_player()->query_temp("shendian/tumigong") == "begin") || (this_player()->query("id") == "shen jiang")))
   {
    message_vision(HIW"\n岂有此理，$N是怎么进来的？出去！\n\n"NOR,this_player());
    this_player()->move("/d/city/kezhan");
   }
   if (this_player()->query_temp("shendian/tumigong") == "begin")
    {
    remove_call_out ("check_hp");
    call_out ("check_hp", 3,this_player());
    }
   add_action ("do_cast","cast");
}
int check_hp(object who)
  {
  object where = this_object();
  if ( (! who)  ||    (! present(who, where)) )  return 1;
  if (random(6)==1 && who->query("kee") > 50 && who->query("sen") > 50 )
    {
    who->add("kee",-(80+random(50)));
     who->add("sen",-(80+random(50)));
   message_vision(HIC"\n一根石柱断成两截，砸到$N头上！\n\n"NOR,who);
    COMBAT_D->report_status(who);
 COMBAT_D->report_sen_status(who);
    }
  if ( (100*(who->query("kee")))/(who->query("max_kee")) <= 10)
    {
     message_vision(HIC"$N被石头砸得头破血流，再也支撑不住了。\n"NOR,who);
     who->delete_temp("last_damage_from");
     who->set_temp("death_msg", "在石林中被砸死了。\n");
     who->die();
     who->save();
     return 1;
    }
  remove_call_out ("check_hp");
  call_out ("check_hp", 3,who);
  return 1;
  }
int do_cast (string arg)
{
  object who = this_player();
  if (who->query_temp("shendian/tumigong")=="begin" && 
             (arg=="escape" || arg=="shuidun" || arg=="tudun"))
     {
      tell_object(who,"这里不能逃生！\n");
      return 1;
     }
  else return 0;
}
