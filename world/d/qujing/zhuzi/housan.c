// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "后三宫");
  set ("long", @LONG

后三宫为三宫连通，东边为玉圣，西边为银圣，中间为金圣。宫殿
华丽无比金银玉雕嵌四周，地上铺设紫红绣锦绒毯，西边更有阵阵
丝竹乐声轻缓飘来。

LONG);
  set("exits", ([ 
    "northwest" : __DIR__"neiyuan",
    "northeast" : __DIR__"nei",
    "west" : __DIR__"zhaoyang",
  ]));
  setup();
}
