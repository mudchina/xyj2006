//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;

void create ()
{
  set ("short", "大道");
  set ("long", @LONG

往西去的是一条阳光大道,路的两边草木茂盛,泉水叮咚.柔柔的风儿
轻拂脸面送来一阵阵花香,偶尔一两只野兔从路旁窜过,惊起几只飞鸟
.你走在大道上,不禁脑清目明,心情舒畅.

LONG);
  set("exits", ([
        "northeast"  : __DIR__"dadao1",
        "west":   __DIR__"dadao3",
        ]));
  set("outdoors","hfd");
  setup();
}
