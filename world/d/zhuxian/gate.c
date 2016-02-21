inherit ROOM;

void create ()
{
  set ("short", "空地");   
  set ("long", @LONG   
总算出了十绝阵，你眼前一亮，居然有一块空地，上面站着三个人。
LONG);

    set("exits", ([ 
               "south" : __DIR__"hongsha",
                 ]));
    set("objects",([
                    __DIR__"npc/ttjz" : 1,
                    __DIR__"npc/ystz" : 1,
                    __DIR__"npc/xyhd" : 1,
                 ]));
  set("outdoors", __DIR__);
    setup();
}
