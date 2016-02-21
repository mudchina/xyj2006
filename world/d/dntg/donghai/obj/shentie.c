//sgzl

#include <ansi.h>

inherit F_UNIQUE;
inherit ITEM;


void create()
{
  set_name("定海神针铁", ({ "shen tie" ,"tie"}));
  set_weight(30000);
  set("long", @LONG
    
传说这神铁是那是大禹治水之时，定江海浅深的一个定子。
上前仔细观瞧， 原来两头是两个金箍，中间乃一段乌铁；
紧挨箍有镌成的一行字，唤做“如意金箍棒”，重一万三
千五百斤。
LONG );

  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "个");
    set("material", "crimsonsteel");
    set("value", 20000000);
    set("no_get", "这么粗的神铁哪里拿得起来？\n");
    set("no_sell", 1);
  }
  setup();
}

void init()
{
        add_action("do_xiao", "xiao");
}

int do_xiao()
{
  object me=this_object();
  object who=this_player();
  object ob;
if (who->query("dntg/donghai")=="done") {
message_vision("$N大喝一声＂小，小，小！但神铁一点反应也没有发生。\n", who);
return 1;
  }

  if (who->query("mana") < 500) 
     message_vision("$N大喝一声＂小，小，小！但什么也没有发生。\n", who);
  else 
    {
     who->add("mana",-500); 
     if (random(5) < 4 )
        message_vision("$N大喝一声＂小，小，小！＂\n只见神铁果然变短变细了些。\n", who);
     else 
       {
       ob=new("/d/dntg/donghai/obj/jingubang");
       message_vision("$N大喝一声＂小，小，小！＂\n只见神铁缩成了一根闪闪放光的金箍棒。\n", who);
       ob->move(environment(me));
       destruct (me);
       }
    }        
  return 1;
}

