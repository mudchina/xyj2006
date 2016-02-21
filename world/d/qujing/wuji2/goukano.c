//  ROOM:  /d/qujing/wuji/guankou.c 关口 乌鸡国和车迟的交界
inherit ROOM;

void create ()
{
  set ("short", "乌鸡国关口");
  set ("long", @LONG

乌鸡国的关口,往西就是车迟国.几个兵将正在这里盘查.两国一向
礼尚往来.边疆守护也乐得轻松,只是这通关文牒却是不可少.
LONG);

  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"shandao3",
    "west" : __DIR__"shandao4",
  ]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (dir == "west")
  {
    if (who->query("obstacle/qujing")=="ren")
    {
      if (who->query("obstacle/wuji")!="done")
      {
      return notify_fail ("一个小兵挡住你说到:“取经人且住,"
 		+"要过关恐怕还得通关文牒。”\n");
      }
      else
      {
      tell_object(who,"几个兵将一起高呼:“此去西天路途遥远,圣僧保重。”\n")  ;
      }
    }
  }
  return ::valid_leave(who, dir);
}

