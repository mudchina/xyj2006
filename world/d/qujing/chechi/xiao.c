// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/xiao.c

inherit ROOM;

void create ()
{
  set ("short", "小相府");
  set ("long", @LONG

小相府门口放着一紫檀木武器架，朝南开有一排莲花窗，朝西靠
墙设有仙桌仙椅，上面供有时鲜水果。北面是一排白底彩染绸缎
面屏风，将堂屋隔开。

LONG);

  set("exits", ([
        "east"         : __DIR__"jieshi1",
      ]));

  set("objects", ([
        __DIR__"npc/xiaoguan"  : 1,
      ]));

  setup();
}

