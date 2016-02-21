// Room: dongnei  create by smile 12/10/1998
inherit ROOM;

void create()
{
  set ("short", "洞内");
  set ("long", @LONG

  这里就到了白骨洞内了。
   洞壁磷火悠悠的，忽闪忽闪，照得你的脸一阵绿一阵黑，
脚下踩着了骨架，格吱格吱的，你打了个冷战。
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "enter" : __DIR__"baigudong",
    "out" : __DIR__"dongkou",
    "west": __DIR__"wangukeng",
    "east": __DIR__"xuechi",
  ]));
  set("outdoors", __DIR__"");                   
  setup();
}
