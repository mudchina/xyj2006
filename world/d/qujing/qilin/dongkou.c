// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "洞口");
  set ("long", @LONG

拐弯处一个巨大的洞口，如巨兽一般张开血盆大口。洞里灯火通明
沸沸扬扬，洞口旌旗飘闪。洞的正上方有一巨岩凸出，写着“麒麟
山獬豸洞”几个大字。

LONG);

  set("exits", ([ 
    "eastdown" : __DIR__"yading",
    "northeast" : __DIR__"dongnei",
  ]));
  set("outdoors", __DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  int to_die = who->query("combat_exp") < 4000;

  if (dir == "eastdown")
    return ::valid_leave (who,dir);

  if (who->query("combat_exp")>1000000 &&
      ! wizardp(who))
    return ::valid_leave (who,dir);

  switch (random(3))
  {
    case 0:
    {
      message_vision ("突然洞里喷出烘烘火光，如千条火龙迎面扑来！\n\n",who);
      message_vision ("$N勉强走了几步，扑倒在地。\n",who);
      who->unconcious();
      if (to_die)
      {
        who->delete_temp("last_damage_from");
        who->set_temp("death_msg","被千条火龙烧死了。");
        who->die();
        who->save();
      }
      break;
    }
    case 1:
    {
      message_vision ("突然洞里冒出股股五色恶烟，铺天盖地滚滚而来！\n\n",who);
      message_vision ("$N勉强走了几步，扑倒在地。\n",who);
      who->unconcious();
      if (to_die)
      {
        who->delete_temp("last_damage_from");
        who->set_temp("death_msg","被五色恶烟熏死了。");
        who->die();
        who->save();
      }
      break;
    }
    case 2:
    {
      message_vision ("突然洞里迸出漫天沙，如遮天蔽日地铺将过来！\n\n",who);
      message_vision ("$N勉强走了几步，扑倒在地。\n",who);
      who->unconcious();
      if (to_die)
      {
        who->delete_temp("last_damage_from");
        who->set_temp("death_msg","被漫天之沙活埋了。");
        who->die();
        who->save();
      }
      break;
    }
  }  
  if (! to_die)
    call_out ("moving",1,who);
  //return notify_fail("你一阵天旋地转……\n");
  return 1;
}

void moving (object who)
{
  who->move(__DIR__"dongnei");        
}
