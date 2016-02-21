#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short", HIG"森林"NOR);
set("long", @LONG
    
这里是阴森森的一片树林。
  
LONG );
     set("exits/east", __DIR__"mumigong"+(string)random(8));
     set("exits/west", __DIR__"mumigong"+(string)random(8));
     set("exits/south", __DIR__"mumigong"+(string)random(8));
     set("exits/north", __DIR__"mumigong"+(string)random(8));
     set("objects", ([ /* sizeof() == 4 */
       __DIR__"npc/shenjiang" : 1,
        __DIR__"obj/tree" : 1,
]));
setup();
}
void init() 
{
 int i;
        object* inv;
        object me = this_object();
  delete("exits/out");
   if(this_player()->query_temp("shendian/mumigong_kill") >= 2)
    {
        message_vision(HIG"\n刹那间你眼前的石头中间裂开了。\n\n"NOR,this_player());
     set("exits/out", __DIR__"shulinwai");
    } 
if (!((this_player()->query_temp("shendian/mumigong") == "begin") || (this_player()->query("id") == "shen jiang")))
   {
    message_vision(HIW"\n岂有此理，$N是怎么进来的？出去！\n\n"NOR,this_player());
    this_player()->move("/d/city/kezhan");
   }
   if (this_player()->query_temp("shendian/mumigong") == "begin")
    {
    remove_call_out ("check_hp");
    call_out ("check_hp", 3,this_player());
    }
        inv = all_inventory(this_player());
        for(i=0; i<sizeof(inv); i++) 
        {
                if( inv[i]->query_unique() ) {
message_vision(HIW"突然间，$n化一道白光飞去，无影无踪！\n"NOR,me,inv[i]);
                        destruct(inv[i]);
                }
        }
   add_action ("do_cast","cast");
}
int check_hp(object who)
  {
  object where = this_object();
  if ( (! who)  ||    (! present(who, where)) )  return 1;
  if (random(6)==1 && who->query("sen") > 50 )
    {
       who->add("sen",-(100+random(50)));
   message_vision(HIG"\n旁边伸出一根树枝，紧紧缠住了$N，紧接着，喷出一股毒烟\n\n"NOR,who);
     COMBAT_D->report_sen_status(who);
    }
  if ( (100*(who->query("kee")))/(who->query("max_kee")) <= 10)
    {
     message_vision(HIG"$N被抢的喘不过气来，再也支撑不住了。\n"NOR,who);
     who->delete_temp("last_damage_from");
    who->set_temp("death_msg", "在森林中被毒死了。\n");
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
