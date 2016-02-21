// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/songshulin.c

inherit ROOM;

void create ()
{
  set ("short", "松树林");
  set ("long", @LONG

高大的松树枝叶繁茂，阳光从枝叶的空隙钻进来，穿透林间的
薄雾，亦真亦幻，在厚厚的落叶上留下点点亮斑。山风过处，
整个山林沙沙作响，美妙如歌。偶有一些不怕人的小动物在林
间钻进钻出，颇惹人爱怜。

LONG);

  set("exits", ([
        "northeast": __DIR__"yangchanglu1",
      ]));
//  set("outdoors", __DIR__);
        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/animal" : 2,
        ]));

  setup();
}





