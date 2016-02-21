//create by smile 12/8/98
// room: /d/qujing/baigudong/shanshipo.c

inherit ROOM;

void create ()
{
  set ("short", "山石坡");
  set ("long", @LONG

    终于走出了山石路，望眼而去是一片起伏不平的山坡田。
四周远远都是山峦，山坡坡度不大，两边的山坡田都已干
裂，天气确实炎热。走在山坡上静悄悄，烈阳高照，让人
心浮气躁,隐约听到有人呼喝声。

LONG);

  set("exits", ([
        "westdown"       : __DIR__"xiapolu1",
        "northeast"  : __DIR__"sroad7",
      ]));
  set("objects", ([
        __DIR__"obj/baigu"   : 1,
      ]));
  set("outdoors",__DIR__"");

  setup();
}

int valid_leave (object who, string dir)
{
  object where = this_object ();

   who->set_temp("obstacle/east_from",1);
  if (who->query("obstacle/baigudong")=="done")
         return ::valid_leave (who, dir);
 
  if (dir == "northeast")
    return ::valid_leave (who, dir);

  if (who->query_temp("obstacle/baigudong_nuzi_killed") == 0)
  {
    if (! present ("nu zi",where))
    {
      object ob = new (__DIR__"npc/nuzi");
      ob->move(where);
     return notify_fail("突然一声惨叫，一名妙龄女子从山坡上滚了下来，跌倒在你脚下。\n");
    }
    return notify_fail("妙龄女子扯住你的脚，不让你走。\n");  
  }
  if (who->query_temp("obstacle/baigudong_furen_killed") == 0)
  {
    if (! present ("fu ren",where))
    {
      object ob = new (__DIR__"npc/furen");
      ob->move(where);
       return notify_fail("你眼前身影一晃，一位年迈的老妇人拦住了你。\n");
    }
      return notify_fail("老妇人拦住了你,不让你走。\n");
  }
  if (who->query_temp("obstacle/baigudong_gonggong_killed") == 0)
  {
    if (! present ("gong gong",where))
    {
      object ob = new (__DIR__"npc/gonggong");
      ob->move(where);
    return notify_fail("忽然听到一声哀叹，一位白发苍苍的老公公挡在你面前。\n");
    }
    return notify_fail("老公公揪住你，就不让你走。\n");
  }
  return ::valid_leave (who, dir);
}
