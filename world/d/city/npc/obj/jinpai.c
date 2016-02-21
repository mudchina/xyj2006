// created by error

inherit ITEM;
inherit RANK_D;
#include <ansi.h>

void create()
{
  set_name("挑战金牌", ({ "jin pai", "pai" }) );
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", @LONG
一面金牌，上面刻着“友谊第一，比武第二”八个字。
你可以凭这面金牌向其他玩家挑战(challenge)！
LONG);
    set("unit", "块");
      set("value",1000);
  }
  setup();
}

int init ()  
{   
  add_action("do_defend","challenge");
  return 1;
}

int do_defend(string arg)
{
  object me,ob,other;
  int j;
  me=this_player();
  if (!arg) return notify_fail("你要向谁挑战?\n");	
  ob=LOGIN_D->find_body(arg);
  if (!ob || !me->visible(ob)) return notify_fail("这里没有这个人。\n");
  if (ob==me) return notify_fail("挑战自我，有志气！\n");
  if (me->query_temp("objectob"))
  {
    if (me->query_temp("objectob")==ob->query("id"))
      return notify_fail ("你已经向他挑战了!\n");
    else 
     {
      other=LOGIN_D->find_body(me->query_temp("objectob"));
      if (other) 
        {
         tell_object(me,"你估计打不过"+other->query("name")+"，决定不和他打了。\n");
         tell_object(other,me->query("name")+"等你不到，以为你不敢去，决定不和你打了。\n");
        }
     }
   } 
  message_vision("$N想跟$n讨教切磋武功法术。\n",me,ob);
  tell_object(ob,me->query("name")+"告诉你："+RANK_D->query_rude(ob)
     +"，有没有胆子和我打上一架(defend)？！我在擂台等你！\n");
     
  me->set_temp("objectob",ob->query("id"));

  return 1;
}
