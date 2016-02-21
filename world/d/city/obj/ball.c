// created by error

inherit ITEM;
inherit RANK_D;
#include <ansi.h>

void create()
{
  set_name("水晶球", ({ "shuijing qiu", "ball" }) );
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", @LONG
一个晶莹透亮的水晶可以用来detect 1-10来探查未知的事.
LONG);
    set("unit", "个");
      set("value",1000);
  }
  setup();
}

int init ()  
{   
  add_action("do_detect","detect");
  return 1;
}

int do_detect(string arg)
{
  object me,ob,other;
  int j;
  string msg_id;
  string rumor_msg,rumor_id;
  me=this_player();
  if (!arg) return notify_fail("你只能查1-10条\n");
  if (sscanf(arg,"%d",j)!=1) return notify_fail("你只能查1-10条\n");	
  if (j<1 || j>10) return notify_fail("你只能查1-10条\n");
  j=CHANNEL_D->query("rumor_point")-j+1;
  if (j<=0) j+=10;
  write(CHANNEL_D->query("rumor_point"));
  if (! rumor_msg=CHANNEL_D->query_rumor_msg(j)) 
    return notify_fail("你想打听什么?\n");
  message_vision("$N抱着水晶球喃喃念了几句咒语。\n",this_player());
  write(HIM"你向水晶请教:刚才'"+rumor_msg+"'是谁说的？\n"NOR);
  rumor_id=CHANNEL_D->query_rumor_id(j);
  if (rumor_id=="none")
   {
     write(HIM"水晶球回答你:'天机不可泄露'\n"NOR);
     return 1;
   }
  write(HIM"水晶球缓缓转动，渐渐出现了一个人影。\n");
  write(HIM"你仔细一看，原来是"HIR+rumor_id+"!\n"NOR);
  return 1;
}
