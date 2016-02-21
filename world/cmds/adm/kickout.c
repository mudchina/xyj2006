// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// kickout.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   object link_ob;
   object obj;
   
   if( !arg )
        return notify_fail("你要将谁赶出去？\n");

   if (arg == "me")  return notify_fail("请先申请降职成玩家后再suicide -f\n");

   if  (!objectp(obj= find_player(arg)))
     return notify_fail("该玩家不在线，这次还是放过他吧。\n");
  
   if ( obj == me )
     return notify_fail("请先申请降职成玩家后再suicide -f\n");
   
   link_ob = obj->query_temp("link_ob");
   obj->set("is_banned_char",1);
   obj->save();
   message_vision(HIY"$N大喝一声，从天上降下一道闪电将$n化为灰烬。\n"NOR,me,obj);
   log_file("kickout", sprintf("%s(%s) kickout user %s (%s) at (%s)\n",
    me->query("name"),me->query("id"), obj->query("name"),obj->query("id"), ctime(time())));
   seteuid(ROOT_UID);
   destruct(link_ob);
   destruct(obj);
   seteuid(getuid(me));
   return 1;
}

