#include <ansi.h>
inherit SSERVER;
#define WIND_FILE "/d/jjf/obj/wind_seal.c"
void get_out(object where);
int cast(object me, object target)
{
  string msg,dest,dir;
  object sleeveroom,qimen;
  string sname;
  object env=environment(me);
  object bagua=present("bagua fu",me);
  seteuid(getuid());
   if(me->query("family/family_name") != "五庄观")
                return notify_fail("[八卦符]是五庄观不传之密！\n");
   if(me->query_temp("pkgame")) return notify_fail("在比赛中还是不要用奇门遁甲阵吧。\n");

  if (me->query_skill("taiyi",1)<60)
     return notify_fail("你的太乙仙法还不够纯熟。\n");
if ((int)me->query("faith") < 500 )
     return notify_fail("你的门忠太低,还未学会奇门遁甲阵。\n");
  if (!bagua) 
    return notify_fail("你身上没有八卦符，不能施展奇门遁甲。\n");
  dir=bagua->query("dir");
  if (!dir) return notify_fail("你必须先在八卦符上指定<direct>施法的方向。\n");
  dest = environment(me)->query("exits/"+dir);
  if(!dest) return notify_fail("这个方向没有路径。\n");
  if (!env->valid_leave(me,dir))
     return notify_fail("你不能朝这个方向施展奇门遁甲。\n");
  sleeveroom=load_object("/d/wiz/sleeveroom");
  if(!sleeveroom) return notify_fail("你失败了。\n");
  sname=me->query("id")+"'s qimen";
  if (me->query_temp("cast_qimen") || present(sname,sleeveroom))
    return notify_fail("你已经在施展奇门遁甲术了。\n");
  if( (int)me->query("mana") < 400 )
          return notify_fail("你的法力不够了！\n");
  if( (int)me->query("sen") < (int)me->query("max_sen")/2 )
      return notify_fail("你现在头脑不清醒，哪里使得出奇门遁甲！\n");
  if( random(me->query("max_mana")) < 50 ) {
       write("你失败了！\n");
       return 1;
  }
  if (me->is_busy())
    return notify_fail("你上一个动作还没有完成。\n");
  if(me->is_fighting())
    return notify_fail("你正忙着打架，没空玩奇门遁甲。\n");
   msg =  HIR "$N叽哩咕噜地念了几句咒语，突然间踪影不见！\n" NOR;
   message_vision(msg, me);
   me->add("mana", -400);
   qimen=new("/d/obj/fabao/qimennei");
   if(!qimen) return notify_fail("ＯＯＰＳ，下半截咒语念错了。\n");
   qimen->set_name(me->query("name")+"的奇门遁甲阵",({sname,"qimen"}));
   if(!qimen->move(sleeveroom)) 
      return notify_fail("ＯＯＰＳ，下半截咒语念错了！\n");
     me->receive_damage("sen", 100);
   if (!env) return notify_fail("ＯＯＰＳ，下半截咒语念错了。:(\n");
   env->set("altered_dir",dir);
   env->set("old_room",dest);
   env->set("exits/"+dir,qimen);
   qimen->set("host",me);
   if (me->move(qimen)) {
     if (me->ride()) me->ride()->move(environment(me));
     qimen->set("old_room",env);
     env=environment(me);
     qimen->set_exits(dest);
     me->set_temp("cast_qimen",1);
   }  
  me->start_busy(random(3));
  return 1;
}
