// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "偏堂");
  set ("long", @LONG

偏堂里阴风嗖嗖，洞穴空荡，岩壁犬牙交错乱石丛生。堂里生
着几小堆篝火，烟气层层熏人。东边通向中堂，西北面有一山
门通向洞外。

LONG);

  set("exits", ([
        "east"    : __DIR__"zhong",
        "northwest"    : __DIR__"shanmen",
      ]));
  setup();
}

